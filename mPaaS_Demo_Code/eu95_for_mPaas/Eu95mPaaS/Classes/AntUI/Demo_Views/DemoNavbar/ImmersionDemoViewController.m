//
//  ImmersionDemoViewController.m
//  AntUIDemo
//
//  Created by Wang on 2018/7/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ImmersionDemoViewController.h"

@interface ImmersionDemoViewController ()

@end

@implementation ImmersionDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIScrollView *scrollView = [[UIScrollView alloc]initWithFrame:self.view.bounds];
    scrollView.backgroundColor = [UIColor blueColor];
    scrollView.contentSize = CGSizeMake(self.view.width, 2 * self.view.height);
    scrollView.delegate = (id<UIScrollViewDelegate>)self;
    [self.view addSubview:scrollView];
    
    // Do any additional setup after loading the view.
}

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    //默认进来设置透明色NavigationBar
    [self setTransparentNavigationBar];
    
}

-(void) setTransparentNavigationBar
{
    //导航栏透明
    [self.navigationController.navigationBar setNavigationBarTranslucentStyle];
    //设置透明时标题字体颜色
    [self.navigationController.navigationBar setNavigationBarTitleTextAttributesWithTextColor:RGB(0xFFFFFF)];
    
    //设置透明时左侧按钮样式
    AUBarButtonItem *leftBarBtn = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(back)];
    leftBarBtn.titleColor = RGB(0xFFFFFF);
    leftBarBtn.backButtonImage = AUBundleImage(@"back_button_normal_white");
    self.navigationItem.leftBarButtonItem = leftBarBtn;
    
}

-(void) setDefaultNavigationItem
{
    [self.navigationController.navigationBar setNavigationBarDefaultStyle];
    [self.navigationController.navigationBar setNavigationBarDefaultTitleTextAttributes];
    
    //设置透明时左侧按钮样式
    AUBarButtonItem *leftBarBtn = [AUBarButtonItem backBarButtonItemWithTitle:@"返回" target:self action:@selector(back)];
    self.navigationItem.leftBarButtonItem = leftBarBtn;
}

#pragma --mark UIScrollViewDelegate
- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    if(scrollView.contentOffset.y >= 50) {
        [self setDefaultNavigationItem];
    }
    else{
        [self setTransparentNavigationBar];
    }
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
