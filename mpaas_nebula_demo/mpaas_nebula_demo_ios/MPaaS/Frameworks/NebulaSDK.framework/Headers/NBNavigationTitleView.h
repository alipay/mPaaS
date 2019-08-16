//
//  NBNavigationTitleView.h
//  Nebula
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBNavigationTitleViewProtocol.h"

@protocol NBNavigationTitleViewDelegate;

@interface NBNavigationTitleView : UIView <NBNavigationTitleViewProtocol>

@property(nonatomic, weak) id<NBNavigationTitleViewDelegate>    delegate;

- (void)startLoading; // 开始转菊花，frame.size.width = 30

- (void)stopLoading; // 结束

- (void)doAnimationRightIcon:(BOOL)isDown; // 右边icon向上、下动画

@end
