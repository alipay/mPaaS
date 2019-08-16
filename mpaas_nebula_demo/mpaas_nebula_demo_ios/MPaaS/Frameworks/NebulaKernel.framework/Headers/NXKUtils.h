//
//  NXKUtils.h
//  NebulaKernel
//
//  Created by theone on 2018/9/20.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NXKNode;

NS_ASSUME_NONNULL_BEGIN

@interface NXKUtils : NSObject
+ (void)swizzleCls:(NSString *)cls
     orginSelector:(SEL)orginSelector
       newSelector:(SEL)newSelector;

+ (BOOL)isNXKNode:(PSDKernel *)node
       targetList:(NSArray<NXKNode *> *)targetList;
@end

NS_ASSUME_NONNULL_END
