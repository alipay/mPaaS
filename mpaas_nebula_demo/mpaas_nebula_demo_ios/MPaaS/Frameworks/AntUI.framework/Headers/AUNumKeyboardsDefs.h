#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumKeyboardsDefs.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef AUNumKeyboardsDefs_h
#define AUNumKeyboardsDefs_h

typedef void(^AUNumericKeyboardButtonPressBlock) ();
typedef void(^AUNumericKeyboardButtonBlock) (UIView *sender, int keyCode);

typedef void(^AUNumericKeyboardButtonHighLightStyleBlock) (UIButton *button,BOOL isHighLight);


typedef NS_ENUM(NSInteger, AUNumKeyboardMode) {
    AUNumKeyboardModeCommon,  //通用键盘
    AUNumKeyboardModeChat,    //聊天键盘
    AUNumKeyboardModePhone,      //电话号码键盘
    AUNumKeyboardModeInvalid,  //无效键盘，目前不可用
    AUNumKeyboardModeTinyAppNumber, //小程序需要的数字键盘
    AUNumKeyboardModeTinyAppPhone, //小程序需要的电话键盘
    
    APNumericKeyboardModeCommon  __attribute__((deprecated))    = AUNumKeyboardModeCommon,  //通用键盘
    APNumericKeyboardModeChat    __attribute__((deprecated))    = AUNumKeyboardModeChat,    //聊天键盘
    APNumericKeyboardModeInvalid __attribute__((deprecated))    = AUNumKeyboardModeInvalid //无效键盘，目前不可用
};


typedef enum {
    AUNumericKeyboardButtonNumber1         = 0,
    AUNumericKeyboardButtonBackspace1,
    AUNumericKeyboardButtonReturn1,
    AUNumericKeyboardButtonDismiss1,
    AUNumericKeyboardButtonBlank1,
    AUNumericKeyboardButtonInvalid,
    AUNumericKeyboardButtonFlex ,// "-",".","X" 三取一
    
    APNumericKeyboardButtonNumber1      __attribute__((deprecated))  = AUNumericKeyboardButtonNumber1, //0,
    APNumericKeyboardButtonBackspace1   __attribute__((deprecated)) = AUNumericKeyboardButtonBackspace1,
    APNumericKeyboardButtonReturn1      __attribute__((deprecated)) = AUNumericKeyboardButtonReturn1,
    APNumericKeyboardButtonDismiss1     __attribute__((deprecated)) = AUNumericKeyboardButtonDismiss1,
    APNumericKeyboardButtonBlank1       __attribute__((deprecated)) = AUNumericKeyboardButtonBlank1,
    
    APNumericKeyboardButtonInvalid      __attribute__((deprecated)) = AUNumericKeyboardButtonInvalid
    
} AUNumericKeyboardButtonType;


typedef enum {
    AUNumericKeyboardButtonKeyCode0         = '0',
    AUNumericKeyboardButtonKeyCode1         = '1',
    AUNumericKeyboardButtonKeyCode2         = '2',
    AUNumericKeyboardButtonKeyCode3         = '3',
    AUNumericKeyboardButtonKeyCode4         = '4',
    AUNumericKeyboardButtonKeyCode5         = '5',
    AUNumericKeyboardButtonKeyCode6         = '6',
    AUNumericKeyboardButtonKeyCode7         = '7',
    AUNumericKeyboardButtonKeyCode8         = '8',
    AUNumericKeyboardButtonKeyCode9         = '9',
    AUNumericKeyboardButtonKeyCodeRadix     = '.',
    AUNumericKeyboardButtonKeyCodeX         = 'X',
    AUNumericKeyboardButtonKeyCodeP         = '-',
    
    
    AUNumericKeyboardButtonKeyCodeBackspace = 10,
    AUNumericKeyboardButtonKeyCodeReturn    = 11,
    AUNumericKeyboardButtonKeyCodeDismiss   = 12,
    AUNumericKeyboardButtonKeyCodeBlank     = 13,
    
    AUNumericKeyboardButtonKeyCodeInvalid   = -1,
    
    APNumericKeyboardButtonKeyCode0    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode0,
    APNumericKeyboardButtonKeyCode1    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode1,
    APNumericKeyboardButtonKeyCode2    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode2,
    APNumericKeyboardButtonKeyCode3    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode3,
    APNumericKeyboardButtonKeyCode4    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode4,
    APNumericKeyboardButtonKeyCode5    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode5,
    APNumericKeyboardButtonKeyCode6    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode6,
    APNumericKeyboardButtonKeyCode7    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode7,
    APNumericKeyboardButtonKeyCode8    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode8,
    APNumericKeyboardButtonKeyCode9    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode9,
    APNumericKeyboardButtonKeyCodeRadix  __attribute__((deprecated))   = AUNumericKeyboardButtonKeyCodeRadix,
    APNumericKeyboardButtonKeyCodeX      __attribute__((deprecated))   = AUNumericKeyboardButtonKeyCodeX,
    
    
    APNumericKeyboardButtonKeyCodeBackspace __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeBackspace,
    APNumericKeyboardButtonKeyCodeReturn    __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeReturn,
    APNumericKeyboardButtonKeyCodeDismiss   __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeDismiss,
    APNumericKeyboardButtonKeyCodeBlank     __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeBlank,
    
    APNumericKeyboardButtonKeyCodeInvalid   __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeInvalid
    
} AUNumericKeyboardButtonKeyCodeType;



// 存储每个键盘按钮信息的结构
typedef struct {
    int keyCode;
    CGRect	frame;
    AUNumericKeyboardButtonType keyType;
    BOOL hidePressLightStyle;
    AUNumKeyboardMode mode;
    NSInteger position;
} AUNumericKeyboardKeyExInfo;



#endif /* AUNumKeyboardsDefs_h */

#endif//程序自动生成
