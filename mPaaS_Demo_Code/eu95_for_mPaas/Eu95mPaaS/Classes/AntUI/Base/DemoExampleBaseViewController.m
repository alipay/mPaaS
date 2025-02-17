//
//  DemoExampleBaseViewController.m
//  AntUIDemo
//
//  Created by Wang on 2018/7/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "DemoExampleBaseViewController.h"
#import "CAGradientLayerDemoFactory.h"

@interface DemoExampleBaseViewController ()

@end

@implementation DemoExampleBaseViewController

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    AUBarButtonItem *cancelItem = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(back)];
    self.navigationItem.leftBarButtonItem = cancelItem;
    
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor colorWithRGB:0x111111 alpha:0.f] translucent:YES];
    UIColor *titleColor = [UINavigationBar getNavigationBarTitleDefaultColor];
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:titleColor];
    UIColor *botLineColor = [UINavigationBar getNavigationBarBotLineColor];
    [self.navigationController.navigationBar setNavigationBarBottomLineColor:botLineColor];
    
    [CAGradientLayerDemoFactory removeCurrentNaviLayer:self.navigationController.navigationBar];
}
-(void) back
{
    [self.navigationController popViewControllerAnimated:YES];
}

@end
