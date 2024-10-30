//
//  AURecordFloatTipViewController.m
//  AntUI
//
//  Created by 莜阳 on 17/1/19.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "RecordFloatTipDemoViewController.h"

@interface RecordFloatTipDemoViewController ()
{
    NSInteger _timeInterval;
}

@end

@implementation RecordFloatTipDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CGFloat topMargin = self.headerView.bottom;
    _tipView = [[AURecordFloatTip alloc] init];
    {
        AUButton *button1 = [self createButtonWithTitle:@"点击开始录音"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        [self.view addSubview:button1];
        [button1 addTarget:self action:@selector(show) forControlEvents:UIControlEventTouchUpInside];
        topMargin = button1.bottom + 10;
    }
    
    {
        AUButton *button1 = [self createButtonWithTitle:@"点击取消录音"];
        button1.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        [self.view addSubview:button1];
        [button1 addTarget:self action:@selector(hide) forControlEvents:UIControlEventTouchUpInside];
        topMargin = button1.bottom + 10;
    }
}

- (AUButton *)createButtonWithTitle:(NSString *)title
{
    AUButton *button1 = [AUButton buttonWithStyle:AUButtonStyle2];
    [button1 setTitle:title forState:UIControlStateNormal];
    button1.width = AUCommonUIGetScreenWidth() - kDemoGlobalMargin * 2;
    return button1;
}

//
- (void)show
{
    [_tipView showRecodingInView:self.view];
}

- (void)hide
{
    [_tipView dismissRecordView];
}

@end
