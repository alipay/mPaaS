#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUNListItemView.h
//  AntUI
//
//  Created by maizhelun on 2017/2/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AUNListItemViewNormalStyle) {
    AUNListItemViewNormalStyle1,
    AUNListItemViewNormalStyle2,
    AUNListItemViewNormalStyle3,
    AUNListItemViewNormalStyle4,
    AUNListItemViewNormalStyle5
};

@interface AUNNormalListItemView : UIView

#pragma mark - 禁止访问

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (void)setFrame:(CGRect)frame NS_UNAVAILABLE;

#pragma mark - 

- (instancetype)initWithWidth:(CGFloat)width displayStyle:(AUNListItemViewNormalStyle)displayStyle;

+ (CGFloat)heightForDisplayStyle:(AUNListItemViewNormalStyle)style;

@property (nonatomic, assign  ) AUNListItemViewNormalStyle     displayStyle;
@property (nonatomic, readonly) UIImageView             *iconView;
@property (nonatomic, readonly) UILabel                 *titleLabel;
@property (nonatomic, readonly) UILabel                 *descLabel;

@end

#endif//程序自动生成
