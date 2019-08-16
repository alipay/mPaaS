//
//  TEXFunctorDecorator.h
//  Texel
//
//  Created by feihu on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

// 主要用于decorator来构建链路，wrappedFunctor随时替换
@interface TEXFunctorDecorator : TEXFunctor

@property (nonatomic, strong) TEXFunctor *wrappedFunctor;

@end
