//
//  MPH5WebViewController.m
//  MPH5Demo
//
//  Created by shifei.wkp on 2019/2/3.
//  Copyright © 2019 alipay. All rights reserved.
//

#import "MPH5WebViewController.h"
#import <MPNebulaAdapter/MPH5ErrorHelper.h>

@interface MPH5WebViewController () <PSDPluginProtocol>

@end

@implementation MPH5WebViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"[NebulaDemo]: 容器中的一个Scene被打开");
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    // 当前页面的WebView
    UIWebView *webView = (UIWebView *)self.psdContentView;
    NSLog(@"[mpaas] webView: %@", webView);
    
    // 当前页面的启动参数
    NSDictionary *expandParams = self.psdScene.createParam.expandParams;
    NSLog(@"[mpaas] expandParams: %@", expandParams);
    
    if ([expandParams count] > 0) {
        [self customNavigationBarWithParams:expandParams];
    }
}

- (void)customNavigationBarWithParams:(NSDictionary *)expandParams
{
    // 定制导航栏背景
    NSString *titleBarColorString = expandParams[@"titleBarColor"];
    if ([titleBarColorString isKindOfClass:[NSString class]] && [titleBarColorString length] > 0) {
        UIColor *titleBarColor = [UIColor colorFromHexString:titleBarColorString];
        [self.navigationController.navigationBar setNavigationBarStyleWithColor:titleBarColor translucent:NO];
        [self.navigationController.navigationBar setNavigationBarBottomLineColor:titleBarColor];
    }
    
    //导航栏是否隐藏，默认不隐藏。设置隐藏后，webview需全屏
    NSString *showTitleBar = expandParams[@"showTitleBar"];
    if (showTitleBar && ![showTitleBar boolValue]) {
        [self.navigationController setNavigationBarHidden:YES];
        
//        // 调整webview的位置
        UIWebView *webView = (UIWebView *)[self psdContentView];
        CGRect frame = webView.frame;
        if (frame.origin.y != 0) {
            frame.origin.y = 0;
        }
//        frame.origin.y = [[UIApplication sharedApplication] statusBarFrame].size.height;
//        frame.size.height -= [[UIApplication sharedApplication] statusBarFrame].size.height;
        webView.frame = frame;
        self.automaticallyAdjustsScrollViewInsets = NO;
        
    }
    
    //导航栏是否透明，默认不透明。设置透明后，webview需全屏
    NSString *transparentTitle = expandParams[@"transparentTitle"];
    if ([transparentTitle isEqualToString:@"always"] || [transparentTitle isEqualToString:@"auto"]) {

        // 导航栏和底部横线变为透明
        UIColor *clearColor = [UIColor clearColor] ;
        [self.navigationController.navigationBar setNavigationBarTranslucentStyle];
        [self.navigationController.navigationBar setNavigationBarStyleWithColor:clearColor translucent:YES];
        
        // 调整webview的位置
        self.edgesForExtendedLayout = UIRectEdgeAll;
        if (@available(iOS 11.0, *)) {
            UIWebView *wb = (UIWebView *)[self psdContentView];
            wb.scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        }else{
            self.automaticallyAdjustsScrollViewInsets = NO;
        }
    }
    
    // 修改默认返回按钮文案颜色
    NSString *backButtonColorString = expandParams[@"backButtonColor"];
    if ([backButtonColorString isKindOfClass:[NSString class]] && [backButtonColorString length] > 0) {
        UIColor *backButtonColor = [UIColor colorFromHexString:backButtonColorString];
        
        NSArray *leftBarButtonItems = self.navigationItem.leftBarButtonItems;
        if ([leftBarButtonItems count] == 1) {
            if (leftBarButtonItems[0] && [leftBarButtonItems[0] isKindOfClass:[AUBarButtonItem class]]) {
                AUBarButtonItem *backItem = leftBarButtonItems[0];
                backItem.titleColor = backButtonColor;
                backItem.backButtonColor = backButtonColor;
            }
        }
    }
    
    // 设置标题颜色
    NSString *titleColorString = expandParams[@"titleColor"];
    if ([titleColorString isKindOfClass:[NSString class]] && [titleColorString length] > 0) {
        UIColor *titleColor = [UIColor colorFromHexString_au:titleColorString];
        id<NBNavigationTitleViewProtocol> titleView = self.navigationItem.titleView;
        [[titleView mainTitleLabel] setFont:[UIFont systemFontOfSize:16]];
        [[titleView mainTitleLabel] setTextColor:titleColor];
    }

}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

//#pragma mark - back
//- (void)back
//{
//    // 触发back事件
//    id<PSDPluginProtocol>  navigationItemPlugin = [[[self psdScene] pluginManager] plugin:@"NBPlugin4NavigationItem"];
//    if ([navigationItemPlugin respondsToSelector:@selector(backItemClicked:)]) {
//        [navigationItemPlugin performSelector:@selector(backItemClicked:) withObject:nil];
//    }
//}

- (NSURL *)url
{
    // 设置当前页面的url
    NSURL *url = [NSURL URLWithString:self.viewControllerProxy.options.url];
    NSLog(@"MTH5WebviewController current url :%@", url);
    return url;
}

#pragma mark - 注册为容器插件
- (void)nbViewControllerInit
{
    [super nbViewControllerInit];
    
    PSDSession *session = [self viewControllerProxy].psdSession;
    [session addEventListener:kEvent_Navigation_All
                 withListener:self
                   useCapture:NO];
    [session addEventListener:kEvent_Page_All
                 withListener:self
                   useCapture:NO];
    
}

- (NSString *)name
{
    return NSStringFromClass([self class]);
}

#pragma mark - 对应UIWebViewDelegate的委托实现

- (void)handleEvent:(PSDEvent *)event
{
    if (![[event.context currentViewController] isEqual:self]) {
        return;
    }
    if ([kEvent_Navigation_Start isEqualToString:event.eventType]) {
        BOOL shouldStart = [self handleContentViewShouldStartLoad:(id)event ];
        
        if (!shouldStart) {
            [event preventDefault];
        }
    }
    else if ([kEvent_Page_Load_Start isEqualToString:event.eventType]) {
        [self handleContentViewDidStartLoad:(id)event];
    }
    else if ([kEvent_Page_Load_Complete isEqualToString:event.eventType]) {
        [self handleContentViewDidFinishLoad:(id)event];
    }
    else if ([kEvent_Navigation_Error isEqualToString:event.eventType]) {
        [self handleContentViewDidFailLoad:(id)event];
    }
    else if ([kNBEvent_Scene_NavigationItem_Left_Back_Click isEqualToString:event.eventType]) {
        
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
