//
//  DemoNetErrorViewController.m
//  AntUI
//
//  Created by maizhelun on 2016/10/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "DemoNetErrorViewController.h"
//#import "AUNetErrorView.h"

@interface DemoNetErrorViewController ()

@property (nonatomic, strong) AUNetErrorView *netErrorView;
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) AUSegment *segment;
@property (nonatomic, assign) BOOL flag;
@property (nonatomic, assign) BOOL halfStyle;

@end

@implementation DemoNetErrorViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    self.view = [[UIView alloc] initWithFrame:self.view.frame];
    self.view.backgroundColor = [UIColor whiteColor];
    
//    AUNetErrorTypeLimit,        //限流
//    AUNetErrorTypeSystemBusy,    // 系统繁忙（系统错误）
//    AUNetErrorTypeFailure,      //网络不给力
//    AUNetErrorTypeEmpty,        //内容为空
//    AUNetErrorTypeNotFound,     // 404找不到
    
    
    [self changeStyle];
}


- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    if (!_contentView) {
        _contentView = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(_segment.frame), self.view.width, self.view.height - CGRectGetMaxY(_segment.frame))];
        [self.view addSubview:_contentView];
    }
    
    [self didSegmentValueChanged:self.segment];
}

- (void)changeVisual
{
    self.halfStyle = !self.halfStyle;
    self.navigationItem.rightBarButtonItems = @[[AUBarButtonItem barButtonItemWithTitle:!self.flag ? @"插画版" : @"简版" target:self action:@selector(changeStyle)],[AUBarButtonItem barButtonItemWithTitle:self.halfStyle ? @"全屏" : @"半屏" target:self action:@selector(changeVisual)]];
    [_contentView removeFromSuperview];
    _contentView = nil;
    if (!_contentView) {
        _contentView = [[UIView alloc] initWithFrame:CGRectMake(0, CGRectGetMaxY(_segment.frame), self.view.width, self.view.height - CGRectGetMaxY(_segment.frame))];
        if (self.halfStyle) {
            _contentView.height /= 2;
        }
        [self.view addSubview:_contentView];
    }
}

- (void)changeStyle
{
    self.flag = !self.flag;
    self.navigationItem.rightBarButtonItems = @[[AUBarButtonItem barButtonItemWithTitle:!self.flag ? @"插画版" : @"简版" target:self action:@selector(changeStyle)],[AUBarButtonItem barButtonItemWithTitle:self.halfStyle ? @"全屏" : @"半屏" target:self action:@selector(changeVisual)]];
    
    [_segment removeFromSuperview];
    _segment = nil;
    
    if (!_segment) {
        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, 64, self.view.width, 50) titles:@[]];
        segment.fixedItemWidth = NO;
        segment.autoScroll = YES;
        segment.textHorizontalPadding = 12;
        segment.delegate = (id<AUSegmentedControlDelegate>)self;
        [self.view addSubview:segment];
        _segment = segment;
    }
    
    if (_flag) {
        _segment.titles = [NSMutableArray arrayWithObjects:@"限流",@"限流(倒计时)", @"系统繁忙", @"网络不给力", @"内容为空", @"404找不到", @"用户已注销", nil];
    } else {
        _segment.titles = [NSMutableArray arrayWithObjects:@"系统繁忙", @"网络不给力", @"内容为空", @"404找不到", @"限流", @"用户已注销", nil];
    }
    
    if (_contentView) {
        [self.segment setSelectedSegmentIndex:0];
        [self didSegmentValueChanged:self.segment];
    }
}

- (void)pressedNetErrorView
{
    NSLog(@"pressedNetErrorView");
}

- (void)didSegmentValueChanged:(AUSegment*)segmentControl
{
    [_netErrorView removeFromSuperview];
    
    AUNetErrorType type = AUNetErrorTypeLimit;
    NSInteger pos = segmentControl.selectedSegmentIndex;
    if (_flag) {
        if (pos == 0 || pos == 1) {
            type = AUNetErrorTypeLimit;
        }
        else if (pos == 2) {
            type = AUNetErrorTypeAlert;
        }
        else if (pos == 3) {
            type = AUNetErrorTypeNetworkError;
        }
        else if (pos == 4) {
            type = AUNetErrorTypeEmpty;
        }
        else if (pos == 5) {
            type = AUNetErrorTypeNotFound;
        }
        else if (pos == 6) {
            type = AUNetErrorTypeUserLogout;
        }
    }
    else {
        if (pos == 0) {
            type = AUNetErrorTypeAlert;
        }
        else if (pos == 1) {
            type = AUNetErrorTypeNetworkError;
        }
        else if (pos == 2) {
            type = AUNetErrorTypeEmpty;
        }
        else if (pos == 3) {
            type = AUNetErrorTypeNotFound;
        }
        else if (pos == 4) {
            type = AUNetErrorTypeLimit;
        }
        else if (pos == 5) {
            type = AUNetErrorTypeUserLogout;
        }
    }
    
    _netErrorView = [[AUNetErrorView alloc] initWithFrame:CGRectMake(0, 0, self.view.width, _contentView.height) style: !self.flag ? AUNetErrorStyleMinimalist : AUNetErrorStyleIlustration type:type target:self action:@selector(pressedNetErrorView)];
    
//    if (segmentControl.selectedSegmentIndex == 0
//        || segmentControl.selectedSegmentIndex == 1) {
//        _netErrorView.detailTitle = @"辅助文案辅助文案辅助文案辅助文案辅助文案";
//    }
    if (segmentControl.selectedSegmentIndex == 1) {
        [_netErrorView setCountdownTimeInterval:10 completeBlock:^{
            NSLog(@"倒计时结束");
        }];
    }
    if (segmentControl.selectedSegmentIndex == 2) {
        [_netErrorView setCountdownTimeInterval:10 completeBlock:nil];
    }

    [_contentView addSubview:_netErrorView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
