//
//  SegmentDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SegmentDemoViewController.h"


@implementation SegmentDemoViewController

- (void)updateTitle:(AUSegment *)segment
{
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (int i=0; i<5; i++) {
        AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
        if (i == 4) {
            model.title = [NSString stringWithFormat:@"选项选项"];
        } else {
            model.title = [NSString stringWithFormat:@"选项"];
        }
        
        model.badgeReserved = NO;
        [array addObject:model];
    }
    [segment updateItems:array];
    [self performSelector:@selector(updateAgain:) withObject:segment afterDelay:3];
}

- (void)updateModel:(AUSegment *)segment
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = @"选项";
    model.badgeNumber = @"2";
    [segment updateItemModel:model atIndex:1];
    [self performSelector:@selector(updateModel1:) withObject:segment afterDelay:1];
}

- (void)updateModel1:(AUSegment *)segment
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = @"选项";
    model.badgeNumber = @"new";
    [segment updateItemModel:model atIndex:1];
    [self performSelector:@selector(updateModel2:) withObject:segment afterDelay:1];
}

- (void)updateModel2:(AUSegment *)segment
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = @"选项";
    model.badgeNumber = @".";
    [segment updateItemModel:model atIndex:1];
    [self performSelector:@selector(updateModel3:) withObject:segment afterDelay:1];
}

- (void)updateModel3:(AUSegment *)segment
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = @"选项";
    model.badgeNumber = @"惠";
    [segment updateItemModel:model atIndex:1];
    [self performSelector:@selector(updateModel4:) withObject:segment afterDelay:1];
}

- (void)updateModel4:(AUSegment *)segment
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = @"选项";
    model.badgeNumber = @"99";
    [segment updateItemModel:model atIndex:1];
    [self performSelector:@selector(updateModel:) withObject:segment afterDelay:1];
}


- (void)updateAgain:(AUSegment *)segment
{
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (int i=0; i<7; i++) {
        AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
        if (i == 4) {
            model.title = [NSString stringWithFormat:@"选项选项"];
        } else {
            model.title = [NSString stringWithFormat:@"选项"];
        }
        model.badgeReserved = YES;
        [array addObject:model];
    }
    [segment updateItems:array];
}

- (void)viewDidLoad
{
    self.view = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [super viewDidLoad];    
//    self.view.backgroundColor = kDemoGlobalBackgroundColor;
    
    CGFloat topMargin = self.headerView.bottom;
    
    {
        NSArray *testArray1 = @[@"选项一",@"选项二"];
        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) titles:testArray1];
        
//        NSMutableArray *array = [[NSMutableArray alloc] init];
//        for (int i=0; i<5; i++) {
//            AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
//            if (i == 4) {
//                model.title = [NSString stringWithFormat:@"选项选项"];
//            } else {
//                model.title = [NSString stringWithFormat:@"选项"];
//            }
//
//            model.badgeReserved = NO;
//            [array addObject:model];
//        }
//        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) menus:array];
        segment.fixedItemWidth = NO;
        segment.autoScroll = YES;
        segment.textHorizontalPadding = 12;
//        segment.autoChangeSelectedIndex = NO;
        segment.backgroundColor = [UIColor whiteColor];
        [self.view addSubview:segment];
        topMargin = segment.bottom + 15;
        [segment showActionIcon:YES target:self action:@selector(clickActionIcon:)];
        
        [self performSelector:@selector(updateModel:) withObject:segment afterDelay:1];
    }
    
    {
        NSArray *testArray1 = @[@"选项一",@"选项二",@"选项三"];
        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) titles:testArray1];
        segment.backgroundColor = [UIColor whiteColor];
        [self.view addSubview:segment];
        topMargin = segment.bottom + 15;
        [segment showActionIcon:YES target:self action:@selector(clickActionIcon:)];
    }

    {
        NSArray *testArray1 = @[@"选项一",@"选项二",@"选项三"];
        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) titles:testArray1];
        segment.backgroundColor = [UIColor whiteColor];
        [segment addTitleArray:@[@"选项四"]];
        [self.view addSubview:segment];
        [segment showActionIcon:YES target:self action:@selector(clickActionIcon:)];
        topMargin = segment.bottom + 15;
    }

    {
        NSArray *testArray1 = @[@"选项一1",@"选项二",@"选项三"];
        AUSegment *segment = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) titles:testArray1];
        segment.backgroundColor = [UIColor whiteColor];
        [segment insertTitleArray:@[@"选项四", @"选项五"] atIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(3, 2)]];
        [self.view addSubview:segment];
        [segment showActionIcon:YES target:self action:@selector(clickActionIcon:)];
        topMargin = segment.bottom + 15;
    }

    {
        UILabel *label = [[UILabel alloc] init];
        label.text = @"调整内边距为60像素";
        label.font = [UIFont systemFontOfSize:11];
        [label sizeToFit];
        label.frame = CGRectMake(kDemoGlobalMargin, topMargin, label.width, label.height);
        label.textColor = [UIColor colorWithRGB:0x999999];
        label.backgroundColor = [UIColor clearColor];
        label.textAlignment = NSTextAlignmentCenter;
        [self.view addSubview:label];
        topMargin = label.bottom + 8;

        NSArray *testArray1 = @[@"选项一",@"选项二",@"选项三",@"选项四", @"选项五",@"选项六", @"选项七"];
        AUSegment *segment2 = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) titles:testArray1];
        segment2.backgroundColor = [UIColor whiteColor];
        segment2.fixedItemWidth = NO;
        segment2.textHorizontalPadding = 30;

        [self.view addSubview:segment2];
        [segment2 showActionIcon:YES target:self action:@selector(clickActionIcon:)];
        [segment2 setNeedsLayout];

        topMargin = segment2.bottom + 15;
    }

    {
        UILabel *label = [[UILabel alloc] init];
        label.textColor = [UIColor colorWithRGB:0x999999];
        label.font = [UIFont systemFontOfSize:11];
        label.text = @"红点样式";
        [label sizeToFit];
        label.frame = CGRectMake(kDemoGlobalMargin, topMargin, label.width, label.height);
        label.backgroundColor = [UIColor clearColor];
        label.textAlignment = NSTextAlignmentCenter;
        [self.view addSubview:label];
        topMargin = label.bottom + 8;

        NSMutableArray *array = [[NSMutableArray alloc] init];
        for (int i=0; i<7; i++)
        {
            AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
            model.title = [NSString stringWithFormat:@"选项 %d", i];
            if (i == 0)
            {
                model.badgeNumber = @".";
            }
            if (i == 1)
            {
                model.badgeNumber = @"new";
            }
            if (i == 6)
            {
                model.badgeNumber = @"6";
            }
            model.badgeReserved = YES;
            [array addObject:model];
        }
        AUSegment *segment2 = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) menus:array];
        [self.view addSubview:segment2];
        [segment2 autoScrollToIndex:6];
        segment2.backgroundColor = [UIColor whiteColor];
        [segment2 showActionIcon:YES target:self action:@selector(clickActionIcon:)];

        [self performSelector:@selector(updateScrollIndex:) withObject:segment2 afterDelay:2];
        [self performSelector:@selector(updateScrollIndex2:) withObject:segment2 afterDelay:4];
//        [self performSelector:@selector(updateBadgeView3:) withObject:segment2 afterDelay:6];


        topMargin = segment2.bottom + 15;
    }
    
    {
        UILabel *label = [[UILabel alloc] init];
        label.textColor = [UIColor colorWithRGB:0x999999];
        label.font = [UIFont systemFontOfSize:11];
        label.text = @"自定义左右边距样式";
        [label sizeToFit];
        label.frame = CGRectMake(kDemoGlobalMargin, topMargin, label.width, label.height);
        label.backgroundColor = [UIColor clearColor];
        label.textAlignment = NSTextAlignmentCenter;
        [self.view addSubview:label];
        
        UILabel *label1 = [[UILabel alloc] init];
        label1.textColor = [UIColor colorWithRGB:0x999999];
        label1.font = [UIFont systemFontOfSize:11];
        label1.text = @"自定义左右边距样式";
        [label1 sizeToFit];
        label1.frame = CGRectMake(self.view.width-label.width-kDemoGlobalMargin, topMargin, label.width, label.height);
        label1.backgroundColor = [UIColor clearColor];
        label1.textAlignment = NSTextAlignmentCenter;
        [self.view addSubview:label1];
        
        
        topMargin = label.bottom + 8;
        
        NSMutableArray *array = [[NSMutableArray alloc] init];
        for (int i=0; i<7; i++)
        {
            AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
            model.title = [NSString stringWithFormat:@"选项 %d", i];
            if (i == 0)
            {
                model.title = [NSString stringWithFormat:@"选项 %d kskaskk", i];
                model.badgeNumber = @".";
            }
            if (i == 1)
            {
                model.badgeNumber = @"new";
            }
            if (i == 3) {
                model.title = [NSString stringWithFormat:@"选项 %d henchanghenchang", i];
            }
            if (i == 6)
            {
                model.badgeNumber = @"6";
            }
            model.badgeReserved = YES;
            [array addObject:model];
        }
        AUSegment *segment2 = [[AUSegment alloc] initWithFrame:CGRectMake(0, topMargin, self.view.width, 44) menus:array];
        [self.view addSubview:segment2];
//        [segment2 autoScrollToIndex:6];
        segment2.fixedItemWidth = NO;
        segment2.itemSpace = 60;
        segment2.itemToEdgeSpace = 16;
        segment2.autoScroll = YES;
        segment2.backgroundColor = [UIColor whiteColor];
//        [segment2 showActionIcon:YES target:self action:@selector(clickActionIcon:)];
        
        [self performSelector:@selector(updateScrollIndex:) withObject:segment2 afterDelay:2];
//        [self performSelector:@selector(updateScrollIndex2:) withObject:segment2 afterDelay:4];
        [self performSelector:@selector(updateBadgeView3:) withObject:segment2 afterDelay:6];
        
        
        topMargin = segment2.bottom + 15;
    }

    CGPoint point = self.footerView.origin_mp;
    point.y = topMargin;
    self.footerView.origin_mp = point;

    topMargin = self.footerView.bottom + 60;
    
    
    [(UIScrollView *)self.view setContentSize:CGSizeMake(self.view.width, topMargin)];
}

- (void)clickActionIcon:(id)sender
{
    AUToastShowWithAutoHide(self.view, AUToastIconNone, @"click action icon", @"AntUIDemo");
}

- (void)updateScrollIndex:(id)sender
{
    AUSegment *segment = (AUSegment *)sender;
    [segment autoScrollToIndex:4];
}

- (void)updateScrollIndex2:(id)sender
{
    AUSegment *segment = (AUSegment *)sender;
    [segment autoScrollToIndex:1];
}

- (void)updateBadgeView:(id)sender
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = [NSString stringWithFormat:@"选项 1"];
    model.badgeNumber = nil;
    model.badgeReserved = YES;
    
    if ([sender isKindOfClass:[AUSegment class]])
    {
        AUSegment *segment = (AUSegment *)sender;
        [segment updateItems:@[model]];
    }
}

- (void)updateBadgeView2:(id)sender
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = [NSString stringWithFormat:@"选项 1"];
    model.badgeNumber = @"2";
    model.badgeReserved = YES;
    
    if ([sender isKindOfClass:[AUSegment class]])
    {
        AUSegment *segment = (AUSegment *)sender;
        [segment updateItems:@[model]];
    }
}

- (void)updateBadgeView3:(id)sender
{
    AUSegmentItemModel *model = [[AUSegmentItemModel alloc] init];
    model.title = [NSString stringWithFormat:@"选"];
    model.badgeNumber = @"99";
    model.badgeReserved = YES;
    
    if ([sender isKindOfClass:[AUSegment class]])
    {
        AUSegment *segment = (AUSegment *)sender;
//        [segment updateItems:@[model]];
        [segment updateItemModel:model atIndex:3];
    }
}


@end
