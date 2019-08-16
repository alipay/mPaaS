#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopMenu_AUPopMenu//程序自动生成
//
//  AUPopItemView.h
//  AntUI
//
//  Created by niki on 2017/6/14.
//  Copyright © 2017年 Alipay. All rights reserved.


#import "AUPopItemBaseView.h"
#import "AUIconView.h"

@class AUPopItemModel;

@interface AUPopItemView : AUPopItemBaseView

@property (nonatomic, strong) AUIconView *iconView;     // 支持iconfont图标
@property (nonatomic, strong) UIView *badgeView;     // 红点支持

- (instancetype)initWithModel:(AUPopItemModel *)model position:(CGPoint )position;

+ (CGFloat) leftRightMargin;

- (CGSize)updateModel:(AUPopItemModel *)model;

@end

// 对象模型
@interface AUPopItemModel : NSObject

@property (nonatomic, strong) NSString *titleString;    // 主文案描述
@property (nonatomic, strong) id iconImage;             // 左侧icon，可以传UIImage 对象或者 URL
@property(nonatomic, copy) NSString *badgeNumber;       // 红点设置
@property(nonatomic, copy) NSString *badgeWidgetId;     // 红点id

@end

#endif//程序自动生成
