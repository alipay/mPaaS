//
//  AURefreshViewDemoViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2017/11/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AURefreshViewDemoViewControllerTest.h"
//#import "AURefreshView.h"
//#import "Lottie.h"

@interface AURefreshViewDemoViewControllerTest ()
{
    BOOL _isHeader;
    LOTAnimationView * lottieAnimationView;
}

@property (nonatomic, strong) AURefreshView *refreshView;
@property(nonatomic, strong) UITableView *tableView;
@property(nonatomic, strong) NSMutableArray* listArray;

@end

@implementation AURefreshViewDemoViewControllerTest

- (void)test
{
    NSLog(@"------2------: %f", lottieAnimationView.animationProgress);
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
    [self setupDatas];
    self.tableView = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStylePlain];
    self.tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.tableView.dataSource = (id <UITableViewDataSource>) self;
    self.tableView.delegate = (id <UITableViewDelegate>) self;
    self.tableView.backgroundColor = [UIColor colorWithRGB:0x108ee9]; //     0xf5f5f9
    self.tableView.separatorColor = [UIColor colorWithRGB:0xdddddd];
    [self.view addSubview:self.tableView];
    
    _refreshView = [[AURefreshView alloc] initWithSuperView:self.tableView type:AURefreshViewTypeFeature1 bizType:@"demo"];
    [_refreshView setupLabelText:@"正在刷新"];
    [_refreshView autoPullRefreshScrollView:self.tableView];
    [self performSelector:@selector(didFinishedLoading) withObject:nil afterDelay:3.6f];
    [self.tableView addSubview:_refreshView];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
//    lottieAnimationView = [LOTAnimationView animationWithFilePath:[[NSBundle mainBundle] pathForResource:@"antuiResource/refresh" ofType:@"json" inDirectory:@"APCommonUI.bundle"]];
//    lottieAnimationView.frame = CGRectMake(self.view.width/2-lottieAnimationView.width/2, (self.view.height-lottieAnimationView.height)/2, lottieAnimationView.width, lottieAnimationView.height);
//    lottieAnimationView.loopAnimation = YES;
//    lottieAnimationView.backgroundColor = [UIColor colorWithRGB:0xffffff];
//    [self.view addSubview:lottieAnimationView];
//    [lottieAnimationView play];
////    [lottieAnimationView performSelector:@selector(play) withObject:nil afterDelay:2];
//
//    NSTimer *t = [NSTimer scheduledTimerWithTimeInterval:0.f target:self selector:@selector(test) userInfo:nil repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:t forMode:UITrackingRunLoopMode];
//    [t fire];
    
//    [_refreshView startAnimating];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
//    [lottieAnimationView stop];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)setupDatas
{
    NSArray *array = @[@"0",
                       @"1",
                       @"2",
                       @"3",
                       @"4",
                       @"5",
                       @"6",
                       @"7",
                       @"8",
                       @"9",
                       @"10",
                       @"11",
                       @"12",
                       @"13",
                       @"14",
                       @"15",
                       @"16",
                       @"17",
                       @"18",
                       @"19"];
    self.listArray = [NSMutableArray arrayWithArray:array];
}

#pragma tableview datasource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _listArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"RefreshCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (nil == cell)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:CellIdentifier];
    }
    cell.textLabel.text = _listArray[indexPath.row];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;

    return cell;
}

#pragma mark -
#pragma mark UIScrollViewDelegate Methods

//- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
//{
//    [_refreshView auRefreshScrollViewWillBeginDragging:scrollView];
//}
//
//- (void)scrollViewDidScroll:(UIScrollView *)scrollView
//{
//    [_refreshView auRefreshScrollViewDidScroll:scrollView];
////    if (scrollView.contentInset.top + scrollView.contentOffset.y < 0) {
////
////        _isHeader = YES;
////    }
//}
//
//- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
//{
//    [_refreshView auRefreshScrollViewDidEndDragging:scrollView];
//
//    [self performSelector:@selector(didFinishedLoading) withObject:nil afterDelay:3.6f];
//}

- (void)didFinishedLoading
{
    [_refreshView auRefreshScrollViewDidFinishedLoading:self.tableView];
}

@end




