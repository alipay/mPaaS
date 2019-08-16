#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUInputDialog//程序自动生成
//
//  AUInputDialog.h
//  AntUI
//
//  Created by QiXin on 2016/12/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auinputdialog
//#########################################################


#define UI_AUInputDialog

@interface AUInputDialog : AUDialogBaseView

/// 文本输入框
@property (nonatomic, strong, readonly) UITextField *textField;

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

/*
 在wkwebview中带输入框的弹窗建议通过设置此值来控制键盘自动弹出
 */
@property (nonatomic, assign) BOOL h5ForceShowKeyboard;

/**
 不带按钮标题的初始化方法。
 
 @param title 标题
 @param message 消息内容
 @return AUInputDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message;


/**
 AUInputDialog 实例化方法

 @param title 标题
 @param message 消息内容
 @param placeholder 文本框的占位文字
 @param delegate 代理对象
 @param buttonTitle 按钮标题
 @return AUInputDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                  placeholder:(NSString *)placeholder
                     delegate:(id<AUDialogDelegate>)delegate
                 buttonTitles:(NSString *)buttonTitle, ... NS_REQUIRES_NIL_TERMINATION;

/// 禁用的初始化方法
- (instancetype)init NS_UNAVAILABLE;

/**
 Dialog 展示方法。
 */
- (void)show;

/**
 Dialog 消失方法, 如果监听 will/didDismissWithButtonIndex: 回调 index 值为默认的 0
 */
- (void)dismiss;

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

/**
 添加按钮以及其回调方法。
 
 @param buttonTitle 按钮标题
 @param actionBlock 按钮点击回调
 */
- (void)addButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;

@end

#endif//程序自动生成
