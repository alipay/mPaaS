//
//  SCWebSocketDefines.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef SCWebSocketDefines_h
#define SCWebSocketDefines_h

#define DEFAULT_TIMEOUT_MILLSECOND 30000

#define DISPATCH_QUEUE_NAME "com.portal.websocket"

@class SCWebSocketHandler;
@protocol SCWebSocketLogDelegate,SCWebSocketStorageDelegate;

extern id<SCWebSocketStorageDelegate> scWebSocketStorage;

typedef void (^openWebSocketCompetionHandler)(NSString* appid, NSString *socketTaskID, NSError* error);
typedef void (^sendWebSocketMessageCompletionHandler)(NSString* appid, NSString *socketTaskID, NSError* error);

typedef void (^connectSCWebSocketCompletionHandler)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^sendSCWebSocketMessageCompletionHandler)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^callBackOnSCWebSocketOpen)(NSString* appid, NSString *socketTaskID);
typedef void (^callBackOnSCWebSocketRecieveMessage)(NSString* appid, NSString *socketTaskID,id data);
typedef void (^callBackOnSCWebSocketError)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^callBackOnSCWebSocketClose)(NSString* appid, NSString *socketTaskID,NSString* reason);

typedef NS_ENUM(NSInteger,SCWebSocketErrorCode) {
    SCErrorCodeSendUnopen = -10001,
    SCErrorCodeMsgNotStringOrData = -10002,
    SCErrorCodeMsgSendToNoSocket = -10003,
};

#define SC_DOMAIN @"scWebSocket"
#define SC_ERROR(errorcode) [[NSError alloc] initWithDomain:SC_DOMAIN code:errorcode userInfo:nil]

#endif /* SCWebSocketDefines_h */
