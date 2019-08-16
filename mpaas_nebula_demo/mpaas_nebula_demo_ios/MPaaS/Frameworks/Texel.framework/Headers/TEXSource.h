//
//  TEXSource.h
//  Texel
//
//  Created by Cloud on 2017/4/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TEXOutput.h"
#import "TEXFramebuffer.h"

@interface TEXSource : TEXOutput

@property (nonatomic, assign) CGSize outputSizeInPixels; // 单位为像素，如果未设置则与输入一样大
@property (nonatomic, assign) CGRect roi; // 感兴趣区域，归一化的OpenGL坐标系，左下角原点，默认是全屏[0, 0, 1.0, 1.0]

- (void)start;
- (void)stop;

@end
