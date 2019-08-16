//
//  DTURLCommonRequestOperation.h
//  APMobileNetwork
//
//  Created by Wanlei on 14-9-6.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "DTURLRequestOperation.h"

@protocol DTURLCommonRequestOperationDelegate <NSObject>
/**
 *  代理 连接完成时调用
 *
 *  @param request      请求
 *  @param responseJSON 返回的json数据
 */
-(void)connectionFinished:(NSURLRequest*)request WithResponseJSON:(NSDictionary*)responseJSON;
/**
 *  代理 连接失败时调用
 *
 *  @param request      请求
 *  @param responseJSON 失败信息
 */
-(void)connectionFailed:(NSURLRequest*)request WithError:(NSError *)error;

@end

@interface DTURLCommonRequestOperation : DTURLRequestOperation

@property (nonatomic, weak) id<DTURLCommonRequestOperationDelegate> delegate;

@property(nonatomic, strong) NSDictionary *responseJSON;

@end
