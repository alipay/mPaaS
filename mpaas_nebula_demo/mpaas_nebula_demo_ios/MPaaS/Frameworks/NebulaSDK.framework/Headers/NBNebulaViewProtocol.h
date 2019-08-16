//
//  NBNebulaViewProtocol.h
//  NebulaSDK
//
//  Created by chenwenhong on 15/12/28.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NBContentViewPageDelegate;

// 默认继承自UIWebView不需要实现，也不要实现
@protocol NBContentViewProtocol <PSDContentViewProtocol>

@property(nonatomic) UIViewAutoresizing                     autoresizingMask;
@property(nonatomic, copy) NSString                         *channelId;
@property(nonatomic, copy) NSString                         *nbl_id;
@property(nonatomic, weak) id<NBContentViewPageDelegate>    pageDelegate;

- (void)contentViewDidLoad;

- (void)contentViewDidPause;

- (void)contentViewDidResume;

- (void)contentViewDidClose;

@end


@protocol NBContentViewPageDelegate <NSObject>

- (void)contentViewPageStart:(NBContentViewPageProfile *)page;

- (void)contentViewPageComplete:(NBContentViewPageProfile *)page;

- (void)contentViewPagePaused:(NBContentViewPageProfile *)page;

- (void)contentViewPageResume:(NBContentViewPageProfile *)page;

- (void)contentViewPageEnd:(NBContentViewPageProfile *)page;

@end