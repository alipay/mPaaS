#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox//程序自动生成
//
//  AUAmountValidator.h
//  AntUI
//
//  Created by zhaolei on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AUAmountValidatorProtocol <NSObject>

@optional
- (BOOL)checkNumberOfDigits:(NSString *) amount;

- (NSString *)formatAmount:(NSString *) amount;

@end

@interface AUAmountDefaultValidator : NSObject <AUAmountValidatorProtocol>

//用于输入位数校验(包括小数点,amount.length < = maxNumberOfDigits则合法),默认NSUIntegerMax
@property (nonatomic, assign) NSUInteger maxNumberOfDigits;

@end

#endif//程序自动生成
