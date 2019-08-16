//
//  APMImageCompress.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APMImageCompressOptions.h"
#import "APMImageProcessResponse.h"

@interface APMImageCompress : NSObject

/**
 *  根据compressOptions 压缩原图
 *
 *  @param image           待压缩的图片
 *  @param compressOptions 压缩参数配置
 *
 *  @return APMImageProcessResponse 对象
 */
+ (APMImageProcessResponse *)compressImage:(UIImage *)image withCompressOptions:(APMImageCompressOptions *)compressOptions;

/**
 *  根据compressOptions 压缩原图
 *
 *  @param imageData           待压缩的图片data表示
 *  @param compressOptions 压缩参数配置
 *
 *  @return APMImageProcessResponse 对象
 */
+ (APMImageProcessResponse *)compressImageData:(NSData *)imageData withCompressOptions:(APMImageCompressOptions *)compressOptions;

@end
