//
//  APInputBox.h
//  APCommonUI
//
//  Created by yang.zy on 14-1-17.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUInputBox.h>

@class APTextField;
@class APButton;
@class APVisualStyle;
@class UITextField;
@class UIButton;

__deprecated_msg("APInputBoxType 已经废弃，请直接使用 AUInputBoxType")
typedef AUInputBoxType APInputBoxType;


__deprecated_msg("APInputBoxStyle 已经废弃，请直接使用 AUInputBoxStyle")
typedef AUInputBoxStyle APInputBoxStyle;

__deprecated_msg("APInputBox 已废弃，请直接使用 AUInputBox")
@interface APInputBox : AUInputBox

@end
