//
//  APMRemoteLog.h
//  APMUtils
//
//  Created by tao zeng on 2017/10/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMRemoteLog : NSObject

+ (void)writeLogWithActionId:(nonnull NSString *)actionId
                   extParams:(nullable NSArray *)extParams
                       appId:(nullable NSString *)appId
                        seed:(nullable NSString *)seed
                        ucId:(nullable NSString *)ucId;

+(void)writeLogWithActionId:(nonnull NSString *)actionId
                  extParams:(nullable NSArray *)extParams
                      appId:(nullable NSString *)appId
                       seed:(nullable NSString *)seed
                       ucId:(nullable NSString *)ucId
                    bizType:(nullable NSString *)bizType;

+ (void)writeLogWithActionId:(nonnull NSString *)actionId
                   extParams:(nullable NSArray *)extParams
                       appId:(nullable NSString *)appId
                        seed:(nullable NSString *)seed
                        ucId:(nullable NSString *)ucId
                     bizType:(nullable NSString *)bizType
         formatterDictionary:(nullable NSDictionary *)formatterDictionary;

@end
