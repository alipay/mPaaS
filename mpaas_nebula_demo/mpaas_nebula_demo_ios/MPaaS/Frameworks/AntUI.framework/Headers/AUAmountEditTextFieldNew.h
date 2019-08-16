#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox//程序自动生成
//
//  AUAmountEditTextFieldNew.h
//  AntUI
//
//  Created by zhaolei on 2017/8/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUAmountValidator.h"

#define kAmountEditTextFieldInnerTextChangedNotify @"kAmountEditTextFieldInnerTextChangedNotify"


/**
 带金额验证功能的的TextField,设置delegate后,delegate的shouldChangeCharactersInRange方法不会被调用,而是调用内部代理实现.delegate的其他方法不受影响.
 */
@interface AUAmountEditTextFieldNew : UITextField


/**
 外部设置输入框内容,可配置是否发送textChanged通知,以及是否对设置内容格式化.
 
 @param text 新内容
 @param notify 是否发送内容变更通知(kAmountEditTextFieldInnerTextChangedNotify)
 @param format 是否对设置内容格式化
 
 AUAmountEditTextFieldNew重写了setText实现如下:
 
 - (void)setText:(NSString *)text
 {
    [self setText:text notify:YES format:YES];
 }
 */
- (void)setText:(NSString *)text
         notify:(BOOL) notify
         format:(BOOL) format;

/**
 返回格式化后的金额.包括格式化和补零处理
 
 @return 格式化后的金额.
 */
- (NSString *)formatedAmount;

/**
 用于(formatedAmount),(setText:notify:format),(shouldChangeCharactersInRange)的内容格式化处理.
 默认值为nil,可使用默认校验器AUAmountDefaultValidator赋值:
 
 AUAmountDefaultValidator *validator = [[AUAmountDefaultValidator alloc] init];
 validator.maxNumberOfDigits = 10;//设置最大位数
 textField.validator = validator;//设置校验器
 */
@property (nonatomic, strong) id<AUAmountValidatorProtocol> validator;

@end

#endif//程序自动生成
