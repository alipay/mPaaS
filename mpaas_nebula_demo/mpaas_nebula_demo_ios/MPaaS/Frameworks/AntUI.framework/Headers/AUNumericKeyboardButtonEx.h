#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardButtonEx.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNumKeyboardsDefs.h"

@interface UIButton (Info)
@property (nonatomic, copy) NSString *info;
@end


@interface AUNumericKeyboardButtonBase : UIView
{
    AUNumericKeyboardKeyExInfo _info;
    
@public
    UIButton *_button;
    bool _tapEnabel;
}

@property (nonatomic, assign) AUNumericKeyboardKeyExInfo info;

- (id)initWithInfo:(AUNumericKeyboardKeyExInfo)info;
//派生类主要实现这个完成自定义画按键
- (void)customInit;
- (void)free;
- (void)enableTap:(bool)flag;
- (float)lineSize;
- (UIColor *) lineColor;

////重新布局
//- (void)resetLayout;
//- (void)resetLayout:(CGRect)rect;

@end


@interface AUNumericKeyboardButtonNumber : AUNumericKeyboardButtonBase
//记录初始化的时候的位置
@property (nonatomic, assign) CGRect originalRect;
//变形位置1
@property (nonatomic, assign) CGRect deformationRect1;
//变形位置2
@property (nonatomic, assign) CGRect deformationRect2;
//变形位置3
@property (nonatomic, assign) CGRect deformationRect3;

- (void)customInit;
@end

@interface AUNumericKeyboardButtonBackspace : AUNumericKeyboardButtonBase
- (void)customInit;
@end

@interface AUNumericKeyboardButtonReturn : AUNumericKeyboardButtonBase
@property (nonatomic, strong) NSString *submitText;
- (void)customInit;
- (void)enableTap:(bool)flag;
@end

@interface AUNumericKeyboardButtonDismiss : AUNumericKeyboardButtonBase
//记录初始化的时候的位置
// @property (nonatomic, assign) CGRect originalRect;
//变形位置1
// @property (nonatomic, assign) CGRect deformationRect1;
//变形位置2
// @property (nonatomic, assign) CGRect deformationRect2;

- (void)customInit;
@end

#endif//程序自动生成
