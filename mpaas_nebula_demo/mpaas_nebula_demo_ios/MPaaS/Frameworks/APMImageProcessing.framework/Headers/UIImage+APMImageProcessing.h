//
//  UIImage+APMImageProcessing.h
//  APMImageProcessing
//
//  Created by 慎一 on 2017/3/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APMImageCompress.h"

@interface UIImage (APMImageProcessing)

/**
 在当前图片的rect位置插入一张新的图片image,如果image=nil,则会返回原图。

 @param image 被插入的图片
 @param rect  图片插入的位置
 @return 插入图片后形成的新图片
 */
- (UIImage *)apm_compositeImage:(UIImage *)image inRect:(CGRect)rect;

/**
 将UIImage压缩成Data数据

 @param CompressLevel 压缩级别
 @param shouldKeepAlpha 是否保留Alpha通道，如果为YES且UIImage中包含Alpha通道，则不会压缩图片。
 @return 压缩后的数据
 */
- (NSData *)apm_dataWithCompressLevel:(APMImageCompressQualityLevelEnum)CompressLevel shouldKeepAlpha:(BOOL)shouldKeepAlpha;

/**
 图片是否包含alpha通道

 @return YES 则包含alpha通道，比如PNG图片。
 */
- (BOOL)apm_hasAlphaChannel;

@end
