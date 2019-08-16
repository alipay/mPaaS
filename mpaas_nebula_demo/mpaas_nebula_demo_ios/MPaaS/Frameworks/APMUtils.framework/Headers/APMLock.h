//
//  APMLock.h
//  APMUtils
//
//  Created by feihu on 2018/3/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMLock : NSObject

- (instancetype)initWithReentrant:(BOOL)reentrant NS_DESIGNATED_INITIALIZER;
- (BOOL)lock;
- (BOOL)tryLock;
- (BOOL)unlock;

@end
