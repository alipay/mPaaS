//
//  TEXThreeInputFunctor.h
//  Texel
//
//  Created by feihu on 2018/3/1.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "TEXTwoInputFunctor.h"

@interface TEXThreeInputFunctor : TEXTwoInputFunctor

- (instancetype)initWithVertexShaderString:(NSString *)vertexShaderString fragmentShaderString:(NSString *)fragmentShaderString secondImage:(UIImage *)secondImage thirdImage:(UIImage *)thirdImage;

@end
