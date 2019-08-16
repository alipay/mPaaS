#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUNListItemWithExtraLabelView.h
//  AntUI
//
//  Created by maizhelun on 2017/2/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNListItemContainerView.h"
#import "AUNNormalListItemView.h"
#import "AUNCssItemView.h"

@interface AUNListItemView : UIView

@property (nonatomic, readonly) UIImageView             *iconView;
@property (nonatomic, readonly) UILabel                 *titleLabel;
@property (nonatomic, readonly) UILabel                 *descLabel;
@property (nonatomic, readonly) UILabel                 *extraLabel;

- (instancetype)initWithWidth:(CGFloat)width andCss:(NSString *)css;
- (instancetype)initWithCss:(NSString *)css;

+ (CGFloat)heightForCss:(NSString *)css;


#pragma mark - 禁止访问
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (void)setFrame:(CGRect)frame NS_UNAVAILABLE;

@end

//
@interface AUNListItemView ()

@property (nonatomic, strong) AUNCssItemView *cssView;

@property (nonatomic, readonly) AUNNormalListItemView *normalListItemView;
@property (nonatomic, readonly) AUNListItemContainerView *containerView;

@end

#endif//程序自动生成
