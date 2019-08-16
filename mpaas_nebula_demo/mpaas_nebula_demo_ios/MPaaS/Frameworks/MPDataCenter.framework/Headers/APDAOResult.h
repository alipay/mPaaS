//
//  APDAOResult.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-26.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, APDAOResultFlag)
{
    APDAOResultFlagUndefined = 0,
    APDAOResultFlagTryBlockExecuted,        // 执行了Try
    APDAOResultFlagExceptBlockExecuted,     // 执行了Except
};

@interface APDAOResult : NSObject

/**
 *  用于含有try...except块的DAO方法，返回到底执行的是try里面的语句还是except中的。
 *  对于不含foreach的DAO方法，用flags[0]来取值，否则flags[i]对应业务传进来的循环数组里面的每个元素执行的到底是try还是except。
 */
@property (nonatomic, assign) APDAOResultFlag* flags;

/**
 *  对于foreach执行的update方法，当设置resumable时，这个数组返回失败的对象
 */
@property (nonatomic, strong) NSMutableArray* foreachFailedObjects;

/**
 *  成功的对象
 */
+ (instancetype)success;

/**
 *  失败的对象
 */
+ (instancetype)failure;

/**
 *  以BOOL值创建对象
 */
+ (instancetype)resultWithBool:(BOOL)value;

/**
 *  是否成功
 */
- (BOOL)value;

/**
 *  是否成功
 */
- (BOOL)succeeded;

/**
 *  是否失败
 */
- (BOOL)failed;

@end

extern APDAOResult* APDAODefaultSuccess;
extern APDAOResult* APDAODefaultFailure;
