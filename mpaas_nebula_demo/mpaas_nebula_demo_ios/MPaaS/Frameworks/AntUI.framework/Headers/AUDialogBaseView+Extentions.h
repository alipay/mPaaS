#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogBaseView+Extentions.h
//  AntUI
//
//  Created by maizhelun on 2017/3/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUDialogBaseView.h"

@interface AUDialogBaseView (Extentions)


- (NSInteger)addButtonWithTitle:(NSString *_Nonnull)title callback:(void (^_Nullable)(int index, NSString *_Nonnull title))callback;

/**
 @brief 添加取消Button和回调
 @param title 按钮title
 @param callback 回调的callback
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *_Nonnull)title callback:(void (^_Nullable)(int index, NSString *_Nonnull title))callback;

/**
 @brief 添加Button
 @param title 按钮title
 */
- (NSInteger)addButtonWithTitle:(NSString *_Nonnull)title;

/**
 @brief 添加取消button
 @param title 按钮title
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *_Nonnull)title;


/**
 获取按钮名称（类似APAlertView的buttonTitleAtIndex:方法）

 @param buttonIndex 按钮位置
 @return 按钮名称
 */
- (nullable NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;


/**
 有多少个按钮（类似APAlertView的numberOfButtons）
 */
@property(nonatomic,readonly) NSInteger numberOfButtons;


/**
 取消按钮的index（类似APAlertView的cancelButtonIndex）
 */
@property(nonatomic) NSInteger cancelButtonIndex;


/**
 dialog 重设新的dialog的type，业务不要直接调用
 */

- (void)resetDialogBuilderType:(AUDialogBuilderType)type;

@end

#endif//程序自动生成
