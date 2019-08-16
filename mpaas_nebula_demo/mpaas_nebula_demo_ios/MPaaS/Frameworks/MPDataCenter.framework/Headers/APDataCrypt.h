//
//  APDataCrypt.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-19.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct APDataCrypt APDataCrypt;

/**
 *  加密方法原型
 *  默认的加密方法input与返回都是NSData，但是用户定义的可以不是。比如input为一个string，输出为base64后的值。
 *  在DAO里，这个方法用来加密OC类的属性。info1和info2分别用来返回加密的OC类名与属性名。
 */
typedef id (*APDataCryptFunc)(APDataCrypt* crypt, id input, id info1, id info2);

struct APDataCrypt
{
    BOOL isDefault; // 内部使用，只有APDefaultEncrypt()和APDefaultDecrypt()返回的方法，这个值才是true。
    char key[32];
    unsigned int keyLength;
    APDataCryptFunc pfCrypt;
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    /**
     *  获取默认加密key的长度，目前是32字节。
     */
    unsigned int APDefaultCryptKeyLength();

    /**
     *  初始化一个APDataCrypt对象，请使用这个方法，不要自己malloc。
     */
    APDataCrypt* APCryptCreate();
        
    /**
     *  复制一个加密解密器，返回的数据需要用户自行free
     */
    APDataCrypt* APCryptCopy(const APDataCrypt* source);

    /**
     *  默认的加密方法，使用样例：
     *      [[[APDataCenter defaultDataCenter] commonPreferences] setObject:object forKey:@"aKey" business:@"aBiz" extension:APDefaultEncrypt()];
     *  返回的加密方法的pfCrypt函数，接收的input与返回值都为NSData*
     *  @return 返回方法结构体指针
     */
    APDataCrypt* APDefaultEncrypt();

    /**
     *  默认的解密方法，使用样例：
     *      id object = [[[APDataCenter defaultDataCenter] commonPreferences] objectForKey:@"aKey" business:@"aBiz" extension:APDefaultDecrypt()];
     *      如果是使用默认加密算法加密的数据，取数据时extension:APDefaultDecrypt()这个参数可以省略。
     *  返回的加密方法的pfCrypt函数，接收的input与返回值都为NSData*
     *  @return 返回方法结构体指针
     */
    APDataCrypt* APDefaultDecrypt();
        
    /**
     *  安装自定义的默认加密方法。使用这个方法可以将默认的加密方法重定向到外部的任意函数。但必须在使用统一存储前进行设置。
     */
    void APInstallDefaultEncrypt(APDataCryptFunc func);
        
    /**
     *  安装自定义的默认解密方法。使用这个方法可以将默认的加密方法重定向到外部的任意函数。但必须在使用统一存储前进行设置。
     */
    void APInstallDefaultDecrypt(APDataCryptFunc func);

#ifdef __cplusplus
}
#endif // __cplusplus