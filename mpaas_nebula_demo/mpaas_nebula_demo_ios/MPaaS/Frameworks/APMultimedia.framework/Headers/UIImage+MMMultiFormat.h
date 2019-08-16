//
//  UIImage+MultiFormat.h
//  SDWebImage
//
//  Created by Olivier Poitrey on 07/06/13.
//  Copyright (c) 2013 Dailymotion. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (MMMultiFormat)

/**
 根据data生成UIImage对象，支持PNG/JPG/Webp/ahp/Gif，失败的情况会上报不可用埋点

 @param data 二进制data数据
 @return UIImage
 */
+ (UIImage *)apmm_imageWithDataExt:(NSData *)data;

/**
 根据data生成UIImage对象，支持PNG/JPG/Webp/ahp/Gif，失败的情况根据reportError决定是否上报不可用埋点

 @param data data 二进制data数据
 @param reportError 失败的情况下，是否上报不可用埋点。
 @return UIImage
 */
+ (UIImage *)apmm_imageWithDataExt:(NSData *)data reportError:(BOOL)reportError;

//获取图片的size，不decode图片,失败返回(-1,-1)
+ (CGSize)apmm_imageSizeWithDataExt:(NSData *)data;
@end
