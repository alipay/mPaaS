//
//  largeNaviBarDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/9/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "largeNaviBarDemoViewController.h"
#import "CAGradientLayerDemoFactory.h"

@implementation largeNaviBarDemoViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.view = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    [CAGradientLayerDemoFactory removeCurrentNaviLayer:self.navigationController.navigationBar];
    
    if (@available(iOS 11.0, *)) {
        self.navigationController.navigationBar.prefersLargeTitles = YES;
    }
    self.title = @"ios11大标题样式";
    
//    if (@available(iOS 11.0, *)) {
//        self.navigationItem.searchController = [[UISearchController alloc] initWithSearchResultsController:self];
//        self.navigationItem.hidesSearchBarWhenScrolling = YES;
//    } else {
//        // Fallback on earlier versions
//    }
    
//    self.navigationController.title = @"iOS11新特性"; // 该方式不起作用
    
    
    AUBarButtonItem *cancelItem = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(cancel)];
    self.navigationItem.leftBarButtonItem = cancelItem;
    
    AUBarButtonItem *righItem = [AUBarButtonItem barButtonItemWithTitle:@"筛选" target:self action:@selector(clickRightItem:)];
    self.navigationItem.rightBarButtonItems = @[righItem];
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor whiteColor] translucent:YES];
    UIColor *titleColor = [UINavigationBar getNavigationBarTitleDefaultColor];
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:titleColor];
    UIColor *botLineColor = [UINavigationBar getNavigationBarBotLineColor];
    [self.navigationController.navigationBar setNavigationBarBottomLineColor:botLineColor];
    
    [(UIScrollView *)self.view setContentSize:CGSizeMake(self.view.width, self.view.height+200)];
}


- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [CAGradientLayerDemoFactory createDemoDefaultLayer:self.navigationController.navigationBar];
    if (@available(iOS 11.0, *)) {
        self.navigationController.navigationBar.prefersLargeTitles = NO;
    }
}


- (void)cancel
{
    //    [self dismissViewControllerAnimated:YES completion:NULL];
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)clickRightItem:(id)sender
{
    
}

@end
