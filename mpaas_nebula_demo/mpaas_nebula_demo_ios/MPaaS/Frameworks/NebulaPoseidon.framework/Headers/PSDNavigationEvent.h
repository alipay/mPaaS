//
//  PSDNavigationEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"
#import <UIKit/UIKit.h>

@interface PSDNavigationEvent : PSDEvent

@property(nonatomic, strong) NSURLRequest *request;
@property(nonatomic, assign) UIWebViewNavigationType navigationType;
@property(nonatomic, strong) NSError *error;
@property(nonatomic, assign) BOOL isMainFrame; //可以通过这个属性来读取当前请求是否是mainFrame的请求,sine 10.1.28

+ (instancetype)allEvent:(NSURLRequest *)request;

+ (instancetype)startEvent:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;

+ (instancetype)completeEvent:(NSURLRequest *)request;

+ (instancetype)errorEvent:(NSURLRequest *)request error:(NSError *)error;

@end
