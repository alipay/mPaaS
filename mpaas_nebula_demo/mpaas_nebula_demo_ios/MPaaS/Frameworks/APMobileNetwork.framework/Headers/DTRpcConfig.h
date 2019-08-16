//
//  DTRpcConfig.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-18.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * \code DTRpcConfig 用于处理 RPC 相关配置，如网关 URL，缓存策略等。
 */
@interface DTRpcConfig : NSObject

/** 网关 URL，不可为空 */
@property(nonatomic, strong) NSURL *gatewayURL;

/** PRC 的缓存策略。暂时未用。 */
@property(nonatomic, assign) NSInteger cacheStrategy;

/** 是否在状态栏中显示网络活动指示器，默认显示。*/
@property(nonatomic, assign) BOOL networkActivityIndicatorVisible;

/** 指定 RPC 请求是否要带上 CTU 所需的额外参数。*/
@property(nonatomic, assign) BOOL shouldAppendCTUExtraParams;

/** 扩展配置信息 */
@property(nonatomic, strong) NSMutableDictionary* userInfo;

/** 是否对请求参数进行GZip，默认YES */
@property(nonatomic, assign) BOOL requestGZip;

/** 接口的名称. 如果设置了operationType，则该DTRpcConfig仅对该接口生效 */
@property(nonatomic, strong) NSString *operationType;

/** 是否走新协议的RPC*/
@property(nonatomic, assign) BOOL isAMRPC;

/** 是否忽略拦截器,默认需要拦截, 主要针对多网关问题处理*/
@property(nonatomic, assign) BOOL ignoreInterceptor;

/** 是否需要MMTP层重发*/
@property(nonatomic, assign) BOOL canResend;

/** 是否走CDN*/
@property(nonatomic, assign) BOOL isCDN;
/** 类拷贝*/
- (id)copy;

@end
