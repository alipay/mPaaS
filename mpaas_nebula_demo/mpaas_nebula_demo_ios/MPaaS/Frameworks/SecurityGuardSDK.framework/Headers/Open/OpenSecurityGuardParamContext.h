//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>

/**
 *  OpenSecuritGuardSDK的参数结构体
 */
@interface OpenSecurityGuardParamContext : NSObject



/**
 *  应用当前使用的appkey
 */
@property (nonatomic, strong) NSString* appKey;



/**
 *  调用接口的接口的类型标识，类型定义见各component的头文件定义
 */
@property (nonatomic, assign) NSInteger requestType;



/**
 *  传入业务参数使用的dictionary，使用的key值见各component的头文件定义
 */
@property (nonatomic, strong) NSMutableDictionary* paramDict;



/**
 *  根据传入的参数生成参数结构体对象
 *
 *  @param appKey      appkey，应用当前使用的appkey
 *  @param paramDict   存储业务参数的dictionary对象
 *  @param requestType 请求类型
 *
 *  @return 生成的参数结构体对象, autorelease对象
 */
+ (OpenSecurityGuardParamContext*) createParamContextWithAppKey: (NSString*) appKey
                                                      paramDict: (NSDictionary*) paramDict
                                                    requestType: (NSInteger) requestType;



@end
