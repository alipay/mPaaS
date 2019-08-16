#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox_AUAmountInputBox//程序自动生成
//
//  AUAmountInputBox.h
//  AntUI
//
//  Created by niki on 16/12/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auamountinputbox
//#########################################################

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


/**
 带组合功能的金额输入框.
 目前支持设置title(纯文本),添加footer(纯文本/输入框)的功能.
 不包含输入内容的校验与预处理逻辑.业务可设置delegate自行实现. 
 */
@interface AUAmountInputBox : UIView

/**
 AUAmountInputBox初始化方法

 @param views @[AUAmountInputField,AUAmountInputFieldFooterView]
 @return AUAmountInputBox
 */
+ (AUAmountInputBox *)amountInputBoxWithViews:(NSArray *) views;

@end

NS_ASSUME_NONNULL_END

#endif//程序自动生成
