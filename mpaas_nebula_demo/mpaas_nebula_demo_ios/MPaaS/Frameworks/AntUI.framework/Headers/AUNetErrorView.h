#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_NetError_AUNetErrorView//程序自动生成
//
//  APExceptionView.h
//  APCommonUI
//
//  Created by Yuanchen on 14-1-20.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auneterrorview
//#########################################################


#define UI_AUNetErrorView

typedef NS_ENUM(NSInteger, AUNetErrorType) {
    
    AUNetErrorTypeLimit,        //限流
    AUNetErrorTypeAlert,        // 系统繁忙（系统错误）、警示
    AUNetErrorTypeNetworkError, //网络不给力
    AUNetErrorTypeEmpty,        //内容为空
    AUNetErrorTypeNotFound,     // 404找不到
    AUNetErrorTypeUserLogout,     // 用户已注销
    
    AUNetErrorTypeFailure __attribute__((deprecated)) = AUNetErrorTypeNetworkError,
    AUNetErrorTypeError __attribute__((deprecated)) = AUNetErrorTypeNetworkError,        //网络错误，完全无法连接
    AUNetErrorTypeSystemBusy __attribute__((deprecated)) = AUNetErrorTypeAlert,        //警示
    APExceptionEnumNetworkError __attribute__((deprecated)) = AUNetErrorTypeNetworkError,   //网络错误，完全无法连接
    APExceptionEnumEmpty __attribute__((deprecated)) = AUNetErrorTypeEmpty,          //内容为空
    APExceptionEnumAlert __attribute__((deprecated)) = AUNetErrorTypeAlert,          //警示
    APExceptionEnumLimit __attribute__((deprecated)) = AUNetErrorTypeLimit,          //限流，
    APExceptionEnumNetworkFailure __attribute__((deprecated)) =  AUNetErrorTypeNetworkError, //网络不给力
};


typedef NS_ENUM(NSInteger, AUNetErrorStyle) {
    AUNetErrorStyleMinimalist,    //简单版
    AUNetErrorStyleIlustration,  //插图版
    
    APExceptionStyleIlustration __attribute__((deprecated)) = AUNetErrorStyleIlustration,  //插图版
    APExceptionStyleMinimalist __attribute__((deprecated)) =  AUNetErrorStyleMinimalist  //简单版
};


// 当Lottie不存在时，也不进行网络下载
// 避免同时去下载时把服务端打挂
// @value ： @（true）不下载
static NSString *AUNetErrorViewParamSkipLottieDownload = @"AUNetErrorViewParamSkipLottieDownload";


/**
 空页面异常视图显示控件

 包括两种提示风格：
    1、简单版风格（默认），包含3种类型样式
    2、插图版风格，包含7种类型样式
 
 两种风格和类型主要是图片不一样。
 */
@interface AUNetErrorView : UIView

/**
 *  行为按钮，通过设置他来修改按钮的样式
 *  注意：用initWithFrame方法初始化异常控件后，行为按钮默认不显示，需调get方法才会显示
 */
@property(nonatomic, strong) UIButton *actionButton;                // 默认文案是刷新
@property(nonatomic, strong, readonly) UIImageView *iconImageView;  // icon视图
@property(nonatomic, strong, readonly) UILabel *infoLabel;          // 主提示文案Label
@property(nonatomic, strong, readonly) UILabel *detailLabel;        // 详细提示文案Label

@property(nonatomic, strong) NSString *infoTitle;                   // 主文案说明
@property(nonatomic, strong) NSString *detailTitle;                 // 辅助文案说明

/**
 *  初始化异常view并设定异常风格和类型
 *  （target和action为空时，刷新按钮不显示）
 *
 *  @param frame   view的起始位置，必选
 *  @param style    异常的风格，插画版or极简版，必选
 *  @param type     异常类型，必选
 *  @param target   刷新事件处理对象
 *  @param action   刷新事件处理方法
 *
 *  @return APExceptionView
 */

- (id)initWithFrame:(CGRect)frame
              style:(AUNetErrorStyle)style
               type:(AUNetErrorType)type
             target:(id)target
             action:(SEL)action;


- (id)initWithFrame:(CGRect)frame
              style:(AUNetErrorStyle)style
               type:(AUNetErrorType)type
             params:(NSDictionary *)params
             target:(id)target
             action:(SEL)action;

/**
 *  初始化异常视图并显示在指定的视图上，布局在 parent 视图中间
 *  （target和action为空时，刷新按钮不显示）
 *
 *  @param parent view的superView，必选，view的位置相对parent居中
 *  @param style  异常的风格，插画版or极简版，必选
 *  @param type   异常类型，必选
 *  @param target 刷新事件处理对象
 *  @param action 刷新事件处理方法
 *
 *  @return APExceptionView
 */
+ (id)showInView:(UIView *)parent
           style:(AUNetErrorStyle)style
            type:(AUNetErrorType)type
          target:(id)target
          action:(SEL)action;

/**
 * 取消异常视图的显示
 */
- (void)dismiss;





/**
 *  获取大图标的只读UIImageView
 *
 *  @return UIImageView
 */
- (UIImageView *)getIconImageView;

/**
 *  获取说明文案的只读UILabel。自定义主文案，请设置infoTitle属性
 *
 *  @return UILabel
 */
- (UILabel *)getInfoLabel;

/**
 *  获取辅助文案的只读UILabel。默认为nil，若需自定义辅助文案，请设置detailTitle属性
 *
 *  @return UILabel
 */
- (UILabel *)getDetailLabel;

/**
 *  获取行动按钮，建议使用actionButton属性
 *
 *  @return UIButton
 */
- (UIButton *)getActionButton;



/**
 *  倒计时 仅限限流使用
 *  如果 completeBlock == nil 且 业务没有设置actionButton的点击响应事件 则倒计时功能不生效；
 *  如果 completeBlock != nil, 倒计时结束直接执行 completeBlock，同时隐藏 actionButton
 *  如果使用 getActionButton 来添加button的响应事件，要确保在该方法之前添加 actionButton 的响应事件
 */
- (void)setCountdownTimeInterval:(NSInteger)startTime  // 倒计时起始时间
                   completeBlock:(void (^)(void))completeBlock; // 倒计时结束后

@end


#endif//程序自动生成
