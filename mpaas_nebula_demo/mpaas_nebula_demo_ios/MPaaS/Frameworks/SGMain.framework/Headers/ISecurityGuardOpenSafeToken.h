//
//  ISecurityGuardOpenSafeToken.h
//  SecurityGuardMain
//
//  Created by chenkong on 15/12/17.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenSafeToken_h
#define ISecurityGuardOpenSafeToken_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenSafeToken <NSObject, IOpenSecurityGuardPluginInterface>

/**
 *  存储token
 *  @param value 存储的value
 *  @param key token值对应的key
 *  @return 存储操作的结果
 */
- (BOOL) saveToken: (NSString*) value
            forKey: (NSString*) key
        additional: (NSString*) additional
              flag: (int) flag;

/**
 *  检测token是否存在
 *  @param key string值对应的key
 *  @return 检测token是否存在的结果
 */
- (BOOL) isTokenExist: (NSString*) key;

/**
 *  删除本地存储的token
 *  @param key 存储值要使用的key
 *  @return 存储操作结果
 */
- (void) removeToken: (NSString*) key;

/**
 *  使用token加密数据
 *  @param key token值对应的key
 *  @param plaintext 待加密的byte数组
 *  @param flag 扩展参数，缺省为0
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSData*) encryptWithToken: (NSString*) key
                   inputData: (NSData*) plaintext
                        flag: (int)  flag;

/**
 *  使用token解密数据
 *  @param key token值对应的key
 *  @param encrypted 待解密的数据
 *  @param flag 扩展参数，缺省为0
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSData*) decryptWithToken: (NSString*)  key
                   inputData: (NSData*) encrypted
                        flag: (int)  flag;

/**
 *  使用token对数据进行签名
 *  @param key token值对应的key
 *  @param data 待签名的byte数组
 *  @param flag 扩展参数，缺省为0
 *  @return 返回签名结果，签名失败返回nil
 */
- (NSString*) signWithToken: (NSString*) key
                  inputData: (NSData*) data
                       flag: (int) flag;


/**
 *  获取Otp验证码，目前只适用于支付宝钱包
 *  @param key token值对应的key
 *  @param flag 对应不同的算法和配置，目前只支持0，即支付宝的otp算法
 *  @param strings 传入具体的参数。根据支付宝OTP的要求，需要传入：servertime、codetype和可扩展的extinfo参数。其中，servertime 需要是大于0的长整形，codetype只允许“0”和“1”，extinfo可为空
 *  @param byteArgs 扩展字段，暂未使用
 *  @return 返回长度为18或者16的byte数组，失败返回nil
 */
- (NSData*) getOtp: (NSString*) key
              flag: (int) flag
           strings: (NSArray*) strings
          byteArgs: (NSData*) byteArgs;

/**
 *  获取Otp验证码，目前只适用于支付宝钱包
 *  @param key token值对应的key
 *  @param flag 对应不同的算法和配置，目前只支持0，即支付宝的otp算法
 *  @param strings 传入具体的参数。根据支付宝OTP的要求，需要传入：servertime、codetype和可扩展的extinfo参数。其中，servertime 需要是大于0的长整形，codetype只允许“0”和“1”，extinfo可为空
 *  @param byteArgs 扩展字段，暂未使用
 *  @return 返回长度为18或者16的byte数组，失败返回nil
 */
- (NSData*) getOtp: (NSString*) key
              flag: (int) flag
           strings: (NSArray*) strings
          byteArgs: (NSData*) byteArgs
          authCode: (NSString*) authCode;


@end

#endif /* ISecurityGuardOpenSafeToken_h */
