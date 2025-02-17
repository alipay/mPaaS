//
//  SegmentDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SegmentHomeDemoViewController.h"
//#import "AUUtils.h"

#define KDemoViewTag    10987

@implementation SegmentHomeDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CGFloat topMargin = self.headerView.bottom;
    NSInteger tag = KDemoViewTag + 1;
    
    {
        AUButton *button1 = [self createButtonWithTitle:@"导航栏分段控件"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        button1.tag = tag++;
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [self createButtonWithTitle:@"页面内分段控件"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        button1.tag = tag++;
        [self.view addSubview:button1];
        topMargin = button1.bottom + 10;
    }

//    {
//        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 1, 100)];
//        view.origin = CGPointMake(kDemoGlobalMargin, topMargin);
//        [self.view addSubview:view];
//        iPhoneX_makeLineVerticalGradual(view, RGB(0xd6d7da));
//
//        view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 1, 100)];
//        view.origin = CGPointMake(kDemoGlobalMargin + 10, topMargin);
//        view.backgroundColor = RGB(0xd6d7da);
//        [self.view addSubview:view];
//    }
}

//- (void)viewWillAppear:(BOOL)animated
//{
//    [super viewWillAppear:animated];
//    
//}

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
                vc = [[NSClassFromString(@"TitleBarSegmentDemoViewController") alloc] init];
                vc.title = @"AUTitleBarSegment";
            }
                break;
            case 2:
            {
                vc = [[NSClassFromString(@"SegmentDemoViewController") alloc] init];
                vc.title = @"AUSegment";
            }
                break;
            default:
                break;
        }
        [self.navigationController pushViewController:vc animated:YES];
    }
}


@end
