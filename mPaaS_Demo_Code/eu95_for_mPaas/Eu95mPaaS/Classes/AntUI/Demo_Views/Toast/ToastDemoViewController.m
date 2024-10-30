//
//  ToastDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ToastDemoViewController.h"

@interface ToastDemoViewController ()

@end

@implementation ToastDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"成功提示";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"成功提示（多行）";
    model.target = self;
    model.selector = @selector(onButton11Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"失败提示";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"警示提示";
    model.target = self;
    model.selector = @selector(onButton3Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"加载反馈";
    model.target = self;
    model.selector = @selector(onButton4Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"纯文本提示";
    model.target = self;
    model.selector = @selector(onButton5Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"纯文本提示（超长）";
    model.target = self;
    model.selector = @selector(onButton51Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"状态更新提示";
    model.target = self;
    model.selector = @selector(onButton6Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"页面加载（不带文案）";
    model.target = self;
    model.selector = @selector(onButton7Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"安全感toast提示框";
    model.target = self;
    model.selector = @selector(onButton8Clicked:);
    [models addObject:model];
    
//    AUDeviceIsIphoneX();
    
    self.functionList = models;
}

- (void)onButton8Clicked:(id)sender
{
//    AUToast *toast = [AUToast presentToastWithin:self.view withIcon:AUToastIconSecurity text:@"安全检测中" logTag:@"AntUIDemo"];
//    [toast performSelector:@selector(toastLoadingDidFinish) withObject:nil afterDelay:5.f];
}

- (void)onButton7Clicked:(id) sender
{
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [MBProgressHUD hideHUDForView:self.view animated:YES];
    });
}

- (void)onButton6Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view withIcon:AUToastIconLoading text:__TEXT(@"NebulaBiz", @"NebulaBiz:清理中", @"清理中") duration:10 delay:0.2 logTag:@"H5Service" completion:nil];
//    [loaddingToast removeFromSuperview];
//    return;
    dispatch_queue_t  queue = dispatch_queue_create("AntUI Demo", NULL);
    dispatch_async(queue, ^{
//        sleep(1);
        dispatch_async(dispatch_get_main_queue(), ^{
//            [loaddingToast dismissToast];
            [AUToast presentToastWithin:self.view withIcon:AUToastIconSuccess text:__TEXT(@"NebulaBiz", @"NebulaBiz:清理成功", @"清理成功") duration:6 logTag:@"H5Service" completion:nil];
        });
    });
}


- (void)onButton1Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconSuccess
                           text:@"成功提示"
                       duration:2
                         logTag:@"demo"];
}

- (void)onButton11Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconSuccess
                           text:@"已保存到系统相册"
                       duration:2
                         logTag:@"demo"];
}


- (void)onButton2Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconFailure
                           text:@"失败提示"
                       duration:2
                         logTag:@"demo"];
}

- (void)onButton3Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconAlert
                           text:@"警示信息"
                       duration:2
                         logTag:@"demo"];
}

- (void)onButton4Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconLoading
                           text:@"加载中"
                       duration:2
                         logTag:@"demo"];
}

- (void)onButton5Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconNone
                           text:@"最长文案不超过14个字"
                       duration:2
                         logTag:@"demo"];
}

- (void)onButton51Clicked:(id) sender
{
    [AUToast presentToastWithin:self.view
                       withIcon:AUToastIconNone
                           text:@"超长文案超长文案超长文案超长文案超长文案超长文案超长文案超长文案超长文案"
                       duration:2
                         logTag:@"demo"];
}

@end
