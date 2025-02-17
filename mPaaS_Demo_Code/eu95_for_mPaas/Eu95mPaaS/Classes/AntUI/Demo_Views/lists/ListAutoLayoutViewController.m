//
//  ListAutoLayoutViewController.m
//  AntUIDemo
//
//  Created by Wang on 2018/8/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ListAutoLayoutViewController.h"

@interface ListAutoLayoutViewController ()

@property (nonatomic,strong)AUTableView *tableview;


@end


@interface ListAutoCell : UITableViewCell
{
    UILabel *_label;
}
@end

@implementation ListAutoLayoutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    self.tableview.frame = self.view.bounds;
}

- (AUTableView *)tableview
{
    if (!_tableview)
    {
        _tableview = [[AUTableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
        _tableview.backgroundColor = self.view.backgroundColor;
        _tableview.delegate = self;
        _tableview.dataSource = self;
        _tableview.separatorStyle = UITableViewCellSeparatorStyleSingleLineEtched;
        [self.view addSubview:_tableview];
    }
    return _tableview;
}
#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
{
    return 44;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [[ListAutoCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:@"ABC"];
    
    return cell;
}


@end

@implementation ListAutoCell

-(id) initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    _label = [[UILabel alloc]init];
    _label.text = @"测试";
    [self.contentView addSubview:_label];
    
    AUBadgeView *bageView = [[AUBadgeView alloc] init];
    [bageView drawBadgeWithStyle:AUBadgeViewStyleText attributes:@{kAUBadgeViewAttributeKeyText:@"推荐"}];
    [self.contentView addSubview:bageView];
    CGSize size = bageView.size_mp;
    [bageView mas_makeConstraints:^(MASConstraintMaker *make) {
        //            make.left.equalTo(label).with.offset(label.width + 5);
        make.center.equalTo(_label);
        make.size.equalTo(@(size));
    }];
    return self;
}

-(void) layoutSubviews
{
    [super layoutSubviews];
    _label.centerY = CGRectGetMinY(self.bounds);
}
@end


