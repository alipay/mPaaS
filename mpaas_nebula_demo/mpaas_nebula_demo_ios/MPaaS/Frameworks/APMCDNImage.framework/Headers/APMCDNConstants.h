//
//  APMCDNConstants.h
//  APMCDNImage
//
//  Created by Kris Tian on 2019/3/9.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef APMCDNConstants_h
#define APMCDNConstants_h

typedef NS_ENUM(NSUInteger, APMImageCutType) {
    APMImageCutTypeScale,//等比缩放
    APMImageCutTypeCrop, //缩放后裁切
};

typedef NS_ENUM(NSUInteger, APMImageFormat) {
    APMImageFormatDefault, //默认格式
    APMImageFormatWebP, //webp
    APMImageFormatHEIC
};


#endif /* APMCDNConstants_h */
