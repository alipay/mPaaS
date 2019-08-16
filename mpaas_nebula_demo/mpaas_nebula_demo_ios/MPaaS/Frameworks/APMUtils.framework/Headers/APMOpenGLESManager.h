//
//  APMOpenGLESManager.h
//  APMUtils
//
//  Created by Cloud on 2016/11/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APMOpenGLESManager;
@protocol APMOpenGLESManagerDelegate
@required
/**
 *  收到active命令，在这里执行active OpenGL操作
 *
 *  @param  manager   OpenGLES管理
 */
- (void)openGLESManagerReceiveActiveCommand:(APMOpenGLESManager *)manager;

/**
 *  收到deactive命令，在这里执行deactive OpenGL操作。可能是自己的请求，也可能是其它对象需要active
 *
 *  @param  manager   OpenGLES管理
 */
- (void)openGLESManagerReceiveDeactiveCommand:(APMOpenGLESManager *)manager;

@end

@interface APMOpenGLESManager : NSObject

/**
 *  共享实例
 */
+ (instancetype)sharedManager;

/**
 *  请求激活
 *
 *  @param  object    请求的对象
 */
- (void)requestBecomeActive:(id<APMOpenGLESManagerDelegate>)object;

/**
 *  请求注销
 *
 *  @param  object    请求的对象
 */
- (void)requestResignActive:(id<APMOpenGLESManagerDelegate>)object;

@end
