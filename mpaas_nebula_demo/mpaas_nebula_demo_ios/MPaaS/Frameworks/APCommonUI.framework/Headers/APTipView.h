//
//  ALTipView.h
//  UITest
//
//  Created by Moncter8 on 13-8-28.
//  Copyright (c) 2013年 Moncter8. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol APTipViewDelegate <NSObject>
@required

/**
 *  点击tipView中button的回调方法
 *
 *  @param sender 点击的button
 */
- (void)tipButtonClick:(UIButton *)sender;
@end

@interface APTipView : UIView
@property (nonatomic, weak) id <APTipViewDelegate> delegate;

/**
 *  创建APTipView对象
 *
 *  @param frame frame的width要够大，否则显示会有问题，建议width取屏幕宽度
 *  @param tip   tipView文案
 *  @param title button的文本
 *
 *  @return 初始化的APTipView对象
 */
- (id)initWithFrame:(CGRect)frame tipMessage:(NSString *)tip title:(NSString *)title;

/**
 *  创建APTipView对象
 *
 *  @param frame frame的width要够大，否则显示会有问题，建议width取屏幕宽度
 *  @param tip   tipView文案
 *
 *  @return 初始化的APTipView对象
 */
- (id)initWithFrame:(CGRect)frame tipMessage:(NSString *)tip;
@end
