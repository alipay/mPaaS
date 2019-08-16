#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardBase.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNumKeyboardsDefs.h"


@interface AUNumericKeyboardBase : UIView
{
@protected
    CGFloat _keyboardHeight;
    NSInteger _keyboardKeyCount;
    CGFloat _numericButtonLayoutWidth;
    CGFloat _numericButtonLayoutHeight;
    CGFloat _keyLineCount;
    
    BOOL _enableRandomKeyShowOrder; // 是否支持乱序键盘
    NSArray *_fixPosKeyArray;  // 固定位置的键值

    // 真正布局的内容区
    UIView *_contentView;
    UIColor *_sepratorLineColor;
    UIView *_toolBarView;
    
    @package
    // 键盘的输入目标
    __weak id<UITextInput> _input;
}

@property (nonatomic, strong) NSMutableArray *buttons;
@property (nonatomic, assign) BOOL submitEnable;
@property (nonatomic, assign) AUNumKeyboardMode mode;

-(id) initWithMode:(AUNumKeyboardMode)mode;
//初始化数据成员
- (void)configurerMembers;
//构造所有按钮键
- (void)createButtons;
//创建工具条
- (UIView *)createToolBarView;

/**
 键盘乱序
 注意：每调用一次，都会乱序重排一次（目前只支持 0 ~ 9）
 
 @param random YES，乱序一次；NO，不乱序
 */
- (void)setNumKeyRandom:(BOOL)random;

- (void)reloadKeyBoard;

@end

#endif//程序自动生成
