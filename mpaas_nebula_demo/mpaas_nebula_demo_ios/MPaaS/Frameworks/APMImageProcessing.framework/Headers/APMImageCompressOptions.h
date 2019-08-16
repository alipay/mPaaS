//
//  APMImageCompressOptions.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APMImageBaseOptions.h"

//图片压缩等级
typedef enum : NSUInteger {
    APMImageCompressQualityLow,    //低质量压缩 压缩比最大
    APMImageCompressQualityHigh,   //高质量压缩 压缩比小
    APMImageCompressQualityHighest, //最高质量压缩 压缩比最小，如果对图片清晰度没有特别的要求，不要设置这个
} APMImageCompressQualityLevelEnum;


@interface APMImageCompressOptions : APMImageBaseOptions

/**
 *  压缩等级
 */
@property (nonatomic, assign) APMImageCompressQualityLevelEnum compressLevel;

/**
 *  实例方法 根据compressLevel 快速生成实例对象
 *
 *  @param compressLevel 压缩等级APMImageCompressQualityLevelEnum
 *
 *  @return 指定压缩等级的实例
 */
+ (APMImageCompressOptions *)compressOptionsWithCompressQuality:(APMImageCompressQualityLevelEnum)compressLevel;


@end
