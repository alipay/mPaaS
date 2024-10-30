//
//  SearchBarDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/25.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SearchHomeDemoViewController.h"

#define KDemoViewTag        109879

@implementation SearchHomeDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    CGFloat topMargin = self.headerView.bottom;
    NSInteger tag = KDemoViewTag + 1;
    
    {
        AUButton *button1 = [self createButtonWithTitle:@"入口式搜索"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        button1.tag = tag++;
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [self createButtonWithTitle:@"沉浸式搜索"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        button1.tag = tag++;
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }
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
        switch (button.tag - KDemoViewTag) {
                
            case 1:
            {
                vc = [[NSClassFromString(@"SearchTitleViewDemoViewController") alloc] init];
                vc.title = @"AUSearchTitleView";
            }
                break;
            case 2:
            {
                vc = [[NSClassFromString(@"SearchBarDemoViewController") alloc] init];
                vc.title = @"AUSearchBar";
            }
                break;
            default:
                break;
        }
        
        [self.navigationController pushViewController:vc animated:YES];
    }
}

@end
