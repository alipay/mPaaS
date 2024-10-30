//
//  DemoAgreementViewViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2018/1/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "DemoAgreementViewViewController.h"
//#import "AUAgreementView.h"

@interface DemoAgreementViewViewController ()

@end

@implementation DemoAgreementViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    {
        AUAgreementView *view = [[AUAgreementView alloc] initWithOrigin:CGPointMake(0, self.topMargin) richText:@"查看<a href='http://www.baidu.com'>《用户授权协议》</a><a>《芝麻服务协议及相关授权条款》</a><a>《骑行用户信息授权协议》</a><a>《单车方用户服务协议》</a>"];
        [view setLinkActionBlock:^BOOL(NSString *urlString) {
            NSLog(@"%@", urlString);
            return YES;
        }];
        [self.view addSubview:view];
        self.topMargin = view.bottom + 10;
    }
    
    {
        AUAgreementView *view = [[AUAgreementView alloc] initAgreementViewOrigin:CGPointMake(0, self.topMargin) richText:@"同意<a href='http://www.baidu.com'>《用户授权协议》</a><a href='http://www.baidu.com>《芝麻服务协议及相关授权条款》</a><a href='http://www.baidu.com>《骑行用户信息授权协议》</a><a href='http://www.baidu.com>《单车方用户服务协议》</a>"];
        [view setLinkActionBlock:^BOOL(NSString *urlString) {
            NSLog(@"%@", urlString);
            return YES;
        }];
        [view.checkBox addTarget:self action:@selector(onClickCheckBox:) forControlEvents:UIControlEventValueChanged];
        [self.view addSubview:view];
        self.topMargin = view.bottom + 10;
    }
    
    {
        AUAgreementView *view = [[AUAgreementView alloc] initAgreementViewOrigin:CGPointMake(0, self.topMargin) richText:@"同意<a href='http://www.baidu.com'>《用户授权协议》</a><a href='http://www.baidu.com>《芝麻服务协议及相关授权条款》</a><a href='http://www.baidu.com>《骑行用户信息授权协议》</a><a href='http://www.baidu.com>《单车方用户服务协议》</a>"];
        [view setLinkActionBlock:^BOOL(NSString *urlString) {
            NSLog(@"%@", urlString);
            return YES;
        }];
        [view.checkBox addTarget:self action:@selector(onClickCheckBox:) forControlEvents:UIControlEventValueChanged];
        [self.view addSubview:view];
        self.topMargin = view.bottom + 10;
    }
}

- (void)onClickCheckBox:(id)sender
{
    NSLog(@"click checkBox");
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
