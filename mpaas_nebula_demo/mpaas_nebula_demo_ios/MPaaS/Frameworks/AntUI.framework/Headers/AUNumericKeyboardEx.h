#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardEx.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUNumericKeyboardBase.h"

@interface AUNumericKeyboardEx : AUNumericKeyboardBase


//手动设置textinput，外部需要设置keyboard的y轴
@property (nonatomic, weak) id<UITextInput> textInput;
//身份证x
@property (nonatomic, assign) BOOL idNumber;
@property (nonatomic, assign) BOOL dotHidden;
@property (nonatomic, assign) BOOL dismissHidden;

@property (nonatomic, strong) NSString *submitText;  //提交按钮文案

- (NSArray *) keyPosArrayDefs;

- (AUNumericKeyboardKeyExInfo)getButtonInfoWithKeyIndex:(int)index keyPos:(NSInteger)keyPos;

@end

#endif//程序自动生成
