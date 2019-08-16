//
//  APImageCropOptions.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APMImageBaseOptions.h"

//    APMImageCropAlignModeCenter      (0, "最大居中模式),
//    APMImageCropAlignModeTop        (1, "上对齐"),
//    APMImageCropAlignModeDown       (2, "下对齐"),
//    APMImageCropAlignModeLeft       (3, "左对齐"),
//    APMImageCropAlignModeRight      (4, "右对齐"),
//    APMImageCropAlignModeManual          (5, "手动模式，抠图");

typedef NS_ENUM (NSInteger, APMImageCropAlignMode) {
    APMImageCropAlignModeCenter,  //缩放再裁剪
    APMImageCropAlignModeTop,     //缩放再裁剪
    APMImageCropAlignModeDown,    //缩放再裁剪
    APMImageCropAlignModeLeft,    //缩放再裁剪
    APMImageCropAlignModeRight,   //缩放再裁剪
    APMImageCropAlignModeManual   //不缩放，抠图
};


@interface APMImageCropOptions : APMImageBaseOptions

/**
 *  指定裁切大小 点作为计量单位 根据scale参数 可以换算成对应的像素单位
 */
@property (nonatomic, assign) CGSize cropSize;

/**
 *  cropSize和像素的scale。通过scale可以将cropSize 转换为像素尺寸，默认为MIN([UIScreen mainScreen].scale, 2)
 */
@property (nonatomic, assign) int scale;

/**
 *  指定Image中从什么点才是有效的 默认(0,0) 如果指定startPoint，从这个开始到右下角的图片区域才是有效的 会先裁切出这个区域 然后再做其他的裁切处理
 */
@property (nonatomic, assign) CGPoint startPoint;

/**
 *  裁切的对其模式 可以通过这个值来指定区域进行裁切
 */
@property (nonatomic, assign) APMImageCropAlignMode cropAlign;

/**
 *  当前option是否有效，参数是否有错误
 *
 *  @return YES 则是有效的 NO则无效
 */
- (BOOL)isValid;

/**
 *  根据裁切尺寸生成裁切参数实例 默认是从中间裁切
 *
 *  @param CropSize 裁切尺寸
 *
 *  @return APMImageCropOptions 实例
 */
+ (APMImageCropOptions *)cropOptionsWithCropSize:(CGSize)CropSize;

/**
 *  根据裁切尺寸 对其模式生成裁切参数实例 默认是从中间裁切
 *
 *  @param cropSize  裁切尺寸
 *  @param cropAlign 对其模式
 *
 *  @return APMImageCropOptions实例
 */
+ (APMImageCropOptions *)cropOptionsWithCropSize:(CGSize)cropSize
                                   cropAlignMode:(APMImageCropAlignMode)cropAlign;
@end
