//
//  ButtonDemoViewViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ButtonDemoViewViewController.h"

@implementation ButtonDemoViewViewController

- (void)viewDidLoad
{
    self.view = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [super viewDidLoad];
    
    CGFloat tag = 10019;
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat topMargin = self.topMargin;
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle1];
        [button1 setLeftTitleImage:[UIImage imageNamed:@"appreciate64"]];
        [button1 setTitle:@"AUButtonStyle1" forState:UIControlStateNormal];
        //[button1 setLeftTitleImage:[UIImage imageNamed:@"ap_add_friend"]];

        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        button1.tag = tag++;
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle1];
        [button1 setTitle:NSLocalizedString(@"主要操作 Disable(AUButtonStyle1)", nil) forState:UIControlStateNormal];
        button1.enabled = NO;
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
        [button1 setTitle:NSLocalizedString(@"辅助操作 Normal(AUButtonStyle2)", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
        [button1 setTitle:NSLocalizedString(@"辅助操作 Disable(AUButtonStyle2)", nil) forState:UIControlStateNormal];
        button1.enabled = NO;
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle6];
        [button1 setTitle:NSLocalizedString(@"警告类操作 Normal(AUButtonStyle6)", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        [self.view addSubview:button1];
        button1.tag = tag++;
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle6];
        [button1 setTitle:NSLocalizedString(@"警告类操作 Disable(AUButtonStyle6)", nil) forState:UIControlStateNormal];
        button1.enabled = NO;
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,self.view.width-kDemoGlobalMargin*2, button1.height);
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

    CGFloat startX = 30;
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle8];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
//        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle8];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,60, 30);
        [self.view addSubview:button1];
        button1.highlighted = YES;
        startX = button1.right + 10;
//                topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle8];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin, 80, 30);
        [self.view addSubview:button1];
        button1.tag = tag++;
        button1.enabled = NO;
        startX = 30;
        topMargin = button1.bottom + 10;
    }

    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle3];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin, 60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        button1.tag = tag++;
//        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle3];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        button1.highlighted = YES;
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin, 60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        //        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle3];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        button1.enabled = NO;
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin, 60, 30);
        [self.view addSubview:button1];
        startX = 30;
        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 setLeftTitleImage:[UIImage imageNamed:@"ap_add_friend"]];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
//        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
        button1.highlighted = YES;
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
//        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
        button1.enabled = NO;
        [button1 setTitle:NSLocalizedString(@"按钮", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,60, 30);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        topMargin = button1.bottom + 10;
    }
    
    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin,56, 30)];
        button.autoSizeToFits = YES;
        [button setTitle:NSLocalizedString(@"选项", nil) forState:UIControlStateNormal];
//        button.titleLabel.text = @"sjkajajksdhka";
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
        topMargin = button.bottom + 10;
    }

    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin, 220, 30)];
//        button.autoSizeToFits = YES;
//        button.titleLabel.text = @"sjkajajksdhka";
        [button setTitle:NSLocalizedString(@"筛选五个字", nil) forState:UIControlStateNormal];
        button.selected  = YES;
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
        button.tag = 10929829;
        topMargin = button.bottom + 10;
        [button addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    }
    
    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin, 220, 30)];
//        button.autoSizeToFits = YES;
        [button setTitle:NSLocalizedString(@"筛选项六个字", nil) forState:UIControlStateNormal];
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
//        button.enabled = NO;
        topMargin = button.bottom + 10;
    }
    
    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin, 220, 30)];
//        button.autoSizeToFits = YES;
        [button setTitle:NSLocalizedString(@"筛选项九个字的样式", nil) forState:UIControlStateNormal];
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
        button.selected = YES;
        topMargin = button.bottom + 10;
    }
    
    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin, 220, 30)];
//        button.autoSizeToFits = YES;
        [button setTitle:NSLocalizedString(@"筛选项十个字的样式哦", nil) forState:UIControlStateNormal];
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
        button.selected = YES;
        topMargin = button.bottom + 10;
    }
    
    
    {
        AUSubscriptButton *button = [[AUSubscriptButton alloc] initWithFrame:CGRectMake(self.view.width/2+ kDemoGlobalMargin/2, topMargin, 260, 30)];
//        button.autoSizeToFits = YES;
        [button setTitle:NSLocalizedString(@"筛选项超过十个字的样式哦", nil) forState:UIControlStateNormal];
        [self.view addSubview:button];
        button.centerX = self.view.centerX;
        button.enabled = NO;
        topMargin = button.bottom + 10;
    }
    
    {
        startX = 0;
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle4];
//        button1.highlighted = YES;
        [button1 setTitle:NSLocalizedString(@"取消关注", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,AUCommonUIGetScreenWidth(), 44);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        topMargin = button1.bottom + 10;
        //        topMargin = button1.bottom + 10;
    }
    
    {
        startX = 0;
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle4];
        button1.enabled = NO;
        [button1 setTitle:NSLocalizedString(@"取消关注", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(startX, topMargin,AUCommonUIGetScreenWidth(), 44);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        topMargin = button1.bottom + 10;
        //        topMargin = button1.bottom + 10;
    }
    {
        startX = 0;
        AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle9];
        button1.enabled = YES;
        [button1 setTitle:NSLocalizedString(@"取消关注_2 Style 9", nil) forState:UIControlStateNormal];
        [button1 addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
        button1.frame = CGRectMake(kDemoGlobalMargin, topMargin,AUCommonUIGetScreenWidth() - 2 * kDemoGlobalMargin, 44);
        [self.view addSubview:button1];
        startX = button1.right + 10;
        topMargin = button1.bottom + 10;
    }
    
    
    topMargin += 50;
    self.topMargin = topMargin;
    [self updateFooterView];
    [(UIScrollView *)self.view setContentSize:CGSizeMake(self.view.width, topMargin*2)];
}

- (void)onButtonClicked:(id)sender
{
    AUButton *button = (AUButton *)sender;
    if (true) {//}(button.tag >= 10019 && button.tag < 10929829) {
        [button startLoadingWithTitle:@"Loading" currentViewController:self];
        [self performSelector:@selector(stopLoadings:) withObject:button afterDelay:2.f];
    } else if(button.tag == 10929829) {
        NSLog(@"hhh:%d", button.selected);
    }
}

- (void)stopLoadings:(id)sender
{
    AUButton *button = (AUButton *)sender;
    if (button.tag >= 10019 && button.tag < 10929829) {
        [button stopLoading];
    }
}

@end
