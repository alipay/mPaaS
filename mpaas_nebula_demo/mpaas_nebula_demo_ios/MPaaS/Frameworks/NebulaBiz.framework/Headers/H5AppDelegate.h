//
//  H5AppDelegate.h
//  H5App
//
//  Created by xuesi on 13-4-2.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H5AppDelegate : NSObject <DTMicroApplicationDelegate>

@property(nonatomic, strong) UIViewController *rootController;

+ (BOOL)isH5AppDelegate:(id)theDelegate;

@end
