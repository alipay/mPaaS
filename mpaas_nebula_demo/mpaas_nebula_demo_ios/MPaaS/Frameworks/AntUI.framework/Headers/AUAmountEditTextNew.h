#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_SimpleAmountInput//程序自动生成
//
//  AUSimpleAmountInputField.h
//  AntUI
//
//  Created by zhaolei on 2017/6/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUAmountEditTextFieldNew.h"

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auamountedittext
//#########################################################


NS_ASSUME_NONNULL_BEGIN

/**
 带"¥"符号和下划线的简版金额输入组件.输入内容字号大小会随内容长度缩放
 */
@interface AUAmountEditTextNew : UIView

/**
 amountTextField.setText时,会进行格式化处理(长度以及非法字符)
 提供delegate.shouldChangeCharactersInRange的代理实现,会对输入内容做长度校验与格式化处理.
 业务方可以自定义delegate.shouldChangeCharactersInRange来覆盖默认实现.
 */
@property (nonatomic,strong) AUAmountEditTextFieldNew *amountTextField;

/**
 开放给AUAmountLabelText,用于inputText长度变化时调整字号使用.
 业务方不要使用.
 
 @param textLength inputText长度
 @return UIFont
 */
+ (UIFont *)resetFontSize:(NSUInteger) textLength;

@end

NS_ASSUME_NONNULL_END

#endif//程序自动生成
