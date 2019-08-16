//
//  MPNebulaViewController.m
//  MPH5Demo_plugin
//
//  Created by yangwei on 2019/8/13.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPNebulaViewController.h"
#import <mPaas/MPJSONKit.h>

@interface MPNebulaViewController ()

@end

@implementation MPNebulaViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"离线包";
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(30, 150, [UIScreen mainScreen].bounds.size.width-60, 44);
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"打开离线包应用" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(openJsApiDemo) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectOffset(button.frame, 0, 80);
    button1.backgroundColor = [UIColor blueColor];
    [button1 setTitle:@"更新离线包" forState:UIControlStateNormal];
    [button1 addTarget:self action:@selector(updateOffLinePackage) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectOffset(button1.frame, 0, 80);
    button2.backgroundColor = [UIColor blueColor];
    [button2 setTitle:@"预置离线包" forState:UIControlStateNormal];
    [button2 addTarget:self action:@selector(openPresetPackage) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    button3.frame = CGRectOffset(button2.frame, 0, 80);
    button3.backgroundColor = [UIColor blueColor];
    [button3 setTitle:@"远程离线包" forState:UIControlStateNormal];
    [button3 addTarget:self action:@selector(openJsApiDemo) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:button3];
}


- (void)openJsApiDemo {
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithNebulaApp:@{@"appId":@"70000000"}];
}

- (void)updateOffLinePackage
{
    // 更新离线包
    [[MPNebulaAdapterInterface shareInstance] requestNebulaAppsWithParams:@{@"70000000":@"*"} finish:^(NSDictionary *data, NSError *error) {
        if (!error) {
            NSLog(@"[mpaas] nebula rpc data :%@", data[@"data"]);
            dispatch_async(dispatch_get_main_queue(), ^{
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"message" message:@"更新成功" delegate:nil cancelButtonTitle:nil otherButtonTitles:@"ok", nil];
                [alert show];
            });
        }
    }];
}

- (void)openPresetPackage {
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithNebulaApp:@{@"appId":@"00025000"}];
}
@end
