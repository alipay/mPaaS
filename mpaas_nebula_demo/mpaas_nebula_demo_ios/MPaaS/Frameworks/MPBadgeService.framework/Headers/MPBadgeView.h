//
//  MPBadgeView.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/10/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import "MPAbsBadgeView.h"

@interface MPBadgeView : MPAbsBadgeView

// 注意：因为红点的样式是可变的，所以红点的位置通过self.center来指定。

@property(nonatomic, strong) UIImageView *badgeImageView; // 显示红点视图
@property(nonatomic, strong) UIImage *badgeImage; // 自定义红点图片

@end
