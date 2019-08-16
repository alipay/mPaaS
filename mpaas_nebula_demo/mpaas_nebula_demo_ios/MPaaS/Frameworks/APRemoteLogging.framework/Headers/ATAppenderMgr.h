//
//  ATAppenderMgr.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/25.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAppender.h"

/**
 * Appender管理器
 */
@interface ATAppenderMgr : NSObject

@property(nonatomic,assign) NSTimeInterval lastPeriodCheckTime;/**上次检查时间*/
@property(nonatomic,strong) NSMutableDictionary<NSString*,NSNumber*>* fileCreateTimes;/**记录logs目录下各biz对应文件创建时间，key是biz*/
/**
 * 根据biz获取Appender实例
 * @param biz bizId
 * @param create 内存中没有缓存时是否创建新的,默认NO.
 */
- (ATAppender *)appenderForBizId:(NSString *)biz
                createIfNotExist:(BOOL)create;

/**
 * 获取内存中所有Appender实例
 */
- (NSArray<ATAppender *> *)appenders;

/**
 * 通知管理器App启动完成
 */
- (void)notifyAfterLaunch:(__unused NSDictionary *)info;

/**
 检查满足时间条件的biztype上报
 
 */
-(void)periodUploadCheck;

@end
