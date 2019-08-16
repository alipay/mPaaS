//
//  H5Session.h
//  H5Service
//
//  Created by noahlu on 14-2-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol H5ServiceDelegate;

@interface H5Session : NSObject <PSDExpandoProtocol>

@property(nonatomic, assign) H5Mode h5Mode;
@property(nonatomic, copy) NSString *appId;
@property(nonatomic, weak) PSDSession *session;
@property(nonatomic, readonly, weak) H5WebViewController *rootController;

- (id)initWithParams:(NSDictionary *)params;

- (id)initWithParams:(NSDictionary *)params
        withDelegate:(id<H5ServiceDelegate>)delegate
              h5Mode:(H5Mode)h5Mode;


+(void)webviewBugFix:(BOOL)shouldUseWKWebView;
@end
