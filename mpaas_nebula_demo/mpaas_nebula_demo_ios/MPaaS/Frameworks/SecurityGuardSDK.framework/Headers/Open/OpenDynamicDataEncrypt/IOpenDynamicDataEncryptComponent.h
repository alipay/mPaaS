//
// OpenSecurityGuardSDK version 2.1.0
//

#ifndef OpenSecurityGuardSDK_IOpenDynamicDataEncryptComponent_h
#define OpenSecurityGuardSDK_IOpenDynamicDataEncryptComponent_h



/**
 *  动态加解密接口
 */
@protocol IOpenDynamicDataEncryptComponent <NSObject>



/**
 *  普通动态加密字符串值
 *  @param key string值对应的key
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSString*) dynamicEncrypt: (NSString*) plainText;


/**
 *  普通动态解密字符串值
 *  @param cipherText string需要解密的字符串值
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSString*) dynamicDecrypt: (NSString*) cipherText;

/**
 *  普通动态加密byte数组
 *  @param plainByteArray 待加密的byte数组
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSData*) dynamicEncryptByteArray: (NSData*) plainByteArray;


/**
 *  普通动态解密byte数组
 *  @param plainByteArray 需要解密的byte数组
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSData*) dynamicDecryptByteArray: (NSData*) cipherByteArray;

/**
 *  与设备、应用绑定的动态加密字符串值
 *  @param key string值对应的key
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSString*) dynamicEncryptDDp: (NSString*) plainText;

/**
 *  与设备、应用绑定的动态解密字符串值（加解密过程依赖设备硬件）
 *  @param cipherText string需要解密的字符串值
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSString*) dynamicDecryptDDp: (NSString*) cipherText;

/**
 *  与设备、应用绑定的动态加密byte数组（加解密过程依赖设备硬件）
 *  @param plainByteArray 待加密的byte数组
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSData*) dynamicEncryptByteArrayDDp: (NSData*) plainByteArray;

/**
 *  与设备应用绑定的动态解密byte数组（加解密过程依赖设备硬件）
 *  @param plainByteArray 需要解密的byte数组
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSData*) dynamicDecryptByteArrayDDp: (NSData*) cipherByteArray;

@end

#endif
