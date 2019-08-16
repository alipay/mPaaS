//
//  APNumericKeyboardDef.h
//  APCommonUI
//
//  Created by majie on 14-11-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


#import <AntUI/AUNumKeyboardsDefs.h>


#ifndef APCommonUI_APNumericKeyboardDef_h
#define APCommonUI_APNumericKeyboardDef_h

//typedef void(^APNumericKeyboardButtonPressBlock) ();
//typedef void(^APNumericKeyboardButtonBlock) (UIView *sender, int keyCode);

__deprecated_msg("APNumericKeyboardButtonPressBlock 已经废弃，请直接使用 AUNumericKeyboardButtonPressBlock")
typedef AUNumericKeyboardButtonPressBlock APNumericKeyboardButtonPressBlock;

__deprecated_msg("APNumericKeyboardButtonBlock 已经废弃，请直接使用 AUNumericKeyboardButtonBlock")
typedef AUNumericKeyboardButtonBlock APNumericKeyboardButtonBlock;

__deprecated_msg("APNumericKeyboardButtonType 已经废弃，请直接使用 AUNumericKeyboardButtonType")
typedef AUNumericKeyboardButtonType APNumericKeyboardButtonType;

__deprecated_msg("APNumericKeyboardButtonKeyCodeType 已经废弃，请直接使用 AUNumericKeyboardButtonKeyCodeType")
typedef AUNumericKeyboardButtonKeyCodeType APNumericKeyboardButtonKeyCodeType;

__deprecated_msg("APNumericKeyboardKeyExInfo 已经废弃，请直接使用 AUNumericKeyboardKeyExInfo")
typedef AUNumericKeyboardKeyExInfo APNumericKeyboardKeyExInfo;
// 存储每个键盘按钮信息的结构
//typedef struct {
//    int keyCode;
//    CGRect	frame;
//    APNumericKeyboardButtonType keyType;
//} APNumericKeyboardKeyExInfo;



//#define DEVICE_IS_IPHONE4 ([[UIScreen mainScreen] bounds].size.height == 480)
//#define DEVICE_IS_IPHONE5 ([[UIScreen mainScreen] bounds].size.height == 568)
//#define DEVICE_IS_IPHONE6 ([[UIScreen mainScreen] bounds].size.height == 667)
//#define DEVICE_IS_IPHONE6Pluc ([[UIScreen mainScreen] bounds].size.height == 736)
//
//#define APNumericKeyboardLineSize() \
//        if (DEVICE_IS_IPHONE6Pluc) {\
//            return 1.1 / 3;         \
//        }                           \
//        return 1. / 2;              \

#endif
