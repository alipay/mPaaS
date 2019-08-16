//
//  AntLogInterceptor.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/11/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AntLogWriteOperation;
@class AntLogUploadOperation;

/**
 日志拦截器。所有日志 写入前 或 上报前 都会经过拦截器，拦截器可做相应处理。
 */
@protocol AntLogInterceptor <NSObject>

/**
 写入一条日志时的前置拦截器。一条日志写入前，会调用该方法。

 @param operation 当前日志写入操作 @see AntLogWriteOperation
 */
- (void)beforeWrite:(AntLogWriteOperation *)operation;

/**
 上报一批日志时的前置拦截器。一批日志上报前，会调用该方法。

 @param operation 当前日志上报操作 @see AntLogUploadOperation
 */
- (void)beforeUpload:(AntLogUploadOperation *)operation;

@end

////////////////////////////////////////////////////////////////////////////////

@interface AntLogWriteOperation : NSObject

@property (nonatomic, readwrite, assign) BOOL shouldWrite;/**< 是否应该写入，默认YES，可写*/

@property (nonatomic, readonly) NSString *bizType;        /**< 日志业务类型, 只读*/

@property (nonatomic, readonly) NSString *log;            /**< 格式化后的日志内容, 只读*/

@end

////////////////////////////////////////////////////////////////////////////////

@interface AntLogUploadOperation : NSObject

@property (nonatomic, assign) BOOL shouldUpload;       /**< 是否应该上报，默认YES，可写*/

@property (nonatomic, readwrite, strong) NSString *url;/**< 即将上报的服务器地址，可写*/

@property (nonatomic, readonly) NSString *bizType;     /**< 日志业务类型, 只读*/

@property (nonatomic, readonly) NSData *logData;       /**< 即将上报的未经压缩的日志内容二进制, 只读*/

@end

