//
//  DemoEmptyLoadingViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/12/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoEmptyLoadingViewController.h"
//#import "AUEmptyPageLoadingView.h"
//#import "MPBadgeView.h"


@interface DemoEmptyLoadingViewController ()

@end

@implementation DemoEmptyLoadingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    UIImage *image = [UIImage imageNamed:@"APCommonUI.bundle/add"];
//    UIImageView *testImageView = [[UIImageView alloc] initWithImage:image];
//    testImageView.contentMode = UIViewContentModeScaleAspectFill;
//    testImageView.size = CGSizeMake(100, 100);
//    [self.view addSubview:testImageView];
//    NSLog(@"1.%@", NSStringFromCGSize(testImageView.image.size));
//    NSLog(@"2.%@", NSStringFromCGSize(image.size));
    
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"显示全屏加载视图";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"隐藏全屏加载视图";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
     self.functionList = models;
    
    
    MPBadgeView *  _badge = [[MPBadgeView alloc]initWithFrame:CGRectMake(0, 0, 5, 5)];
    _badge.center = CGPointMake(20, CGRectGetMaxY(self.view.bounds) - 50);
    //_badge.widgetId = @"0002";
    [_badge drawBadgeStyle:@"."];
    //MPBadgeInfo *info = [MPBadgeInfo badgeInfoWithBadgeId:@"0002"];
    //[[MPBadgeManager sharedInstance] insertLocalBadgeInfo:@[info]];
    [self.view addSubview:_badge];
   
}

- (void)onButton1Clicked:(id) sender
{
    [AUEmptyPageLoadingView showInView:self.view animated:YES];
}

- (void)onButton2Clicked:(id) sender
{
    [AUEmptyPageLoadingView hideInView:self.view animated:YES];
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
