//
//  DemoViewController.m
//  test
//
//  Created by mPaaS on 16/11/21.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) UITableView *tableView;

@end

@implementation DemoViewController

- (NSArray *)dataList
{
    return @[
        @{@"name":@"移动网关 Mobile Gat eway Service", @"class":@"MPRPCViewController"},
        @{@"name":@"实时发布服务 Mobile Delivery Service", @"class":@"MPMDSViewController"},
        @{@"name":@"H5容器和离线包 H5NebulaApp", @"class":@"MPH5NebulaAppViewController"},
        @{@"name":@"小程序 MiniProgram", @"class":@"MPMiniProgramViewController"},
        @{@"name":@"移动分析 Mobile Analysis Service", @"class":@"MP_AnalysisViewController"},
        @{@"name":@"终端环境检测 Mobile Environment Detection", @"class":@"MPSecurityViewController"},
//        @{@"name":@"AB实验室", @"class":@"MPABViewController"},
        ];
}
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    // 通知 Launcher 已经展示
    [[NSNotificationCenter defaultCenter] postNotificationName:@"kNotificationLauncherDidAppear" object:nil];

}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.tableView];
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self dataList].count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [UITableViewCell createCellWithTableView:tableView];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    if (indexPath.row < [self dataList].count) {
        NSDictionary *dic = [self dataList][indexPath.row];
//        cell.textLabel.text = dic[@"name"];
        cell.textLabel.text = NSLocalizedString(dic[@"name"], nil);
        cell.textLabel.font = [UIFont systemFontOfSize:18];
    }
   
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row < [self dataList].count) {
        NSDictionary *dic = [self dataList][indexPath.row];
        NSString *className = dic[@"class"];
        if (className.length) {
            Class cls = NSClassFromString(className);
            id vc = [[cls alloc] init];
            if ([vc isKindOfClass:UIViewController.class]) {
                [self.navigationController pushViewController:vc animated:YES];
            }
        }else{
            NSLog(@"没找到对应控制器");
        }
    }
}


- (UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.rowHeight = 64;
//        _tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    }
    return _tableView;
}


@end
