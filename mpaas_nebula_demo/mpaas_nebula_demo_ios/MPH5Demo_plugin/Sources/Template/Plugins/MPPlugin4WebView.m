//
//  MPPlugin4WebView.m
//  MPH5Demo_plugin
//
//  Created by yangwei on 2019/8/12.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPPlugin4WebView.h"

@implementation MPPlugin4WebView

- (void)pluginDidLoad
{
    self.scope = kPSDScope_Scene;
    
    // -- 拦截调用的jsapi信息
    [self.target addEventListener:kEvent_Invocation_Event_Start withListener:self useCapture:NO];
    [self.target addEventListener:kEvent_Invocation_Invoke withListener:self useCapture:NO];
    
    // -- 拦截H5页面请求事件
    [self.target addEventListener:kEvent_Proxy_Request_Start_Handler withListener:self useCapture:NO];
    
    [super pluginDidLoad];
}

- (void)handleEvent:(PSDEvent *)event
{
    [super handleEvent:event];
    
    if([kEvent_Invocation_Event_Start isEqualToString:event.eventType] ||
             [kEvent_Invocation_Invoke isEqualToString:event.eventType]){
        PSDInvocationEvent *invocationEvent = (PSDInvocationEvent *)event;
        NSString *apiName = invocationEvent.invocationName;
        if ([apiName isEqualToString:@"setOptionMenu"]) {
            NSLog(@"[jsapi param: %@]", invocationEvent.invocationData);
        }
        
    }else if ([kEvent_Proxy_Request_Start_Handler isEqualToString:event.eventType]
              && [event isKindOfClass:[PSDProxyEvent class]] ){
        // 离线包走fallback，且fallbackurl地址为空时，直接跳转到默认错误页
        PSDProxyEvent *proxyEvent = (PSDProxyEvent*) event;
        NSMutableURLRequest *redirectReq = proxyEvent.request.mutableCopy;
        NSString *appId = event.context.currentSession.createParam.expandParams[@"appId"];
        NAMApp *app = [NAMServiceGet() findApp:appId version:nil];
        NSString *fallBackUrl = app.fallback_host;
        NSString *vhost = app.vhost;;
        NSString *url = redirectReq.URL.absoluteString;
        if ([url containsString:vhost] &&  [fallBackUrl length] <= 0) {
            
            UIWebView *webView = (UIWebView *)event.context.currentViewControllerProxy.psdContentView;
            NSString *filePath = [[NSBundle mainBundle] pathForResource:@"h5_page_error" ofType:@".html"];
            NSString *htmlString = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil];
            NSData *data = [htmlString dataUsingEncoding:NSUTF8StringEncoding];
            
            [webView loadData:data
                     MIMEType:@"text/html"
             textEncodingName:@"utf-8"
                      baseURL:webView.request.URL];
            
            [proxyEvent preventDefault];
            
        }
    }
}

- (int)priority
{
    return PSDPluginPriority_High+1;
}

@end
