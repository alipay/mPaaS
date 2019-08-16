//
//  TEXTransparentVideoFunctor.h
//  Texel
//
//  Created by Cloud on 2017/9/8.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXTransparentVideoFunctor : TEXFunctor

/**
 *  初始化
 *  因为系统会用16的倍数去填充视频帧的每一行，所以填充之后帧宽度并非与视频本身的宽度一致，
 *  计算alpha的位置时如果以一半宽度来取，则会出现错位的情况，所以这里需要原始的宽度
 *
 *  @param width 视频的真实宽度
 */
- (instancetype)initWithWidth:(int)width;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
