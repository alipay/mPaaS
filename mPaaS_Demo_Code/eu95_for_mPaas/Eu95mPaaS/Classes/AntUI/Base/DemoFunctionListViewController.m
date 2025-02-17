//
//  DemoFunctionListViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoFunctionListViewController.h"

@implementation DemoFunctionListModel

@end

@interface DemoFunctionListViewController () <UITableViewDelegate,UITableViewDataSource,UIScrollViewDelegate>

@property(nonatomic, strong) UITableView *tableView;

@end

@implementation DemoFunctionListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.tableView = [[UITableView alloc] initWithFrame:self.contentView.bounds];
    self.tableView.height -= self.footerView.height + 25;
    self.tableView.autoresizingMask = (UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth);
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.backgroundColor = [UIColor clearColor];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.automaticallyAdjustsScrollViewInsets = NO;
    [self.contentView addSubview:self.tableView];
}

#pragma mark - UITableView Delegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 47.0;
}

#pragma mark - UITableView DataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [self.functionList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"tableView"];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    DemoFunctionListModel *model = [self.functionList objectAtIndex:indexPath.row];
    
    AUButton *button = [AUButton buttonWithStyle:AUButtonStyle2];
    [button setTitle:model.title forState:UIControlStateNormal];
    [button.titleLabel setFont:[UIFont systemFontOfSize:17.0]];
    [button addTarget:model.target action:model.selector forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake(kDemoGlobalMargin, 0,kDemoGlobalWidth, 42);
    
    cell.backgroundColor = [UIColor clearColor];
    [cell.contentView addSubview:button];
    
    return cell;
}


- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

@end
