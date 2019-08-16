#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUActionButton//程序自动生成
//
//  AUActionButton.h
//  AntUI
//
//  Created by 莜阳 on 2018/2/8.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, AUIActionButtonStyle) {
    AUIActionButtonStyleDefault,       // 白色边框，适用于深色背景
    AUIActionButtonStyleFeature1  // 蓝色边框，适用于白色背景
};

@interface AUIActionButton : UIControl

- (instancetype)initWithStyle:(AUIActionButtonStyle)style;

- (void)setupTitle:(NSString *)title message:(NSString *)message;

@end


#endif//程序自动生成
