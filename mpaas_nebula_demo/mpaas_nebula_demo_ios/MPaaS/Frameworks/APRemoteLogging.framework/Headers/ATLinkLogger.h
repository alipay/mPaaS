//
//  ATLinkLogger.h
//  APRemoteLogging
//
//  Created by feisong on 10/18/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ATLogger.h"
#import <APProtocolBuffers/ProtocolBuffers.h>


@interface ATLinkLogger : ATLogger

/**
 启动全链路事务
 
 @param tranId 唯一事务id标识
 @param name 链路名称
 @param rule 链路计算规则
 @param fields 合并字段名称数组
 @param linkExt 扩展参数 便于后续增加其他参数
 */
+(void)startLinkTransaction:(NSString*)tranId linkName:(NSString*)name calculateRule:(NSString*)rule mergeFields:(NSArray<NSString*>*)fields linkExt:(NSDictionary<NSString*,NSString*>*)linkExt;

/**
 记录事务
 
 @param tranId 唯一事务id标识
 @param seq 事务内唯一seq
 @param persist 是否落盘持久化标识
 @param node 链路节点数据
 */
+(void)recordLinkTransaction:(NSString*)tranId seq:(UInt64)seq isPersist:(BOOL)persist linkNode:(APDPBGeneratedMessage*)node;

/**
 结束事务
 
 @param tranId 唯一事务id标识
 */
+(void)endLinkTransaction:(NSString*)tranId;

/**
 回滚事务
 
 @param tranId 唯一事务id标识
 */
+(void)rollbackLinkTransactioin:(NSString*)tranId;


/**
 单独明细埋点（与事务无关）
 
 @param node 链路节点数据
 */
+(void)logLink:(APDPBGeneratedMessage*)linkNode;

@end

