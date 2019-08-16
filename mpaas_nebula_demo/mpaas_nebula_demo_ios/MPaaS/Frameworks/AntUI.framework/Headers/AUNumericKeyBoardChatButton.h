#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyBoardChatButton.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNumKeyboardsDefs.h"

@interface AUNumericKeyBoardBaseChatButton : UIButton
@property (nonatomic, copy) AUNumericKeyboardButtonPressBlock pressBlock;
@property (nonatomic, copy) AUNumericKeyboardButtonHighLightStyleBlock highLightStyleBlock;
@property (nonatomic, assign) BOOL hidePressLightStyle;
+(AUNumericKeyBoardBaseChatButton *) buttonWithType:(UIButtonType)type mode:(AUNumKeyboardMode) mode;

@end

@interface AUNumericKeyBoardChatButton : AUNumericKeyBoardBaseChatButton
@end

//只针对0和清除按钮
@interface AUNumericKeyBoardPerformChatButton : AUNumericKeyBoardBaseChatButton
@end

//@interface AUNumericKeyBoardChatView : UIView
//@end

#endif//程序自动生成
