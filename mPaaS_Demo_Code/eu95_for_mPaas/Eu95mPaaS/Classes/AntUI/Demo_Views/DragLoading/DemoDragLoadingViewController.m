//
//  DemoDragLoadingViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/11/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoDragLoadingViewController.h"
#import "DemoCollectionDragLoadingViewController.h"
#import "DemoTableViewDragLoadingViewController.h"

@interface DemoDragLoadingViewController ()

@end

@implementation DemoDragLoadingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSMutableArray *models = [[NSMutableArray alloc] init];

    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"table上拉记载";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];

    model = [[DemoFunctionListModel alloc] init];
    model.title = @"collectionView上拉加载";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
    
    self.functionList = models;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)onButton1Clicked:(id) sender
{
    DemoTableViewDragLoadingViewController *vc = [DemoTableViewDragLoadingViewController new];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)onButton2Clicked:(id) sender
{
    DemoCollectionDragLoadingViewController *vc = [DemoCollectionDragLoadingViewController new];
    [self.navigationController pushViewController:vc animated:YES];
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
