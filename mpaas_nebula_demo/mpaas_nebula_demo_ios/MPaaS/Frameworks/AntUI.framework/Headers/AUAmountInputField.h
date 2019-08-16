#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_Deprecated//程序自动生成
//
//  AUAmountInputField.h
//  AntUI
//
//  Created by niki on 16/12/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUAmountEditText.h"

NS_ASSUME_NONNULL_BEGIN


/**
 基于AUAmountEditText的组合扩展.目前支持设置title.
 */
@interface AUAmountInputField : UIView

@property (nonatomic, strong,readonly) UILabel *amountTitleLabel;
@property (nonatomic, strong,readonly) AUAmountEditText *amountEditText;// 资金输入框
/**
 外部设置金额请使用 [self.textField updateAmountText:@"123"] 的方式
 切勿直接修改self.textField.text.
 直接修改会因为没有触发change事件发生异常(字号不符或clearButton未显示)
 */
- (AUAmountEditTextField *)textField;

+ (AUAmountInputField *)amountInputWithTitle:(NSString *) title;

@end

NS_ASSUME_NONNULL_END

#endif//程序自动生成
