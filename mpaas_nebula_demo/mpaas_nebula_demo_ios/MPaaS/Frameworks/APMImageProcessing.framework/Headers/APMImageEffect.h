//
//  APMImageEffect.h
//  APMImageProcessing
//
//  Created by Monster on 16/9/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "base.h"

@interface APMImageEffect : NSObject
/**
 *  计算图片复杂度
 *
 *  @param image UIImage
 *
 *  @return int
 */
+ (int)CalculateImageComplexity:(UIImage*)image;

/**
 *  计算图片色值
 *
 *  @param image UIImage
 *
 *  @return sCalcColor
 */
+ (sCalcColor)CalculateImageColor:(UIImage*)image;

/**
 *  油画效果处理
 *
 *  @param image UIImage
 *
 *  @return 返回油画效果处理后的UIImage
 */
+ (UIImage*)ImageFiltersOilsPaint:(UIImage*)image;
@end
