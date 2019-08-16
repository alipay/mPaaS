#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUBaseListItem.h
//  AntUI
//
//  Created by sara on 16/9/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUListItemModel.h"
#import "AUListItemProtocols.h"
#import "TTTAttributedLabel.h"
#import "AUListSeparatorLine.h"
#import "AUScalingModel.h"

#import "AUListLeftAccessorViewProtocol.h"

@interface AUBaseListItem : UITableViewCell <AUListItemLeftAccessorViewProtocol>
{
    AUScalingModel *_scalingModel;
}

@property(nonatomic, strong) UILabel *titleLabel;     // 标题
@property(nonatomic, strong) TTTAttributedLabel *attributelabel;    // 富文本样式，目前主要支持副标题的富文本样式
@property(nonatomic, strong) AUListSeparatorLine *topLine; // 顶部分割线
@property(nonatomic, strong) AUListSeparatorLine *bottomLine; // 底部分割线
@property(nonatomic, copy) NSIndexPath *curIndexPath;
@property(nonatomic, weak) UITableView *curTableView;

/**
 返回默认的cell高度
 @return             返回默认的cell高度
 */
+ (CGFloat)cellHeight;

#pragma mark - 设置AntUI默认分割线
//- (void)setupSeparatorAtIndexPath:(NSIndexPath *)indexPath __deprecated_msg("废弃，业务请勿继续使用");

//
- (void)setupSeparatorAtIndexPath:(NSIndexPath *)indexPath tableView:(UITableView *)tableView;

#pragma mark - 左边扩展区域

// 左边的扩展区域，可以通过设置leftAccessorType和leftAccessorView来展示
// 设置了leftAccessorType，可以获取leftAccessorType对应的leftAccessorView
@property (nonatomic, assign) AUListItemLeftAccessorType leftAccessorType;

@property (nonatomic, strong) UIView *leftAccessorView;

/**
 右边扩展区域类型
 */
@property (nonatomic, assign) AUListItemRightAccessorType rightAccessorType;

/**
 右扩展区域（默认距离左边和内容区为16像素, 默认size最大为cell高度-上下边距16）
 */
@property (nonatomic, strong) UIView *rightAccessorView;

#pragma mark - 红点

/**
 红点显示位置
 */
@property (nonatomic, assign) AUListItemBadgeAreaType badgeAreaType;

/**
 设置红点
 注意：此方法的widgetId不生效，由于影响面的原因也修改
 如果要生效，请使用setBadgeViewV2:badgeNumber:方法
 @param wedgetId 红点的wedgetId
 @param badgeNumber @"."   显示红点
 @"new" 显示new
 @"数字" 显示数字，大于99都显示图片more（...）
 @"惠"/"hui"  显示“惠”字
 @"xin" 显示"新"字
 nil    清除当前显示
 */
- (void)setBadgeView:(NSString *)wedgetId badgeNumber:(NSString *)badgeNumber;


- (void)setBadgeViewV2:(NSString *)widgetId badgeNumber:(NSString *)badgeNumber;

/**
 * 红点上报
 */
- (void)reportBadgeClick;
/**
 * 设置新红点控件样式
 * @see AUBadgeView
 * 使用 AUBadgeViewStyleText 进行渲染。
 */
-(void) setBadgeValue:(NSString *)badgeView;


// list支持右边展示按钮，这里按钮是直接展示在cell的accessoryView
- (void)setupActionButton:(NSString *)title actionBlock:(AUButtonBlock)block;


- (void)setupActionButton:(NSString *)title btnStyle:(void(^)(UIButton *btn))styleBlock actionBlock:(AUButtonBlock)block;
@end

/**
 
 业务方一般调用AUBaseListItem子类的【initWithReuseIdentifier:model:】方法即可满足需求
 
 这里提供单独的 针对title等参数方法
 除title外，都放在子类实现，访问隔断
 
 */
@interface AUBaseListItem (Extensions)

/**
 设置主标题
 
 @param title 主标题字符串
 */
- (void)setTitle:(NSString* )title __deprecated_msg("废弃，业务请勿继续使用");

/**
 主标题get方法
 
 @return 返回主标题字符串
 */
- (NSString*)title ;

/**
 设置展示勾勾（目前实现是系统的accessoryType = UITableViewCellAccessoryCheckmark）
 */
- (void)setShowMark:(BOOL)showMark;

/**
 当前cell是否有展示checkmark
 
 @return 返回当前cell是否有展示checkmark
 
 */
- (BOOL)showMark;

/**
 设置展示箭头（目前实现是系统的accessoryType = UITableViewCellAccessoryDisclosureIndicator）
 
 @param showAccessory 是否设置展示箭头
 */
- (void)setShowAccessory:(BOOL)showAccessory;

/**
 当前cell是否有展示箭头
 
 @return 返回 当前cell是否有展示箭头
 */
- (BOOL)showAccessory;

/* 子cell中绘制自定义分割线
 */
- (void)layoutSeparatorOriginX:(CGFloat)startX;

@end

/**
 * 支持放大
 * https://yuque.antfin-inc.com/antui/auidoc/bhgnov#p468qb
 */
@interface AUBaseListItem (ScalingSupport)

/**
 *
 *
 *
 */
-(void) setListItemScaling:(AUScalingModel *) scalingValue;

@end
#endif//程序自动生成
