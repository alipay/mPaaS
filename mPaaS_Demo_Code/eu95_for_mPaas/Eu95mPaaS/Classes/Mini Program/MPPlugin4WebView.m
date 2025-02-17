//
//  MPPlugin4WebView.m
//  CarLife
//
//  Created by 冯冠华 on 2024/5/29.
//  Copyright © 2024 Sunboxsoft. All rights reserved.
//

#import "MPPlugin4WebView.h"
#import <AriverNebulaBiz/H5Defines.h>
#import <AriverNebulaPoseidon/PSDDefine.h>
#import <AriverNebulaPoseidon/PSDEvent.h>
#import <AriverNebulaSDK/NBDefines.h>
#import <AriverNebulaPoseidon/PSDInvocationEvent.h>

@implementation MPPlugin4WebView

- (void)pluginDidLoad{
    // -- 拦截调用的jsapi信息
    [self.target addEventListener:kEvent_Invocation_Event_Start 
                     withListener:self
                       useCapture:NO];
    [self.target addEventListener:kEvent_Invocation_Invoke 
                     withListener:self
                       useCapture:NO];
    [self.target addEventListener:kEvent_Invocation_All 
                     withListener:self
                       useCapture:NO];
    
//    [self.target addEventListener:kEvent_Scene_Disappear_Before withListener:self useCapture:NO];
//    
    [self.target addEventListener:kEvent_Proxy_Request_Start_Handler 
                     withListener:self
                       useCapture:NO];
    
    
    [super pluginDidLoad];
}


// 目前通过插件监听事件解决横竖屏无法切换的问题
- (void)handleEvent:(RVKEvent *)event
{
    [super handleEvent:event];
//    if([kEvent_Scene_Disappear_Before isEqualToString:event.eventType]) {
//        [event preventDefault];
//        [event stopPropagation];
//    }
    if([kEvent_Invocation_Event_Start isEqualToString:event.eventType] ||
       [kEvent_Invocation_Invoke isEqualToString:event.eventType]){
        
        RVKInvocationEvent *invocationEvent = (RVKInvocationEvent *)event;
        NSString *apiName = invocationEvent.invocationName;
        NSDictionary *tmpDic = invocationEvent.invocationData;
        
        NSLog(@"customInvocation %@", apiName);
        if([apiName isEqualToString:@"resume"]){
        }

        if ([apiName isEqualToString:@"getCurrentLocation"]) {
            //to do怎么给小程序callback消息
            
        }
        NSLog(@"监听所有事件-- %@--%@",apiName,invocationEvent.invocationData);
    }
    
    if([kEvent_Proxy_Request_Start_Handler isEqualToString:event.eventType]){
        NSLog(@"-----请求开始----%@",event.eventType);
        RVKProxyEvent *proxyEvent = (RVKProxyEvent *) event;
        NSURLRequest *req = proxyEvent.request;
        NSDictionary *dictionary = req.allHTTPHeaderFields;
        NSLog(@"dictionary11111=====>>>>%@",dictionary);

        [proxyEvent.customResponse setHeader:@"content-type" value:@"multipart/form-data"];
        NSLog(@"dictionary22222=====>>>>%@",dictionary);
        
//        NSString *path = [req.URL.path lowercaseString];
//        NSLog(@"imageURL path [%d][%@]",arc4random(),path);
//        NSString *imageURL = [req.URL absoluteString];
//        NSLog(@"imageURL path [%@]",arc4random(),imageURL);

        

    }
    
}


- (int)priority
{
    return PSDPluginPriority_High+1;
}

@end

