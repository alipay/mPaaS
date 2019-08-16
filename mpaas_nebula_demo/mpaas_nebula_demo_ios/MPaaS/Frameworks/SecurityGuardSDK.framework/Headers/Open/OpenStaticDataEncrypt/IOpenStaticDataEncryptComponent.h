//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>


/**
 *  静态加解密算法
 */
@protocol IOpenStaticDataEncryptComponent <NSObject>



/**
 *  传入加密算法,使用的key，需要处理的数据，生成加密结果返回
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要加密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回加密的字符串，失败时返回nil
 */
- (NSString*) staticSafeEncrypt: (NSInteger) mode
                         forKey: (NSString*) key
            forNeedProcessValue: (NSString*) needProcessValue
                       authCode: (NSString*) authCode;



/**
 *  传入解密算法,使用的key，需要处理的数据，生成解密结果返回
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要加密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回解密的字符串，失败时返回nil
 */
- (NSString*) staticSafeDecrypt: (NSInteger) mode
                         forKey: (NSString*) key
            forNeedProcessValue: (NSString*) needProcessValue
                       authCode: (NSString*) authCode;



/**
 *  传入加密算法,使用的key，需要处理的数据，生成加密的字符数组结果返回
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要加密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回加密的字符数组结果，失败时返回nil
 */
- (NSData*) staticBinarySafeEncrypt: (NSInteger) mode
                             forKey: (NSString*) key
                forNeedProcessValue: (NSData*) needProcessValue
                           authCode: (NSString*) authCode;



/**
 *  传入解密算法,使用的key，需要处理的数据，生成解密的字符数组结果返回
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要解密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回解密的字符数组结果，失败时返回nil
 */
- (NSData*) staticBinarySafeDecrypt: (NSInteger) mode
                             forKey: (NSString*)key
                forNeedProcessValue: (NSData*) needProcessValue
                           authCode: (NSString*) authCode;




/**
 *  传入加密算法,使用的key，需要处理的数据，生成加密的字符数组结果返回(与staticBinarySafeEncrypt接口区别在于：对加密结果不做base64)
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要加密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回加密的字符数组结果，失败时返回nil
 */
- (NSData*) staticBinarySafeEncryptNoB64: (NSInteger) mode
                             forKey: (NSString*) key
                forNeedProcessValue: (NSData*) needProcessValue
                           authCode: (NSString*) authCode;



/**
 *  传入解密算法,使用的key，需要处理的数据，生成解密的字符数组结果返回(staticBinarySafeEncryptNoB64对应的解密接口)
 *
 *  @param mode 算法，定义见OpenStaticDataStoreDefine.h
 *
 *  @param key 安全key，用于获取内嵌的keyData
 *
 *  @param needProcessValue 需要解密的数据
 *
 *  @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 *  @return 返回解密的字符数组结果，失败时返回nil
 */
- (NSData*) staticBinarySafeDecryptNoB64: (NSInteger) mode
                             forKey: (NSString*)key
                forNeedProcessValue: (NSData*) needProcessValue
                           authCode: (NSString*) authCode;



@end
