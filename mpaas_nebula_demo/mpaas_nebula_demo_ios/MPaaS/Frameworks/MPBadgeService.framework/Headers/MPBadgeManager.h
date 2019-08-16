//
//  MPBadgeManager.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/9/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 定义红点数据更新通知
#define kMPBadgeServiceUpdateNotification @"MPBadgeServiceUpdateNotification"

@class MPBadgeDataTransfer, MPBadgeInfo, MPAbsBadgeView;
@protocol MPBadgeServiceConfig;

@interface MPBadgeManager : NSObject

#pragma mark - 红点管理接口

/**
 * 获取红点管理实例
 *
 * @param 无
 *
 * @return 成功返回对象实例，失败返回nil
 */
+ (instancetype)sharedInstance;

/**
 * 设置红点管理配置对象
 *
 * @param config 配置对象
 *
 * @return 无
 */
- (void)setBadgeServiceConfig:(id<MPBadgeServiceConfig>)config;

/**
 * 用户登录后，调用该接口处理红点的显示
 *
 * @param userId 当前登录用户ID
 *
 * @return 无
 */
- (void)refreshAfterLogin:(NSString *)userId;

/**
 * 清除内存缓存的红点数据和界面上所有红点控件的显示
 *
 * @param 无
 *
 * @return 无
 */
- (void)clearAllBadges;

#pragma mark - 红点控件使用接口

/**
 * 注册红点控件到通用红点管理模块
 *
 * @param badgeView 红点控件
 *
 * @return 无
 */
- (void)registerBadgeView:(MPAbsBadgeView *)badgeView;

/**
 * 在通用红点管理模块中，注销掉红点控件
 *
 * @param badgeView 红点控件
 *
 * @return 无
 */
- (void)unregisterBadgeView:(MPAbsBadgeView *)badgeView;

/**
 * 如果是叶子红点就消除红点，否则不处理。（不用关心红点的类型）
 *
 * @param badgeView 红点控件
 *
 * @return 无
 */
- (void)tapBadgeView:(MPAbsBadgeView *)badgeView;

/**
 * 点击红点触发和该红点有关的显示处理（不用关心红点的类型）
 *
 * @param widgetId 红点控件Id
 *
 * @return 无
 */
- (void)tapBadgeViewWithWidgetId:(NSString *)widgetId;

/**
 * 消除关联的红点，无论是父子节点还是子节点
 *
 * @param widgetId 红点控件Id
 *
 * @return 无
 */
- (void)clearBadgeWithWidgetId:(NSString *)widgetId;

#pragma mark - 红点信息获取接口

/**
 * 根据指定的红点路径ID获取红点信息
 *
 * @param badgeId 红点路径ID，如:"#M_PUBLIC_RD#2013112300002181,#M_TRANS_RD#2088502524001315"
 *
 * @return 成功返回红点信息，否则返回nil
 */
- (MPBadgeInfo *)badgeInfoWithBadgeId:(NSString *)badgeId;

/**
 * 根据指定的业务ID获取相关的红点总数
 *
 * @param bizId 业务ID
 *
 * @return 指定业务相关的所有红点数
 */
- (NSUInteger)badgeCountWithBizId:(NSString *)bizId;

/**
 * 根据指定的红点控件ID获取相关的红点总数
 *
 * @param widgetId 红点控件ID
 *
 * @return 指定控件ID相关的所有红点数
 */
- (NSUInteger)badgeCountWithWidgetId:(NSString *)widgetId;

#pragma mark - 红点数据注入接口

/**
 * 用于sync返回增量数据
 * 插入（红点）服务端返回的红点信息，如果本地有数据则红点数累加。
 *
 * @param badgeList MPBadgeInfo数组
 *
 * @return 无
 */
- (void)insertRemoteBadgeInfo:(NSArray *)badgeList;

/**
 * 用于sync返回增量数据
 * 修改（红点）服务端返回的红点信息，如果本地有数据则覆盖。
 *
 * @param badgeList MPBadgeInfo数组
 *
 * @return 无
 */
- (void)modifyRemoteBadgeInfo:(NSArray *)badgeList;

/**
 * 用于sync返回增量数据
 * 删除服务端返回的红点信息。
 *
 * @param badgeList MPBadgeInfo数组
 *
 * @return 无
 */
- (void)deleteRemoteBadgeInfo:(NSArray *)badgeList;

/**
 * 增量方式：插入本地红点信息
 * 注意：1、不做本地缓存；2、点击不上报服务器；
 *
 * @param badgeList 红点数据，元素是MPBadgeInfo
 *
 * @return 无
 */
- (void)insertLocalBadgeInfo:(NSArray *)badgeList;

@end
