//
//  DemoBasicViewContriller.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/16.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoBaseViewController.h"

#define kConentViewTop (self.navigationController.navigationBar.bottom + 36)

@implementation DemoBaseViewController

- (void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    
    self.headerView.origin_mp = CGPointMake((self.view.width-self.headerView.width)/2, kConentViewTop);
    CGPoint point = self.footerView.origin_mp;
    self.footerView.origin_mp = CGPointMake((self.view.width-self.footerView.width)/2, MAX(self.view.bottom-15-self.footerView.height, point.y));
    self.contentView.top = self.headerView.bottom;
    self.contentView.height = self.view.height - self.headerView.bottom;
}

- (void)codeteleport_completed
{
    NSLog(@"DemoBaseViewController:codeteleport_completed");
//    [AUThemeManager loadTheme];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.01 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [AUThemeManager loadTheme];
        [self.view removeAllSubviews];
        [self viewDidLoad];
    });
}

- (void)viewDidLoad
{
//    self.auBundleName = @"AntUI";
    [super viewDidLoad];
    
    self.view.backgroundColor = kDemoGlobalBackgroundColor;
    self.contentView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.width, self.view.height - kConentViewTop)];
    self.contentView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:self.contentView];
    
    self.headerView = [[DemoPageHeaderView alloc] init];
    [self.view addSubview:self.headerView];
    
    self.footerView = [[DemoPageFooterView alloc] init];
    [self.view addSubview:self.footerView];
    
    self.headerView.titleLabel.text = self.title;
    self.headerView.frame = CGRectMake((self.view.width-self.headerView.width)/2, kConentViewTop, self.headerView.width, 36 + DemoHeaderViewMarginBottom);
    self.footerView.frame = CGRectMake((self.view.width-self.footerView.width)/2, self.view.bottom-15-self.footerView.height, self.footerView.width, self.footerView.height);
    
    self.topMargin = self.headerView.bottom;
}

- (void)updateFooterView
{
    CGPoint point = self.footerView.origin_mp;
    point.y = self.topMargin;
    self.footerView.origin_mp = point;
    
    self.topMargin = self.footerView.bottom + 15;
}


- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    AUBarButtonItem *item = (AUBarButtonItem *)self.navigationItem.leftBarButtonItem;
    if(!item)
    {
        item = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(back)];
    }
    item.titleColor = [UIColor whiteColor];
    item.backButtonImage = AUBundleImage(@"back_button_normal_white");
    self.navigationItem.leftBarButtonItem = item;
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:RGB(0x85adf9) translucent:YES];
    [self.navigationController.navigationBar setNavigationBarBottomLineColor:RGB(0x85adf9)];
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:RGB(0xffffff)];
    
    [self.view setNeedsLayout];
//    [self.view layoutIfNeeded];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"DTViewControllerDidAppearNotifications" object:self];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"DTViewControllerDidDisappearNotifications" object:self];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"DTViewControllerWillDisappearNotifications" object:self];
}

- (void)back
{
    [self.navigationController popViewControllerAnimated:YES];
}

//- (UIStatusBarStyle)preferredStatusBarStyle
//{
//    return UIStatusBarStyleLightContent;
//}

//
//- (void)viewDidAppear:(BOOL)animated
//{
//    [super viewDidAppear:animated];
//
//}

- (UIView *)getANewSpliteLineWithTop:(CGFloat) top
                                left:(CGFloat) left
{
    CGFloat lineHeight = 1/[UIScreen mainScreen].scale;
    UIView *line = [[UIView alloc] initWithFrame:CGRectMake(left, top, [UIScreen mainScreen].bounds.size.width - left, lineHeight)];
    line.backgroundColor = RGB(0xdddddd);
    return line;
}

@end


@interface UINavigationController (StatusBar)
- (UIStatusBarStyle)preferredStatusBarStyle;
@end

@implementation UINavigationController (StatusBar)
- (UIStatusBarStyle)preferredStatusBarStyle {
//    return [[self topViewController] preferredStatusBarStyle];
    return UIStatusBarStyleLightContent;
}
@end
