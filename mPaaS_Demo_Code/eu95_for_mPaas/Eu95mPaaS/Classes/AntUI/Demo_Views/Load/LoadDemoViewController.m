//
//  LoadDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "LoadDemoViewController.h"
//#import "AUDragLoadingView.h"
//#import "AUPullLoadingView.h"
//AUDragLoadingView&AUPullLoadingView

@interface LoadDemoViewController()

@property(nonatomic,strong) AUDragLoadingView *loadingView;

@end

@implementation LoadDemoViewController

//AUDragLoadingView&AUPullLoadingView

- (void)viewDidLoad {
    [super viewDidLoad];
    
    AUPullLoadingView *pullLoadingView = [[AUPullLoadingView alloc] initWithFrame:CGRectMake(0, 0, AUCommonUIGetScreenWidth(), 60)];
    pullLoadingView.backgroundColor = [UIColor clearColor];
    pullLoadingView.delegate = self;
    [pullLoadingView refreshLastUpdatedDate];
    pullLoadingView.state = AUEGOOPullRefreshPulling;
    [pullLoadingView ShowLastPullDate:YES];
    [self.contentView addSubview:pullLoadingView];
    
    pullLoadingView = [[AUPullLoadingView alloc] initWithFrame:CGRectMake(0, pullLoadingView.bottom, AUCommonUIGetScreenWidth(), 60)];
    pullLoadingView.backgroundColor = [UIColor clearColor];
    pullLoadingView.state = AUEGOOPullRefreshNormal;
    [pullLoadingView ShowLastPullDate:YES];
    [self.contentView addSubview:pullLoadingView];
    
    pullLoadingView = [[AUPullLoadingView alloc] initWithFrame:CGRectMake(0, pullLoadingView.bottom, AUCommonUIGetScreenWidth(), 60)];
    pullLoadingView.backgroundColor = [UIColor clearColor];
    pullLoadingView.state = AUEGOOPullRefreshLoading;
    [pullLoadingView ShowLastPullDate:YES];
    [self.contentView addSubview:pullLoadingView];
    
    self.loadingView = [[AUDragLoadingView alloc] initWithTableView:nil bizType:@"demo" makeConfig:nil];
    self.loadingView.top = pullLoadingView.bottom;
    self.loadingView.width = AUCommonUIGetScreenWidth();
    self.loadingView.state = AUDragLoadingStateLoading;
    [self.contentView addSubview:self.loadingView];
    
    AUDragLoadingView *loadingView = [[AUDragLoadingView alloc] initWithTableView:nil bizType:@"demo" makeConfig:^(AUDragLoadingConfig *config) {
        config.endTipsEnable = YES;
    }];
    loadingView.width = AUCommonUIGetScreenWidth();
    loadingView.top = self.loadingView.bottom;
    loadingView.state = AUDragLoadingStateNormal;
    loadingView.state = AUDragLoadingStateLoading;
    loadingView.state = AUDragLoadingStateEnd;
    [self.contentView addSubview:loadingView];
}

- (NSDate*)egoRefreshTableHeaderDataSourceLastUpdated:(AUPullLoadingView*)view
{
    return [NSDate date];
}

@end
