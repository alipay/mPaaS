//
//  DTStartApplicationHandler.h
//  APMobileFramework
//
//  Created by liangbao.llb on 10/15/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DTMicroApplication;

@protocol DTStartApplicationHandler <NSObject>

@optional

/**
 * 询问代理应用是否可以启动。
 * 注意：只用特殊情况返回YES，表示业务处理启动应底层不用处理。
 *
 * @param application 应用对象。
 * @param params 启动参数。
 *
 * @return 可以返回YES，否则返回NO。
 */
- (BOOL)canHandleStartApplication:(DTMicroApplication *)application params:(NSDictionary *)params;

@end
