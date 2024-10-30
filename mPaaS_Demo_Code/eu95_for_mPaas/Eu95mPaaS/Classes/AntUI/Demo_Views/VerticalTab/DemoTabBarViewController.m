//
//  DemoTabBarViewController.m
//  AntUIDemo
//
//  Created by zhaolei on 2018/4/13.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "DemoTabBarViewController.h"

@interface DemoTabBarViewController ()

@end

@implementation DemoTabBarViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CGFloat topMargin = self.headerView.bottom;
   
    AUButton *button1 = [self createButtonWithTitle:@"纵向选显卡"];
    button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
    button1.tag = 1;
    [self.view addSubview:button1];
    topMargin = button1.bottom + 10;
}

- (AUButton *)createButtonWithTitle:(NSString *)title
{
    AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
    [button1 setTitle:title forState:UIControlStateNormal];
    button1.width = AUCommonUIGetScreenWidth() - kDemoGlobalMargin * 2;
    [button1 addTarget:self action:@selector(clickButton:) forControlEvents:UIControlEventTouchUpInside];
    return button1;
}

- (void)clickButton:(id)sender
{
    if ([sender isKindOfClass:[AUButton class]])
    {
        AUButton *button = (AUButton *)sender;
        UIViewController *vc;
        switch (button.tag) {
            case 1:
            {
                vc = [[NSClassFromString(@"DemoVerticalTabViewController") alloc] init];
                vc.title = @"AUVerticalTabView";
            }
                break;
            default:
                break;
        }
        [self.navigationController pushViewController:vc animated:YES];
    }
}
@end
