//
//  MPH5WebViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/4/18.
//

#import "MPH5WebViewController.h"
#import <AriverMPNebulaAdapter/MPH5ErrorHelper.h>

@interface MPH5WebViewController ()<PSDPluginProtocol,MPMpaaSWKNavigationDelegateProtocol,WKUIDelegate>

@end

@implementation MPH5WebViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}



#pragma mark - 注册为容器插件
- (void)viewControllerIMPDidInit
{
//    [super nbViewControllerInit];
//    
//    PSDSession *session = [self viewControllerProxy].psdSession;
//    [session setExpando:@"" withValue:nil];
//    
//    [session addEventListener:kEvent_Navigation_All
//                 withListener:self
//                   useCapture:NO];
//    [session addEventListener:kEvent_Page_All
//                 withListener:self
//                   useCapture:NO];
//    [session addEventListener:kEvent_All
//                  withListener:self
//                    useCapture:NO];
//   
//    [PSDProxy addEventListener:kEvent_Page_Load_FirstByte
//                  withListener:self
//                    useCapture:NO];
//    [PSDProxy addEventListener:kEvent_Proxy_Request_Finish
//                  withListener:self
//                    useCapture:NO];
    [PSDProxy addEventListener:kEvent_Proxy_Request_Start_Handler
                  withListener:self
                    useCapture:NO];
//    [PSDProxy addEventListener:kEvent_Proxy_Request_FinishReceiveData
//                  withListener:self
//                    useCapture:NO];
//    [PSDProxy addEventListener:kEvent_Navigation_Complete
//                  withListener:self
//                    useCapture:NO];
//    [PSDProxy addEventListener:kEvent_Navigation_Start
//                  withListener:self
//                    useCapture:NO];
}


- (NSString *)name
{
    return NSStringFromClass([self class]);
}

//-(UIView *)customNavigationBar{
//    
//}


#pragma mark - 对应UIWebViewDelegate的委托实现

- (void)handleEvent:(PSDEvent *)event
{
    [super handleEvent:event];
    
    if (![[event.context currentViewController] isEqual:self]) {
        return;
    }
    
    NSLog(@"---------%@",event.eventType);
    if ([event.eventType isEqualToString:kEvent_Page_Create]) {
        NSLog(@"----容器页面创建-----%@",event.eventType);
        return;
    }
    if ([event.eventType isEqualToString:kEvent_Page_Load_Start]) {
        NSLog(@"----容器页面开始加载-----%@",event.eventType);
//        NSString *str1 = [self.url absoluteString];
//        if ([str1 isEqualToString:@"https://render.alipay.com/p/s/tinyapperror/?appId=0000000111111100&errorCode=1001"]) {
//            [event preventDefault];
//            [event preventDefault];
//        }

        return;
    }
    if ([event.eventType isEqualToString:kEvent_Page_Load_FirstByte]) {
        NSLog(@"----已请求第一个字节-----%@",event.eventType);
        return;
    }
    if ([event.eventType isEqualToString:kEvent_Page_Load_DomReady]) {
        NSLog(@"----容器dom已ready-----%@",event.eventType);
        return;
    }
    if ([event.eventType isEqualToString:kEvent_Page_Load_Complete]) {
        NSLog(@"-----容器加载完成----%@",event.eventType);
        // 此事件可拦截当前url是否加载
        NSLog(@"%@",self.appId);
        return;
    }
    
    if ([event.eventType isEqualToString:kEvent_Page_Load_Error]) {
        NSLog(@"-----容器加载失败----%@",event.eventType);
        return;
    }
    if ([event.eventType isEqualToString:kEvent_Page_Destroy]) {
        NSLog(@"----已销毁-----%@",event.eventType);
        return;
    }
    
    if ([kEvent_Invocation_Event_Start isEqualToString:event.eventType] || [kEvent_Invocation_Invoke isEqualToString:event.eventType]) {
        PSDInvocationEvent *invocationEvent = (PSDInvocationEvent *)event;
        NSString *apiName = invocationEvent.invocationName;
        NSLog(@"[jsapi : %@]",apiName);
        NSLog(@"[jsapi url ==== %@]",invocationEvent.url);

        if([apiName isEqualToString:@"resume"]){
            [event preventDefault];
            [event stopPropagation];
        }
        if([apiName isEqualToString:@"alert"]){
            [event preventDefault];
            [event stopPropagation];
            
        }
    }
    
    if ([kEvent_Navigation_Start isEqualToString:event.eventType]) {
        // 此事件可拦截当前url是否加载
        BOOL shouldStart = [self handleContentViewShouldStartLoad:(id)event ];
        
        if (!shouldStart) {
            [event preventDefault];
        }
        
        PSDProxyEvent *proxyEvent = (PSDProxyEvent *) event;
        NSURLRequest *req = proxyEvent.request;
        NSString *path = [req.URL.path lowercaseString];
        NSLog(@"%@",proxyEvent.request);
        NSLog(@"%@",path);

    }
    else if ([kEvent_Page_Load_Start isEqualToString:event.eventType]) {
        [self handleContentViewDidStartLoad:(id)event];
    }
    else if ([kEvent_Navigation_Complete isEqualToString:event.eventType]) {
        NSLog(@"-----容器资源加载完成----%@",event.eventType);
        

        return;
    }
    else if ([kEvent_Navigation_Error isEqualToString:event.eventType] || [kEvent_Invocation_Error isEqualToString:event.eventType] || [kEvent_Page_Load_Error isEqualToString:event.eventType]) {
        [self handleContentViewDidFailLoad:(id)event];
    }
    
    else if([kEvent_Proxy_Request_Start_Handler isEqualToString:event.eventType] && [event isKindOfClass:[PSDProxyEvent class]]){
        
        PSDProxyEvent *proxyEvent = (PSDProxyEvent *) event;
        NSURLRequest *req = proxyEvent.request;
        NSDictionary *dictionary = req.allHTTPHeaderFields;
        NSLog(@"dictionary11111=====>>>>%@",dictionary);

        [proxyEvent.customResponse setHeader:@"content-type" value:@"multipart/form-data"];
        NSLog(@"dictionary22222=====>>>>%@",dictionary);

//        NSURLRequest *req = proxyEvent.request;
//        NSString *path = [req.URL.path lowercaseString];
//        NSLog(@"imageURL path [%d][%@]",arc4random(),path);
//        NSString *imageURL = [req.URL absoluteString];
//        NSLog(@"imageURL path [%@]",arc4random(),imageURL);

        
    }
    else if ([kEvent_Proxy_Request_Finish isEqualToString:event.eventType]){
        PSDProxyEvent *proxyEvent = (PSDProxyEvent *) event;
        NSURLRequest *req = proxyEvent.request;
        NSString *path = [req.URL.path lowercaseString];
        NSLog(@"%@",proxyEvent.request);
        NSLog(@"%@",path);
    }
}

- (BOOL)handleContentViewShouldStartLoad:(PSDNavigationEvent *)event
{
    return YES;
}

- (void)handleContentViewDidStartLoad:(PSDPageEvent *)event
{
    
}

- (void)handleContentViewDidFinishLoad:(PSDPageEvent *)event
{
    
}



- (void)handleContentViewDidFailLoad:(PSDNavigationEvent *)event
{
    PSDNavigationEvent *naviEvent = (PSDNavigationEvent *)event;
    NSError *error = naviEvent.error;
    [MPH5ErrorHelper handlErrorWithWebView:(UIWebView *)self.psdContentView error:error];
}



@end
