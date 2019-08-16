#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_Deprecated//程序自动生成
//
//  AUSimpleAmountInputField.h
//  AntUI
//
//  Created by zhaolei on 2017/6/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auamountedittext
//#########################################################


NS_ASSUME_NONNULL_BEGIN

@interface AUAmountEditTextField : UITextField

/**
 
 外部设置金额接口.请勿直接修改amountTextField.text.
 直接修改会因为没有触发change事件发生异常(字号不符或clearButton未显示)
 方法内部实现为:
 
 - (void)updateAmountText:(NSString *) amountText
 {
    self.text = amountText;
    [self sendActionsForControlEvents:UIControlEventEditingChanged];
 }
 
 @param amountText amountTextField需要设置的新金额
 
 */
- (void)updateAmountText:(NSString *) amountText;

@end


/**
 带"¥"符号和下划线的简版金额输入组件.
 输入内容字号大小会随内容长度缩放
 目前不包含输入内容的校验与预处理逻辑.业务可设置delegate自行实现.
 */
@interface AUAmountEditText : UIView

/**
    金额输入框.可按需修改属性或设置delegate.
    clear事件发生时,会调用[amountTextField sendActionsForControlEvents:UIControlEventEditingChanged]
 */
@property(nonatomic,strong) AUAmountEditTextField *amountTextField;


/**
 开放给AUAmountLabelText,用于inputText长度变化时调整字号使用.
 业务方不要使用.
 
 @param textLength inputText长度
 @return UIFont
 */
+ (UIFont *)resetFontSize:(NSUInteger) textLength;

@end

NS_ASSUME_NONNULL_END

#endif//程序自动生成
