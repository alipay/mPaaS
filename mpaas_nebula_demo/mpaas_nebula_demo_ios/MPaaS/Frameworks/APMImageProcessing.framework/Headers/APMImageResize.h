//
//  APMImageProcess.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMImageProcessResponse.h"
#import "APMImageScaleOption.h"
#import "APMImageCropOptions.h"
#import "APMImageBaseOptions.h"

@interface APMImageResize : NSObject

/**
 *  根据cropOptions配置 从image中裁切一张小图; 如果裁切的尺寸大于原图 则会直接返回原图
 *
 *  @param image       待裁切的图像
 *  @param cropOptions 裁切参数配置
 *
 *  @return APMImageProcessResponse对象
 */
+ (APMImageProcessResponse *)cropImage:(UIImage *)image withCropOptions:(APMImageCropOptions *)cropOptions;

/**
 *  根据cropOptions配置 从imageData中裁切一张小图；如果裁切的尺寸大于原图 则会直接返回原图
 *
 *  @param imageData   UIImage的data
 *  @param cropOptions 裁切参数配置
 *
 *  @return APMImageProcessResponse对象
 */
+ (APMImageProcessResponse *)cropImageData:(NSData *)imageData withCropOptions:(APMImageCropOptions *)cropOptions;

/**
 *  根据scaleOptions 生成一张等比的小图； 如果缩放后的尺寸大于原图 则会直接返回原图
 *
 *  @param image         待缩放的原图
 *  @param scaleOptions 缩放参数配置
 *
 *  @return APMImageProcessResponse对象
 */
+ (APMImageProcessResponse *)scaleImage:(UIImage *)image withScaleOptions:(APMImageScaleOption *)scaleOptions;

/**
 *  根据scaleOptions 生成一张等比的小图 如果缩放后的尺寸大于原图 则会直接返回原图
 *
 *  @param image         待缩放的原图data表示
 *  @param scaleOptions 缩放参数配置
 *
 *  @return APMImageProcessResponse对象
 */
+ (APMImageProcessResponse *)scaleImageData:(NSData *)imageData withScaleOptions:(APMImageScaleOption *)scaleOptions;

//默认的scale
+ (CGFloat)defaultScale;

+(BOOL)hasAlphaChannelWithImage:(UIImage *)image;

@end
