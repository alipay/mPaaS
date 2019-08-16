//
//  PSDPage.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDKernel.h"
#import <UIKit/UIKit.h>

@class PSDPageParam;
@class PSDView;
@class PSDJsBridge;
@class PSDContentView;
@protocol WKNavigationDelegate;
@protocol WKUIDelegate;

//Page类：代指浏览器打开一个页面，所产生的对象，通常一个一次跳转或者刷新产生一个Page。
@interface PSDPage : PSDKernel

@property(nonatomic, readonly, strong) PSDJsBridge *bridge;
@property(nonatomic, strong) NSString *pageUUID;


- (PSDPageParam *)createParam;

/**
 *  @brief 给定一个pageParam参数，创建一个Page对象
 *
 *  @date 2014-08-08
 *
 *  @param pageParam 要创建所需要的参数，不能为nil
 *
 *  @return 返回Page对象
 */
+ (instancetype)pageWithPageParam:(PSDPageParam *)pageParam parentObject:(PSDKernel *)parentObject;

@end

//创建Page所需的参数类
@interface PSDPageParam : NSObject

@property(nonatomic, weak) PSDContentView           *contentView;
@property(nonatomic, weak) id<UIWebViewDelegate>    webViewDelegate4PsdView;
@property(nonatomic, weak) id<WKNavigationDelegate> webViewNavigationDelegate4PsdView;
@property(nonatomic, weak) id<WKUIDelegate>         webViewUIDelegate4PsdView;
@property(nonatomic, strong) NSDictionary           *expandParams;

@end

