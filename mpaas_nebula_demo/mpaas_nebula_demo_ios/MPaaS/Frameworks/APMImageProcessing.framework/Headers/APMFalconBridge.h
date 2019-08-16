//
//  APMFalconBridge.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  桥接FalconImage的接口， 提供同名的方法来替换FalconImage类库的方法
 */
@interface APMFalconBridge : NSObject

/**
 *  根据QualityLevel对image进行压缩，如果比较大 则取缩小刀到适当的尺寸 然后再压缩
 *
 *  @param Img          待压缩的image
 *  @param QualityLevel 压缩质量
 *
 *  @return 被压缩的data
 */
+ (NSData *)AutoImgComPress2:(UIImage*)Img Quality:(NSInteger)QualityLevel;

/**
 * 从Img中根据FrameW和FrameH裁切图片 如果FrameW或者FrameH为－1， 则取原图 如果为0 则取大图  否则则取裁切图
 *
 *  @param Img        待裁切的图片
 *  @param FrameW     裁切尺寸的宽度
 *  @param FrameH      裁切尺寸的高度
 *  @param ResizeType 没有意义这个参数 只是为了保持和Falcon中同名的方法
 *
 *  @return 裁切出的图片
 */
+ (UIImage *)ImgResizeWHEx:(UIImage *)Img FrameW:(int)FrameW FrameH:(int)FrameH ResizeType:(int)ResizeType;

/**
 *  判断当前设备能否的内存是否足够解析指定width和height的图片
 *
 *  @param width  图片的宽度
 *  @param height 图片的高度
 *
 *  @return YES表示内存足够结鞋 NO表示内存不够
 */
+ (BOOL)isEnoughMemToDecodeImg:(NSInteger)width height:(NSInteger)height;


@end
