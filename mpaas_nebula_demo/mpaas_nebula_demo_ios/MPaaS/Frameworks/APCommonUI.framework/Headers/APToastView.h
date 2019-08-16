//
//  APToastView.h
//  CommonUI
//
//  Created by  tudou on 13-4-12.
//  Copyright (c) 2013年  tudou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUToast.h>

#define APToast_Default_Duration    AUToast_Default_Duration    // 2.0    // APToast默认展示时间
#define APToast_Strong_Duration     AUToast_Strong_Duration    //1.5     // APToast强提示展示时长
#define APToast_Weak_Duration       AUToast_Weak_Duration     //1.0       // APToast弱提示展示时长

// log输出函数声明，由外部设置
//typedef void(*apuiExternLogFuncType)(NSString *tag, NSString *format, ...);
//extern apuiExternLogFuncType g_apuiExternLogFunc;
//#define APUI_EXLapuiExternLogFuncTypeOG(fmt, ...) {if(g_apuiExternLogFunc)g_apuiExternLogFunc(@"@APUI",fmt,##__VA_ARGS__);}

extern AUToastLogFunc g_apuiExternLogFunc;

/**
 *  添加新的toastIcon时，请向后添加，不要在中间插入，否则业务使用会有问题
 */

__deprecated_msg("APToastIcon 已经废弃，请尽快替换成 AUToastIcon")
typedef AUToastIcon APToastIcon;


__deprecated_msg("APToastView 已废弃，请直接使用 AUToast")
@interface APToastView : AUToast //UIView

///**
// * 首页卡券页面弹得特殊样式toast。
// */
//- (void)setSocialTipToastStyle;


#pragma mark - 带tag的版本，tag串会打到log文件里，用来标识这个ToastView是哪弹的。业务尽量使用这组方法，方便出问题时定位哪里弹的toast。

+ (APToastView *)presentTagToastWithin:(UIView *)superview
                              withIcon:(APToastIcon)icon
                                  text:(NSString *)text
                              duration:(NSTimeInterval)duration
                                logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                             logTag:(NSString*)logTag;
/**
 *  不推荐。 为使带tag的方法接口名保持一致，请使用 presentTagToastWithin 初始化，之后此方法会废弃。
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                             logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview text:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithText:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentModelTagToastWithin:(UIView *)superview text:(NSString *)text logTag:(NSString*)logTag;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                                logTag:(NSString*)logTag
                         completion:(void (^)())completion;
+ (APToastView *)presentTagToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                              delay:(NSTimeInterval)delay
                                logTag:(NSString*)logTag
                         completion:(void (^)())completion;
+ (APToastView *)presentModalTagToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                     logTag:(NSString*)logTag
                              completion:(void (^)())completion;
+ (APToastView *)presentModalTagToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                   delay:(NSTimeInterval)delay
                                     logTag:(NSString*)logTag
                              completion:(void (^)())completion;

#pragma mark - 没有带tag的老版本


/**
 * 显示Toast
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 * @param duration  显示时长
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview text:(NSString *)text;

/*
 * 模态显示提示，此时屏幕不响应用户操作，需调用dismissToast方法使Toast消失
 *
 * @param text 显示文本，默认为loading加载
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithText:(NSString *)text;

/*
 * 模态toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param text      显示文本
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModelToastWithin:(UIView *)superview text:(NSString *)text;


/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                         completion:(void (^)())completion;

/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentToastWithin:(UIView *)superview
                           withIcon:(APToastIcon)icon
                               text:(NSString *)text
                           duration:(NSTimeInterval)duration
                              delay:(NSTimeInterval)delay
                         completion:(void (^)())completion;

/**
 * 显示模态Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModalToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                              completion:(void (^)())completion;


/**
 * 显示模态Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (APToastView *)presentModalToastWithin:(UIView *)superview
                                withIcon:(APToastIcon)icon
                                    text:(NSString *)text
                                duration:(NSTimeInterval)duration
                                   delay:(NSTimeInterval)delay
                              completion:(void (^)())completion;

@end
