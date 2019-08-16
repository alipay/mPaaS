//
//  AUConfigShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/2.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUConfigShell : NSObject

/**
 [APConfigService stringForKey]
 
 @param key 配置服务key
 @return 配置服务的value值
 */
+ (NSString *)configForKey:(NSString *)key;

/**
 [APConfigService addConfigChangedObserver]
 @param observer 监听通知的对象
 @param key 配置服务key
 */
+ (void)addConfigChangedObserver:(id)observer key:(NSString *)key;

+ (void)removeConfigChangedObserver:(id)observer key:(NSString *)key;

//+ (NSString *)readKvConfigForKey:(NSString *)key;
//
//+ (void)writeKvConfigForKey:(NSString *)key value:(NSString*)value;

@end



NS_ASSUME_NONNULL_END
