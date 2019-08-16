#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopTip_AUPopTipView//程序自动生成
//
//  AUPopTipView.h
//  AntUI
//
//  Created by 沫竹 on 2018/2/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUPopDrawBoardView.h"

@class AUPopTipContentView;

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aupoptipview
//#########################################################


AntUI_DEMO(@"PopTipDemoViewController")

@interface AUPopTipView : AUPopDrawBoardView

AU_UNAVAILABLE_INIT

+ (instancetype)showFromView:(UIView *)fromView
                   fromPoint:(CGPoint)fromPoint
                      toView:(UIView *)toView
                    animated:(BOOL)animated
                    withText:(NSString *)text
                 buttonTitle:(NSString *)buttonTitle;



-(instancetype)initWithText:(NSString *)text
                buttonTitle:(NSString *)buttonTitle
               buttonAction:(BOOL(^)())actionBlock;




/**
 修改展示的颜色（对文案和button的颜色都会有影响）

 @param color 颜色
 */
- (void)setAppearenceColor:(UIColor *)color;

/**
 * 内容具体块,如果是自定义的，返回空
 */
- (AUPopTipContentView *) contentView;


- (void) removeCloseX;
@end

#endif//程序自动生成
