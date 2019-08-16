//
//  TEXImageFilter.h
//  Texel
//
//  Created by feihu on 2018/3/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TEXFunctor.h"

@interface TEXImageFilter : NSObject

@property (nonatomic, strong) TEXFunctor *filter;

// 注意：图像需要不能够带方向，为性能考虑，交由外部处理，如果有方向，调用[image apm_fixeOrientation]，将去除方
// 向之后的图像拿来处理
- (UIImage *)filterImage:(UIImage *)image;

@end
