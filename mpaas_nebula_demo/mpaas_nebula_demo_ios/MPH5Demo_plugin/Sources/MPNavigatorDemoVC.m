//
//  MPNavigatorDemoVC.m
//  MPFrameworkDemo
//
//  Created by yangwei on 2019/2/20.
//  Copyright © 2019年 alipay. All rights reserved.
//

#import "MPNavigatorDemoVC.h"
#import "MPNavigatorScrollVC.h"

#import <mPaas/MPJSONKit.h>

@interface MPNavigatorDemoVC ()

@end

@implementation MPNavigatorDemoVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title  = @"定制导航栏";
    self.view.backgroundColor = [UIColor grayColor];
    
    CREATE_UI({
        BUTTON_WITH_ACTION(@"修改导航栏背景颜色", gotoUpdateBackgroundColor)
        BUTTON_WITH_ACTION(@"透明导航栏", gotoTransparency)
        BUTTON_WITH_ACTION(@"隐藏导航栏", gotoHideNavigator)
        BUTTON_WITH_ACTION(@"显示导航栏", gotoShowNavigator)
        BUTTON_WITH_ACTION(@"修改标题颜色", gotoUpdateTitleColor)
        BUTTON_WITH_ACTION(@"修改默认返回按钮文案颜色", gotoUpdateBackTitleColor)
        
    })
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    //pageStart
    APLogTrackContext *context = [APLogTrackContext new];
    context.spmId = @"http://www.baidu.com/hx" ;
    context.param = @{@"url":@"http://www.baidu.com/hx"};
    context.level = @"loggerLevelMedium";
    [APLogTrackContext filterContext:context];
    [APLogTrackManager logPageStartWithIndex:self context:context];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    //pageEnd
    [APLogTrackManager logPageEndWithIndex:self];
}

#pragma mark 进入页面时修改，H5需通过启动参数设置
- (void)gotoUpdateBackgroundColor
{
    // 修改导航栏背景颜色
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"titleBarColor":@"16775138", @"showOptionMenu":@NO}];
}

- (void)gotoTransparency
{
    // 打开H5页面，设置透明导航栏
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"transparentTitle":@"auto"}];
}

- (void)gotoHideNavigator
{
    // 打开H5页面，隐藏导航栏
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"showTitleBar":@NO}];
}

- (void)gotoShowNavigator
{
    // 打开H5页面，显示导航栏
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"showTitleBar":@YES, @"showOptionMenu":@NO}];
}

- (void)gotoUpdateStatusBarStyle
{
    // 修改状态栏颜色
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
}

- (void)gotoUpdateBackTitleColor
{
    // 修改默认返回按钮文案颜色
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"backButtonColor":@"ff0000", @"showOptionMenu":@NO}];
}

- (void)gotoUpdateTitleColor
{
    // 修改标题颜色
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://tech.antfin.com", @"titleColor":@"ff0000", @"showOptionMenu":@NO}];
}

@end
