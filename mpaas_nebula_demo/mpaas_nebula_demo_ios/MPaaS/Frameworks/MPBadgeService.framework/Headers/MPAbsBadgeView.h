//
//  MPAbsBadgeView.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/10/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MPWidgetInfo;
@protocol MPBadgeViewDelegate;

/**
 * 定义红点控件刷新回调接口
 *
 * widgetInfo 红点信息
 * isShow     YES表示显示，NO表示不显示
 */
typedef void(^MPBadgeViewUpdateBlock)(MPWidgetInfo *widgetInfo, BOOL isShow);

@interface MPAbsBadgeView : UIView

// 红点控件ID，在UITableviewCell中使用时，要注意复用的问题，每次都要设置该属性。
@property(nonatomic, copy) NSString *widgetId;
@property(nonatomic, copy) void (^callback)();                  // 提供业务监控红点控件刷新接口。
@property(nonatomic, copy) MPBadgeViewUpdateBlock updateBlock;  // 提供业务监控红点控件刷新接口。

@property(nonatomic, strong) MPWidgetInfo *widgetInfo;          // 红点控件信息，业务不用关心。
@property(nonatomic, weak) id<MPBadgeViewDelegate> delegate;    // 刷新代理内部使用，业务不用关心。

/**
 * 数字的计算方式
 * 注意：1、叶子节点不要设置该属性；
 *      2、在UITableviewCell中使用时，注意：复用的问题，每次都要设置该属性。
 *
 * @"point" 只计算红点个数
 * @"new"   只计算new个数
 * @"num"   只计算数字个数
 * @"hui"   只计算惠字个数
 * @"xin"   只计算新字个数
 * nil      默认计算方式，所有的个数
 */
@property(nonatomic, copy) NSString *numberCalculateMode;

/**
 * 更新显示“红点”样式
 *
 * @param badgeValue:  @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 *
 * @return 无
 */
- (void)updateBadgeValue:(NSString *)badgeValue;

/**
 * 绘制“红点”样式显示
 *
 * @param style:       @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 *
 * @return 无
 */
- (void)drawBadgeStyle:(NSString *)style;

/**
 * 判断红点样式是否变更,updateBadgeValue接口会根据该接口的返回值决定是否重新draw红点
 *
 * @param badgeValue:  @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 *
 * @return YES:新传入的Style和上一次Style类型一样，没有改变；
 *          NO:新传入的Style和上一次Style类型不一样，Style类型改变；
 */
- (BOOL)isLastStyle:(NSString *)badgeValue;

@end
