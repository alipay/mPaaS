//
//  APConfigService.h
//  APConfig
//
//  Created by WenBi on 13-8-28.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <APMobileFramework/DTService.h>

// 无论是rpc还是sync更新配置时，都会发通知。建议使用APConfigObserverProtocol实现一对一监听。
#define kAPCommonConfig @"com.alipay.mobile.common.config"

// sync下发配置时，才会发通知，不建议使用。
#define kAPCommonConfigData @"com.alipay.mobile.common.sync.configdata"

// 春节红包相关配置变化通知，其它业务请勿使用。
#define kAPCommonConfigLmac @"com.alipay.mobile.common.sync.lmac"

// rpc处理完获取配置的流程后，发送通知(无论此次拉取是否有更新操作)。
#define kAPCommonConfigFinishGetInfo @"com.alipay.mobile.common.finishgetinfo"

/**
 * 监听开关值发生变化的回调，不会因为其它开关变化而频繁收到通知。
 * 观察者被作为弱引用被持有，不会有不释放或者释放后还发通知的情况。
 */
@protocol APConfigObserverProtocol <NSObject>

@required
- (void)configChangedForKey:(NSString *)key value:(NSString *)value;

@end


@protocol APConfigCustomDelegate <NSObject>

/**
 * 默认从配置中心获取特定key对应的配置失败时，若业务实现此接口，会返回此接口对应的值。
 *
 *内部接口，外部请勿调用
 *
 * @param key 要获取的配置key。
 *
 * @return 返回特定key对应的配置值。
 */
- (NSString *)tinyAppServiceForKey:(NSString *)key;
@end

/**
 * 配置服务，负责维护通过RPC拉取的各个开关配置，可通过sync更新。
 */
@protocol APConfigService <DTService>

@required

#pragma mark - 通用配置接口。
/**
 * 从配置中心获取特定key对应的配置。
 *
 * @param key 要获取的配置key。
 *
 * @return 返回特定key对应的配置值。
 */
- (NSString *)stringValueForKey:(NSString *)key;

/**
 *  对指定的配置加观察者。
 *
 *  @param observer 观察者
 *  @param key      指定配置的key
 *
 *  @return 成功返回YES，否则返回NO，失败原因：参数错误或者重复观察。
 */
- (BOOL)addConfigChangedObserver:(id<APConfigObserverProtocol>)observer key:(NSString *)key;

/**
 *  删除指定配置的观察。
 *
 *  @param observer 观察者
 *  @param key      指定配置的key
 */
- (void)removeObserver:(id)observer key:(NSString *)key;

/**
 *  删除指定观察者对所有配置的观察。
 *
 *  @param observer 观察者
 */
- (void)removeObserver:(id)observer;

/**
 * 通过RPC 主动拉取服务端配置
 */
- (void)fetchConfigFromRPC;

#pragma mark - 内部接口，业务不要直接使用。
/**
 * 业务不要使用，切换环境时，框架调用清除本地开关配置
 */
- (void)cleanup;


/**
 *  设置获取开关值的自定义代理实现类。内部接口，外部不要直接使用
 *
 *  @param delegate 代理类
 */
- (void)setConfigDelegate:(id <APConfigCustomDelegate>)delegate;

@end
