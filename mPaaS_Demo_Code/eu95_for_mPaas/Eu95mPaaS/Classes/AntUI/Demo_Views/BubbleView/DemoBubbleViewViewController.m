//
//  DemoBubbleViewViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2018/5/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "DemoBubbleViewViewController.h"
//#import "AUBubbleView.h"

@interface DemoBubbleViewViewController ()

@end

@implementation DemoBubbleViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    AUButton *button = nil;
    
    {
        button = [AUButton buttonWithStyle:AUButtonStyle1];
        button.width = 100;
        button.centerX = self.view.width / 2;
        button.y = 160;
        [button setTitle:@"显示在左边" forState:UIControlStateNormal];
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            if ([weakButton viewWithTag:10]) {
                [[weakButton viewWithTag:10] removeFromSuperview];
            }
            else {
                AUBubbleView *bubbleView = [AUBubbleView showText:@"免单"
                                                         fromView:weakButton
                                                         position:AUBubbleViewPositionLeft];
                bubbleView.tag = 10;
                
                
//                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//                    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 100, 200, 300)];
//                    view.backgroundColor = [UIColor blackColor];
//                    [self.view addSubview:view];
//                    
//                    AUNoticeDialogWithTitleAndMessage(@"测试", @"但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是但是");
//                });
            }
        };
        [self.view addSubview:button];
    }
    
    {
        CGFloat nextY = CGRectGetMaxY(button.frame);
        button = [AUButton buttonWithStyle:AUButtonStyle1];
        button.width = 100;
        button.centerX = self.view.width / 2;
        button.y = nextY + 30;
        [button setTitle:@"显示在右边" forState:UIControlStateNormal];
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            if ([weakButton viewWithTag:10]) {
                [[weakButton viewWithTag:10] removeFromSuperview];
            }
            else {
                AUBubbleView *bubbleView = [AUBubbleView showText:@"免单"
                                                         fromView:weakButton
                                                         position:AUBubbleViewPositionRight];
                bubbleView.tag = 10;
            }
        };
        [self.view addSubview:button];
    }
    
    {
        CGFloat nextY = CGRectGetMaxY(button.frame);
        button = [AUButton buttonWithStyle:AUButtonStyle1];
        button.width = 100;
        button.centerX = self.view.width / 2;
        button.y = nextY + 30;
        [button setTitle:@"显示在中间" forState:UIControlStateNormal];
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            if ([weakButton viewWithTag:10]) {
                [[weakButton viewWithTag:10] removeFromSuperview];
            }
            else {
                AUBubbleView *bubbleView = [AUBubbleView showText:@"免单"
                                                         fromView:weakButton
                                                         position:AUBubbleViewPositionCenter];
                bubbleView.tag = 10;
            }
        };
        [self.view addSubview:button];
    }
}


- (void)onButton2Clicked:(id) sender
{
    
}


- (void)dealloc
{
    NSLog(@"DemoBubbleViewViewController dealloc");
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
