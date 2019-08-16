#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUNListItemContainerView.h
//  AntUI
//
//  Created by maizhelun on 2017/2/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNListItemSepratorLine.h"
#import "AUListLeftAccessorViewProtocol.h"


@interface AUNListItemContainerView : UIView <AUListItemLeftAccessorViewProtocol>

/**
 内容区视图，外部设置（通常为AUNCssItemView实例）
 */
@property (nonatomic, strong) UIView *contentView;

-(void) prepareForReuse;

#pragma mark - 左边扩展区域

/**
 左边扩展区域类型
 */
@property (nonatomic, assign) AUListItemLeftAccessorType leftAccessorType;

/**
 左边扩展区域（默认距离左边和内容区为16像素, 默认size为cell高度-上下边距16）
 */
@property (nonatomic, strong) UIView *leftAccessorView;


/**
 设置左边扩展区域的margin，top和bottom暂不支持，强制居中
 */
- (void)leftAccessorView_setMargin:(UIEdgeInsets)margin;

/**
 右边扩展区域类型
 */
@property (nonatomic, assign) AUListItemRightAccessorType rightAccessorType;

/**
 右扩展区域（默认距离左边和内容区为16像素, 默认size最大为cell高度-上下边距16）
 */
@property (nonatomic, strong) UIView *rightAccessorView;

/**
 设置左边扩展区域的margin，top和bottom暂不支持，强制居中
 */
- (void)rightAccessorView_setMargin:(UIEdgeInsets)margin;


#pragma mark - 红点控件
/**
 红点View MPBadgeView
 */
@property (nonatomic, strong) UIView *badgeView;

/**
 红点View距离右边的间距
 */
@property (nonatomic, assign) CGFloat badgeMargin;

/**
 *  如果设置了widgetId，就不需要设置badgeNumber
 */
@property (nonatomic, strong) NSString *badgeNumber;

/**
 *  红点显示的widgetId
 */
@property (nonatomic, copy) NSString *badgeWidgetId;

/**
 红点显示位置
 */
@property (nonatomic, assign) AUListItemBadgeAreaType badgeAreaType;

/**
 设置新红点的展示
 */
@property (nonatomic, strong) NSString *badgeValue;


/**
 * 设置老红点SDK的WidgetId 或 固定的气泡样式
 * 如果能从红点SDK优先级高于badgeValue
 */
-(void) updateBadgeWidgetId:(NSString *) widgetId badgeNumber:(NSString*)badgeNumber;


@end

#endif//程序自动生成
