#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUSubscriptButton//程序自动生成
//
//  AUSubscriptButton.h
//  AntUI
//
//  Created by Niki on 2017/11/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

/** 带角标的按钮
 *  特点：选中状态下默认带角标，无高亮色
*/

// button文案默认边距
#define AUSubscriptButtonTitleHorizontalPadding     AUI_THEMES_FLOAT(@"SUBSCRIPT_BUTTON_EDGE_MARGIN", @"NUMBER(18)")

@interface AUSubscriptButton : UIButton

/* 宽高使用蚂蚁通用规范默认值（默认为NO）
 1. 具有默认的内边距
 2. 具备默认UI默认宽高，不支持业务调整
 注意：需要在调用setTitle:forState:方法前设置当前参数
 */
@property (nonatomic, assign) BOOL autoSizeToFits; //

@end

#endif//程序自动生成
