//
//  APDataCenter.h
//  AliPay
//
//  Created by shenmo on 14-9-17.
//  Copyright (c) 2014年 shenmo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSharedPreferences.h"
#import "APPreferencesAccessor.h"
#import "APDAOProtocol.h"
#import "APCustomStorage.h"
#import "APCacheProtocol.h"
#import "APLRUMemoryCache.h"
#import "APLRUDiskCache.h"
#import "APUserCacheCleaner.h"
#import "APPurgeablePath.h"
#import "APDataCenter+Utils.h"
#import "RavenJSONEncoder.h"
#import "RavenJSONDecoder.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
/**
 *  打开或关闭统一存储的控制台log，默认是打开的
 */
void APDataCenterLogSwitch(BOOL on);
#ifdef __cplusplus
}
#endif // __cplusplus

/**
 *  前一个用户的数据库文件将要关闭的事件通知。通知的object为前一个用户的userId。
 */
extern NSString* const kAPDataCenterWillLastUserResign;

/**
 *  用户状态已经发生切换的通知。有可能是user变为nil了，具体userId可以用currentUserId来获取。
 *  这个通知附加的object是个字典，如果不为nil，里面@"switched"这个键值返回@YES表示确实发生了用户切换事件。
 */
extern NSString* const kAPDataCenterDidUserUpdated;

/**
 *  用户并没切换，APDataCenter重新收到登入事件。会抛这个通知。
 */
extern NSString* const kAPDataCenterDidUserRenew;

#define APDefaultDataCenter [APDataCenter defaultDataCenter]
#define APCommonPreferences [APDefaultDataCenter commonPreferences]
#define APUserPreferences [APDefaultDataCenter userPreferences]
#define APCurrentVersionStorage [APDefaultDataCenter currentVersionStorage]

@interface APDataCenter : NSObject

@property (atomic, strong, readonly) NSString* currentUserId;

/**
 *  单例对象
 */
+ (instancetype)defaultDataCenter;

/**
 *  得到存储commonPreferences和userPreferences数据库文件夹的路径。
 */
+ (NSString*)preferencesRootPath;

/**
 *  设置当前登录的用户Id，业务代码请不要调用，需要由登录模块调用。
 */
- (void)setCurrentUserId:(NSString*)currentUserId;

/**
 *  完全重置整个统一存储目录，请谨慎。
 */
- (void)reset;

/**
 *  完全重置整个统一存储目录，请谨慎。允许在reset之前和之后执行一个用户指定的回调方法。
 */
- (void)reset:(void(^)())before after:(void(^)())after;

/**
 *  与用户无关的全局存储数据库
 *
 *  @return 存储对象，方法参看APSharedPreferences
 */
- (APSharedPreferences*)commonPreferences;

/**
 *  当前登录用户的存储数据库。不是登录态时，取到的是nil。
 *
 *  @return 存储对象，方法参看APSharedPreferences
 */
- (APSharedPreferences*)userPreferences;

/**
 *  返回指定用户id的存储对象，业务层通常使用userPreferences方法即可。当有异步存储需要时，防止窜数据，可以使用该方法取特定用户的存储对象。
 */
- (APSharedPreferences*)preferencesForUser:(NSString*)userId;

/**
 *  根据business生成一个存取器，业务层需要自行持有这个对象。
 *  使用这个对象访问key-value存储空间时，不需要传business。
 *  比如：
 *      APPreferencesAccessor* accessor = [[APDataCenter defaultDataCenter] accessorForBusiness:@"aBiz"];
 *      [[accessor commonPreferences] doubleForKey:@"aKey"];
 *  等价于调用
 *      [[[APDataCenter defaultDataCenter] commonPreferences] doubleForKey:@"aKey" business:@"aBiz"];
 *
 *  业务层持有的APPreferencesAccessor，在切换用户后不需要重新创建。
 *  @param business 业务名
 *
 *  @return 存取对象，方法参看APPreferencesAccessor
 */
- (APPreferencesAccessor*)accessorForBusiness:(NSString*)business;

/**
 *  统一存储会维护一个当前版本的数据库，当版本发生升级时，这个数据库会重置。
 */
- (APCustomStorage*)currentVersionStorage;

/**
 *  从一个配置文件生成DAO访问对象
 *
 *  @param filePath DAO配置文件的文件路径，在main bundle里的文件使用下面方式：
 *      NSString* filePath = [[NSBundle mainBundle] pathForResource:@"file" ofType:@"xml"];
 *  @param userDependent 指定这个DAO对象操作哪个数据库。如果userDependent=NO，表示与用户无关，那么DAO会在commonPreferences的数据库文件中建表。
 *      如果userDependent=YES，那么DAO对象会在userPreferences的数据库文件中建表。当切换用户后，后续的DAO操作会自动在更换后的用户文件中进行，业务无须关心用户切换。
 *  @param protocol ORM对象实现的接口
 *
 *  @return 返回DAO对象，业务不用关心它的类名，只需要使用业务自己定义的id<AProtocol>强制转换一下即可
 *      返回的DAO对象，在需要时也可以使用id<APDAOProtocol>进行转换，调用默认提供的方法。所以自定义的AProtocol不要含有APDAOProtocol里定义的方法。
 */
- (id<APDAOProtocol>)daoWithPath:(NSString*)filePath userDependent:(BOOL)userDependent protocol:(Protocol*)protocol;

/**
 *  创建一个维护自己独立数据库文件的DAO访问对象
 *  使用daoWithPath:userDependent:接口创建的DAO对象，操作的是commonPreferences或userPreferences。
 *  这个接口会创建一个DAO对象，并且操作的是databasePath指定的特定数据库文件，文件不存在会创建。
 *  可以创建多个DAO对象，指定相同的databasePath。
 *
 *  @param filePath     同daoWithPath:userDependent:接口
 *  @param databasePath DAO数据库文件的位置，可以传绝对路径，也可以传'Documents/XXXX.db'或'Library/Movie/XXX.db'这样的相对路径
 *
 *  @return DAO对象
 */
- (id<APDAOProtocol>)daoWithPath:(NSString*)filePath databasePath:(NSString*)databasePath protocol:(Protocol*)protocol;

@end