//
//  TEXViewSource.h
//  Texel
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"

@interface TEXViewSource : TEXSource

@property(nonatomic, assign)BOOL needUpdate;//是否需要每帧都更新

- (instancetype)initWithView:(UIView *)view;

@end
