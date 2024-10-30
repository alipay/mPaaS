//
//  MenuTitleViewDemoViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2017/11/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "MenuTitleViewDemoViewController.h"
#import "AUMenuTitleView.h"

@interface MenuTitleViewDemoViewController ()

@end

@implementation MenuTitleViewDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    AUMenuTitleView *titleView = [[AUMenuTitleView alloc] initWithTitle:@"标题"];
    self.navigationItem.titleView = titleView;
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
