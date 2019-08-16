//
//  APCustomStorage.h
//  MobileFoundation
//
//  Created by shenmo on 12/5/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBusinessPreferences.h"
#import "APDAOProtocol.h"

typedef NS_ENUM(NSUInteger, APCustomStorageEvent)
{
    APCustomStorageEventWillLoadDatabase = 0,   // 即将创建数据库连接
    APCustomStorageEventDidReleaseDatabase,     // 数据库连接已经关闭
};

typedef void (^APCustomStorageEventListener)(APCustomStorageEvent event, NSString* databasePath, BOOL user);

/**
 *  统一存储APDataCenter对应的默认的存储空间为/Documents/Preferences目录。
 *  业务可以根据需要创建自己的APCustomStorage对象，并指定它的目录。下属的commonPreferences和userPreferences等数据库文件在自己指定的目录里，与APDataCenter的不相关。
 *  业务可以自己持有这个对象，也可以不持有，底层会对相同目录的APCustomStorage保留一份备份。支持与用户无关和相关的数据存储，业务同样无须关注用户切换的事件。
 */
@interface APCustomStorage : NSObject

@property (nonatomic, strong, readonly) NSString* path;

/**
 *  设置监听方法
 */
+ (void)setEventListener:(APCustomStorageEventListener)listener forStorageInDocumentsWithName:(NSString*)name;

/**
 *  创建路径为/Documents/name的自定义存储
 *
 *  @param name Documents下文件夹名称
 */
+ (instancetype)storageInDocumentsWithName:(NSString*)name;

/**
 *  在指定路径创建自定义存储，通常不需要使用这个方法
 *
 *  @param path 路径
 */
- (id)initWithPath:(NSString*)path;

/**
 *  删除自定义存储的所有数据库文件，并重置；用于缓存清除。
 */
- (void)reset;

/**
 *  与用户无关的全局存储对象，使用key-value方式存取数据。
 *  与APDataCenter的区别是：在业务的自定义存储空间里，存储key-value数据时不需要business参数，只需要key即可。
 *
 *  @return 存储对象，方法参看APBusinessPreferences
 */
- (APBusinessPreferences*)commonPreferences;

/**
 *  当前登录用户的存储对象，使用key-value方式存取数据。不是登录态时，取到的是nil。
 *  与APDataCenter的区别是：在业务的自定义存储空间里，存储key-value数据时不需要business参数，只需要key即可。
 *
 *  @return 存储对象，方法参看APBusinessPreferences
 */
- (APBusinessPreferences*)userPreferences;

/**
 *  从一个配置文件生成DAO访问对象
 *
 *  @param filePath 文件路径，在main bundle里的文件使用下面方式：
 *      NSString* filePath = [[NSBundle mainBundle] pathForResource:@"file" ofType:@"xml"];
 *  @param userDependent 这个DAO对象操作的数据库文件是否是与用户相关的。如果为YES，那么切换到userB后，dao对象的操作实际会指向userB的数据库文件。
        如果为NO，dao对象的操作会指向common数据库文件，也就是commonPreferences所在的数据库文件。
 *
 *  @return 返回DAO对象，业务不用关心它的类名，只需要使用业务自己定义的id<AProtocol>强制转换一下即可
 *      返回的DAO对象，在需要时也可以使用id<APDAOProtocol>进行转换，调用默认提供的方法。所以自定义的AProtocol不要含有APDAOProtocol里定义的方法。
 */
- (id<APDAOProtocol>)daoWithPath:(NSString*)filePath userDependent:(BOOL)userDependent protocol:(Protocol*)protocol;

@end
