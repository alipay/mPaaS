//
//  CheckboxDemoViewCotroller.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "CheckboxDemoViewCotroller.h"

@implementation CheckboxDemoViewCotroller

- (void)viewDidLoad
{
    self.view = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [super viewDidLoad];
    
    CGFloat topMargin = self.headerView.bottom;
    
    UILabel *labelView = [self createDefaultLabel:@"默认样式"];
    labelView.frame = CGRectMake(kDemoGlobalMargin, topMargin, labelView.width, [AUAssitLableView viewHeight]);
    [self.view addSubview:labelView];
    topMargin = labelView.bottom;
    
    CGFloat rightMargin = 0;
    
    {
        AUCheckBox *checkbox = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];
        checkbox.origin_mp = CGPointMake(kDemoGlobalMargin, topMargin);
        checkbox.checked = YES;
        [self.view addSubview:checkbox];
        
        UILabel *label = [self createDefaultLabel:@"选中"];
        label.frame = CGRectMake(checkbox.right + 4, checkbox.centerY-label.height/2, label.width, label.height);
        [self.view addSubview:label];
        
        rightMargin = label.right + 22;
    }
    
    {
        AUCheckBox *checkbox = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];
        checkbox.checked = NO;
        checkbox.origin_mp = CGPointMake(rightMargin, topMargin);
        [self.view addSubview:checkbox];
        
        UILabel *label = [self createDefaultLabel:@"未选中"];
        label.frame = CGRectMake(checkbox.right + 4, checkbox.centerY-label.height/2, label.width, label.height);
        [self.view addSubview:label];
        
        rightMargin = label.right + 22;
    }
    
    {
        AUCheckBox *checkbox = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];
        checkbox.disabled = YES;
        checkbox.origin_mp = CGPointMake(rightMargin, topMargin);
        [self.view addSubview:checkbox];
        
        UILabel *label = [self createDefaultLabel:@"不可勾选"];
        label.frame = CGRectMake(checkbox.right + 4, checkbox.centerY-label.height/2, label.width, label.height);
        [self.view addSubview:label];
        
        rightMargin = label.right + 22;
        topMargin = label.bottom + 20;
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
    
    topMargin = [self createBottomViews:topMargin];
    
    topMargin += 14;
    
    AUButton *button = [AUButton buttonWithStyle:AUButtonStyle1 title:@"主操作" target:self action:nil];
    button.frame = CGRectMake(kDemoGlobalMargin, topMargin, self.view.width-kDemoGlobalMargin*2, button.height);
    [self.view addSubview:button];
    
    topMargin = button.bottom + 30;
    
    CGPoint point = self.footerView.origin_mp;
    point.y = topMargin;
    self.footerView.origin_mp = point;
    
    topMargin = self.footerView.bottom + 15;
    
    
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
    AUCheckBoxListItem *cell = [[AUCheckBoxListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.checked = [title isEqualToString:@"中国"];
    cell.backgroundColor = [UIColor whiteColor];
    cell.titleLabel.text = title;
    
    cell.frame = CGRectMake(0, topMargin, AUCommonUIGetScreenWidth(), [AUCheckBoxListItem cellHeight]);
    return cell;
}

- (CGFloat)createBottomViews:(CGFloat)topMargin
{
    CGFloat newTopMargin = topMargin;
    
    AUCheckBox *checkbox = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];
    checkbox.checked = YES;
    checkbox.origin_mp = CGPointMake(kDemoGlobalMargin, newTopMargin);
    [self.view addSubview:checkbox];
    
    UILabel *label1 = [self createDefaultLabel:@"我已阅读并同意"];
    label1.font = [UIFont systemFontOfSize:15];
    [label1 sizeToFit];
    label1.frame = CGRectMake(checkbox.right + 9, topMargin, label1.width, label1.height);
    [self.view addSubview:label1];
    
    UILabel *label2 = [self createDefaultLabel:@"《服务协议》"];
    label2.font = [UIFont systemFontOfSize:15];
    label2.textColor = AU_COLOR9;
    [label2 sizeToFit];
    label2.frame = CGRectMake(label1.right + 7, topMargin, label2.width, label2.height);
    [self.view addSubview:label2];
    
    label2.centerY = checkbox.centerY;
    label1.centerY = checkbox.centerY;
    
    newTopMargin = checkbox.bottom;
    return newTopMargin;
}

@end
