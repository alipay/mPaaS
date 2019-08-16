#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_checkbox_AUCheckBox//程序自动生成
//
//  APCheckBox.h
//  AlipayPortal
//
//  Created by WenBi on 12-5-29.
//  Copyright (c) 2012年 aliPay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aucheckbox
//#########################################################


#define UI_AUCheckBox

/**
 checkbox类型

 - AUCheckBoxStyleDefault:   默认样式，跟web的checkbox类似
 - AUCheckBoxStyleCheckmark: tableview的checkmark样式
 */
typedef NS_ENUM(NSInteger, AUCheckBoxStyle) {
    AUCheckBoxStyleDefault,
    AUCheckBoxStyleCheckmark
};


/**
 单选框控件
 */
@interface AUCheckBox : UIControl

/**
 根据类型初始化AUCheckBox方法

 @param style checkbox类型

 @return AUCheckBox
 */
- (instancetype)initWithStyle:(AUCheckBoxStyle)style;

/**
 是否选中属性
 */
@property(nonatomic, assign, getter = isChecked) BOOL checked;

/**
 是否disabled属性
 */
@property(nonatomic, assign, getter = isDisabled) BOOL disabled;

/**
 checkbox类型（只读，只能在初始化时候设置）
 */
@property (nonatomic, assign, readonly) AUCheckBoxStyle style;


@end

#endif//程序自动生成
