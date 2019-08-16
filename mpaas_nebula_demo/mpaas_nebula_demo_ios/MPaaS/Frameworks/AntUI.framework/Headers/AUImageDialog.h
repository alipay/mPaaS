#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUImageDialog//程序自动生成
//
//  AUImageDialog.h
//  AntUI
//
//  Created by QiXin on 2016/9/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUDialogBaseView.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auimagedialog
//#########################################################


#define UI_AUImageDialog

// 按钮点击 Index 对应值
typedef NS_ENUM(NSInteger, AUImageDialogButtonIndex) {
    AUImageDialogButtonIndex_Close  = -2,
    AUImageDialogButtonIndex_Link   = -1,
    AUImageDialogButtonIndex_Action =  0
};


/**
 图片 Dialog ， 支持 UED 需求的一种特殊样式 Dialog, 图片会做圆形显示。
 有两种模式:
    普通图片模式，添加按钮为普通按钮
    行为按钮模式，可以添加一个行为按钮以及链接按钮，右上角会有 X 退出按钮样式。
 两种模式不可添加对方模式的按钮，有 assert 校验。
 详细外观可参考文档：http://idoc.alipay.net/article/57fb153322ec746a420304d6
 */
@interface AUImageDialog : AUDialogBaseView

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

 @param image 图片
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                        title:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate;

/**
 带按钮标题的初始化方法。

 @param image 图片
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param buttonTitle 按钮标题参数列表
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                        title:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
                 buttonTitles:(NSString *)buttonTitle, ... NS_REQUIRES_NIL_TERMINATION;

/**
 带下载链接的
 
 @param imageUrl 图片链接
 @param placeholder 占位图片
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithImageUrl:(NSString *)imageUrl
                     placeholder:(UIImage *)placeholder
                           title:(NSString *)title
                         message:(NSString *)message
                        delegate:(id<AUDialogDelegate>)delegate;

/**
 带蓝色行为按钮的初始化方法。
 
 @param image 图片
 @param title 标题
 @param message 消息详情
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param actionTitle 行为按钮标题
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                        title:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
            actionButtonTitle:(NSString *)actionTitle DEPRECATED_MSG_ATTRIBUTE("暂时不需要该样式的 dialog");

/**
 带蓝色行为按钮以及链接按钮的初始化方法。

 @param image 图片
 @param title 标题
 @param message 消息详情
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param linkText 链接文本
 @param actionTitle 行为按钮标题
 @return AUImageDialog 实例
 */
- (instancetype)initWithImage:(UIImage *)image
                        title:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
                     linkText:(NSString *)linkText
            actionButtonTitle:(NSString *)actionTitle DEPRECATED_MSG_ATTRIBUTE("暂时不需要该样式的 dialog");

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
 设置自定义图片尺寸, 宽度不许超过 Dialog 最大宽度 270, 默认 135x135
 注意：在largeImage样式下，设置该imageSize无效
 */
- (void)configImageAreaSize:(CGSize)imageSize;

/**
 添加普通按钮以及其回调方法(仅支持不带行为按钮情况下添加)。

 @param buttonTitle 普通按钮标题
 @param actionBlock 按钮回调
 */
- (void)addButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;

/**
 添加行为按钮以及其回调方法。

 @param actionTitle 行为按钮标题
 @param actionBlock 行为按钮回调
 */
- (void)addActionButton:(NSString *)actionTitle actionBlock:(AUDialogActionBlock)actionBlock DEPRECATED_MSG_ATTRIBUTE("暂时不需要该样式的 dialog");

/**
 添加链接按钮以及其回调方法。

 @param linkText 链接文本
 @param actionBlock 链接按钮回调
 */
- (void)addLinkButton:(NSString *)linkText actionBlock:(AUDialogActionBlock)actionBlock;

/**
 隐藏右上角关闭按钮
 */
- (void)setCloseButtonHidden:(BOOL) hidden;

/**
 右上角关闭按钮回调
 */
- (void)setCloseButtonActionBlock:(AUDialogActionBlock)actionBlock;

@end

#endif//程序自动生成
