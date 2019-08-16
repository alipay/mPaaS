//
//  MPFunctionMaintainer.h
//  APMPaaS
//
//  Created by qiwei on 2018/5/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef MPFunctionMaintainer_h
#define MPFunctionMaintainer_h


@interface MPFunctionManager : NSObject
+ (instancetype)shared;
- (void)start;
@end


#endif /* MPFunctionMaintainer_h */
