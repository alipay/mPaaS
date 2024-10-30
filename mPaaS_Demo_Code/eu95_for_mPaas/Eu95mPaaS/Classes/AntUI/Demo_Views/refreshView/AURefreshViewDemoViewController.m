//
//  AURefreshViewDemoViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2017/11/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AURefreshViewDemoViewController.h"
//#import "AURefreshView.h"

@interface AURefreshViewDemoViewController ()
{
    BOOL _isHeader;
    LOTAnimationView * lottieAnimationView;
    AURefreshViewType _currentType;
}

@property (nonatomic, strong) AURefreshView *refreshView;
@property(nonatomic, strong) UITableView *tableView;
@property(nonatomic, strong) NSMutableArray* listArray;

@end

@implementation AURefreshViewDemoViewController

- (void)test
{
    NSLog(@"------2------: %f", lottieAnimationView.animationProgress);
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
    
    
//    return;
    
    [self setupDatas];
    self.tableView = [[UITableView alloc]initWithFrame:self.view.bounds style:UITableViewStylePlain];
    self.tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.tableView.dataSource = (id <UITableViewDataSource>) self;
    self.tableView.delegate = (id <UITableViewDelegate>) self;
    self.tableView.backgroundColor = [UIColor colorWithRGB:0xf5f5f9]; //     0xf5f5f9
    self.tableView.separatorColor = [UIColor colorWithRGB:0xdddddd];
    [self.view addSubview:self.tableView];
    
    self.navigationItem.rightBarButtonItem = [AUBarButtonItem barButtonItemWithTitle:@"切换样式" target:self action:@selector(switchType:)];
    
    _refreshView = [[AURefreshView alloc] initWithSuperView:self.tableView type:_currentType bizType:@"demo"];
    [_refreshView setupLabelText:@"正在刷新"]; 
    [self.tableView addSubview:_refreshView];
}

-(void) switchType:(id)sender
{
    _currentType = (_currentType ^ 1);
    [_refreshView changeType:_currentType completion:^(AURefreshView *view) {
        view.backgroundColor = (view.viewType == 0 ? [UIColor yellowColor] : [UIColor blueColor]);
    }];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [_refreshView resumeAnimation];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    [_refreshView pauseAnimation];
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

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    [_refreshView auRefreshScrollViewWillBeginDragging:scrollView];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    [_refreshView auRefreshScrollViewDidScroll:scrollView];
//    if (scrollView.contentInset.top + scrollView.contentOffset.y < 0) {
//
//        _isHeader = YES;
//    }
}

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
    [_refreshView auRefreshScrollViewDidEndDragging:scrollView];

    [self performSelector:@selector(didFinishedLoading) withObject:nil afterDelay:3.6f];
}

- (void)didFinishedLoading
{
    [_refreshView auRefreshScrollViewDidFinishedLoading:self.tableView];
}

@end




