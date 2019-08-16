#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Toast_AUToast//程序自动生成
//
//  AUToast.h
//  CommonUI
//
//  Created by  tudou on 13-4-12.
//  Copyright (c) 2013年  tudou. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_autoast
//#########################################################


#define UI_AUToast

// log输出函数声明，由外部设置
typedef void(*AUToastLogFunc)(NSString *tag, NSString *format, ...);
extern AUToastLogFunc g_ToastExternLogFunc; // log输出函数全局变量，由外部设置
//#define AUToastLog(fmt, ...) {if(g_ToastExternLogFunc)g_ToastExternLogFunc(@"@AUToast",fmt,##__VA_ARGS__);}


#define AUToast_Default_Duration 2.0    // AUToast默认展示时间
#define AUToast_Strong_Duration 1.5     // AUToast强提示展示时长
#define AUToast_Weak_Duration 1.0       // AUToast弱提示展示时长

/**
 *  添加新的toastIcon时，请向后添加，不要在中间插入，否则业务使用会有问题
 */
typedef enum{
    AUToastIconNone = 0,    // 无图标
    AUToastIconSuccess,     // 成功图标
    AUToastIconFailure,     // 失败图标
    AUToastIconLoading,     // 加载图标
    AUToastIconNetFailure,  // 网络失败
    AUToastIconSecurityScan,// 安全扫描
    
    AUToastIconNetError,    // 网络错误，完全无法连接
    AUToastIconProgress,    // 加载图标，显示加载进度
    AUToastIconAlert,       // 警示图标
//    AUToastIconSecurity,   // 安全感专用toast提示
    
    APToastIconNone     __attribute__((deprecated)) = AUToastIconNone ,//0,    // 无图标
    APToastIconSuccess  __attribute__((deprecated)) = AUToastIconSuccess,     // 成功图标
    APToastIconFailure __attribute__((deprecated))  = AUToastIconFailure,     // 失败图标
    APToastIconLoading __attribute__((deprecated))  = AUToastIconLoading,     // 加载图标
    APToastIconNetFailure __attribute__((deprecated)) = AUToastIconNetFailure,  // 网络失败
    APToastIconSecurityScan __attribute__((deprecated)) = AUToastIconSecurityScan,// 安全扫描
    APToastIconNetError __attribute__((deprecated))     = AUToastIconNetError,    // 网络错误，完全无法连接
    APToastIconProgress __attribute__((deprecated))     = AUToastIconProgress,    // 加载图标，显示加载进度
    APToastIconAlert __attribute__((deprecated))        = AUToastIconAlert,       // 警示图标
} AUToastIcon;



/**
 * Toast控件
 */
@interface AUToast : UIView

@property (nonatomic, assign) CGFloat xOffset; // 设置相对父视图中心位置X坐标方向的偏移量
@property (nonatomic, assign) CGFloat yOffset; // 设置相对父视图中心位置Y坐标方向的偏移量

/*
 * 模态显示提示，此时屏幕不响应用户操作（显示在keywindow上面），
 * 需调用dismissToast方法使Toast消失
 *
 * @param text   显示文本，默认为loading加载
 * @param logTag 日志标识
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithText:(NSString *)text
                           logTag:(NSString*)logTag;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param text      显示文本
 * @param logTag    日志标识
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithin:(UIView *)superview
                           text:(NSString *)text
                         logTag:(NSString*)logTag;

/**
 * 显示Toast，需调用dismissToast方法使Toast消失
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 * @param logTag    日志标识
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithin:(UIView *)superview
                       withIcon:(AUToastIcon)icon
                           text:(NSString *)text
                         logTag:(NSString*)logTag;

/**
 * 显示Toast
 *
 * @param superview 父视图
 * @param icon      图标类型
 * @param text      显示文本
 * @param duration  显示时长
 * @param logTag    日志标识
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithin:(UIView *)superview
                       withIcon:(AUToastIcon)icon
                           text:(NSString *)text
                       duration:(NSTimeInterval)duration
                         logTag:(NSString*)logTag;



/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param logTag        日志标识
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithin:(UIView *)superview
                       withIcon:(AUToastIcon)icon
                           text:(NSString *)text
                       duration:(NSTimeInterval)duration
                         logTag:(NSString*)logTag
                     completion:(void (^)())completion;


/**
 * 显示Toast
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param logTag        日志标识
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentToastWithin:(UIView *)superview
                       withIcon:(AUToastIcon)icon
                           text:(NSString *)text
                       duration:(NSTimeInterval)duration
                          delay:(NSTimeInterval)delay
                         logTag:(NSString*)logTag
                     completion:(void (^)())completion;



/*
 * 模态toast，需调用dismissToast方法使Toast消失
 * 跟普通的toast区别是，会添加一个透明的背景层，防止用户屏幕点击
 *
 * @param superview 父视图
 * @param text      显示文本
 * @param logTag    日志标识
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentModelToastWithin:(UIView *)superview
                                text:(NSString *)text
                              logTag:(NSString*)logTag;


/**
 * 显示模态Toast
 * 跟普通的toast区别是，会添加一个透明的背景层，防止用户屏幕点击
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param logTag        日志标识
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentModalToastWithin:(UIView *)superview
                            withIcon:(AUToastIcon)icon
                                text:(NSString *)text
                            duration:(NSTimeInterval)duration
                              logTag:(NSString*)logTag
                          completion:(void (^)())completion;


/**
 * 显示模态Toast
 * 跟普通的toast区别是，会添加一个透明的背景层，防止用户屏幕点击
 *
 * @param superview     要在其中显示Toast的视图
 * @param icon          图标类型
 * @param text          显示文本
 * @param duration      显示时长
 * @param delay         延迟显示时长
 * @param logTag        日志标识
 * @param completion    Toast自动消失后的回调
 *
 * @return 返回显示的Toast对象
 */
+ (AUToast *)presentModalToastWithin:(UIView *)superview
                            withIcon:(AUToastIcon)icon
                                text:(NSString *)text
                            duration:(NSTimeInterval)duration
                               delay:(NSTimeInterval)delay
                              logTag:(NSString*)logTag
                          completion:(void (^)())completion;


/*
 * 使toast消失
 */
- (void)dismissToast;

/**
 *  设置进度的前缀文本，如果不设置，默认为“加载数据”
 *  当toast类型为AUToastIconProgress设置有效，否则忽略
 *
 *  @param prefix 文本
 */
- (void)setProgressPrefix:(NSString*)prefix;

/**
 * 显示当前加载数据的进度百分比
 * 当toast类型为AUToastIconProgress设置有效，否则忽略
 *
 * @param value      当前已加载的数据，范围为<0.0，1.0>
 *
 */
- (void)setProgressText:(float)value;

@end

@interface AUToast (AUSecurity)

// 变更当前的进度状态，结束状态的动画完成后自动消失当前展示的toast
- (void)toastLoadingDidFinish;

@end


/**
 展现一个toast

 @param superView 父view
 @param icon toast类型
 @param text toast文案
 @param logTag 业务tag
 @return toast
 */
NS_INLINE AUToast *AUToastShow(UIView *superView, AUToastIcon icon, NSString *text, NSString *logTag) {
    return [AUToast presentToastWithin:superView withIcon:icon text:text logTag:logTag];
}


/**
 展现一个toast，2s后自动消失


 @param icon toast类型
 @param text toast文案
 @param logTag 业务tag
 @return toast
 */
NS_INLINE AUToast *AUToastShowWithAutoHide(UIView *superView, AUToastIcon icon, NSString *text, NSString *logTag) {
    return [AUToast presentToastWithin:superView withIcon:icon text:text duration:2 logTag:logTag];
}


#endif//程序自动生成
