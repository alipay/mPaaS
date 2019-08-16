//
// SecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>


/**
 *  增强加解密算法
 */
@protocol IOpenAtlasEncryptComponent <NSObject>



/**
 *  传入需要处理的数据，生成加密结果返回
 *
 *  @param needProcessValue 需要加密的数据
 *
 *  @param authCode SDK授权码
 *
 *  @return 返回加密的字符串，失败时返回nil
 */
- (NSString*) atlasSafeEncrypt: (NSString*) needProcessValue
                      authCode: (NSString*) authCode;



@end
