//
//  DoubleTitleBarDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DoubleTitleBarDemoViewController.h"
#import "CAGradientLayerDemoFactory.h"
//#import "AUDoubleTitleView.h"

@implementation DoubleTitleBarDemoViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    [CAGradientLayerDemoFactory removeCurrentNaviLayer:self.navigationController.navigationBar];
    
    self.navigationItem.titleView = [[AUDoubleTitleView alloc] initWithTitle:@"主标题" detailTitle:@"副标题"];
    
//    AUBarButtonItem *cancelItem = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(cancel)];
//    self.navigationItem.leftBarButtonItem = cancelItem;
    
    AUBarButtonItem *righItem = [AUBarButtonItem barButtonItemWithTitle:@"筛选" target:self action:@selector(clickRightItem:)];
    self.navigationItem.rightBarButtonItems = @[righItem];
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor whiteColor] translucent:YES];
    UIColor *titleColor = [UINavigationBar getNavigationBarTitleDefaultColor];
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:titleColor];
    UIColor *botLineColor = [UINavigationBar getNavigationBarBotLineColor];
    [self.navigationController.navigationBar setNavigationBarBottomLineColor:botLineColor];
}


- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [CAGradientLayerDemoFactory createDemoDefaultLayer:self.navigationController.navigationBar];
}


//- (void)cancel
//{
//    //    [self dismissViewControllerAnimated:YES completion:NULL];
//    [self.navigationController popViewControllerAnimated:YES];
//}

- (void)clickRightItem:(id)sender
{
    
}

@end
