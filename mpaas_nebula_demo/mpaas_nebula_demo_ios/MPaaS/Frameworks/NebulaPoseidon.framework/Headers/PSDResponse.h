//
//  PSDResponse.h
//  Poseidon
//
//  Created by chenwenhong on 14-10-15.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^StopLoadingHandler)();

@class PSDWebViewURLProtocol;

@interface NSURLCustomResponse : NSHTTPURLResponse

@property(atomic, copy) NSString *customMIMEType;

@end

@interface PSDResponse : NSObject <NSURLConnectionDataDelegate>

@property(nonatomic, assign) NSURLCacheStoragePolicy cachePolicy; //cache policy for response
@property(nonatomic, weak) PSDWebViewURLProtocol *protocol;

- (id)initWithProtocol:(PSDWebViewURLProtocol*)protocol;

/**
 *  用类型响应对应的请求
 *  图片、文本、html、json
 */
- (void)respondWithImage:(UIImage *)image;
- (void)respondWithImage:(UIImage *)image mimeType:(NSString *)mimeType;
- (void)respondWithText:(NSString *)text;
- (void)respondWithHTML:(NSString *)html;
- (void)respondWithJSON:(NSDictionary *)jsonObject;

/**
 *  手动停止比较耗时的加载请求
 *  @param stopLoadingHandler 回调
 */
- (void)handleStopLoadingRequest:(void (^)(void))stopLoadingHandler;

/**
 *  HTTP status error code and text
 *  @param statusCode 错误码 text  错误信息
 *  eg: respondWithError:404 text:@"Not found"
 */
- (void)respondWithError:(NSInteger)statusCode text:(NSString *)text;

/**
 *  设置响应头
 *  eg : setHeader:@"Content-Type" value:@"image/gif"
 */
- (void)setHeader:(NSString *)headerName value:(NSString *)headerValue;

//TODO 有可能为多个同 key ,但是 NSURLResponse - (instancetype)initWithURL:(NSURL *)url statusCode:(NSInteger)statusCode HTTPVersion:(NSString *)HTTPVersion headerFields:(NSDictionary *)headerFields 传的是 dictionary

- (void)setHeaders:(NSDictionary *)headers;

/**
 *  data 响应
 *  eg: respondWithData:data mimeType:@"text/plain"
 */
- (void)respondWithData:(NSData *)data mimeType:(NSString *)mimeType;
- (void)respondWithData:(NSData *)data mimeType:(NSString *)mimeType statusCode:(NSInteger)statusCode;

- (void)startLoading;
- (void)responseWithCode:(NSInteger)code mimeType:(NSString *)mimeType contentLength:(NSString *)length;
- (void)responseWithURL:(NSURL *)url statusCode:(NSInteger)code mimeType:(NSString *)mimeType contentLength:(NSString *)length;
- (void)wasRedirectedToRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)response;
- (void)finishLoadData:(NSData *)data;
- (void)failLoadWithError:(NSError *)error;


@end
