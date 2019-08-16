//
//  NBContext.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBSession.h"
#import "NBSessionManager.h"

@class NBSessionContext;

@interface NBContext : NSObject

@property(nonatomic, weak) UIWindow                   *window;
@property(nonatomic, weak) UINavigationController     *navigationController;
@property(nonatomic, strong) NBSessionManager           *sessionManager;

+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

+ (instancetype)sharedContext;

- (NBSession *)createSession:(NBSessionContext *)context;

- (BOOL)startSession:(NSDictionary *)params animated:(BOOL)animated;

- (void)exitSession:(NBSession *)session animated:(BOOL)animated;

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

- (NSArray *)sessions;

/**
 * 获取当前正在运行的应用对象。
 */
- (NBSession *)currentSession;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    NBContext * NBContextGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
