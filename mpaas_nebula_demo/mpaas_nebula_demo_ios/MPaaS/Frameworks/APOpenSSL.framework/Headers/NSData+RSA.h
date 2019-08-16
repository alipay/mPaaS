//
//  NSData+RSA.h
//  APOpenSSL
//
//  Created by tashigaofei on 14-8-12.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//



@interface NSData (RSA)

/**
 * 使用RSA算法，用公钥对NSData数据加密，返回加密数据
 *
 * @param key 公钥key
 *
 * @return (NSData *) 加密后的数据
 */
-(NSData *) dataByRSAEncryptedWithPublicKey:(NSString *) key;


/**
 * 使用RSA算法，用私钥对NSData数据解密，返回解密数据
 *
 * @param key 私钥key
 *
 * @return (NSData *) 解密后的数据
 */
-(NSData *) dataByRSADecryptedWithPrivateKey:(NSString *) key;

@end
