//
//  TEXCleanBackgroundFunctor.h
//  Texel
//
//  Created by Cloud on 2017/8/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXCleanBackgroundFunctor : TEXFunctor

/** The threshold sensitivity controls how similar pixels need to be colored to be replaced
 
 The default value is 0.35
 */
@property(nonatomic, assign) CGFloat threshold;

/** The degree of smoothing controls how gradually similar colors are replaced in the image
 
 The default value is 0.09
 */
@property(nonatomic, assign) CGFloat smoothing;

/// 要清除的背景色，默认为绿色，即0x00FF00
@property(nonatomic, assign) int backgroundColor;

/// 如果是纯色前景，可以设置该颜色，以防出现过多半透明导致的颜色不对
@property(nonatomic, assign) int foregroundColor;

@end
