//
//  TAWebViewUtils.h
//  TinyAppCommon
//
//  Created by 应俊康 on 2018/5/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TAWebViewUtils : NSObject

+ (BOOL)isEmbeddedWebViewWith:(PSDSession*)session;

+ (NSString*)parentAppIdWith:(PSDSession*)session;

+ (BOOL)canEmbedWebViewOpenOfflinePackge:(NSString *)packageAppid
                               tinyAppId:(NSString *)tinyAppid;
@end
