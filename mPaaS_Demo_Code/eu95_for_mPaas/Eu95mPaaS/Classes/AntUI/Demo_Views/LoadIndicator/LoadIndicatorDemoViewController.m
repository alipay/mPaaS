//
//  LoadIndicatorDemoViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/11/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "LoadIndicatorDemoViewController.h"
//#import "AUILoadingIndicatorView.h"
//#import "AULoadingIndicatorView.h"
//#import "AUSecurityLoadingView.h"

@interface LoadIndicatorDemoViewController ()
{
    MBProgressHUD *_hud;
//    AUSecurityLoadingView *_loading;
}
@end

@implementation LoadIndicatorDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    CGFloat topmargin = self.headerView.bottom;
    
    {
        AUILoadingIndicatorView *loadView = [[AUILoadingIndicatorView alloc] initWithType:AUILoadingIndicatorTypeDragLoadMore bizName:@"demo" makeConfig:NULL];
        loadView.y = topmargin;
        loadView.x = 20;
        [self.view addSubview:loadView];
        [loadView startAnimating];
    }
    
    {
        topmargin = self.headerView.bottom + 50;
        AUILoadingIndicatorView *loadView = [[AUILoadingIndicatorView alloc] initWithType:AUILoadingIndicatorTypeToast bizName:@"demo" makeConfig:NULL];
        loadView.y = topmargin ;
        loadView.x = 20;
        [self.view addSubview:loadView];
        [loadView startAnimating];
    }
    {
        topmargin = self.headerView.bottom + 100;
        AUILoadingIndicatorView *loadView = [[AUILoadingIndicatorView alloc] initWithType:AUILoadingIndicatorTypeButton bizName:@"demo" makeConfig:NULL];
        loadView.y = topmargin ;
        loadView.x = 20;
        [self.view addSubview:loadView];
        [loadView startAnimating];
    }
    {
        topmargin = self.headerView.bottom + 150;
        AULoadingIndicatorView *loadView2 = [[AULoadingIndicatorView alloc] initWithLoadingIndicatorStyle:AULoadingIndicatorViewStyleToast];
        loadView2.hidesWhenStopped = NO;
        loadView2.progress = 0.8;
        loadView2.y = topmargin ;
        loadView2.x = 20;
        [self.view addSubview:loadView2];
        [loadView2 startAnimating];
    }
    
//    {
//
//        topmargin = self.headerView.bottom + 200;
//
//        AUSecurityLoadingView *securityLoading = [[AUSecurityLoadingView alloc] initWithType:AUSecurityLoadingTypeInPage bizName:@"AntUIDemo"];
////        securityLoading.x = 20;
////        securityLoading.y = topmargin;
//
//        [securityLoading performSelector:@selector(loadingFinishAnimating:) withObject:nil afterDelay:6.f];
//
//        UIView *bgView = [[UIView alloc] initWithFrame:CGRectMake(20, topmargin, securityLoading.width+20, securityLoading.width+20)];
//        bgView.backgroundColor = [UIColor whiteColor];
//        [self.view addSubview:bgView];
//
//        [bgView addSubview:securityLoading];
//        securityLoading.origin = CGPointMake((bgView.width-securityLoading.width)/2, (bgView.height-securityLoading.height)/2);
//        [securityLoading startAnimating];
//        _loading = securityLoading;
//
//        AUButton *button = [AUButton buttonWithStyle:AUButtonStyle8];
//        [button setTitle:@"停止动画" forState:UIControlStateNormal];
//        button.origin = CGPointMake(bgView.right + 10, bgView.top + 5);
//        [button addTarget:self action:@selector(stopLoading:) forControlEvents:UIControlEventTouchUpInside];
//        [self.view addSubview:button];
//
//    }
}

//- (void)stopLoading:(id)sender
//{
//    [_loading stopAnimating];
//    [NSObject cancelPreviousPerformRequestsWithTarget:_loading];
//}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(15 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if(UIAccessibilityIsVoiceOverRunning())
        {
            _hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
            
            [_hud hide:YES afterDelay:20];
            
        }
    });
 
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
