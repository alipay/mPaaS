//
//  APRequestExtraParamKey.h
//  APMultimedia
//
//  Created by 慎一 on 2017/7/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//加解密密钥对应的key. 上传下载时，如果设置在extraParams中设置此key 会对上传/下载的二进制数据根据对应的key值 做加/解密处理，此值必须为256bit，否则会报错
extern NSString* const kAPExtraParamsEncryptKey;

//bizSessionID对应的key. 如果设置了kExtraParamsEncryptKey， 上传下载必须设置此值，否则会出错
extern NSString* const kAPExtraParamsSessionIDKey;

//RefID对应的key. 如果设置了kExtraParamsEncryptKey，下载必须设置此值，否则会出错
extern NSString* const kAPExtraParamsRefIDKey;

//FileKeyToken对应的key. 如果设置了kExtraParamsEncryptKey，上传必须设置此值，否则会出错
extern NSString* const kAPExtraParamsFileTokenKey;

