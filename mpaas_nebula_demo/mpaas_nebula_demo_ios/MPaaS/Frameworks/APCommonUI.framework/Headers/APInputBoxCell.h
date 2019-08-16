//
//  APInputBoxCell.h
//  APCommonUI
//
//  Created by Yuanchen on 14-1-17.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APTableViewCell.h"

@class APInputBox;

@interface APInputBoxCell : APTableViewCell

/**
 *  返回cell的默认高度，默认45
 *
 *  @return cell的高度
 */
+ (float)cellHeight;

/**
 *  返回cell中输入框
 *
 *  @return 输入框
 */
- (APInputBox *)textFieldInCell;

@end
