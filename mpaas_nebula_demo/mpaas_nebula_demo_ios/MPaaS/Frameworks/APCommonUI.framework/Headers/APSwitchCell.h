//
//  APSwitchCell.h
//  APCommonUI
//
//  Created by Yuanchen on 14-1-18.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APTableViewBaseCell.h"

@interface APSwitchCell : APTableViewBaseCell

/**
 *  返回cell高度
 *
 *  @return 高度值
 */
+ (float)cellHeight;

/**
 *  初始化函数,设置的Style为UITableViewCellStyleDefault
 *
 *  @param reuseIdentifier cell复用id
 *
 *  @return APSwitchCell实例
 */
- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

@property (nonatomic, readonly) UISwitch *switchControl;//UISwitch控件

@end
