//
//  TitleBarSegmentDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TitleBarSegmentDemoViewController.h"
#import "CAGradientLayerDemoFactory.h"

@implementation TitleBarSegmentDemoViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.view.backgroundColor = [UIColor whiteColor];
    
    [CAGradientLayerDemoFactory removeCurrentNaviLayer:self.navigationController.navigationBar];
    
    
    AUBarButtonItem *cancelItem = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(cancel)];
    self.navigationItem.leftBarButtonItem = cancelItem;
    
    AUBarButtonItem *righItem = [AUBarButtonItem barButtonItemWithTitle:@"筛选" target:self action:nil];
    self.navigationItem.rightBarButtonItems = @[righItem];
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor whiteColor] translucent:YES];
    UIColor *titleColor = [UINavigationBar getNavigationBarTitleDefaultColor];
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:titleColor];
    UIColor *botLineColor = [UINavigationBar getNavigationBarBotLineColor];
    [self.navigationController.navigationBar setNavigationBarBottomLineColor:botLineColor];
    
    
    AUTitleBarSegment *titleBatSegment = [[AUTitleBarSegment alloc] init];
    [titleBatSegment insertSegmentWithTitle:@"Tab1标题" atIndex:0 animated:YES];
    [titleBatSegment insertSegmentWithTitle:@"Tab2标题" atIndex:1 animated:YES];
    titleBatSegment.selectedSegmentIndex = 0;
    titleBatSegment.frame = CGRectMake(0, 0, 180, 26);
    self.navigationItem.titleView = titleBatSegment;
    
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [CAGradientLayerDemoFactory createDemoDefaultLayer:self.navigationController.navigationBar];
}

- (void)cancel
{
    //    [self dismissViewControllerAnimated:YES completion:NULL];
    [self.navigationController popViewControllerAnimated:YES];
}

@end
