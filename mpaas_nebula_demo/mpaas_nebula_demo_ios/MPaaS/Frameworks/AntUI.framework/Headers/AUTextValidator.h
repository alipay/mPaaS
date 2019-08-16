#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields//程序自动生成
//
//  AUTextValidator.h
//  AntUI
//
//  Created by QiXin on 2016/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 文本有效性验证器。
 */
@interface AUTextValidator : NSObject

/**
 *  Creates and returns a new validator that checks the validity of amount.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)amountValidator;

/**
 *  Creates and returns a new validator used for checking the validity of mobile number.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)mobileNumberValidator;

/**
 *  Creates and returns a new validator that checks the validity of bank card number.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)bankCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of cridit card number.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)creditCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of ID card.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)IDCardValidator;

/**
 *  Creates and returns a new validator that checks the validity of alipay account.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)alipayAccountValidator;

/**
 *  Creates and returns a new validator that checks string is empty or not.
 *
 *  @return A newly created validator.
 */
+ (AUTextValidator *)notEmptyValidator;

/**
 *  Checks the validity of specified text.
 *
 *  @param text The text to be check.
 *
 *  @return <code>YES</code if the specified text is valid, otherwise <code>NO</code>.
 */
- (BOOL)checkText:(NSString *)text;

@end

#endif//程序自动生成
