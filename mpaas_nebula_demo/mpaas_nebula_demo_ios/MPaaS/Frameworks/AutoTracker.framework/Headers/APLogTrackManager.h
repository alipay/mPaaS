//
//  APLogTrackManager.h
//  APRemoteLogging
//
//  Created by majie on 16/10/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APLogTrackAgent.h"

@interface APLogTrackPageInfo : NSObject

@property (atomic, readonly, copy) NSString *pageId;
@property (atomic, readonly, copy) NSString *timestamp;
@property (atomic, readonly, copy) NSString *spmId;
@property (atomic, readonly, copy) NSString *information;
@property (atomic, readonly, assign) BOOL needRpc;

@end


@interface APLogTrackManager : NSObject

/**
 通知自动化埋点页面打开

 @param index 页面唯一标识,通常传入UIViewController的实例
 @param context 参数信息 \@ see APLogTrackContext
 */
+ (void)logPageStartWithIndex:(NSObject *)index context:(APLogTrackContext *)context;

/**
 通知自动化埋点页面关闭
 
 @param index 页面唯一标识,需要保证此处传入的对象与调用[logPageStartWithIndex:context]时传入的index为同一个对象
 @param context 参数信息 \@ see APLogTrackContext
 */
+ (void)logPageEndWithIndex:(NSObject *)index;


+ (void)logPageUpdateWithIndex:(NSObject *)index context:(APLogTrackContext *)context;


+ (void)logPageUpdateWithIndex:(NSObject *)index context:(APLogTrackContext *)context updateType:(APLogTrackUpdateType)updateType;


+ (void)logAutoClickWithContext:(APLogTrackContext *)context;


+ (APLogTrackPageInfo *)pageInfoWithIndex:(NSObject *)index;

@end
