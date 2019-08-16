//
//  AULanguageShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AULanguageShell : NSObject

/**
 *  在名称为 \c bundleName 的bundle中取当前语言状态下\c key 对应的字符串值.
 *
 *  @param key        字符串表中\c key
 *  @param value      默认值, 当找不到该 \c key 对应的 \c value 时返回该默认值.
 *  @param bundleName bundle名称字符串
 *
 *  @return 当前语言状态下\c key 对应的字符串值
 */
+ (NSString *)localizedStringForKey:(NSString *)key
                       defaultValue:(NSString *)value
                           inBundle:(NSString *)bundleName;

@end

NS_ASSUME_NONNULL_END
