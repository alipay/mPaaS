//
//  APTableViewCell.h
//  APCommonUI
//
//  Created by WenBi on 13-12-5.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APTableViewCellStyle) {
    /** Simple cell with text label and optional image view. */
    APTableViewCellStyleSimple,
    APTableViewCellStyleSubtitle = UITableViewCellStyleSubtitle,
};

@interface APTableViewCell : UITableViewCell

@property(nonatomic) UIEdgeInsets contentInset;//Add additional padding area around content

/**
 *  初始化
 *
 *  @param style           cell的风格
 *  @param reuseIdentifier cell重用ID
 *
 *  @return APTableViewCell
 */
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier;



/**
 *  设置cell右侧间距，也就是ContentView和最右侧的距离
 *  默认为0
 *
 *  @return 右侧间距值
 */
- (CGFloat )contentViewRightGap;

@end
