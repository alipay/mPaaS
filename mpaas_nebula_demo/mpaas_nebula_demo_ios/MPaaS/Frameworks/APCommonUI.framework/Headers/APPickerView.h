//
//  ALPPicketView.h
//  TestCell
//
//  Created by zhiyuan.yzy on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUDatePicker.h>

__deprecated_msg("APPickerDelegate 已废弃，请直接使用 AUDatePickerDelegate ")
@protocol APPickerDelegate <AUDatePickerDelegate>

@end

__deprecated_msg("APPickerView 已废弃，请直接使用 AUDatePicker ")
@interface APPickerView : AUDatePicker //UIView

@end
