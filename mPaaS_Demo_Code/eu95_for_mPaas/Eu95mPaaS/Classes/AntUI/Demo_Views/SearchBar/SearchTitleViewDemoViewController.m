//
//  SearchTitleViewDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/25.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SearchTitleViewDemoViewController.h"


@implementation SearchTitleViewDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CGFloat topMargin = self.topMargin;
    
    {
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, topMargin + 10, self.view.width, 60)];
        view.backgroundColor = [UIColor colorWithRGB:0xffffff];
        [self.view addSubview:view];
        
        AUSearchTitleView *titleView = [[AUSearchTitleView alloc] initWithSearchStyle:AUSearchTitleStyleDefault];
        titleView.origin_mp = CGPointMake(0, 10);
        titleView.placeHolder = @"AUSearchTitleStyleDefault";
        titleView.isShowVoiceIcon = YES;
        titleView.delegate = self;
        
//        titleView.normalBackgroundColor = [UIColor whiteColor];
        [view addSubview:titleView];
        topMargin = view.bottom + 10;
    }
    {
        AUSearchTitleView *titleView = [[AUSearchTitleView alloc] initWithSearchStyle:AUSearchTitleStyleMiddleAlign];
        titleView.origin_mp = CGPointMake(0, topMargin);
        titleView.placeHolder = @"AUSearchTitleStyleMiddleAlign";
        titleView.isShowVoiceIcon = YES;
        titleView.delegate = self;
//        titleView.normalBackgroundColor = [UIColor whiteColor];
        [self.view addSubview:titleView];
        topMargin = titleView.bottom + 10;
    }
    
    {
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, topMargin + 10, self.view.width, 60)];
        view.backgroundColor = [UIColor colorWithRGB:0x108ee9];
        [self.view addSubview:view];
        
        AUSearchTitleView *titleView = [[AUSearchTitleView alloc] initWithSearchStyle:AUSearchTitleStyleContent];
        titleView.origin_mp = CGPointMake(0, 10);
        titleView.placeHolder = @"AUSearchTitleStyleContent";
        titleView.isShowVoiceIcon = YES;
        titleView.delegate = self;

        [view addSubview:titleView];
        topMargin = titleView.bottom + 10;
    }
}


#pragma mark - AUSearchTitleViewDelegate

- (void)didPressedTitleView:(AUSearchTitleView *)titleView
{
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"点击了searchTitle" message:nil];
    [alert addButton:@"确定" actionBlock:nil];
    [alert show];
}

- (void)didPressedVoiceButton:(AUSearchTitleView *)titleView
{
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"点击了voiceButton" message:nil];
    [alert addButton:@"确定" actionBlock:nil];
    [alert show];
}

@end
