#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUDoubleTitleView//程序自动生成
//
//  APTitleView.h
//  APCommonUI
//
//  Created by yangwei on 16/4/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_audoubletitleview
//#########################################################


#define UI_AUDoubleTitleView

/**
 包含两行的导航栏titleView
 */
@interface AUDoubleTitleView : UIView

/**
 *  创建上下两个标题的titleView
 *
 *  @param title          主标题
 *  @param detaileTitle   副标题
 *
 *  @return 初始化后的APTitleView控件
 */
- (UIView *)initWithTitle:(NSString *)title detailTitle:(NSString *)detaileTitle;

/**
 *  修改主标题的文案。
 *
 *  @param title          主标题文案
 *
 */
- (void)updateTitle:(NSString *)title;

/**
 *  修改主标题的文案。
 *
 *  @param detailTitle          主标题文案
 *
 */
- (void)updateDetailTitle:(NSString *)detailTitle;


/**
 修改主标题的font。

 @param titleFont 主标题font
 */
- (void)updateTitleFont:(UIFont *)titleFont;

/**
 *  修改主标题的font。
 *
 *  @param detailTitleFont      主标题font
 *
 */
- (void)updateDetailTitleFont:(UIFont *)detailTitleFont;

@end

#endif//程序自动生成
