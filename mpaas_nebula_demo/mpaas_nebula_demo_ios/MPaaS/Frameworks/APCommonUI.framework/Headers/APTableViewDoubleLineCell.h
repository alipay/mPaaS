//
//  APTableViewDoubleLineCell.h
//  APCommonUI
//
//  Created by 紫空 on 14-1-18.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APTableViewCell.h"

@interface APTableViewDoubleLineCell : APTableViewCell

@property(nonatomic, assign) CGFloat imageSize;                         //图片大小，不设置会使用默认值45
@property (nonatomic) UIEdgeInsets imageEdgeInsets;                     //设置左侧图片edgeinset
@property (nonatomic) UIEdgeInsets textLabelEdgeInsets;                 //设置左侧主标题edgeinset
@property (nonatomic) UIEdgeInsets detailTextLabelEdgeInsets;           //设置左侧副标题edgeinset
@property(nonatomic, strong) UILabel *cellRightTitle;                   //右侧主提示信息
@property(nonatomic, strong) UILabel *cellRightDetailTitle;             //右侧副提示信息
@property(nonatomic, strong) UIImageView *cellRightInfoImg;             //右侧副提示图标，位置同右侧副提示信息

/**
 *  APTableViewDoubleLineCell初始化函数，设置的Style为UITableViewCellStyleSubtitle
 *  推荐使用该接口初始化
 *
 *  @param reuseIdentifier 重用标记
 *
 *  @return 返回初始化的实例
 */
- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

/**
 *  返回cell的默认高度
 *
 *  @return cell的高度
 */
+ (float)cellHeight;

/**
 *  cell的重置
 */
- (void)reset;

/**
 * 设置右侧主标题cellRightTitle
 */
- (void)setRightTitle:(NSString* )title;

/**
 * 设置右侧副标题cellRightDetailTitle
 */
- (void)setRightDetaileTitle:(NSString* )title;

/**
 * 设置右侧提示图标cellRightInfoImg，位置同右侧副标题，提示信息和提示图标同时只能设一个
 */
- (void)setRightInfoImg:(UIImage *)img;


@end