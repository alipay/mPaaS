//
//  AUImageTextTitleBarDemoViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2017/11/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUImageTextTitleBarDemoViewController.h"
#import "AUImageTextTitleView.h"

@interface AUImageTextTitleBarDemoViewController ()

@end

@implementation AUImageTextTitleBarDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view.
    
    AUImageTextTitleView *titleView = [[AUImageTextTitleView alloc] initWithIcon:[UIImage imageWithColor_au:[UIColor colorWithRGB:0xCCCCCC] size:CGSizeMake(20, 30)] title:@"标题"];
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
