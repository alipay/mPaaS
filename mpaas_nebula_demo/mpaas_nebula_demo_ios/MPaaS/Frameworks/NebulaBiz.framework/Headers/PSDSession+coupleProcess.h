//
//  PSDSession+H5Auth.h
//  NebulaBiz
//
//  Created by Glance on 2018/7/19.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

typedef void  (^PSDSessionAccessoryDestroyTask)();
typedef void  (^PSDSessionAccessorySaveTask)(id);
typedef void  (^PSDSessionAccessoryReadyTask)();
typedef void  (^PSDSessionAccessoryCancelTask)();


/**
 授权过程由主session(业务H5)和从session(授权H5)两方组成
 */
@interface PSDSession (coupleProcess)

@property (nonatomic, assign) BOOL isMainSession;

/**
 当前session的成组session
 */
@property (nonatomic, weak) PSDSession *pairSession;

/**
 授权任务执行中
 */
@property (nonatomic, assign) BOOL processing;

/**
 主session存储从session的处理结果
 */
@property (nonatomic, strong) id processResult;

/**
 从session Ready时的触发任务
 */
@property (nonatomic, strong) PSDSessionAccessoryReadyTask readyTask;

/**
 从session销毁时的触发任务
 */
@property (nonatomic, strong) PSDSessionAccessoryDestroyTask destroyTask;

/**
 从session保存时的定制任务
 */
@property (nonatomic, strong) PSDSessionAccessorySaveTask saveTask;

/**
 主session取消操作时的定制任务
 */
@property (nonatomic, strong) PSDSessionAccessoryCancelTask cancelTask;


- (void)cancelProcess;

@end

