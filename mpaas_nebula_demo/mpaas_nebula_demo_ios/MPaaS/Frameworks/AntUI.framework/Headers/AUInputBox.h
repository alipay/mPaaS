#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUInputBox//程序自动生成
//
//  AUInputBox.h
//  AntUI
//
//  Created by QiXin on 2016/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUTextField.h"

#define UI_AUInputBox

//@class AUTextField;
@class AUButton;
@class UITextField;
@class UIButton;

typedef NS_ENUM(NSInteger, AUInputBoxType)
{
    AUInputBoxTypeMobileNumber,     // 手机号码
    AUInputBoxTypeCreditCard,       // 信用卡
    AUInputBoxTypeBankCard,         // 借记卡
    AUInputBoxTypeAmount,           // 金额
    AUInputBoxTypeIDNumber,         // 身份证
    AUInputBoxTypeNotEmpty,         // 非空
    AUInputBoxTypeAlipayAccount,    // 支付宝账号
    AUInputBoxTypeNone,              // 不校验
    
    APInputBoxTypeMobileNumber __attribute__((deprecated))  = AUInputBoxTypeMobileNumber,            // 手机号码
    APInputBoxTypeCreditCard    __attribute__((deprecated)) = AUInputBoxTypeCreditCard,               // 信用卡
    APInputBoxTypeBankCard      __attribute__((deprecated)) = AUInputBoxTypeBankCard,                  // 借记卡
    APInputBoxTypeAmount        __attribute__((deprecated)) = AUInputBoxTypeAmount,                     // 金额
    APInputBoxTypeIDNumber      __attribute__((deprecated)) = AUInputBoxTypeIDNumber,                // 身份证
    APInputBoxTypeNotEmpty      __attribute__((deprecated)) = AUInputBoxTypeNotEmpty,               // 非空
    APInputBoxTypeAlipayAccount __attribute__((deprecated)) = AUInputBoxTypeAlipayAccount,    // 支付宝账号
    APInputBoxTypeNone          __attribute__((deprecated)) = AUInputBoxTypeNone                      // 不校验
};

typedef enum AUInputBoxStyle
{
    AUInputBoxStyleNone, // 没有背景图片
    AUInputBoxStyleiOS6, // 圆角的背景图片
    AUInputBoxStyleiOS7,  // 非圆角的背景图片
    
    APInputBoxStyleNone         __attribute__((deprecated)) = AUInputBoxStyleNone,   // 没有背景图片
    APInputBoxStyleiOS6         __attribute__((deprecated)) = AUInputBoxStyleiOS6,  // 圆角的背景图片
    APInputBoxStyleiOS7         __attribute__((deprecated)) = AUInputBoxStyleiOS7  // 非圆角的背景图片
} AUInputBoxStyle;


/**
 普通输入框，可带标题文字，按钮图片样式
 文档:https://yuque.antfin-inc.com/antui/auidoc/ios_auinputbox
 */
@interface AUInputBox : UIView

#pragma mark - AUInputBox属性

// 文本输入框
@property(strong, nonatomic)   AUTextField      *textField;
@property(strong, nonatomic)   NSString         *textFieldText;
@property(strong, nonatomic)   NSString         *textFieldFormat;
@property(assign, nonatomic)   CGFloat          horizontalMargin;
@property(assign, nonatomic)   CGFloat          textFieldHorizontalMargin;


// 按钮
@property(strong, nonatomic)   UIButton         *iconButton;
@property(assign, nonatomic)   BOOL             hidesButtonWhileNotEmpty;
@property(assign, nonatomic)   BOOL             hidesButton;


// 显示在输入框左边的lable
@property(nonatomic, readonly) UILabel          *titleLabel;
@property(nonatomic, assign)   CGFloat          titleLabelWidth;


// 样式、验证器、背景图、文本框类型
@property(assign, nonatomic)   AUInputBoxStyle  style;
@property(readonly, nonatomic) UIImageView      *backgroundImage;
@property(assign, nonatomic)   AUInputBoxType   inputBoxType;


#pragma mark - AUInputBox静态方法
/**
 *  创建输入框组件
 *  @param  originY 输入框的y坐标
 *  @param  type 文本输入框的类型
 *  @return 输入框组件
 */
+ (instancetype)inputboxWithOriginY:(CGFloat)originY
                       inputboxType:(AUInputBoxType)type;

/**
 *  创建带图标按钮的输入框组件
 *  @param  originY 输入框的y坐标
 *  @param  icon 按钮上的图标，44x44
 *  @param  type 文本输入框的类型
 *  @return 带按钮的输入框组件
 */
+ (instancetype)inputboxWithOriginY:(CGFloat)originY
                         buttonIcon:(UIImage *)icon
                       inputboxType:(AUInputBoxType)type;

/**
 *  @return 控件高度,默认值44，iPhone6 plus 为47
 */
+ (float)heightOfControl;


#pragma mark - AUInputBox实例方法

- (instancetype)initWithFrame:(CGRect)frame inputboxType:(AUInputBoxType)type;

- (void)buildIconButton:(UIImage *)icon;

/**
 *  按照指定格式对文本添加空格
 *  @param  text 文本内容
 *  @return 添加空格后的文本
 */
- (NSString *)formatText:(NSString *)text;

/**
 *  对于没有在初始化时指定icon的inputBox, 可以使用此方法添加
 *  @param icon 按钮上的图标
 *
 */
- (void)setRightButtonIcon:(UIImage *)icon;

/**
 * 检查输入的有效性.
 */
- (BOOL)checkInputValidity;

/**
 * 过滤文本，只可输入数字，限定最大长度
 * 参数为相应delegate参数，maxLength为最大长度
 */
- (BOOL)shouldChangeRange:(NSRange)range
        replacementString:(NSString *)string
            withMaxLength:(int)maxLength;

/**
 * 限定最大长度
 * @maxLength 最大长度，不包括format的空格
 */
- (BOOL)shouldChangeRange:(NSRange)range
        replacementString:(NSString *)string
withFormatStringMaxLength:(int)maxLength;

@end

#endif//程序自动生成
