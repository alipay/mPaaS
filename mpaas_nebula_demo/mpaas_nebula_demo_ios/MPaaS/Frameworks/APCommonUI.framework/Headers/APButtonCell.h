//
//  APButtonCell.h
//  APCommonUI
//
//  Created by WenBi on 14-2-1.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "APButton.h"

@interface APButtonCell : UITableViewCell

/**
 *  添加button
 *
 *  @param button 需要添加的button
 */
- (void)addButton:(APButton *)button;

/**
 *  用于cell中的点击button场景
 *
 *  @param buttonType button类型
 *  @param title      button的文本
 *  @param target     控制button的对象
 *  @param action     点击button触发的事件
 *
 *  @return 
 */
- (APButton *)addButtonWithType:(APButtonType)buttonType title:(NSString *)title target:(id)target action:(SEL)action;

/**
 *  返回cell的高度
 *
 *  @return 返回cell的高度
 */
+ (CGFloat)cellBtnHeight;

@end
