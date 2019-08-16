#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardExTask.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUNumericKeyboardEx.h"

@class AUNumericKeyboardButtonTaskBase;
@interface AUNumericKeyboardExTask : AUNumericKeyboardEx

//整块键盘背景色
-(UIColor *)backgroundColorForKeyBoard;

//分割色颜色
-(UIColor *)sepratorLineColor;

-(void) updateButtonStyle:(AUNumericKeyboardButtonTaskBase *)button;

@end

@interface AUNumericKeyboardExPhone : AUNumericKeyboardEx

@end

#endif//程序自动生成
