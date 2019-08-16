#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUAuthorizeDialog//程序自动生成
//
//  AUAuthorizeDialog.h
//  AntUI
//
//  Created by 沫竹 on 2017/11/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AUAuthorizeDialog : UIView 

AU_UNAVAILABLE_INIT

- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                    authTitle:(NSString *)authTitle
                  authDetails:(NSArray *)authDetails
                      bizName:(NSString *)bizName;

- (void)setConfirmButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;
- (void)setCancelButtonActionBlock:(AUDialogActionBlock)actionBlock;
- (void)setLinkActionBlock:(BOOL (^)(NSString *))linkActionBlock;

- (void)show;
- (void)dismiss;

@end

#endif//程序自动生成
