//
//  DTURLRequestOperation.h
//  RPC
//
//  Created by WenBi on 13-3-1.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//
/*!
 @class     DTURLRequestOperation
 @abstract  URL网络请求的处理线程类
 */
@interface DTURLRequestOperation : NSOperation <NSURLConnectionDataDelegate,NSURLProtocolClient,NSURLSessionDataDelegate>

/*!
 @property  request
 @abstract  表示一个 URL 请求
 */
@property(nonatomic, strong) NSURLRequest *request;

/*!
 @property  response
 @abstract  一个可以访问 URL 回应的编程接口
 */
@property(nonatomic, strong) NSURLResponse *response;
@property(nonatomic, strong) NSURLResponse *responseOrg;
@property(nonatomic, strong) NSMutableDictionary *httpBodyParameters;
@property(nonatomic, strong) NSData *responseData;
@property(nonatomic, strong) NSString *responseString;
@property(nonatomic, strong) NSString *customAppKey;
/*!
 @property  error
 @abstract  一个 NSError 错误对象，包含了网络连接为什么失败的原因
 */
@property(nonatomic, strong) NSError *error;

/*!
 @property  inputStream
 @abstract  网络处理的输入流
 */
@property(nonatomic, strong) NSInputStream *inputStream;

/*!
 @property  outputStream
 @abstract  网络处理的输出流
 */
@property(nonatomic, strong) NSOutputStream *outputStream;

/*!
 @property  runLoopModes
 @abstract  RunLoop消息处理模式
 */
@property(nonatomic, strong) NSSet *runLoopModes;

/*!
 @property  totalBytesRead
 @abstract  接收到数据的字节数
 */
@property(nonatomic, assign) NSInteger totalBytesRead;

/*!
 @property  lock
 @abstract  线程同步锁
 */
@property(nonatomic, strong) NSRecursiveLock *lock;

/*!
 @property  runningThread
 @abstract  一个线程对象，用于指定这个 URL 请求运行在哪个线程中
 */
@property(nonatomic, strong) NSThread *runningThread;

/*!
 @property  threadCreated
 @abstract  一个线程对象，用于标志是那个线程在运行这个operation请求
 */
@property(nonatomic, strong) NSThread *createdThread;

/*!
 @property  networkActivityIndicatorVisible
 @abstract  指定是否在状态栏中显示网络活动指示器。
 */
@property(nonatomic, assign) BOOL networkActivityIndicatorVisible;

/*!
 @property  requestBodyGZip
 @abstract  指定是否在对requestBody进行gzip。
 */
@property(nonatomic, assign) BOOL requestBodyGZip;

@property(nonatomic, assign) BOOL requestBodySign;
/*!
 @function  timeoutTimer
 @abstract 特殊rpc走特殊通道 需要设置超时定时器
 */
@property(nonatomic) NSTimer *timeoutTimer;
/*!
 @function
 @abstract 特殊rpc走特殊通道使用 防止多次调用fail方法
 */
@property(nonatomic,assign) BOOL hasCanceled;   //didfail是否调用过
/** 是否走H2的RPC*/
@property(nonatomic, assign) BOOL isH2RPC;
/** ip直连*/
@property(nonatomic,strong) NSString *httpDnsIp;
/**request 请求走post还是get 默认是post **/
@property(nonatomic,assign) BOOL httpGET;
/**rpc解密 key **/
@property(nonatomic,strong) NSData *deKey;
/**rpc是否需要自加密 mpaas用**/
@property(nonatomic,assign) BOOL isCrypt;
/**网关地址**/
@property(nonatomic,strong) NSURL *gatewayURL;
/*!
 @function  defaultOperationQueue
 @abstract  得到用于URL访问的缺省OperationQueue
 */
+ (NSOperationQueue *)defaultOperationQueue;

/*!
 @function  initWithRequest
 @abstract  生成一个URL网络请求的处理线程对象
 @param     request
 请求对象
 */
- (id)initWithRequest:(NSURLRequest *)request;

/*!
 @function  initWithRequest
 @abstract  生成一个URL网络请求的处理线程对象
 @param     request
 请求对象
 @param     outputStream
 网络处理的输出流
 */
- (id)initWithRequest:(NSURLRequest *)request outputStream:(NSOutputStream *)outputStream;

/**
 * 结束当前的请求操作。
 */
- (void)finish;

/*!
 @function      didStart
 @abstract      网络请求开始回调
 @discussion    可以在子类中重载处理
 */
- (void)didStart;

/*!
 @function      didFinish
 @abstract      网络请求结束回调
 @discussion    可以在子类中重载处理
 */
- (void)didFinish;
/*!
 @function      当前RPC的operationType
 */
- (NSString*)rpcOperationType;
/*!
 @function      网络重传
 */
@property(nonatomic, strong) NSString *netRetryable;
/*!
 @function      往body添加内容
 */
-(void)addHTTPBodyParameter:(NSString *) parameter forKey:(NSString *) key;
/*!
 @function      开始连接
 */
- (void)startConnection;
/*!
 @function      添加netRetryable
 */
-(void)addRetryToRequest:(NSMutableURLRequest*)request;
/*!
 @function      gunzip rpc解密 secData 要解密的数据
 */
-(NSData *)gunzipAndDecrypt:(NSData *)secData;
/*!
 @function      gzip and rpc加密 requestBody 要压缩和加密的数据
 */
-(void)gzipAndEncrypt:(NSData *)requestBody;
/*!
 @function      是否需要自加密
 */
-(BOOL)shouldCrypt;
@end
