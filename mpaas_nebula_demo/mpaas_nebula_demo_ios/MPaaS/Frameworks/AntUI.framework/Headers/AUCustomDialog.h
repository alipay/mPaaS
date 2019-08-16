#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUCustomDialog//程序自动生成
//
//  AUCustomDialog.h
//  AntUI
//
//  Created by 沫竹 on 2018/3/14.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUView.h"

@class AUDialogButton;
@interface AUCustomDialog : AUView

@property (nonatomic, strong) AUDialogButton *closeButton; // 右上角的关闭按钮，只有调用了showCloseButton才会初始化


/**
 展示右上角的关闭按钮

 @param color 关闭按钮的颜色
 */
- (void)showCloseButton:(UIColor *)color;

- (void)show;

- (void)dismiss;

@end

#endif//程序自动生成
