//
//  DTRpcContext.h
//  APMobileNetwork
//
//  Created by feisong on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DTRpcContext : NSObject

/**
 * 设置rpc请求header
 * @param 字典类型的header
 */
+(void)setRpcHeader:(NSDictionary*)header;
/**
 * 获取rpc请求header
 * @return 获取字典类型的请求header
 */

+(NSDictionary*)getRpcHeader;
/**
 *  移除rpc请求的Header
 */
+(void)removeRpcHeader;
/**
 *  设置是否是前台rpc
 */
+(void)setForegroundRPC:(BOOL)isForeground;
/**
 *  获取是否是前台rpc 默认是yes
 */
+(BOOL)isForegroundRPC;

/**
 *  设置网络层是否需要显示限流页面
 */
+(void)setShouldShowFlow:(BOOL)showFlow;
/**
 *  获取网络层是否需要显示限流页面
 */
+(BOOL)shouldShowFlow;
/**
 * 设置rpc响应header
 * @param 字典类型的header
 */
+(void)setRpcRespHeader:(NSDictionary *)header;
/**
 * 获取rpc响应的header
 * @return 获取字典类型的响应header
 */
+(NSDictionary*)getRpcRespHeader;

@end
