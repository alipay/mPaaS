//
//  SwitchDemoViewViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SwitchDemoViewViewController.h"


@implementation SwitchDemoViewViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    CGFloat topmargin = self.topMargin;
    
    {
        UILabel *label = [AssistDemoDefaultLabelUtil createDefaultLabelStyle1:@"默认样式"];
        label.frame = CGRectMake(kDemoGlobalMargin, topmargin, label.width, label.height);
        [self.view addSubview:label];
        
        topmargin = label.bottom + 8;
    }
    
    {
        AUSwitch *switch1 = [[AUSwitch alloc] initWithFrame:CGRectMake(kDemoGlobalMargin, topmargin, 51, 31)];
        switch1.on = YES;
        [self.view addSubview:switch1];
        
        AUSwitch *switch2 = [[AUSwitch alloc] initWithFrame:CGRectMake(switch1.right + kDemoGlobalMargin, topmargin, 51, 31)];
        switch2.on = NO;
        [self.view addSubview:switch2];
        
        topmargin = switch1.bottom + 20;
    }
    
    {
        UILabel *label = [AssistDemoDefaultLabelUtil createDefaultLabelStyle1:@"开关"];
        label.frame = CGRectMake(kDemoGlobalMargin, topmargin, label.width, label.height);
        [self.view addSubview:label];
        
        topmargin = label.bottom + 8;

    }
    
    NSArray *array = @[@"开启", @"关闭"];
    [self createCheckboxList:array topMargin:topmargin];
}

- (CGFloat)createCheckboxList:(NSArray *)lists topMargin:(CGFloat)topMargin
{
    CGFloat lineHeight = 1/[UIScreen mainScreen].scale;
    CGFloat cellTopMargin = topMargin;
    for (NSString *title in lists)
    {
        UIView *view = [self createlistView:title topMargin:cellTopMargin];
        [self.view addSubview:view];
        
        UIView *line = [[UIView alloc] initWithFrame:CGRectMake(kDemoGlobalMargin, view.bottom, AUCommonUIGetScreenWidth() - kDemoGlobalMargin *2, lineHeight)];
        line.backgroundColor = [UIColor colorWithRGB:0xdddddd];
        [self.view addSubview:line];
        cellTopMargin = line.bottom;
    }
    return cellTopMargin;
}


- (UIView *)createlistView:(NSString *)title topMargin:(CGFloat)topMargin
{
    AUSwitchListItem *cell = [[AUSwitchListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.accessoryType = UITableViewCellAccessorySwitch;
    cell.switchControl.on = [title isEqualToString:@"开启"];
    cell.backgroundColor = [UIColor whiteColor];
    cell.titleLabel.text = title;
    [cell setBadgeView:nil badgeNumber:@"."];
    
    cell.frame = CGRectMake(0, topMargin, AUCommonUIGetScreenWidth(), [AUSwitchListItem cellHeight]);
    return cell;
}


@end
