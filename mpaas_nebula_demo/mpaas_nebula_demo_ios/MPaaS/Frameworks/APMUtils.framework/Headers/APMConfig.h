//
//  APMConfig.h
//  APMUtils
//
//  Created by Cloud on 2016/12/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APMConfig;

@protocol APMConfigUpdateProtocol <NSObject>

- (void)configDidUpdate:(NSString *)config key:(NSString *)key;

@end

@interface APMConfig : NSObject

+ (instancetype)sharedInstance;

#pragma mark - for Observer

/**
 *  为对象注册key对应的配置的更新监听，注册之后会立刻回调一次对象的configDidUpdate:key方法
 *
 *  @param object 要注册的对象
 *  @param key    要监听的配置对应的key
 */
- (void)registerObject:(id<APMConfigUpdateProtocol>)object withKey:(NSString *)key;

/**
 *  删除该对象注册的所有观察key
 *
 *  @param object 注册过的对象
 */
- (void)unregisterObject:(id<APMConfigUpdateProtocol>)object;

/**
 *  删除该对象注册的key，如果有注册其它key，会保留
 *
 *  @param object 注册过的对象
 *  @param key    要去除的key，【注意】：如果还有注册其它的key，会保留
 */
- (void)unregisterObject:(id<APMConfigUpdateProtocol>)object withKey:(NSString *)key;

/**
 *  所有注册过的keys
 *
 *  @return 注册监听的keys
 */
- (NSArray *)allKeys;

#pragma mark - for Subject

/**
 *  通知key配置有对象
 *
 *  @param config 配置信息
 *  @param key    配置信息对应的key
 */
- (void)notifyConfig:(NSString *)config forKey:(NSString *)key;

#pragma mark - for overwrite in category

/**
 *  查找key对应的配置，【注意】：这个方法需要覆盖
 *
 *  @param key 配置的key
 *
 *  @return 返回key对应的配置
 */
- (NSString *)configForKey:(NSString *)key;

/**
 *  配置已经初始化
 */
- (void)configDidInit;

/**
 *  配置即将反初始化
 */
- (void)configWillUninit;

@end
