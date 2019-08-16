//
//  ATActionMgr.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ATAction;

/**
 * 操作管理器
 */
@interface ATActionMgr : NSObject

@property (nonatomic, readonly, strong) NSOperationQueue *actionQueue; /**< 操作队列*/

/**
 * 入队一个操作
 */
- (void)enqueueAction:(ATAction *)action;

@end

////////////////////////////////////////////////////////////////////////////////

/**
 * 操作对象基类
 */
@interface ATAction : NSOperation

@property (nonatomic, copy) NSString *actionName; /**< 操作名*/

/**
 * 是否可用. 不可用时不执行. 默认返回 \c YES.
 */
- (BOOL)validate;

@end
