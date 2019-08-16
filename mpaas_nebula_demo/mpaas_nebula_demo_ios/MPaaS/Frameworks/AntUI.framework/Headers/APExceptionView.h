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
#import <AntUI/AUNetErrorView.h>

typedef AUNetErrorType APExceptionEnum;
typedef AUNetErrorStyle APExceptionStyle;

__deprecated_msg("请使用AUNetErrorView")
@interface APExceptionView : AUNetErrorView

/**
 *  初始化异常view并设定异常风格和类型
 *
 *  @param frame view的坐标，必选
 *  @param style 异常的风格，插画版or极简版，必选
 *  @param type  异常类型，必选
 *
 *  @return APExceptionView
 */
- (id)initWithFrame:(CGRect)frame style:(AUNetErrorStyle)style exceptionType:(AUNetErrorType)type;

/**
 *  初始化异常视图并显示在指定的视图上
 *
 *  @param parent view的superView，必选
 *  @param style  异常的风格，插画版or极简版，必选
 *  @param type   异常类型，必选
 *  @param target 事件处理对象
 *  @param action 事件处理方法
 *
 *  @return APExceptionView
 */
- (id)initWithParentView:(UIView *)parent style:(AUNetErrorStyle)style exceptionType:(AUNetErrorType)type target:(id)target action:(SEL)action;

/**
 *  初始化异常view并设定异常类型
 *
 *  @param frame view的坐标，必选
 *  @param type  异常类型，必选
 *
 *  @return APExceptionView
 */
- (id)initWithFrame:(CGRect)frame exceptionType:(AUNetErrorType)type;

/**
 *  初始化异常视图并显示在指定的视图上
 *
 *  @param parent view的superView，必选
 *  @param type   异常类型，必选
 *  @param target 事件处理对象
 *  @param action 事件处理方法
 *
 *  @return APExceptionView
 */
- (id)initWithParentView:(UIView *)parent exceptionType:(AUNetErrorType)type target:(id)target action:(SEL)action;

@end

#endif//程序自动生成
