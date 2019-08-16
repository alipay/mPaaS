#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUNoticeDialog//程序自动生成
//
//  AUNoticeDialog+Extension.h
//  AntUI
//
//  Created by 莜阳 on 17/3/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUNoticeDialog.h"

@interface AUNoticeDialog (Extension)

/**
 带按钮标题的初始化方法。
 
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param cancelButtonTitle 取消按钮文案
 @param otherButtonTitles 确定按钮文案
 @return AUNoticeDialog 实例
 */

- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
            cancelButtonTitle:(NSString *)cancelButtonTitle
            otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;


- (void)showAlert __deprecated_msg("请使用show方法");

+ (void)removeAllAlerviews __deprecated_msg("请使用dismissAll方法");

+ (void)setBackgroundMode:(BOOL)isBackMode;

- (NSInteger)showModel __deprecated_msg("同步show方法，会阻塞主线程，请不要使用");


- (void)setLinkActionBlock:(BOOL (^)(NSString *))linkActionBlock;

@end

//
NS_INLINE AUNoticeDialog *AUNoticeDialogWithTitleAndMessage(NSString *title, NSString *message)
{
    AUNoticeDialog *alertView = [[AUNoticeDialog alloc] initWithTitle:title message:message];
    [alertView addCancelButton:@"确定" actionBlock:nil];//NoticeDialog的buttonclick默认dismiss
    [alertView show];
    return alertView;
}

//
NS_INLINE AUNoticeDialog *AUNoticeDialogWithTitle(NSString *title)
{
    AUNoticeDialog *alertView = AUNoticeDialogWithTitleAndMessage(title,nil);
    return alertView;
}

#endif//程序自动生成
