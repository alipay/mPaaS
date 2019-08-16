//
//  APMethodSwizzling.h
//  APCommonUI
//
//  Created by WenBi on 14-1-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AUMethodSwizzling)

+ (SEL)replaceSelector:(SEL)originalSelector withSelector:(SEL)newSelector;

+ (SEL)renamedSelectorForSelector:(SEL)selector;

@end

@interface AUMethodSwizzling : NSObject

+ (SEL)replaceSelector:(SEL)originalSelector withSelector:(SEL)newSelector inClass:(Class)aClass;



/**
 hook实例方法

 @param originSelector <#originSelector description#>
 @param toSelector <#toSelector description#>
 @param clazz <#clazz description#>
 */
+ (void)swizzleMethod:(SEL)originSelector toMethod:(SEL)toSelector forClass:(Class)clazz;

// 类方法
+ (void)swizzleClassMethod:(SEL)originSelector toMethod:(SEL)toSelector forClass:(Class)clazz;

@end
