//
//  SCWebSocketHandler.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCWebSocketConfig.h"
#import "SCWebSocketDefines.h"
#import <SocketCraft/SRWebSocket.h>

@class SCWebSocketHandler;

@protocol SCWebSocketHandlerDelegate <NSObject>

-(void)webSocketDidClose:(SCWebSocketHandler*)handler;

@end

@interface SCWebSocketHandler : NSObject<SRWebSocketDelegate>

@property (nonatomic) NSString*             appID;              //小程序的唯一标识
@property (nonatomic) NSString*             socketTaskID;       //同一小程序下socketTask唯一标识

@property (nonatomic) UInt64                appVersion;         //小程序版本

@property (nonatomic) SCWebSocketConfig*    webSocketConfig;    //当前handler的配置

@property (nonatomic) BOOL                  isOpen;

@property (nonatomic) SRWebSocket*          webSocket;          //socket结构

@property (nonatomic) dispatch_queue_t      workerQueue;        

@property (nonatomic,weak) id<SCWebSocketHandlerDelegate> delegate;

@property (nonatomic) callBackOnSCWebSocketOpen  openCallBack;
@property (nonatomic) callBackOnSCWebSocketRecieveMessage messageCallBack;
@property (nonatomic) callBackOnSCWebSocketError errorCallBack;
@property (nonatomic) callBackOnSCWebSocketClose closeCallBack;

-(void)callbackWithError:(NSError*)err;

-(void)close;
-(void)closeWithCode:(NSInteger)code reason:(NSString*)reason;

-(instancetype)initWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID appVersion:(UInt64)version workerQueue:(dispatch_queue_t)queue;

-(void)openWithRequest:(NSMutableURLRequest*)request isIgnoreCheckDomain:(BOOL)ignDomain completionHandler:(openWebSocketCompetionHandler)handler;

-(void)sendMessage:(id)msg completionHandler:(sendWebSocketMessageCompletionHandler)handler;

-(void)webSocketAppid:(NSString*)appid version:(UInt64)version upFlow:(NSInteger)up downFlow:(NSInteger)down;

@end

































