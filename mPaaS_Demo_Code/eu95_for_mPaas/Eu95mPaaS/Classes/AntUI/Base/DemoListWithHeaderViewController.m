//
//  DemoListWithHeaderViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoListWithHeaderViewController.h"

@implementation DemoContentModel

@end

@interface DemoListWithHeaderViewController () <UITableViewDelegate,UITableViewDataSource>


@end

@implementation DemoListWithHeaderViewController

- (void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    self.tableView.height = self.contentView.height+27.0;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.tableView = [[UITableView alloc] initWithFrame:self.view.frame
                                                  style:UITableViewStyleGrouped];
    self.tableView.sectionFooterHeight = 0.0;//不加的话会有个莫名footerHeight
    self.tableView.top -= 27.0;
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.backgroundColor = [UIColor clearColor];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.automaticallyAdjustsScrollViewInsets = NO;
    [self.contentView addSubview:self.tableView];
}

#pragma mark - UITableView Delegate

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return [self.contentModelList count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    DemoContentModel *model = [self.contentModelList objectAtIndex:section];
    return [AUAssitLableView viewHeightForType:AUAssitLableViewTypeHeader
                                          text:model.headerTitle
                                    totalWidth:AUCommonUIGetScreenWidth()];
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    DemoContentModel *model = [self.contentModelList objectAtIndex:indexPath.section];
    return model.contentView.height;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    DemoContentModel *model = [self.contentModelList objectAtIndex:section];
    AUAssitLableView *view = [[AUAssitLableView alloc] initWithViewType:AUAssitLableViewTypeHeader
                                                           describeText:model.headerTitle];
    return view;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"tableView"];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    DemoContentModel *model = [self.contentModelList objectAtIndex:indexPath.section];
    [cell.contentView addSubview:model.contentView];
    
    [cell.contentView addSubview:[self getANewSpliteLineWithTop:0 left:0]];
    [cell.contentView addSubview:[self getANewSpliteLineWithTop:model.contentView.height left:0]];
    
    cell.backgroundColor = [UIColor clearColor];
    return cell;
}

- (UIView *)getNewWrapView
{
    UIView *wrapView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, AUCommonUIGetScreenWidth(), kDemoGlobalCellHeight)];
    wrapView.backgroundColor = [UIColor whiteColor];
    return wrapView;
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    [self.view endEditing:YES];
}

@end

