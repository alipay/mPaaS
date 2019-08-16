#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUCheckBoxListItem//程序自动生成
//
//  AUCheckBoxListItem.h
//  AntUI
//
//  Created by sara on 16/10/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBaseListItem.h"

@class AUCheckBoxListItem;
@class AUCheckBox;

@protocol AUCheckBoxListItemDelegate <NSObject>

/**
 checkbox状态变化，给外部的回调

 @param item checkbox实例
 */
- (void)checkboxValueDidChanged:(AUCheckBox *)item;//item的tag取的是cell的tag

@end

@interface AUCheckBoxListItem : AUBaseListItem<AUCheckBoxListItemModelDelegate>

@property(nonatomic, assign, getter = isChecked) BOOL checked;//设置checkbox勾选状态
@property(nonatomic, assign, getter = isDisableCheck) BOOL disableCheck;//是否禁用checkbox
@property(nonatomic, weak) id <AUCheckBoxListItemDelegate> delegate;


@end

#endif//程序自动生成
