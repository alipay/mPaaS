//
//  APLimitView.h
//  CommonUI
//
//  Created by yangwei on 15/11/3.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APLimitView : UIView

/**
 *  模态view
 */
@property (nonatomic, strong) UIView *backgoundView;

/**
 *  主图片
 */
@property(nonatomic, strong) UIImageView *imageView;

/**
 *  主文案
 */
@property(nonatomic, strong) UILabel *titleLabel;

/**
 *  副文案
 */
@property(nonatomic, strong) UILabel *detailTitleLabel;

/**
 *  底部事件按钮。无关闭按钮时，默认文案为“确定”；有关闭按钮时，默认文案为“再试一次”。
 */
@property(nonatomic, strong) UIButton *actionButton;

/**
 *  判断当前界面是否有弹框显示，若返回YES，表明界面上已显示限流弹框,初始化方法控件不生效
 *
 *  @return 展示中返回YES，否则返回NO
 */
+ (BOOL)isShowing;

/**
 *  创建限流弹框控件，此方法创建一个单例对象，模态显示初始化后的限流弹框，若界面上已显示限流弹框，show方法不生效
 *  注意：业务请调用此方法进行初始化，保证界面上只显示一个弹框。
 *
 *  显示限流控件，无关闭按钮，用户只能点击底部按钮使弹框消失，底部按钮默认文案为“确定”
 *
 *  @param superview   父view
 *  @param title       主文案，只能显示一行
 *  @param detailTitle 副文案，最多显示两行
 *
 *  @return 初始化后的APLimitView控件
 */
+ (APLimitView *)showInSuperview:(UIView *)superview title:(NSString *)title detailTitle:(NSString *)detailTitle;

/**
 *  创建限流弹框控件，此方法创建一个单例对象，模态显示初始化后的限流弹框，若界面上已显示限流弹框，show方法不生效
 *  注意：业务请调用此方法进行初始化，保证界面上只显示一个弹框
 *
 *  显示限流弹框控件，用户可点击右上角关闭按钮使弹框消失，业务自行配置倒计时时间，倒计时结束后，显示底部按钮默认文案“再试一次”
 *
 *  @param superview   父view
 *  @param title       主文案，只能显示一行
 *  @param detailTitle 副文案，最多显示两行
 *  @param interval    倒计时等待时间
 *
 *  @return 初始化后的APLimitView控件
 */
+ (APLimitView *)showInSuperview:(UIView *)superview title:(NSString *)title detailTitle:(NSString *)detailTitle interval:(NSTimeInterval)interval;

/*
 *  创建限流弹框控件，此方法创建一个单例对象，模态显示初始化后的限流弹框，若界面上已显示限流弹框，show方法不生效
 *  注意：业务请调用此方法进行初始化，保证界面上只显示一个弹框
 *
 *  显示限流弹框控件，用户可点击右上角关闭按钮使弹框消失，业务自行配置倒计时时间，倒计时结束后，显示底部按钮默认文案“再试一次”
 *  @param title       主文案，只能显示一行
 *  @param detailTitle 副文案，最多显示两行
 *
 *  @return 初始化后的APLimitView控件
 */

+ (APLimitView *)showWithTitle:(NSString *)title detailTitle:(NSString *)detailTitle;

/**
 *  消除当前显示的弹框控件
 */
+ (void)dismiss;

#pragma mark 回调方法
/**
 *  设置点击底部按钮时执行的block
 *  @param block  执行的block
 */
- (void)setActionButtonDidClickBlock:(void (^)(void))block;

/**
 *  设置点击右上角关闭按钮时执行的block
 *
 *  @param block 执行的block
 */
- (void)setCloseButtonDidDissmissBlock:(void (^)(void))block;

/**
 *  链接按钮默认不显示，如需显示请调用此方法，并设置title
 *
 *  @return 获取链接按钮
 */
- (UIButton *)getLinkButton;

@end
