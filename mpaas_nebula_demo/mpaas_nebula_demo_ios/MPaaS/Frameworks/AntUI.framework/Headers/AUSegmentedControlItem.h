#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Segment_AUSegment//程序自动生成
//
//  AUSegmentedControlItem.h
//  AntUI
//
//  Created by sara on 16/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUView.h"

#define kBadgeLabelReserveWidth  1

@class AUSegmentedControlItem;

@protocol AUSegmentedControlItemDelegate <NSObject>

- (void) ausegmentedControlItemClicked:(AUSegmentedControlItem *)item;

@end

@interface AUBadgeLabel : AUView

@property (nonatomic, strong) UILabel *titleLabel;

@end

@interface AUSegmentedControlItem : UIView

@property (nonatomic, weak)     id <AUSegmentedControlItemDelegate> delegate;

@property (nonatomic, copy)     NSString *title;
@property (nonatomic, strong)   AUBadgeLabel *badgeLabel;
@property (nonatomic, copy)     UIFont *titleFont;
@property (nonatomic, assign,getter=isSelected)   BOOL selected;
@property (nonatomic, copy)     UIColor *selectedColor;
@property (nonatomic, assign)   NSInteger textHorizontalPadding;
@property (nonatomic, assign)   BOOL fixedWidth;
@property(nonatomic, assign)    BOOL badgeReserved; // 设置条目是否要预留红点位置，如果不预留则红点展示时界面可能有跳动感

/*
 * 10.1.60 新增支持每个iteme分别设置它的左右间距，textLeftPadding、textRightPadding设置之后则textHorizontalPadding不起作用，
 */
@property (nonatomic, assign)   CGFloat textLeftPadding;
@property (nonatomic, assign)   CGFloat textRightPadding;


- (instancetype)initWithFrame:(CGRect)frame title:(NSString*)title;
- (void)addTarget:(id)target action:(SEL)action;

@end

#endif//程序自动生成
