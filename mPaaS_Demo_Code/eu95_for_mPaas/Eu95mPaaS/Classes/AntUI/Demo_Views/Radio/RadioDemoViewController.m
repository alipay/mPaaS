//
//  RadioDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "RadioDemoViewController.h"

@implementation RadioDemoViewController

- (void)viewDidLoad
{
    self.view = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [super viewDidLoad];
    
    CGFloat topMargin = self.headerView.bottom;
    
    UILabel *labelView = [self createDefaultLabel:@"默认样式"];
    labelView.frame = CGRectMake(kDemoGlobalMargin, topMargin, labelView.width, [AUAssitLableView viewHeight]);
    [self.view addSubview:labelView];
    topMargin = labelView.bottom + 8;
    
    CGFloat rightMargin = 0;
    
    {
        AUCheckBox *checkbox = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleCheckmark];
        checkbox.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        checkbox.checked = YES;
        [self.view addSubview:checkbox];
        
        UILabel *label = [self createDefaultLabel:@"选中"];
        label.frame = CGRectMake(checkbox.right + 4, checkbox.centerY-label.height/2, label.width, label.height);
        [self.view addSubview:label];
        
        rightMargin = label.right + 22;
        topMargin = checkbox.bottom + 15;
    }
    
    {
        UILabel *label = [self createDefaultLabel:@"复选列表项目"];
        label.frame = CGRectMake(kDemoGlobalMargin, topMargin, label.width, label.height);
        [self.view addSubview:label];
        topMargin = label.bottom + 8;
    }
    
    NSArray *array = @[@"中国", @"美国", @"巴西", @"俄罗斯", @"英国", @"发过"];
    topMargin = [self createCheckboxList:array topMargin:topMargin];
    topMargin += 30;
    
    
    CGPoint point = self.footerView.origin_mp;
    point.y = topMargin;
    self.footerView.origin_mp = point;
    
    topMargin = self.footerView.bottom + 60;
    
    
    [(UIScrollView *)self.view setContentSize:CGSizeMake(self.view.width, topMargin)];
}

- (UILabel *)createDefaultLabel:(NSString *)title
{
    UILabel *label = [[UILabel alloc] init];
    label.text = title;
    label.textColor = [UIColor colorWithRGB:0x999999];
    label.font = [UIFont systemFontOfSize:12];
    [label sizeToFit];
    return label;
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
    AUSingleTitleListItem *cell = [[AUSingleTitleListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.accessoryType = [title isEqualToString:@"中国"] ? UITableViewCellAccessoryCheckmark : UITableViewCellAccessoryNone;
    cell.backgroundColor = [UIColor whiteColor];
    cell.titleLabel.text = title;
    
    cell.frame = CGRectMake(0, topMargin, AUCommonUIGetScreenWidth(), [AUCheckBoxListItem cellHeight]);
    return cell;
}

@end
