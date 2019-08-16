//
//  NBNavigationTitleViewProtocol.h
//  Nebula
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NBNavigationTitleViewDelegate;

@protocol NBNavigationTitleViewProtocol <NSObject>

@required
// mainTitle
- (void)setMainTitle:(NSString *)mainTitle subtitle:(NSString *)subtitle;

// titleLoading
- (void)showTitleLoading;

- (void)hideTitleLoading;

@optional
// mainTitleLabel
- (UILabel *)mainTitleLabel;

// subtitleLabel
- (UILabel *)subtitleLabel;

// padding
- (void)setPaddingLeft:(CGFloat)paddingLeft;

- (void)setPaddingRight:(CGFloat)paddingRight;

// right icon
- (void)setRightIconImage:(UIImage *)image;

- (void)setRightIconWidth:(CGFloat)width;

- (void)setCanShowRightIconWhenSubTitleIsWhitespace:(BOOL)canShow; // defult is NO

// delegate
- (void)setDelegate:(id<NBNavigationTitleViewDelegate>)delegate;

- (id<NBNavigationTitleViewDelegate>)delegate;

- (void)doAnimationRightIcon:(BOOL)isDown;

// rightIconImageView
- (UIImageView *)rightIconImageView;
@end


@protocol NBNavigationTitleViewDelegate <NSObject>

@optional
// 点击了主标题
- (void)navigationTitleView:(id<NBNavigationTitleViewProtocol>)navigationTitleView didClickedMainTitleView:(UIView *)mainTitleView;
// 点击了副标题
- (void)navigationTitleView:(id<NBNavigationTitleViewProtocol>)navigationTitleView didClickedSubTitleView:(UIView *)subtitleView;
// 点击了右边图标
- (void)navigationTitleView:(id<NBNavigationTitleViewProtocol>)navigationTitleView didClickedRightIconView:(UIView *)rightIconView;

@end
