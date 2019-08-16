//
//  DTMicroApplicationTypeFinder.h
//  APMobileFramework
//
//  Created by wenbi on 14-5-12.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  App类型查找器
 */
@interface DTMicroApplicationTypeFinder : NSObject

/**
 *  注册指定的App查找器。
 *
 *  @param finder 指定的App查找器。
 */
+ (void)registerFinder:(DTMicroApplicationTypeFinder *)finder;

/**
 *  注册指定的App查找器。
 *
 *  @param finder  指定的App查找器。
 *  @param atIndex 指定的App查找器的位置。
 */
+ (void)registerFinder:(DTMicroApplicationTypeFinder *)finder atIndex:(NSUInteger)index;

/**
 *  注销指定的App查找器。
 *
 *  @param finder 指定的App查找器。
 */
+ (void)unregisterFinder:(DTMicroApplicationTypeFinder *)finder;

/**
 *  获取App的类型。
 *
 *  @param name   AppId
 *  @param params App启动参数。
 *
 *  @return 返回App的类型。
 */
- (NSString *)typeForApplication:(NSString *)name params:(NSDictionary *)params;

@end
