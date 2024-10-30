//
//  SegmentNavigationDemoViewController.m
//  AntUIDemo
//
//  Created by Wang on 2018/7/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "SegmentNavigationDemoViewController.h"
#import "CAGradientLayerDemoFactory.h"
@interface SegmentNavigationDemoViewController ()

@end

@implementation SegmentNavigationDemoViewController

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
     [CAGradientLayerDemoFactory removeCurrentNaviLayer:self.navigationController.navigationBar];
    
     [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor colorWithRGB:0x111111 alpha:0.f] translucent:YES];
    
    AUSegment *segment = [[AUSegment alloc]initWithFrame:CGRectMake(0, 0, self.navigationController.navigationBar.width, self.navigationController.navigationBar.height) menus:@[
                                                                                                                                                                                 ({
        AUSegmentItemModel *model1 = [[AUSegmentItemModel alloc]init];
        //设置红点
        model1.badgeNumber = @".";
        model1.title = @"Tab标题1";
        model1;
    }),
                                                                                                                                                                                 ({
        AUSegmentItemModel *model2 = [[AUSegmentItemModel alloc]init];
        model2.title = @"Tab标题2";
        model2;
    })]];
    
    segment.delegate = (id <AUSegmentedControlDelegate>)self;
    
    self.navigationItem.titleView = segment;
}

- (void)didSegmentValueChanged:(AUSegment*)segmentControl
{
    NSLog(@"Segment DidChanged");
}

@end
