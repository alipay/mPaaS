//
//  FooterDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "FooterDemoViewController.h"
//#import "AUCopyrightView.h"
//#import "AUPageFooterView.h"

@implementation FooterDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    CGFloat topMargin = self.topMargin;
    
    {
        AUCopyrightView *copyRightView1 = [[AUCopyrightView alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 40) string:@"© 2004-2017 Alipay.com. All rights reserved."];
        copyRightView1.centerX = self.view.centerX;
        [self.view addSubview:copyRightView1];
        topMargin = copyRightView1.bottom + 22;
    }
    
    {
        AUPageFooterView *ankletView = [[AUPageFooterView alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 100) params:^(AUPageFooterModel *model) {
            model.textLinkInfos = [[NSMutableArray alloc] initWithArray:@[@"底部链接"]];
            model.copyrightInfo = @"© 2004-2017 Alipay.com. All rights reserved.";
        }];
        ankletView.centerX = self.view.centerX;
        [self.view addSubview:ankletView];
        topMargin = ankletView.bottom + 22;
    }

    {
        AUPageFooterView *ankletView = [[AUPageFooterView alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 100) params:^(AUPageFooterModel *model) {
            model.textLinkInfos = [[NSMutableArray alloc] initWithArray:@[@"底部链接，底部链接"]];
            model.copyrightInfo = @"© 2004-2017 Alipay.com. All rights reserved.";
        }];
        ankletView.centerX = self.view.centerX;
        [self.view addSubview:ankletView];
        topMargin = ankletView.bottom + 64;
    }

    {
        AUTextLinkView *textLinkBtns = [[AUTextLinkView alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 50) params:@[@"底部链接", @"底部链接"]];
        textLinkBtns.centerX = self.view.centerX;
        [self.view addSubview:textLinkBtns];
//        topMargin = textLinkBtns.bottom + 22;
    }
    
    self.topMargin = topMargin + 50;
}

@end
