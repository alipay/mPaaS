#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_AUAmountInputBox//程序自动生成
//
//  AUAmountInputFieldNew.h
//  AntUI
//
//  Created by niki on 16/12/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUAmountInputFieldNew.h"

NS_ASSUME_NONNULL_BEGIN

/**
 基于AUAmountEditTextNew的组合扩展.目前支持设置title.
 */
@interface AUAmountInputFieldNew : UIView

- (AUAmountEditTextFieldNew *)textField;// 资金输入框
- (UILabel *)titleLabel;

//title设置为AUAmountInputFieldNew.titleLabel.text
+ (AUAmountInputFieldNew *)amountInputWithTitle:(NSString *) title;

@end

NS_ASSUME_NONNULL_END
#endif//程序自动生成
