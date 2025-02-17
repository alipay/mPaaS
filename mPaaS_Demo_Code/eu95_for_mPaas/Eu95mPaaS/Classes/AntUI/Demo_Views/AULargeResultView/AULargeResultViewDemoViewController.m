//
//  AULargeResultViewDemoViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2018/3/5.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "AULargeResultViewDemoViewController.h"
//#import "AULargeResultView.h"

@interface AULargeResultViewDemoViewController ()

@end

@implementation AULargeResultViewDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"Result View";
    self.view.backgroundColor = RGB(0xF5F5F9);
    
    UIScrollView *contentView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, AUCommonUIGetScreenWidth(), AUCommonUIGetScreenHeight())];
    [self.view addSubview:contentView];
    
    CGFloat originY = self.topMargin + 16;
    CGFloat marginX = 0;
    
    UIImage *image = AUBundleImage(@"alipay-60");
    AULargeResultView *largeResult = [[AULargeResultView alloc] initWithResultModel:^(AULargeResultViewModel *model) {
        model.icon = image;
        model.mainTitleText = @"支付成功";
        model.midTitleText = @"998.0元";
        model.bottomMessage = @"1098.00元";
        model.messageThrough = YES;
    }];
    [largeResult addActionButtonTitle:@"主要操作" target:nil action:nil];
    [largeResult addActionButtonTitle:@"辅助操作" target:nil action:nil];
    largeResult.frame = CGRectMake(marginX, originY, AUCommonUIGetScreenWidth()-2*marginX, largeResult.expectHeight);
    [self.view addSubview:largeResult];
//
//    AUResultView *resultView = [[AUResultView alloc] initWithIcon:image
//                                                    mainTitleText:@"支付成功"
//                                                     midTitleText:@"998.00"
//                                                    bottomMessage:@"1098.00元"
//                                                   messageThrough:YES];
//    resultView.frame = CGRectMake(marginX, originY, AUCommonUIGetScreenWidth()-2*marginX, resultView.expectHeight);
//    [contentView addSubview:resultView];
//    originY += resultView.expectHeight+15;
//
//    image = [UIImage imageNamed:@"result_wait"];
//    AUResultView *waitResult = [[AUResultView alloc] initWithIcon:image
//                                                    mainTitleText:@"等待处理"
//                                                     midTitleText:nil
//                                                    bottomMessage:@"已提交申请，等待银行处理"
//                                                   messageThrough:NO];
//    waitResult.frame = CGRectMake(marginX, originY , AUCommonUIGetScreenWidth()-2*marginX, waitResult.expectHeight);
//    [contentView addSubview:waitResult];
//    originY += waitResult.expectHeight+15;
//    waitResult.hideShadow = YES;
//
//    image = [UIImage imageNamed:@"result_warning"];
//    AUResultView *warningResult = [[AUResultView alloc] initWithIcon:image
//                                                       mainTitleText:@"无法完成操作"
//                                                        midTitleText:nil
//                                                       bottomMessage:@"由于你的支付宝账户还未绑定淘宝账户请登请登录www.taobao.com"
//                                                      messageThrough:NO];
//    warningResult.frame = CGRectMake(marginX, originY, AUCommonUIGetScreenWidth()-2*marginX, warningResult.expectHeight);
//    [contentView addSubview:warningResult];
//    originY += warningResult.expectHeight+15;
//
//    image = [UIImage imageNamed:@"result_info"];
//    AUResultView *infoResult = [[AUResultView alloc] initWithIcon:image
//                                                    mainTitleText:@"提示信息"
//                                                     midTitleText:nil
//                                                    bottomMessage:@"辅助说明信息"
//                                                   messageThrough:NO];
//    infoResult.frame = CGRectMake(marginX, originY, AUCommonUIGetScreenWidth()-2*marginX, infoResult.expectHeight);
//    [contentView addSubview:infoResult];
    
//    CGFloat contentHeight = originY + infoResult.expectHeight + 16;
//    contentView.contentSize = CGSizeMake(AUCommonUIGetScreenWidth(), contentHeight);
    
}

@end
