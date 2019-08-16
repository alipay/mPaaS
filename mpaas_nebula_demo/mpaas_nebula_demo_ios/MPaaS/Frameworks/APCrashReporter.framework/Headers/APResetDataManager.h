//
//  APResetDataManager.h
//  APCrashReporter
//
//  Created by NianXi on 16/1/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  定制容灾恢复出厂设置操作，默认值是支付宝白名单
 *  mPaaS接入方务必通过 set_data_cleanup_action(APDataCleanupAction action) 接口重置自己的清除任务
 */
typedef void (*APDataCleanupAction)(void);

extern void set_data_cleanup_action(APDataCleanupAction action);
extern APDataCleanupAction get_data_cleanup_action(void);


//异常事件关键字
extern NSString * const kSequentialCrashRecord;                 //闪退
extern NSString * const kSequentialMainThreadDeadLockRecord;    //主线程卡死
extern NSString * const kSequentialBlockLaunchRecord;           //启动卡死

/**
 *  清理白名单以外的本地数据
 */
extern void data_mananger_clean_local_data(void);

/**
 *  创建异常事件的标记，并且自动计数为1
 *
 *  @param key 异常事件关键字 如：闪退、主线程卡死
 *
 *  @return BOOL型 创建标记文件成功与否，若该异常标记已经存在则返回NO
 */
extern BOOL data_manager_create_mark(NSString *key);

/**
 *  异常计数加1，若之前没有记录则自动创建该异常的计数，并且计数为1
 *
 *  @param key 异常事件关键字 如：闪退、主线程卡死
 */
extern void data_manager_record_mark(NSString *key);

/**
 *  检查连续启动发生异常事件的计数是否超时
 *
 *  @param key     异常事件关键字 如：闪退、主线程卡死
 *  @param timeout 超时时间
 *
 *  @return BOOL型 YES表示超时，反之NO
 */
extern BOOL data_manager_check_mark_timeout(NSString *key, NSTimeInterval timeout);

/**
 *  检查异常事件的计数是否到了设定的最大值（触发异常容灾逻辑的计数数值）
 *
 *  @param key 异常事件关键字 如：闪退、主线程卡死
 *  @param max 触发容灾逻辑的异常次数
 *
 *  @return OOL型 YES表示到了最大值，应触发容灾；反之则NO
 */
extern BOOL data_manager_check_mark(NSString *key, NSInteger max);

/**
 *  清除异常计数
 *
 *  @param key 异常事件关键字 如：闪退、主线程卡死
 */
extern void data_manager_clean_mark(NSString *key);

/**
 *  重置异常事件计数，并自动创建1次异常标记
 *
 *  @param key 异常事件关键字 如：闪退、主线程卡死
 */
extern void data_manager_refresh_mark(NSString *key);

/**
 *  设置连续异常的容灾策略
 *
 *  @param key      异常事件关键字 如：闪退、主线程卡死
 *  @param timeout  连续异常判定的超时阈值
 *  @param max      连续发生异常的次数最大值，到达该值则触发容灾逻辑
 *  @param callback 容灾回调
 */
extern void data_manager_disaster_recovery(NSString *key,
                                           NSTimeInterval timeout,
                                           NSInteger max,
                                           void(*callback)(void));

