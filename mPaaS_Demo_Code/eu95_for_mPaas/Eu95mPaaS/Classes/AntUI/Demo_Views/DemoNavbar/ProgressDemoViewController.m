//
//  ProgressDemoViewController.m
//  AntUIDemo
//
//  Created by Wang on 2018/7/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ProgressDemoViewController.h"
#import "CAGradientLayerDemoFactory.h"

@interface ProgressDemoViewController ()

@end

@implementation ProgressDemoViewController

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.navigationItem.rightBarButtonItems = @[
                                                //按钮1
                                                ({
        AUBarButtonItem *righItem = [AUBarButtonItem barButtonItemWithTitle:@"筛选" target:self action:@selector(clickRightItem:)];
        righItem;
    }),
                                                //留空
                                               // ({[AUBarButtonItem flexibleSpaceItem];}),
                                                //按钮2
                                                ({
                                                    AUBarButtonItem *righItem = [AUBarButtonItem barButtonItemWithTitle:@"筛选2" target:self action:@selector(clickRightItem:)];
                                                    righItem;
                                                }),
                                                
                                                ];
}
-(void) clickRightItem:(id) sender
{
    
}


@end
