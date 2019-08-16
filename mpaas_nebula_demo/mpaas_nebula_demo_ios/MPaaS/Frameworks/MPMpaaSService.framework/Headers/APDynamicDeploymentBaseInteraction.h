//
//  APDynamicDeploymentBaseInteraction.h
//  DynamicDeployment
//
//  Created by majie on 16/6/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//单个业务相关的request对象
@class UnionResourceParam;

//单个业务相关的response对象
@class UnionResourceInfo;


@interface APDynamicDeploymentBaseInteraction : NSObject

/**
 *  设置与业务相关rpc请求特定值（比如开关设置时间戳，hotpatch设置uuid）
 *
 *  @param request 必填，单个业务对象
 *  @return void
 */
- (void)setRequest:(UnionResourceParam *)param;


/**
 *  与业务相关的rpc请求完成时的通知函数
 *
 *  @param responses 必填，发布中心返回的任务下载列表
 *  @param error 必填，rpc返回状态
 */
- (void)responseInfo:(UnionResourceInfo *)info error:(NSError *)error;



/**
 *  与业务相关的长链接通知函数
 *
 *  @param responses 必填，长链接通知
 */
- (void)responseLongLinkNotification:(NSDictionary *)notification;

@end
