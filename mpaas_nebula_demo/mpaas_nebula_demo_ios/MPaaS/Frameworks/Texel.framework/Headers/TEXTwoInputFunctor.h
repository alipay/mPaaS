//
//  TEXTwoInputFunctor.h
//  Texel
//
//  Created by feihu on 2018/2/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXTwoInputFunctor : TEXFunctor

- (instancetype)initWithVertexShaderString:(NSString *)vertexShaderString fragmentShaderString:(NSString *)fragmentShaderString secondImage:(UIImage *)image;

@end
