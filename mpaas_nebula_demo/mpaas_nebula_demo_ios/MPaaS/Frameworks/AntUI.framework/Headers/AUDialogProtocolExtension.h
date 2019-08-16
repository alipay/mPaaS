#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogProtocolExtension.h
//  AntUI
//
//  Created by 莜阳 on 17/3/16.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUDialogProtocol.h"

@protocol AUDialogDelegateExtension <AUDialogDelegate>

//
- (void)alertView:(AUDialogBaseView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

//
- (void)alertViewCancel:(AUDialogBaseView *)alertView;

//
- (void)willPresentAlertView:(AUDialogBaseView *)alertView;

//
- (void)didPresentAlertView:(AUDialogBaseView *)alertView;

//
- (void)alertView:(AUDialogBaseView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex;

//
- (void)alertView:(AUDialogBaseView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex;

@end

#endif//程序自动生成
