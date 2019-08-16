//
//  AUBadgeServiceShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/2.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUBadgeServiceShell : NSObject

//红点协议MPBadgeService
/*
 初始化红点View
 */
+ (UIView *)badgeViewWithFrame:(CGRect)frame;

/*
 红点设置widgetId
 
 */
+ (void)badgeViewWith:(UIView *)badgeView
             widgetId:(NSString *) widgetId;

/*
 注册红点view到MPBadgeManager管理者去。
 */
+ (void)badgeViewReg:(UIView *)badgeView;

+ (void)reportMPBadge:(NSString*)widgetId;

+ (BOOL)badgeValid:(UIView *)badgeView;

+ (void)cleanBadgeView:(UIView *)badgeView;

/**
 * 更新显示“红点”样式
 * @param badgeView     红点View
 * @param badgeValue:  @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 *
 * @return 无
 */
+ (void)badgeViewWith:(UIView *)badgeView
          updateValue:(NSString *)badgeValue;

/*
 提供业务监控红点控件刷新接口。
 widgetInfo 类型是MPWidgetInfo
 */
+ (void)badgeViewWith:(UIView *)badgeView
          updateBlock:(void(^)(id widgetInfo, BOOL isShow)) updateBlock;

@end



NS_ASSUME_NONNULL_END
