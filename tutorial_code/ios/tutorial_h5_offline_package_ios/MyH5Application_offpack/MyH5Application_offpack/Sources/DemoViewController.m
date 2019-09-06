//
//  DemoViewController.m
//  MyH5Application_offpack
//
//  Created by Evan on 2019/08/23.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    UIButton *button4 = [UIButton buttonWithType:UIButtonTypeCustom];
    button4.frame = CGRectMake(30, 150, [UIScreen mainScreen].bounds.size.width-60, 44);
    button4.backgroundColor = [UIColor blueColor];
    [button4 setTitle:@"打开离线包页面" forState:UIControlStateNormal];
    [button4 addTarget:self action:@selector(startOffPack) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button4];
    
    UIButton *button5 = [UIButton buttonWithType:UIButtonTypeCustom];
    button5.frame = CGRectOffset(button4.frame, 0, 80);
    button5.backgroundColor = [UIColor blueColor];
    [button5 setTitle:@"更新离线包" forState:UIControlStateNormal];
    [button5 addTarget:self action:@selector(updateOffPack) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button5];

}

- (void)startOffPack
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithNebulaApp:@{@"appId":@"80000000"}];
}

- (void)updateOffPack
{
    [[MPNebulaAdapterInterface shareInstance] requestNebulaAppsWithParams:@{@"80000000":@"*"} finish:^(NSDictionary *data, NSError *error) {
        NSString *result = @"后台无新包发布";
        if (!error && [data[@"data"] count] > 0) {
            result = [NSString stringWithFormat:@"%@", data[@"data"]];
        }
        
        dispatch_async(dispatch_get_main_queue(), ^{
            UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:@"离线包已更新" message:result delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
            [alertView show];
        });
    }];
}



@end
