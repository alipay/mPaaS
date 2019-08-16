//
//  APImageBaseOptions.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
   图片处理模式 暂时只支持缩放 裁切和压缩
 */
typedef enum : NSUInteger {
    APMImageProcessMode_Compress,                     //压缩
    APMImageProcessMode_Scale,                       //缩放
    APMImageProcessMode_Crop,                         //裁剪
} APMImageProcessMode;

/**
 *  图片处理参数类的基类 指定一些公用信息
 */
@interface APMImageBaseOptions : NSObject

/**
 *  指定图片的处理模式
 */
@property (nonatomic,assign) APMImageProcessMode processMode;

/**
 *  是否在response中 要包含NSData信息 如果指定需要 则NSData信息一定返回 Image则可能返回 也可能不返回，默认为NO
 */
@property (nonatomic, assign) BOOL reponseNeedContainData;

/**
 *  是否在response中 要包含Image信息 如果指定需要 则Image信息一定返回 data则可能返回 也可能不返回， 默认为YES
 */
@property (nonatomic, assign) BOOL reponseNeedContainImage;

@end
