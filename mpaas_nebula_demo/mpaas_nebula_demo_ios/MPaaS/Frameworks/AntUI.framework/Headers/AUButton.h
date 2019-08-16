#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUButton//程序自动生成
//
//  AUButton.h
//  AntUI
//
//  Created by maizhelun on 2016/9/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aubutton
//#########################################################

typedef void (^AUButtonBlock)();

typedef NS_ENUM(NSInteger, AUButtonStyle) {
    AUButtonStyleNone, //系统默认
    AUButtonStyle1, //蓝底，白字，无边框，大按钮样式
    AUButtonStyle2, //白底，黑字，浅灰色边框，大按钮样式
    AUButtonStyle3, //透明底，蓝字，蓝色边框，小按钮字样
    AUButtonStyle4,  // 白底，默认带上下分割线，字是红色的；使用场景（取消关注）等页面底部操作，默认高度44单位，宽度为屏幕宽度
    AUButtonStyle5,  // 白底，默认带上下分割线，字是蚂蚁蓝；使用场景（更多服务）等页面底部操作，默认高度44单位，宽度为屏幕宽度
    AUButtonStyle6,  // 红底白字，警告类操作，大按钮样式
    AUButtonStyle7, // 白底，黑字，浅灰色边框，小按钮样式
    AUButtonStyle8, //蓝底，白字，无边框，小按钮样式
    AUButtonStyle9, // 白底，字是红色的；使用场景登出，大按钮样式
};

AntUI_BaseComponent
@interface AUButton : UIButton


/**
 按钮样式
 */
@property (nonatomic, readonly) AUButtonStyle style;

// button 行动block
@property (nonatomic, copy) AUButtonBlock actionblock;

/**
 初始化方法

 @param style 样式

 @return 创建的初始化对象
 */
+ (instancetype)buttonWithStyle:(AUButtonStyle)style;

/**
 *  初始化的辅助方法，用于创建并初始化一个按钮的对象。
 *
 *  @param style      按钮类型，必须是定义在<code>AUButtonStyle</code>中的其中一个值。
 *  @param title      铵钮标题
 *  @param target     响应按钮点击事件的对象
 *  @param action     响应按钮点击事件的函数
 *
 *  @return 新创建并经过初始化的按钮对象。
 *  
 *  此方法初始化的对象 需要设置frame
 */
+ (instancetype)buttonWithStyle:(AUButtonStyle)style title:(NSString *)title target:(id)target action:(SEL)action;

/*
 *  获取默认样式 button 的高度
 */
+ (CGFloat)buttonHeightWithStyle:(AUButtonStyle)style;

@end



@interface AUButton (AULoading)

/**
 在按钮上展示菊花动画和文字，左菊花右文字，无文字时菊花居中
 
 @param loadingTitle 展示菊花时候的文字，设置nil或者空串不展示，菊花居中
 @param currentVC    当前VC，为了loading结束的去掉遮罩
 */
- (void)startLoadingWithTitle:(NSString *)loadingTitle currentViewController:(UIViewController *)currentVC;


/**
 停止转菊花
 */
- (void)stopLoading;

@end

//标题左侧的image
//since 10.1.38
@interface AUButton (LeftImageSupport)

-(void) setLeftTitleImage:(UIImage *)image;

@end

#endif//程序自动生成
