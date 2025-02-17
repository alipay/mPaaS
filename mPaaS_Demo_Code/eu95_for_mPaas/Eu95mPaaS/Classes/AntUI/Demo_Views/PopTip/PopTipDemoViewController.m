//
//  PopTipDemoViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2018/2/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "PopTipDemoViewController.h"
#import "AUPopTipView.h"
#import "AUPopBar.h"
#import "AUPopFloatView.h"
#import "AUPopMsgView.h"

@interface PopTipDemoViewController ()

@end

@implementation PopTipDemoViewController

- (void)showPopTipWithButton:(UIButton *)button
{
    static NSInteger count = 0;
    
    if ([self.view viewWithTag:98]) {
        [(AUPopTipView *)[self.view viewWithTag:98] dismiss:YES];
    }
    else {
        
        count ++;
        
        AUPopTipView *popTipView = nil;
        if(count % 2) {
            popTipView = [AUPopTipView showFromView:button
                                                    fromPoint:CGPointZero
                                                       toView:self.view
                                                     animated:YES
                                                     withText:@"你好熟练度福建省练"
                                                  buttonTitle:@"关闭"];
            if(count % 4 == 0){
                popTipView.contentViewDidClicked = ^(AUPopDrawBoardView *view) {
                    NSLog(@"点击自己");
                };
            }
        }
        else {
            popTipView =[[AUPopTipView alloc]initWithText:@"你好熟练度福建省练" buttonTitle:@"关闭" buttonAction:^BOOL{
                NSLog(@"closed");
                return YES;
            }];
            popTipView.actionOnDismiss = ^{
                NSLog(@"dismissed");
            };
            if(count % 3 == 0) {
                popTipView.contentViewDidClicked = ^(AUPopDrawBoardView *view) {
                    NSLog(@"点击自己");
                };
            }
            
            
            [[popTipView contentView].button setBackgroundColor:[UIColor redColor]];
          
             
             
            [popTipView showFromView:button
                           fromPoint:CGPointZero
                              toView:self.view
                            animated:YES];
            
        }
//        popTipView.width = 250;
        popTipView.indicatorDirection = AUPopViewIndicatorDirectionDown;
        popTipView.tag = 98;
   //     [popTipView setBackgroundColor:[UIColor blackColor]];
    }
}

- (void)showPopTipWithoutButton:(UIButton *)button
{
    if ([self.view viewWithTag:97]) {
        [(AUPopTipView *)[self.view viewWithTag:97] dismiss:YES];
    }
    else {
        AUPopTipView *popTipView = [AUPopTipView showFromView:button
                                                    fromPoint:CGPointZero
                                                       toView:self.view
                                                     animated:YES
                                                     withText:@"你好熟练度福建省练度福建省练度福建省"
                                                  buttonTitle:nil];
        popTipView.contentViewDidClicked = ^(AUPopDrawBoardView *view) {
            NSLog(@"点击自己");
            [view dismiss:YES];
        };
        popTipView.width = 320;
        popTipView.tag = 97;
        
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            button.y += 30;
//        });
        
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 100, 200, 300)];
//            view.backgroundColor = [UIColor blackColor];
//            [self.view addSubview:view];
//        });
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.rightBarButtonItem = [[AUBarButtonItem alloc]initWithTitle:@"测试测试" style:UIBarButtonItemStylePlain target:self action:NULL];
    
    AUPopTipView *tipView = [[AUPopTipView alloc]initWithText:@"这里有信用卡" buttonTitle:NULL buttonAction:NULL];
    [tipView removeCloseX];
    [tipView showFromView:self.view fromPoint:CGPointMake(self.view.width - 40, CGRectGetMaxY(self.navigationController.navigationBar.frame)) toView:self.view];
    [tipView setIndicatorDirection:AUPopViewIndicatorDirectionUp];

    
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"带有按钮" forState:UIControlStateNormal];
        button.width = 100;
        button.center = CGPointMake(300, 380);
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            [weakSelf showPopTipWithButton:weakButton];
        };
        [self showPopTipWithButton:button];
        
    }
    
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"带有按钮+X" forState:UIControlStateNormal];
        button.width = 100;
        button.center = CGPointMake(300, 380);
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            [weakSelf showPopTipWithButton:weakButton];
        };
        [self showPopTipWithButton:button];
        
    }
    
    
    {
        AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"不带有按钮" forState:UIControlStateNormal];
        button.width = 100;
        button.center = CGPointMake(100, 200);
        button.left = 0;
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            [weakSelf showPopTipWithoutButton:weakButton];
        };
        [self showPopTipWithoutButton:button];
        
        
    }
    
    
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"底部浮层" forState:UIControlStateNormal];
        button.width = 100;
        button.center = CGPointMake(200, 450);
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        button.auviewActionBlock = ^{
            if ([weakSelf.view viewWithTag:99]) {
                [(AUPopBar *)[weakSelf.view viewWithTag:99] dismiss:YES];
            }
            else {
                AUPopBar *popBar = [AUPopBar showInViewBottom:weakSelf.view animated:YES withText:@"<b>把“城市服务”添加\n到首页到首页到首页到首页</b>" icon:[UIImage imageNamed:@"ap_scan"] buttonTitle:@"立即添加" actionBlock:^{
                    NSLog(@"点击了");
                    return YES;
                }];
                popBar.tag = 99;
                
                
                [popBar setCloseActionBlock:^BOOL(AUPopBar *popbar) {
                    NSLog(@"自动dismiss");
                    return YES;
                }];
                
                
//                [popBar setBackgroundColor:[UIColor blackColor]];
            }
            
            
        };
        
    }
    
    {
        AUPopFloatView *tipView = [[AUPopFloatView alloc]initWithLeftIcon:AUBundleImage(@"antuiResource/auth_dialog_logo") text:@"测试测试"];
        tipView.origin_mp = CGPointMake(100, 600);
        tipView.delegate = self;
        [tipView showInView:[UIApplication sharedApplication].keyWindow atPoint:CGPointMake(0, (self.view.height - tipView.height) / 2) animated:YES];
        //[self.view addSubview:tipView];
    }

    {
        AUPopFloatView *tipView = AUPopFloatBackArrowView(@"测试测试");
        tipView.origin_mp = CGPointMake(20, 640);
        tipView.delegate = self;
        [tipView showInView:[UIApplication sharedApplication].keyWindow atPoint:CGPointMake(0, (self.view.height - tipView.height) / 2) animated:YES];
        //[self.view addSubview:tipView];
    }
    
    {
        AUPopFloatView *tipView = AUPopFloatWithBackArrowView(@"返回钉钉", AUPopFloatViewStyleDark);
        tipView.origin_mp = CGPointMake(self.view.width-tipView.width, 640);
        tipView.delegate = self;
        [tipView showInView:[UIApplication sharedApplication].keyWindow atPoint:CGPointMake(self.view.width-tipView.width, (self.view.height - tipView.height) / 2) animated:YES];
        //[self.view addSubview:tipView];
    }
    
    {
        
        static NSInteger count = 0;
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"底部浮层2" forState:UIControlStateNormal];
        button.width = 100;
        button.center = CGPointMake(200, 450);
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        button.auviewActionBlock = ^{
            if ([weakSelf.view viewWithTag:99]) {
                [(AUPopBar *)[weakSelf.view viewWithTag:99] dismiss:YES];
            }
            else {
                count ++;
                AUPopBar *popBar = nil;
                if(count %  2 == 0) {
                    popBar = [[AUPopBar alloc]initWithText:@"把“城市服务”" icon:[UIImage imageNamed:@"ap_scan"] buttonTitle:@"立即添加" actionBlock:^BOOL{
                        NSLog(@"点击了");
                        return YES;
                    }];
                }
                else {
                    popBar = [[AUPopBar alloc]initWithText:@"<b>把“城市服务”添加到首页到首页到首页到首页</b>" desc:@"测试测试测试测试测试" icon:[UIImage imageNamed:@"ap_scan"] buttonTitle:@"立即添加" actionBlock:^BOOL{
                        NSLog(@"点击了");
                        return YES;
                    }];
                }
                
                //[popBar showInView:self.view animated:NO];
                [popBar showInView:self.view position:CGPointMake(0, 100) verticalAlignment:UIControlContentVerticalAlignmentTop animated:NO];
                popBar.tag = 99;
                
                [popBar setCloseActionBlock:^BOOL(AUPopBar *popbar) {
                    NSLog(@"自动dismiss");
                    return YES;
                }];
                
                //                [popBar setBackgroundColor:[UIColor blackColor]];
            }
            
            
        };
        
    }

    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"往右靠" forState:UIControlStateNormal];
        button.width = 100;
        button.x = 50;
        button.tag = 120;
        button.center = CGPointMake(200, 550);
        button.auviewActionBlock = ^{
            static NSInteger times = 0;
            if([self.view viewWithTag:201])
            {
                AUPopTipView *popView = [self.view viewWithTag:201];
                [popView dismiss:YES];
            }
            else {
                times ++ ;
                NSMutableString *s = [NSMutableString new];
                for(NSInteger i = 0 ; i < times ; i++) {
                    [s appendString:@"测试"];
                }
                AUPopTipView *popTipView = [[AUPopTipView alloc]initWithText:s buttonTitle:@"关闭" buttonAction:^BOOL{
                    return YES;
                }];
                popTipView.tag = 201;
                //popTipView.customlizedMoveRightIfNeeded = YES;
                
                [popTipView showFromView:button
                               fromPoint:CGPointZero
                                  toView:self.view
                                animated:YES];
            }
   
        };
        [self.view addSubview:button];
    }
    
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"左侧间距32px不带X" forState:UIControlStateNormal];
        button.width = 100;
        button.x = 0;
        button.tag = 120;
        button.y = 600;
        button.auviewActionBlock = ^{
            AUPopTipView *popTipView =  [[AUPopTipView alloc]initWithText:@"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" buttonTitle:nil buttonAction:NULL];
            [popTipView removeCloseX];
            [popTipView enableMaskView:YES];
        
            popTipView.customlizedMiniMarginLeft = 16;
            popTipView.customlizedMiniMarginRight = 16;
            popTipView.contentView.fillMaxWidthIfMultipleLines = YES;
            [popTipView showFromView:button
                           fromPoint:CGPointZero
                              toView:self.view
            ];
            
        };
        [self.view addSubview:button];
    }
    
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"左侧间距32px" forState:UIControlStateNormal];
        button.width = 100;
        button.x = 0;
        button.tag = 120;
        button.y = 650;
        button.auviewActionBlock = ^{
            AUPopTipView *popTipView = [[AUPopTipView alloc]initWithText:@"你好像复制了：“钱包” | 去搜索" buttonTitle:nil buttonAction:NULL];
            popTipView.customlizedMiniMarginLeft = 16;
            
            [popTipView showFromView:button
                           fromPoint:CGPointZero
                              toView:self.view
                            animated:YES];
            
        };
        [self.view addSubview:button];
    }

    // AUPopMsgView
    {
        __block AUButton *button = [AUButton buttonWithStyle:AUButtonStyle6];
        [button setTitle:@"titleBar提示浮层" forState:UIControlStateNormal];
        button.width = 150;
        button.center = CGPointMake(100, 500);
        [self.view addSubview:button];
        __weak typeof(self) weakSelf = self;
        __weak AUButton *weakButton = button;
        button.auviewActionBlock = ^{
            [weakSelf showPoMsgWithoutButton:weakButton];
        };
//        [self showPoMsgWithoutButton:button];
        
//        AUBarButtonItem *item1 = [AUBarButtonItem barButtonItemWithIconFontName:kICONFONT_COMPLAIN target:nil action:NULL];
//        AUBarButtonItem *item2 = [AUBarButtonItem barButtonItemWithIconFontName:kICONFONT_PRAISE target:nil action:NULL];
//
//        self.navigationItem.rightBarButtonItems = @[item1, item2];
    }
    
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [popTipView setInidicatorDirection:AUTipPopViewIndicatorDirectionDown];
//    });
}

- (void)showPoMsgWithoutButton:(UIButton *)button
{
    if ([self.view viewWithTag:97]) {
        [(AUPopMsgView *)[self.view viewWithTag:97] dismiss:YES];
    }
    else {
//        NSArray *items = self.navigationItem.rightBarButtonItems;
        
        CGFloat startX = self.view.width - (158+16+21+10);
        CGFloat naviBarH = self.navigationController.navigationBar.height;
        AUPopMsgView *popTipView = [AUPopMsgView showFromView:self.navigationController.navigationBar
                                                    fromPoint:CGPointMake(startX, naviBarH*3+5)
                                                       toView:self.view
                                                     withIcon:[UIImage imageWithColor_au:RGB(0xe8e800) size:CGSizeMake(35, 35)]
                                                        title:@"你好，我是标题标题标题"
                                                     descText:@"你好熟练度福建省练度福建省练度福建省"];
//        popTipView.width = 320;
        popTipView.backgroundColor = RGB_A(0x333333, 0.85);
        popTipView.tag = 97;
        
    }
}


-(void) auPopFoloatViewDidClicked:(AUPopFloatView*)floatView
{
    [floatView dismiss:YES];
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
