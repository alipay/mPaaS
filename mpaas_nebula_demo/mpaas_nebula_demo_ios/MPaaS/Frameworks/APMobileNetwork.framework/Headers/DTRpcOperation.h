//
//  DTRpcOperation.h
//  DTFNetwork
//
//  Created by WenBi on 13-3-26.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTRpcBaseOperation.h"

enum { kJSONDecoderMaxElementClass = 10 };


@class DTRpcMethod;

/**
 * 执行 RPC 请求的 operation。
 *
 * DTRpcOperation 类在实例化时，把调用方传入的参数（通常是一个数组，数组中可以是普通对象、字符串或是数字）序列化为
 * JSON 格式的字符串。在收到服务端的回应后，把返回的 JSON 字符串再转换成指定 Class 的对象。
 *
 * 客户端以表单的形式把请求的数据提交到服务端，有三个表单项：
 *	<ul>
 *		<li>mobilerpc - 协议版本号</li>
 *		<li>operationType - 应用名|服务名|接口名</li>
 *		<li>requestData - JSON序列化后的数据</li>
 *	</ul>
 *
 */
@interface DTRpcOperation : DTRpcBaseOperation

@property(nonatomic, assign) BOOL shouldAppendCTUExtraParams;
@property(nonatomic, assign) BOOL shouldAppendTrafficControlParams;
@property(nonatomic, assign) BOOL isSDPYProtocol;
@property(nonatomic, assign) NSTimeInterval startTime;
/** 是否忽略拦截器,默认需要拦截*/
@property(nonatomic, assign) BOOL ignoreInterceptor;
@property(nonatomic, copy) void (^responseBlock)(NSDictionary* allHeaderFields);
@property(nonatomic, assign) BOOL canResend;//是否需要MMTP层重发
/** rpc超时时长可设置 */
@property(nonatomic,assign) NSTimeInterval timeoutInterval;
/** 设置是否忽略网络状态 */
@property(nonatomic,assign) BOOL isIgnoreNetStatus;
/** 是否是前台rpc 默认为true*/
@property(nonatomic,assign) BOOL isForegroundRPC;
/** 是否是黑名单rpc 默认为false*/
@property(nonatomic,assign) BOOL isBlackListRPC;

/** 是否是特殊通道rpc 默认为false*/
@property(nonatomic,assign) BOOL isSpecialChannelRPC;
/** 设置是否是登录rpc(专为登录session串号提供) 默认no */
@property(nonatomic,assign) BOOL isLoginRPC;
/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 *
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(DTRpcMethod *)method params:(NSArray *)params;

/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 * @param headerFields 在request中添加headerField。
 *
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(DTRpcMethod *)method params:(NSArray *)params headerFields:(NSDictionary*)fields;
/**
 * 初始化并返回一个 <code>DTRpcOperation</code> 的对象。
 *
 * @param config 描述 RPC 请求信息的对象
 * @param params 请求参数数组，可为nil。
 * @param headerFields 在request中添加headerField。
 * @param amrpc 是否走amrpc，可为nil。
 * @param cdn 是否走cdn，可为nil。
 * @return 如果调用成功，返回初始化后的 <code>DTRpcOperation</code> 的对象，否则返回 nil。
 */
- (id)initWithURL:(NSURL *)url method:(DTRpcMethod *)method params:(NSArray *)params headerFields:(NSDictionary*)fields amrpc:(BOOL)AMRPC cdn:(BOOL)cdn;

/**
 * 返回 \DTRpcMethod 对象。
 */
- (DTRpcMethod *)method;

/**
 * 返回请求参数数组。
 */
- (NSArray *)params;

/**
 * 获取 RPC 请求成功的对象，如果调用失败，则返回 nil。
 *
 * @return 服务端返回的对象。
 */
- (id)resultObject;

/**
 重复执行次数
 */
- (int)retryCount;

/**
 上下文
 */
- (NSMutableDictionary *)userInfo;
/**
 *  把response转化为PB
 */
- (void)setResponseToPBIntoClass;
/**
 *  取消发送rpc
 */
-(void)stopSendRPC;
/**
 *  签名
 */
-(void)signRequest:(NSString*)ts;
@end
