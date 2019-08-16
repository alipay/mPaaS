//
//  NBComponent.h
//  NebulaPlugins
//
//  Created by theone on 17/5/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^NBComponentResourceCallback)(NSData *resource);

@class NBComponentContext;

@interface NBComponent : NSObject <NBComponentProtocol>

@property(nonatomic, weak) id<NBComponentMessageDelegate>  nbComponentMessageDelegate;

@property(nonatomic, copy)            NSString *type;
@property(nonatomic, strong)          NSDictionary *data;
@property(nonatomic, copy)            NSString *componentId;
@property(nonatomic, strong)          NBComponentContext *context;

/**
 业务需要重写这个方法在此方法中创建一个需要插入到WebView中的View否则无法正常工作

 @param config 配置项
 @param messageDelegate 消息发送的代理
 @return component
 */
- (id)initWithConfig:(NSDictionary *)config
     messageDelegate:(id<NBComponentMessageDelegate>)messageDelegate;

/**
 component通过传入url来获取url对应的资源来源可能是本地离线包资源或者线上
 @param url 资源url
 @param callback 回调函数
 @return void
 */
- (void)getComponentResourceDataWithUrl:(NSString *)url callback:(NBComponentResourceCallback)callback;
@end
