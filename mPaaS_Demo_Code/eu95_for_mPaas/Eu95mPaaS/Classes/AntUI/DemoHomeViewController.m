//
//  DemoHomeViewController.m
//  AntUIDemo
//
//  Created by 莜阳 on 2017/9/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoHomeViewController.h"

@implementation DemoHomeViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.view.backgroundColor = kDemoGlobalBackgroundColor;
    
    self.tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.width, self.view.height-60) style:UITableViewStyleGrouped];
    self.tableView.backgroundColor = [UIColor clearColor];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.tableView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:self.tableView];
    
    self.headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.width, 223)];
    self.headerView.backgroundColor = kDemoGlobalBackgroundColor;
    
    // 开始页面布局
    UIImageView *logoView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"home_tab_icon"]];
    logoView.frame = CGRectMake(self.view.width/2-53/2, 45, 53, 53);
    [self.headerView addSubview:logoView];
    
    UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(self.view.width/2-90, CGRectGetMaxY(logoView.frame)+23, 190, 42)];
    descLabel.text = @"设计、前端高效协同，快速搭建移动端组件库";
    descLabel.numberOfLines = 2;
    descLabel.textAlignment = NSTextAlignmentCenter;
    descLabel.lineBreakMode = NSLineBreakByTruncatingTail;
    descLabel.font = [UIFont systemFontOfSize:14];
    descLabel.textColor = [UIColor colorWithRGB:0x999999];
    [self.headerView addSubview:descLabel];
    
    self.headerView.height = descLabel.bottom + 24;
    
    self.tableView.tableHeaderView = self.headerView;
    
    self.dataArray = [[NSMutableArray alloc] init];
    self.tableView.contentSize = CGSizeMake(self.view.width, 2*(self.dataArray.count * DemoViewDeaultHeight + (self.dataArray.count)*15));
}

#pragma mark - 点击处理

//
- (void)changeSelectedState:(id)sender
{
    UITapGestureRecognizer *gesture = (UITapGestureRecognizer *) sender;
    if ([gesture.view.superview isKindOfClass:[DemoBasicView class]])
    {
        DemoBasicView *view = (DemoBasicView *)gesture.view.superview;
        view.hideBottomlistView = !view.bottomListView.hidden;
        //        DemoModel *obj1 = _dataArray[view.tag];
        //        obj1.sectionHeight = view.selected ? DemoViewDeaultHeight + [view bottomListHeight] : DemoViewDeaultHeight;
        //        [self.tableView reloadData];
    }
}

- (void)didClickBasicViewItem:(DemoBasicViewItem *)item vcName:(NSString *)vcName
{
    if (vcName.length)
    {
        UIViewController *vc = [NSClassFromString(vcName) new];
        vc.title = item.titleLabel.text;
        [self.navigationController pushViewController:vc animated:YES];
    }
    else
    {
        [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"开发中，敬请期待" duration:2.0 logTag:@"AntUI"];
    }
}

#pragma mark - viwe 高度更新处理

- (void)viewDidUpdateLayout:(UIView *)view viewHeight:(CGFloat)viewHeight
{
    DemoModel *obj1 = _dataArray[view.tag];
    obj1.sectionHeight = viewHeight;
    [self.tableView reloadData];
    NSLog(@"** [%@] **, height = %ld", obj1.title, (long)obj1.sectionHeight);
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 15;
}


- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 0.0001;
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *cellIdentify = [NSString stringWithFormat:@"DemoBasicView_%ld_%ld", (long)indexPath.section, (long)indexPath.row];
    DemoBasicViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentify];
    if (!cell) {
        cell = [[DemoBasicViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"DemoBasicView"];
    }
    [cell setupDataModel:_dataArray[indexPath.section]];
    cell.basicView.headerView.tag = indexPath.section;
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(changeSelectedState:)];
    [cell.basicView.headerView addGestureRecognizer:gesture];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.basicView.delegate = self;
    
    return cell;
}


- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    DemoModel *obj1 = _dataArray[indexPath.section];
    NSLog(@"--[%@]--, height = %ld", obj1.title, (long)obj1.sectionHeight);
    return obj1.sectionHeight;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    for (UIView *view in cell.contentView.subviews) {
        if ([view isKindOfClass:[DemoBasicView class]]) {
            DemoBasicView *demoView = (DemoBasicView *)view;
            demoView.hideBottomlistView = !demoView.bottomListView.hidden;
            DemoModel *obj1 = _dataArray[indexPath.section];
            obj1.sectionHeight = demoView.isSelected ? DemoViewDeaultHeight + [demoView bottomListHeight]: DemoViewDeaultHeight;
            break;
        }
    }
    
    [self.tableView reloadData];
}

#pragma mark - 数据初始化

- (void)setup_category_content:(NSString *)categoryName
                    subItemDic:(NSDictionary *)subItemDic
                      logoPath:(NSString *)logoPath
{
    int index = -1;
    for (int i=0; i<self.dataArray.count; i++)
    {
        DemoModel *obj6 = self.dataArray[i];
        if ([obj6.title isEqualToString:categoryName]) // 找到所属类目
        {
            [obj6.itemList addEntriesFromDictionary:subItemDic];
            index = i;
            break;
        }
    }
    if (index >= self.dataArray.count) // 说明找不到，则新建一个类目在末尾
    {
        DemoModel *obj6 = [[DemoModel alloc] init];
        obj6.title = categoryName;
        obj6.logoImage = [UIImage imageNamed:logoPath];
        obj6.itemList = [[NSMutableDictionary alloc] initWithDictionary:subItemDic];
        obj6.sectionHeight = DemoViewDeaultHeight;
        [self.dataArray addObject:obj6];
    }
}

@end
