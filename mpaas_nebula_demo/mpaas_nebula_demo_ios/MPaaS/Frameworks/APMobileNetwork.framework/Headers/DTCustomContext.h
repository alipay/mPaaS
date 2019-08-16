//
//  DTCustomContext.h
//  APMobileNetwork
//
//  Created by cuinacai on 16/6/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTCustomContext : NSObject
/** 网关 URL，不可为空 */
@property(nonatomic, strong) NSURL *gatewayURL;
/** 签名用的appKey，不可为空 */
@property(nonatomic, strong) NSString *appKey;
/** 是否对请求参数进行GZip，默认YES */
@property(nonatomic, assign) BOOL requestGZip;
@end
