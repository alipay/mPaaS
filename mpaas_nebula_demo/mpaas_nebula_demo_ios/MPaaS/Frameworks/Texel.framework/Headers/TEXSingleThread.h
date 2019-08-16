//
//  TEXSingleThread.h
//  Texel
//
//  Created by Cloud on 2017/3/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// GCD和NSOperationQueue都不是在一个固定的线程中执行的，所以OpenGL的使用总是出问题
// 这里用NSThread来创建一个可以在固定线程中执行代码的类
@interface TEXSingleThread : NSObject

- (instancetype)initWithName:(NSString *)name;
- (void)run:(void (^)())block;
- (void)stop;

@end
