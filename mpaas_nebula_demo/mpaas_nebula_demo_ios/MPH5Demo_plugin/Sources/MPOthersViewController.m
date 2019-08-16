//
//  MPOthersViewController.m
//  MPH5Demo_plugin
//
//  Created by yangwei on 2019/8/12.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPOthersViewController.h"
#import "MPNavigatorDemoVC.h"

@interface MPOthersViewController ()

@end

@implementation MPOthersViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"自定义设置";
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(30, 150, [UIScreen mainScreen].bounds.size.width-60, 44);
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"定制导航栏" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(customNavigatorBar) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectOffset(button.frame, 0, 80);
    button1.backgroundColor = [UIColor blueColor];
    [button1 setTitle:@"内嵌 WebView" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(openWebView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectOffset(button1.frame, 0, 80);
    button2.backgroundColor = [UIColor blueColor];
    [button2 setTitle:@"打开本地 Html" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(openHtml) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
}

- (void)customNavigatorBar
{
    MPNavigatorDemoVC *vc = [MPNavigatorDemoVC new];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)openWebView
{
    UIView *customView = [[UIView alloc] initWithFrame:CGRectMake(0, 400, AUCommonUIGetScreenWidth(), 320)];
    customView.backgroundColor = [UIColor redColor];
    [self.view addSubview:customView];
    
    UIViewController *vc = (UIViewController *)[NBServiceGet() createNBViewController:@{@"url":@"http://tech.antfin.com"}];
    UIWebView *webView = vc.psdContentView;
    webView.frame = CGRectMake(0, 0, AUCommonUIGetScreenWidth(), 320);
    [customView addSubview:webView];
}

- (void)openHtml {
    NSString *path = [[NSBundle mainBundle].bundlePath stringByAppendingFormat:@"/%@", @"H52Native.html"];
    if ([path length] > 0) {
        [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": path, @"showOptionMenu":@NO}];
    }
}

@end
