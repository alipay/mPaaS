//
//  H5Service.h
//  H5Service
//
//  Created by xuesi on 13-12-14.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PSDSession;
@class H5Session;
@class ACApp;
@class NAMApp;

@interface H5Service (Private)

/**
 * 取单例
 */
+ (H5Service *)sharedService;

/**
 *  创建H5Sessioin实例
 *
 *  @param params session根webview启动参数
 *
 *  @return H5Session实例
 */
- (H5Session *)createH5Session:(NSDictionary *)params;
- (void)removeSession:(H5Session *)session;
- (void)increaseControllerCount;
- (void)decreaseControllerCount;
- (H5Session *)lastSession;
- (NSArray *)sessions;
- (NSString *)getVhost:(ACApp *)app;
@end
