#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUOperationResultDialog//程序自动生成
//
//  AUOperationResultDialog.h
//  AntUI
//
//  Created by 莜阳 on 17/3/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUDialogBaseView.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auoperationresultdialog
//#########################################################


#define UI_AUOperationResultDialog

/**
 该弹窗仅限于 社交和收银台 分享结果成功
 */

@interface AUOperationResultDialog : AUDialogBaseView

/**
 该实例是否在展示，适用于有指针指向该实例的情况。
 如果有其他 dialog 盖住此 dialog, 属性值也为 YES 不会发生变化。
 */
@property (nonatomic, assign, readonly) BOOL isDisplay;

/**
 * 描述文案
 */
@property (nonatomic, strong) NSString *message;

/**
 不带按钮标题的初始化方法。
 
 @param image 图片
 @param describe 消息描述
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate;

/**
 带按钮标题的初始化方法。
 
 @param image 图片
 @param describe 消息描述
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param buttonTitle 按钮标题参数列表
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
                 buttonTitles:(NSString *)buttonTitle, ... NS_REQUIRES_NIL_TERMINATION;

/**
 带下载链接的
 
 @param imageUrl 图片链接
 @param placeholder 占位图片
 @param describe 消息描述
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithImageUrl:(NSString *)imageUrl
                     placeholder:(UIImage *)placeholder
                         message:(NSString *)message
                        delegate:(id<AUDialogDelegate>)delegate;

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
 添加普通按钮以及其回调方法(仅支持不带行为按钮情况下添加)。
 
 @param buttonTitle 普通按钮标题
 @param actionBlock 按钮回调
 */
- (void)addButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;


@end

#endif//程序自动生成
