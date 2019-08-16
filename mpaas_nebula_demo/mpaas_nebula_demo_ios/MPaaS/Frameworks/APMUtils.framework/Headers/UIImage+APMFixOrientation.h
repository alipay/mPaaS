//
//  UIImage+APMFixOrientation.h
//  APMultimedia
//
//  Created by Cloud on 15/11/16.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (APMFixOrientation)

/**
 *  去除图像的方向信息，将图像根据本身的方向信息进行旋转处理
 *
 *  @return  丢掉方向之后的图像
 */
- (UIImage *)apm_fixOrientation;

/**
 *  对图像进行镜像处理
 *
 *  @return  镜像之后的图像
 */
- (UIImage *)APM_mirror;

/**
 *  获取去除图片方向信息所需要的矩阵
 *
 *  @return  去除图片方向信息所需要的矩阵
 */
- (CGAffineTransform)apm_transformToFixOrientation;

@end
