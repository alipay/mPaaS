#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_floatTip_AURecordFloatTip//程序自动生成
//
//  AURecordFloatTip.h
//  AntUI
//
//  Created by niki on 14-12-4.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aurecordfloattip
//#########################################################


#define UI_AURecordFloatTip

@interface AURecordFloatTip : UIView

@property (nonatomic, strong) UILabel *messageLabel; // 录音提示语，默认值为"正在录音"

// 浮层展示
- (void)showRecodingInView:(UIView *)view;

// 浮层消失
- (void)dismissRecordView;

// 更新浮层分贝值显示正确图标
//- (void)updateDecibel:(CGFloat)decibel;

@end

#endif//程序自动生成
