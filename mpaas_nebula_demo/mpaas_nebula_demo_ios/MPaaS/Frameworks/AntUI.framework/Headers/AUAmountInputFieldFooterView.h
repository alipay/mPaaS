#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_AUAmountInputBox//程序自动生成
//
//  AUAmountInputFieldFooterView.h
//  AntUI
//
//  Created by niki on 16/12/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUTextField.h"

NS_ASSUME_NONNULL_BEGIN

@interface AUAmountInputFieldFooterView : UIView

@property (nonatomic, strong) UITextField * inputTextField;
@property (nonatomic, strong) UILabel * descTextLabel;

+ (AUAmountInputFieldFooterView *)footerWithInput:(nullable NSString *)placeholder;
+ (AUAmountInputFieldFooterView *)footerWithDesc:(nullable NSString *)text;

@end

NS_ASSUME_NONNULL_END

#endif//程序自动生成
