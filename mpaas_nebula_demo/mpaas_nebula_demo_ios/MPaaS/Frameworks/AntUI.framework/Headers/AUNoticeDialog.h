#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUNoticeDialog//程序自动生成
//
//  AUNoticeDialog.h
//  AntUI
//
//  Created by QiXin on 2016/9/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUDialogBaseView.h"
#import "AUEdge.h"

#define UI_AUNoticeDialog

/**
 普通 Dialog ，同系统样式不带 blur 背景
 文档：https://yuque.antfin-inc.com/antui/auidoc/ios_aunoticedialog
 */
@interface AUNoticeDialog : AUDialogBaseView

/**
 该实例是否在展示，适用于有指针指向该实例的情况。
 如果有其他 dialog 盖住此 dialog, 属性值也为 YES 不会发生变化。
 */
@property (nonatomic, assign, readonly) BOOL isDisplay;

/**
 * 标题
 */
@property (nonatomic, strong) NSString *title;

/**
 * 文本消息
 */
@property (nonatomic, strong) NSString *message;

/**
 不带按钮标题的初始化方法。
 注意 弹框视觉要求，当title和message中一个不存在时，必须设置为title，但不推荐只传title或message的情况，建议所有弹窗都带title和message
 
 @param title 标题
 @param message 消息内容(支持NSString、NSAttributedString)
 @return AUNoticeDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(id)message;

/**
 带按钮标题的初始化方法。
 注意 弹框视觉要求，当title和message中一个不存在时，必须设置为title，但不推荐只传title或message的情况，建议所有弹窗都带title和message
 
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象
 @param buttonTitle 按钮标题列表
 @return AUNoticeDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
                 buttonTitles:(NSString *)buttonTitle, ... NS_REQUIRES_NIL_TERMINATION;

/// 禁用的初始化方法
- (instancetype)init NS_UNAVAILABLE;

/**
 Dialog 展示方法。
 */
- (void)show;

/**
 Dialog 消失方法, 如果监听 will/didDismissWithButtonIndex: 未设置cancelbutton时，回调 index 值为默认的 0
 */
- (void)dismiss;

/**
 Dialog 消失方法,类似APAlertView的dismissWithClickedButtonIndex方法
 */
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

/**
 隐藏 Dialog Window 上全部 dialog 视图
 */
+ (void)dismissAll;

/**
 描述文本置为灰色, Default is YES
 */
- (void)setGrayMessage:(BOOL)grayMessage;

/**
 设置文本对齐
 
 @param alignment 对齐参数
 */
- (void)setMessageAlignment:(NSTextAlignment)alignment;



@end

#endif//程序自动生成
