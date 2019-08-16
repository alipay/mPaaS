//
//  APImageScaleOption.h
//  APMImageProcessing
//
//  Created by 慎一 on 16/8/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APMImageBaseOptions.h"

@interface APMImageScaleOption : APMImageBaseOptions

/**
 *  缩放到的区域大小 如果传入（100，100） 但原图宽高比是4：3 则返回的尺寸是（100＊scale，75*scale）
 */
@property (nonatomic, assign) CGSize zoom;

/**
 *  cropSize和像素的scale。通过scale可以将cropSize 转换为像素尺寸，默认为MIN([UIScreen mainScreen].scale, 2)
 */
@property (nonatomic, assign) int scale;



/**
 *  根据zoom生成实例
 *
 *  @param zoom 缩放到的区域
 *
 *  @return <#return value description#>
 */
+ (APMImageScaleOption *)scaleOptionsWithZoom:(CGSize)zoom;

/**
 *  当前option是否有效，参数是否有错误
 *
 *  @return <#return value description#>
 */
- (BOOL)isValid;

@end
