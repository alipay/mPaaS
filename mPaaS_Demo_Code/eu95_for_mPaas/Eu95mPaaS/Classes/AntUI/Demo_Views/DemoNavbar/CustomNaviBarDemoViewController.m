//
//  CustomNaviBarDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/9/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "CustomNaviBarDemoViewController.h"

@interface CustomNaviBarDemoViewController ()
{
    AUCustomNavigationBar *_customBar;
}
@end

@implementation CustomNaviBarDemoViewController

- (void)test
{
    _customBar.title = @"自定义导航栏2";
    [_customBar setTitleView:nil];
    _customBar.autoHideTitleLabel = YES;
    [self performSelector:@selector(test1) withObject:nil afterDelay:3.f];
}

- (void)test1
{
    _customBar.title = @"自定义导航栏3";
    [_customBar setTitleView:[[UIImageView alloc] initWithImage:[UIImage imageWithColor_au:[UIColor colorWithRGB:0x108ee9] size:CGSizeMake(1000, 1000)]]];
    UIImage *img = [[AUIconView alloc] initWithFrame:CGRectMake(0, 0, 22, 22) name:kICONFONT_USER_SETTING].image;
    _customBar.rightItemImage = img;
    _customBar.autoHideTitleLabel = YES;
//    [self performSelector:@selector(test2) withObject:nil afterDelay:3.f];
}

- (void)test2
{
    _customBar.title = @"自定义导航栏4";
    [_customBar setTitleView:nil];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    AUCustomNavigationBar *customBar = [AUCustomNavigationBar navigationBarForCurrentVC:self];
    _customBar.autoHideTitleLabel = YES;
//    customBar.rightItemTitle = @"设置";
//    UIImage *img = [[AUIconView alloc] initWithFrame:CGRectMake(0, 0, 22, 22) name:kICONFONT_USER_SETTING].image;
//    customBar.rightItemImage = img;
    customBar.title = @"自定义导航栏1自定义导航栏1自定义导航栏1自定义导航栏1自定义导航栏1";
//    customBar.autoHideTitleLabel = YES;
    
//    AUButton *button = [AUButton buttonWithStyle:AUButtonStyleNone];
//    [button setTitle:@"设置XXXX" forState:UIControlStateNormal];
//    [button setTitleColor:AU_COLOR5 forState:UIControlStateNormal];
    
    AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyleNone];
    [button1 setImage:[[AUIconView alloc] initWithFrame:CGRectMake(0, 0, 22, 22) name:kICONFONT_USER_SETTING].image forState:UIControlStateNormal];
    customBar.rightItemList = @[button1];

//  customBar.rightItemList = @[button, button1];
//    customBar.rightItemList = @[button];
    
//    [customBar setTitleView:[[UIImageView alloc] initWithImage:[UIImage imageWithColor:[UIColor colorWithRGB:0x108ee9] size:CGSizeMake(1000, 1000)]]];
//    [customBar setNavigationBarBlurEffective];
    customBar.backgroundView.alpha = 1.f;
    _customBar = customBar;
    
//    [self performSelector:@selector(test1) withObject:nil afterDelay:3.f];
    
//    customBar.rightItem.aubadgeNumber = @".";
    
//    [customBar startTitleLoading];
    [customBar resetNaviBarLeftItemTarget:self action:@selector(back)];
    
//    [self performSelector:@selector(updateBadgeValue:) withObject:customBar afterDelay:2.0];
//    [self performSelector:@selector(updateBadgeValue1:) withObject:customBar afterDelay:4.0];
    
    [self.view addSubview:customBar];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.navigationController.navigationBar.hidden = YES;
}

- (void)back
{
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)updateBadgeValue:(AUCustomNavigationBar *)naviBar
{
    naviBar.rightItem.aubadgeNumber = nil;
}

- (void)updateBadgeValue1:(AUCustomNavigationBar *)naviBar
{
    naviBar.rightItem.aubadgeNumber = @"new";
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    self.navigationController.navigationBar.hidden = NO;
}

@end
