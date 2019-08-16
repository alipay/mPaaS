//
//  APTitleView.h
//  APCommonUI
//
//  Created by yangwei on 16/4/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APTitleView : UIView

@property(nonatomic, strong) UILabel *titleBar;           // 主标题。注意：初始化后如需修改title请使用下面接口方法，不要直接设置
@property(nonatomic, strong) UIButton *detailTitleBar;    // 副标题。注意：初始化后如需修改detailTitle请使用下面接口方法，不要直接设置

/**
 *  创建上下两个标题的titleView
 *
 *  @param title          主标题
 *  @param detaileTitle   副标题
 *
 *  @return 初始化后的APTitleView控件
 */
- (UIView *)initWithTitle:(NSString *)title detailTitle:(NSString *)detaileTitle;

/**
 *  修改主标题的文案或font。注意：直接修改titleBar的text或font不会自动布局，业务若需修改title，务必调用此接口方法
 *  说明：在导航栏titleView的layoutSubview方法里设置frame，会死循环调用layoutSubview，导致程序卡死
 *
 *  @param title          主标题文案
 *  @param titleFont      主标题font
 *
 */
- (void)updateTitle:(NSString *)title titleFont:(UIFont *)titleFont;

/**
 *  修改主标题的文案或font。注意：直接修改detailTitleBar的text或font不会自动布局，业务若需修改detailTitle，务必调用此接口方法
 *  说明：在导航栏titleView的layoutSubview方法里设置frame，会死循环调用layoutSubview，导致程序卡死
 *
 *  @param title          主标题文案
 *  @param titleFont      主标题font
 *
 */
- (void)updateDetailTitle:(NSString *)detailTitle detailTitleFont:(UIFont *)detailTitleFont;
@end
