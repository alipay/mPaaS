//
//  TEXFunctorContainer.h
//  Texel
//
//  Created by feihu on 2018/5/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXFunctorContainer : TEXFunctor

// 这个functor chain必须自己处理好，传入第一个functor与最后一个functor
- (instancetype)initWithInputFunctor:(TEXFunctor *)input output:(TEXFunctor *)output;

@end
