//
//  APNumericKeyboardEx.h
//  APCommonUI
//
//  Created by majie on 14-11-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUNumericKeyboardEx.H>

__deprecated_msg("APNumericKeyboardEx 已废弃，请直接使用 AUNumericKeyboardEx")
@interface APNumericKeyboardEx : AUNumericKeyboardEx

//手动设置textinput，外部需要设置keyboard的y轴
//@property (nonatomic, weak) id<UITextInput> textInput;
////身份证x
//@property (nonatomic, assign) BOOL idNumber;
//
//@property (nonatomic, assign) BOOL dotHidden;
//@property (nonatomic, assign) BOOL dismissHidden;
//@property (nonatomic, assign) BOOL submitEnable;
//@property (nonatomic, strong) NSString *submitText;  //提交按钮文案
@end
