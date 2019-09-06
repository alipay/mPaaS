//
//  DemoViewController.m
//  MyH5Application
//
//  Created by Evan on 2019/08/22.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    

    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(30, 150, [UIScreen mainScreen].bounds.size.width-60, 44);
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"在线 URL" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(openOnline) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectOffset(button.frame, 0, 80);
    button1.backgroundColor = [UIColor blueColor];
    [button1 setTitle:@"前端调用 native" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(openJsApi) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectOffset(button1.frame, 0, 80);
    button2.backgroundColor = [UIColor blueColor];
    [button2 setTitle:@"前端调用自定义 JSAPI" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(openCusJsApi) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    button3.frame = CGRectOffset(button2.frame, 0, 80);
    button3.backgroundColor = [UIColor blueColor];
    [button3 setTitle:@"自定义导航栏" forState:UIControlStateNormal];
    [button3 addTarget:self action:@selector(customNavigatorBar) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
    
    
}

- (void)openOnline
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://tech.antfin.com"}];
}

- (void)openJsApi
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://mcube-prod.oss-cn-hangzhou.aliyuncs.com/570DA89281533-default/80000000/1.0.0.1_all/nebula/fallback/h5_to_native.html"}];
}

- (void)openCusJsApi
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://mcube-prod.oss-cn-hangzhou.aliyuncs.com/570DA89281533-default/80000001/1.0.0.1_all/nebula/fallback/custom_jsapi.html"}];
}

- (void)customNavigatorBar
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://tech.antfin.com"}];
}


@end
