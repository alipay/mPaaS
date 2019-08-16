//
//  NBSessionManager.h
//  NBService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NBSession;
@class NBSessionContext;

@interface NBSessionManager : NSObject

// 使用Nebula的startSession模式

- (NBSession *)session4Context:(NBSessionContext *)context createIfNoExist:(BOOL)createIfNoExist;

- (BOOL)startSession:(NBSession *)session params:(NSDictionary *)params animated:(BOOL)animated;

- (void)exitSession:(NBSession *)session animated:(BOOL)animated;

// 使用session

- (NBSession *)createSession:(NBSessionContext *)context;

- (void)pushSession:(NBSession *)session;

- (void)popSession:(NBSession *)session;

/**
 * 显示栈中添加session
 * @param session
 */
- (void)showSession:(NBSession *)session;

/**
 * 从session的显示栈中移除session
 * @param session
 */
- (void)hideSession:(NBSession *)session;

// 

- (NBSession *)currentSession;

- (NSArray *)sessions;

@end
