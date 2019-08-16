#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUSwitchListItem//程序自动生成
//
//  AUSwitchListItem.h
//  AntUI
//
//  Created by sara on 16/10/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBaseListItem.h"
#import "AUSwitch.h"


@interface AUSwitchListItem : AUBaseListItem

@property (nonatomic,strong)  AUSwitch *switchControl;   // cell中的switch控件

// 设置菊花为展示或者隐藏状态
- (void)showLoadingIndicator:(BOOL)show;

@end

#endif//程序自动生成
