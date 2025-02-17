//
//  IconfontDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "IconfontDemoViewController.h"
//#import "UIFont+CustomFont.h"
//#import "AUIconView.h"

#define kMaxRetryTimes (100)
#define kFontText @"\U0000e600"
#define kFontName @"LLIconfont"

@interface IconfontDemoViewController ()

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, assign) NSInteger testCount;
@property (nonatomic, strong) UISegmentedControl *typeSegment;
@property (nonatomic, strong) UISegmentedControl *sizeSegment;
@property (nonatomic, strong) UISegmentedControl *timesSegment;
@property (nonatomic, strong) UIButton *testButton;
@property (nonatomic, strong) UIButton *stopButton;
@property (nonatomic, assign) CGFloat totalTimes;
@property (nonatomic, assign) NSInteger retryTimes;
@property (nonatomic, strong) NSTimer *timer;
@end

@implementation IconfontDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [UIFont au_loadFontWithResource:kFontName];
    
    
    self.testCount = 100;
    [self.view removeAllSubviews];
    
    self.typeSegment = [[UISegmentedControl alloc] initWithItems:@[@"label",@"button",@"drawImg",@"png"]];
    [self.typeSegment addTarget:self action:@selector(typeClick:) forControlEvents:UIControlEventValueChanged];
    self.typeSegment.selectedSegmentIndex = 0;
    [self.typeSegment setFrame:CGRectMake(15, 70, AUCommonUIGetScreenWidth()-30, 30)];
    [self.view addSubview:self.typeSegment];
    
    self.sizeSegment = [[UISegmentedControl alloc] initWithItems:@[@"64",@"200"]];
    [self.sizeSegment addTarget:self action:@selector(sizeClick:) forControlEvents:UIControlEventValueChanged];
    self.sizeSegment.selectedSegmentIndex = 0;
    self.sizeSegment.top = self.typeSegment.bottom + 10;
    self.sizeSegment.left = self.typeSegment.left;
    self.sizeSegment.height = self.typeSegment.height;
    [self.view addSubview:self.sizeSegment];
    
    self.testButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.testButton setTitle:@"Test!" forState:UIControlStateNormal];
    [self.testButton addTarget:self action:@selector(doTest:) forControlEvents:UIControlEventTouchUpInside];
    self.testButton.top = self.sizeSegment.top;
    self.testButton.height = self.sizeSegment.height;
    self.testButton.left = self.sizeSegment.right + 15.0;
    self.testButton.width = 80;
    [self.view addSubview:self.testButton];
    
    self.stopButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.stopButton setTitle:@"Stop!" forState:UIControlStateNormal];
    [self.stopButton addTarget:self action:@selector(tearDown) forControlEvents:UIControlEventTouchUpInside];
    self.stopButton.top = self.sizeSegment.top;
    self.stopButton.height = self.sizeSegment.height;
    self.stopButton.left = self.testButton.right + 15.0;
    self.stopButton.width = 80;
    [self.view addSubview:self.stopButton];
    
    self.timesSegment = [[UISegmentedControl alloc] initWithItems:@[@"100",@"500",@"1000"]];
    [self.timesSegment addTarget:self action:@selector(timesClick:) forControlEvents:UIControlEventValueChanged];
    self.timesSegment.selectedSegmentIndex = 0;
    self.timesSegment.top = self.sizeSegment.bottom + 10;
    self.timesSegment.left = 15.0;
    self.timesSegment.height = self.sizeSegment.height;
    [self.view addSubview:self.timesSegment];

    
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    self.scrollView.top = self.timesSegment.bottom+15;
    self.scrollView.height = self.view.bottom - self.scrollView.top;
    [self.view addSubview:self.scrollView];
}

- (void)typeClick:(UISegmentedControl *)control
{
    NSLog(@"typeClick");
}

- (void)sizeClick:(UISegmentedControl *)control
{
    NSLog(@"sizeClick");
}

- (void)timesClick:(UISegmentedControl *)control
{
    switch (control.selectedSegmentIndex) {
        case 0:
            self.testCount = 100;
            break;
        case 1:
            self.testCount = 500;
            break;
        case 2:
            self.testCount = 1000;
            break;
        default:
            break;
    }
}

- (void)tearDown {
    if (self.timer) {
        [self.timer invalidate];
    }
    
    self.totalTimes = 0;
    self.retryTimes = 0;
    for (UIView *view in self.scrollView.subviews) {
        [view removeFromSuperview];
    }
    self.scrollView.contentSize = CGSizeZero;
}

- (void)doTest:(id)sender {
    [self tearDown];
        self.timer = [NSTimer scheduledTimerWithTimeInterval:1.5 target:self selector:@selector(doAutoTest) userInfo:nil repeats:YES];
    [self.timer fire];
//    [self doAutoTest];
}

- (void)doAutoTest
{
    if (self.retryTimes >= kMaxRetryTimes) {
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:[NSString stringWithFormat:@"%.3fs", self.totalTimes/self.retryTimes] style:UIBarButtonItemStylePlain target:nil action:nil];
        [self.timer invalidate];
        self.timer = nil;
        return;
    }

    [self.scrollView removeAllSubviews];
    self.scrollView.contentSize = CGSizeZero;
    
    @autoreleasepool {
    
        NSInteger size = [self testSize];
        NSInteger testCount = self.testCount;
        NSString *name = @"";
        NSDate *beginDate = [NSDate date];
        for (int i=0; i<testCount; i++) {
            @autoreleasepool {
                if (self.typeSegment.selectedSegmentIndex == 0) {
                    name = @"label";
                    
                    UILabel *label = [[UILabel alloc] initWithFrame:[self getRectWithIndex:i size:size]];
                    label.text = kFontText;
                    label.font = [UIFont fontWithName:kFontName size:size];
                    label.textColor = RGB(0x272636);
                    
                    [self.scrollView addSubview:label];
                } else if (self.typeSegment.selectedSegmentIndex == 1){
                    name = @"button";
                    
                    UIButton *button = [[UIButton alloc] initWithFrame:[self getRectWithIndex:i size:size]];
                    button.titleLabel.font = [UIFont fontWithName:kFontName size:size];
                    button.titleLabel.textAlignment = NSTextAlignmentCenter;
                    [button setTitle:kFontText forState:UIControlStateNormal];
                    [button setTitleColor:RGB(0x272636) forState:UIControlStateNormal];
                    
                    [self.scrollView addSubview:button];
                }else if (self.typeSegment.selectedSegmentIndex == 3) {
                    name = @"drawImg";
                    
                    UIImageView *imageView = [[UIImageView alloc] initWithFrame:[self getRectWithIndex:i size:size]];
                    imageView.image = [UIImage iconWithName_au:kFontText fontName:kFontName width:size color:RGB(0x272636)];
                    [self.scrollView addSubview:imageView];
                    
                }else if (self.typeSegment.selectedSegmentIndex == 4) {
                    name = @"png";
                    
                    UIImageView *imageView = [[UIImageView alloc] initWithFrame:[self getRectWithIndex:i size:size]];
                    NSString *iconName = @"appreciate%ld";
                    switch ([self testSize]) {
                        case 64:
                            iconName = @"appreciate64";
                            break;
                        case 200:
                        default:
                            iconName = @"appreciate200";
                            break;
                    }
                    imageView.image = [UIImage imageNamed:iconName];
                    
                    [self.scrollView addSubview:imageView];
                }
            }
        }
        NSTimeInterval timeCost = -[beginDate timeIntervalSinceNow];
        self.scrollView.contentSize = CGSizeMake(self.view.width, size * testCount);
        self.retryTimes++;
        self.totalTimes += timeCost;
        NSLog(@"%@ %d/%d Time Cost: %f Size: %ld ,totalCost:%f,avgCost:%f", name,(int)self.retryTimes,self.testCount,timeCost, size,self.totalTimes,self.totalTimes/self.retryTimes);
    }
}

- (CGRect)getRectWithIndex:(int)index size:(CGFloat)size
{
    return CGRectMake(0, index * size, size, size);
}

- (NSInteger)testSize {
    switch (self.sizeSegment.selectedSegmentIndex) {
//        case 0:
//            return 32;
        case 0:
            return 64;
        case 1:
            return 200;
        default:
            return 0;
    }
}

@end
