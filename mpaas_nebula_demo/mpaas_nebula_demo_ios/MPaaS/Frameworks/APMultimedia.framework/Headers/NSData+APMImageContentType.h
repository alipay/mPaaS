//
// Created by Fabrice Aneche on 06/01/14.
// Copyright (c) 2014 Dailymotion. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, APMImageContentType) {
    //不要调整位置 埋点中已经使用 而且业务方直接使用的是index整数值
    APMImageContentTypeJPEG,
    APMImageContentTypePNG,
    APMImageContentTypeGIF,
    APMImageContentTypeTIFF,
    APMImageContentTypeWEBP,
    APMImageContentTypeHEVC,
    APMImageContentTypeUNKNOWN,
};

@interface NSData (APMImageContentType)

/**
 *  Compute the content type for an image data
 *
 *  @param data the input data
 *
 *  @return the content type as string (i.e. image/jpeg, image/gif)
 */
+ (APMImageContentType)apm_contentTypeForImageData:(NSData *)data;

@end
