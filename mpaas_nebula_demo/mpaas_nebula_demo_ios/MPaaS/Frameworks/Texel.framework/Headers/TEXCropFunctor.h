//
//  TEXCropFunctor.h
//  Texel
//
//  Created by Monster on 2017/11/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXCropFunctor : TEXFunctor
@property(nonatomic, assign)CGRect cutRect;

- (instancetype)initWithRect:(CGRect)cutRect;
@end
