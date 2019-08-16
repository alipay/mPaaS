#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields//程序自动生成
//
//  AUTextField.h
//  AntUI
//
//  Created by QiXin on 2016/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class /*AUTextFieldDelegateProxy,*/ AUTextValidator;

typedef NS_ENUM(NSInteger, AUTextFieldStyle) {
    AUTextFieldStylePlain,
    AUTextFieldStyleBordered,
    
    APTextFieldStylePlain       __attribute__((deprecated))   = AUTextFieldStylePlain,
    APTextFieldStyleBordered    __attribute__((deprecated))   = AUTextFieldStyleBordered,
};

typedef NS_ENUM(NSInteger, AUKeyboardType) {
    AUKeyboardTypeIDCard = 100,
    
    APKeyboardTypeIDCard    __attribute__((deprecated)) = AUKeyboardTypeIDCard, //100,
};

@interface AUTextFieldDelegateProxy : NSProxy

@end

/**
 *  输入框控件
 *
 */
@interface AUTextField : UITextField

// 验证器、原始文本
@property(nonatomic, strong) AUTextValidator *validator;
@property(nonatomic, strong) NSString        *normalizedText;
// 用于显示身份证‘X’的键
@property(nonatomic, strong) UIButton        *buttonX;
@property (nonatomic, assign) BOOL           keyboardTypeIDCard;
@property(nonatomic, strong) AUTextFieldDelegateProxy *delegateProxy;

#pragma mark - AUTextField静态方法

/**
 *  创建输入框组件
 *  @param style 文本框样式
 *  @param originY 输入框的y坐标
 *  @return 返回输入框组件
 */
+ (AUTextField *)textFieldWithStyle:(AUTextFieldStyle)style originY:(CGFloat)originY;

/**
 *  Initializes and returns an newly created text field object with the height of 43.0.
 *
 *  @return An initialized text field object.
 */
- (id)init;

#pragma mark - AUTextField实例方法

/**
 * 检查输入的有效性
 * @return 返回验证结果
 */
- (BOOL)checkInputValidity;

/**
 * 格式化文本
 * @return 返回格式化后的文本
 */
- (NSString *)formatText:(NSString *)text;



@end

#endif//程序自动生成
