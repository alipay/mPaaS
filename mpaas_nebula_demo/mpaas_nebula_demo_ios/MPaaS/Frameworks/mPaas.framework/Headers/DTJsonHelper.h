//
//  DTJsonHelper.h
//  MobileFoundation
//
//  Created by WenBi on 13-4-12.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@interface DTJsonHelper : NSObject

+ (Class)elementClassForContainer:(NSString *)name ofObject:(id)object;

/*
 * 解析并返回一个属性的类型。
 */
+ (NSString *)typeStringForProperty:(objc_property_t)property;

@end
