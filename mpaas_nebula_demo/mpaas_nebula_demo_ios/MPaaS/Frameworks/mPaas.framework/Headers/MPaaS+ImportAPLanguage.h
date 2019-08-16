//
//  MPaaS+ImportAPLanguage.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APLanguage+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APLanguageSettingClass> getAPLanguageSetting();
    
    // 在这里将__TEXT重定向到getMultilanguageRes这个方法，可以动态获取语言资源。
    // 如果未加入APLanguage模块，也会默认返回defaultValue
    NSString* getMultilanguageRes(NSString* bundle, NSString* key, NSString* defaultValue);
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APLanguageSetting       getAPLanguageSetting()

#undef	__TEXT
#define __TEXT(bundle,key,comment) \
    getMultilanguageRes(bundle, key, comment)

#define APLanguageSettingDidChangeNotification  @"APLanguageSettingDidChangeNotification"