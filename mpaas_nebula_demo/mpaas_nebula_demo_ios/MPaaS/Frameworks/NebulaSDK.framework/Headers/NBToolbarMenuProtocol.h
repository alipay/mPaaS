//
//  NBToolbarMenuProtocol.h
//  Nebula
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NBToolbarMenuDelegate;

@protocol NBToolbarMenuProtocol <NSObject>

@required
- (void)show;

- (void)dismiss;

- (void)reload;

- (UILabel *)tipsLabel;

- (BOOL)isShowing;

- (void)setToolbarMenu:(NSDictionary *)data asDefault:(BOOL)asDefault;

@optional
- (void)setViewInsets:(UIEdgeInsets)insets;

- (void)setBackgroundColor:(UIColor *)color;

- (void)setContentViewBgColor:(UIColor *)color;

- (void)setMenuItemImageViewInsets:(UIEdgeInsets)insets;

// cancel btn
- (UIButton *)cancelButton;

- (void)setDelegate:(id<NBToolbarMenuDelegate>)delegate; // 若外部设置了，则kNBEvent_Scene_ToolbarMenu_Select事件无法发出
- (id<NBToolbarMenuDelegate>)delegate;

@end


@protocol NBToolbarMenuDelegate <NSObject>

@optional
- (void)toolbarMenu:(id<NBToolbarMenuProtocol>)toolbarMenu didSelectedItem:(id)item; // 必须实现.tag方法

@end