//
//  APNumericKeyboard.h
//  2014117
//
//  Created by yang.zy on 14-1-22.
//  Copyright (c) 2014年 yang.zy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUNumKeyboards.h>

__deprecated_msg("APNumericKeyboardMode已经废弃，请尽快替换 AUNumKeyboardMode")
typedef AUNumKeyboardMode APNumericKeyboardMode;

__deprecated_msg("APNumericKeyboard 已经废弃，请直接使用 AUNumKeyboards")
@interface APNumericKeyboard : AUNumKeyboards //UIView

@end
