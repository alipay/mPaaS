#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopTip_AUPopBar//程序自动生成
//
//  AUPopBarContentView.h
//  AntUI
//
//  Created by 沫竹 on 2018/3/16.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUDefine.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aupopbar
//#########################################################


AntUI_DEMO(@"PopTipDemoViewController")

@interface AUPopBar : AUView

AU_UNAVAILABLE_INIT

/**
 展示AUPopBar控件

 注意：
    1、同一个view只会在底部显示一个popbar，所以调用此方法时会把之前显示的dismiss掉，然后返回新的给你
 
 @param view 将控件展示在哪个视图上
 @param animated 是否动画
 @param text 文案
 @param icon 图标
 @param buttonTitle 按钮名称，如果length为0，按钮不会创建
 @param actionBlock 按钮响应事件（返回YES，会自动调用dismiss方法消失控件，否则需要手动调用）
 @return AUPopBar组件
 */
+ (instancetype)showInViewBottom:(UIView *)view
                        animated:(BOOL)animated
                        withText:(NSString *)text
                            icon:(UIImage *)icon
                     buttonTitle:(NSString *)buttonTitle
                     actionBlock:(BOOL(^)())actionBlock;

/**
 * 在view的底部展示改控件
 *
 */
- (void) showInView:(UIView*)view animated:(BOOL) animated;

/**
 * 在view的特定位置展示改控件
 * @param view: superView
 * @param
 *
 */
- (void) showInView:(UIView*)view position:(CGPoint)origin verticalAlignment:(UIControlContentVerticalAlignment) alignment animated:(BOOL) animated;


/**
 隐藏控件

 @param animated 是否动画
 */
- (void)dismiss:(BOOL)animated;

@end



/**
 提供一些扩展接口，业务有特殊需求时才需要使用
 */
@interface AUPopBar (AUExtend)


/**
 初始化一个popbar视图
 1、可以用这个方法渲染出一个控件，然后添加到任意地方
 
 @param text 文案
 @param icon 图标
 @param buttonTitle 按钮名称
 @param actionBlock 按钮响应事件（返回YES，会自动调用dismiss方法消失控件，否则需要手动调用）
 @return AUPopBar组件
 */
- (instancetype)initWithText:(NSString *)text
                        icon:(UIImage *)icon
                 buttonTitle:(NSString *)buttonTitle
                 actionBlock:(BOOL(^)())actionBlock;

/**
 初始化一个popbar视图
 1、可以用这个方法渲染出一个控件，然后添加到任意地方
 
 @param text 主标题文案
 @param desc 下方说明文案
 @param icon 图标
 @param buttonTitle 按钮名称
 @param actionBlock 按钮响应事件（返回YES，会自动调用dismiss方法消失控件，否则需要手动调用）
 @return AUPopBar组件
 */
- (instancetype)initWithText:(NSString *)text
                        desc:(NSString *)desc
                        icon:(UIImage *)icon
                 buttonTitle:(NSString *)buttonTitle
                 actionBlock:(BOOL(^)())actionBlock;

/**
 按钮
 1、可以设置backgroundColor改变默认的按钮背景色
 2、可以设置titleColor改变文字的颜色
 */
@property (nonatomic, readonly) UIButton    *button;

/**
 设置关闭的block
 注意：
 block返回值YES时，会自动调用dismiss，
 block返回值NO时，需要业务手动调用dismiss操作
 
 @param closeActionBlock 关闭的block
 */
- (void)setCloseActionBlock:(BOOL(^)(AUPopBar *popBar))closeActionBlock;

/**
 设置按钮的block
 注意：
 block返回值YES时，会自动调用dismiss，
 block返回值NO时，需要业务手动调用dismiss操作
 
 @param buttonActionBlock 关闭的block
 */
- (void)setButtonActionBlock:(BOOL (^)(AUPopBar *))buttonActionBlock;

@end


#endif//程序自动生成
