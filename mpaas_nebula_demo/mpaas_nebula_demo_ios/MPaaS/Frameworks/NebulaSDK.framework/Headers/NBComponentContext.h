//
//  NBComponentContext.h
//  NebulaPlugins
//
//  Created by theone on 17/5/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBComponentContext : NSObject
@property(nonatomic, weak)   UIViewController *currentViewController;
@property(nonatomic, strong) NSURL *url;
@end
