//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>

@protocol IOpenSecurityBodyComponent <NSObject>

/**
 *  获取风控参数
 *  @return 用户昵称，获取失败返回nil
 */
- (NSString*) getSecurityBodyDataEx: (NSString*) timeStamp
                             appKey: (NSString*) appKey
                           authCode: (NSString*) authCode
                        extendParam: (NSDictionary*) extendParam
                               flag: (int) flag
                                env: (int) env
                              error: (NSError* __autoreleasing*) error;

@end
