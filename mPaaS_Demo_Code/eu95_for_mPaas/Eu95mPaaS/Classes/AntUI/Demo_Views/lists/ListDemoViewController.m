//
//  ListDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ListDemoViewController.h"
//#import "AULineBreakListItem.h"

@interface BLListSelectCell : AUBaseListItem

@property (nonatomic, strong) AUCheckBox *checkBox;

@end

@implementation BLListSelectCell

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}


- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    [self initUI];
    return self;
}


- (void)initUI
{
    self.checkBox = [[AUCheckBox alloc] init];
    self.checkBox.userInteractionEnabled = NO;
    [self.contentView addSubview:self.checkBox];
}


- (void)updateConstraints
{
    [super updateConstraints];
    UIView *superView = self.contentView;
    
    [self.checkBox mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(superView.mas_left).offset(20);
        make.width.and.height.equalTo(22);
        make.centerY.equalTo(superView.mas_centerY);
    }];
}

- (void)setChecked:(BOOL)checked
{
//    _checked = checked;
    self.checkBox.checked = checked;
    
}

- (void)setDisabled:(BOOL)disabled
{
//    _disabled = disabled;
    self.checkBox.disabled = disabled;
    
}
@end











@interface ListDemoViewController () <UITableViewDelegate, UITableViewDataSource, TTTAttributedLabelDelegate>

@property (nonatomic, strong)NSMutableArray *singleLists;
@property (nonatomic, strong)NSMutableArray *doubleLists;
@property (nonatomic, strong)NSMutableArray *multiLists;
@property (nonatomic, strong)NSMutableArray *linebreakLists;
@property (nonatomic,strong)AUTableView *tableview;

@end

@implementation ListDemoViewController

- (void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    self.footerView.frame = CGRectMake((self.tableview.tableFooterView.width-self.footerView.width)/2, self.tableview.tableFooterView.height-15-self.footerView.height, self.footerView.width, self.footerView.height);
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self.headerView removeFromSuperview];
    [self.footerView removeFromSuperview];
    
    UIView *header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.tableview.width, self.headerView.bottom)];
    [header addSubview:self.headerView];
    
    UIView *footer = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.tableview.width,self.tableview.height-self.footerView.top+50)];
    self.footerView.centerX = footer.centerX;
    [footer addSubview:self.footerView];
    
    self.tableview.tableHeaderView = header;
    self.tableview.tableFooterView = footer;
    
    self.tableview.separatorStyle = UITableViewCellSeparatorStyleNone;
    
    [self createSingleLists];
    [self createDoubleLists];
    [self createMultiList];
    [self createLineBreakData];
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

- (void)createSingleLists
{
    UIImage *image = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xd8d8d8] size:CGSizeMake(18, 18)];
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel1 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel1.title = @"标题文字";
    singleModel1.subtitle = @"说明信息";
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel2 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel2.title = @"标题文字";
    singleModel2.subtitle = @"说明信息";
    singleModel2.leftImage = image;//[UIImage imageNamed:@"list_singleList"];
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel3 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel3.title = @"标题文字";
    singleModel3.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel4 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel4.title = @"标题文字";
    singleModel4.subtitle = @"说明信息";
    singleModel4.accessoryType  = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel5 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel5.title = @"标题文字";
    singleModel5.subtitle = @"说明信息";
    singleModel5.leftImage = image;//[UIImage imageNamed:@"list_singleList"];
    singleModel5.accessoryType  = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel6 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel6.title = @"标题文字";
    singleModel6.subtitle = @"说明信息";
    singleModel6.rightImage = [UIImage imageNamed:@"samplePng"];
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel7 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel7.leftImage = [UIImage imageNamed:@"list_singleList"];
    singleModel7.title = @"标题文字";
    singleModel7.subtitle = @"说明信息";
    singleModel7.rightImage = [UIImage imageNamed:@"samplePng"];
    singleModel7.rightAssistImage = [UIImage imageNamed:@"ap_help"];
    singleModel7.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel8 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel8.title = @"用户名";
    singleModel8.leftImage = [UIImage imageNamed:@"list_user"];
    singleModel8.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel9 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel9.title = @"邀请有礼";
    singleModel9.rightAssistImage = [UIImage imageNamed:@"ap_help"];
    //singleModel9.rightImage = [UIImage imageNamed:@"samplePng"];
    singleModel9.subtitle = @"恭喜获得抽奖机会";
    //singleModel9.badge
    singleModel9.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AUSingleTitleListItemModelDelegate> *singleModel10 = [[AUListItemModel<AUSingleTitleListItemModelDelegate> alloc] init];
    singleModel10.title = @"右侧气泡文案";
    //singleModel9.badge
    singleModel10.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    _singleLists = [[NSMutableArray alloc] initWithArray:@[singleModel1,singleModel2,singleModel3,singleModel4,singleModel5,singleModel6,singleModel7,singleModel8,singleModel10,singleModel9]];
}

- (void)createDoubleLists
{
    UIImage *image = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xd8d8d8] size:CGSizeMake(18, 18)];
    
    // 高度 120
    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel1 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
//    doubleModel1.title = @"双行列表";
    doubleModel1.subtitle = @"描述信息";
    doubleModel1.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
   
    //    doubleModel1.subtitleLines = 1;

    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel2 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
    doubleModel2.title = @"标题文字";
    //    doubleModel4.subtitle = @"描述信息";
//    doubleModel2.leftImage = [UIImage imageNamed:@"list_default_big"];
    doubleModel2.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    //    doubleModel4.subtitleLines = 1;

    // 高度 136
    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel3 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
//    doubleModel3.title = @"双行列表";
    doubleModel3.leftImage = image; //[UIImage imageNamed:@"list_default_big"];
    doubleModel3.subtitle = @"描述信息";
    doubleModel3.accessoryType = UITableViewCellAccessoryDisclosureIndicator;

    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel4 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
//    doubleModel4.title = @"用户名";
    doubleModel4.subtitle = @"摘要信息";
    doubleModel4.timeString = @"12:21";
    doubleModel4.leftImage = [UIImage imageNamed:@"list_user_big"];
    //    doubleModel2.subtitleLines = 1;

    // 高度 176
    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel5 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
    doubleModel5.title = @"用户名";
    doubleModel5.subtitle = @"摘要信息";
    doubleModel5.leftImage = image; //[UIImage imageNamed:@"list_user_big"];
    //    doubleModel3.subtitleLines = 1;
    doubleModel5.accessoryType = UITableViewCellAccessoryDisclosureIndicator;

    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel6 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
    doubleModel6.title = @"双行列表";
    doubleModel6.subtitleLines = 3;
    doubleModel6.subtitle = @"描述信息";
    doubleModel6.leftImage = image; //[UIImage imageNamed:@"list_default_big"];
    doubleModel6.rightAssistString = @"辅助信息";
    doubleModel6.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    // 高度 120
    AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *doubleModel7 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> alloc] init];

    doubleModel7.title = @"双行列表";
    doubleModel7.attributeText = @"指纹仅对本机有效，开通即视为同意《指纹相关协议》，巴拉巴拉巴拉巴拉巴拉啦巴拉巴拉搜索发~";
    doubleModel7.linkText = @"《指纹相关协议》";
    doubleModel7.linkURL = @"https://yuque.antfin-inc.com/antui/auidoc/ios_aulistitem";
    doubleModel7.subtitleLines = 5;
    doubleModel7.leftImage = image; // [UIImage imageNamed:@"list_default_big"];
//    doubleModel7.rightAssistString = @"辅助信息";

    doubleModel7.accessoryType = UITableViewCellAccessorySwitch;
    
    AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *doubleModel8 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> alloc] init];
    
    doubleModel8.title = @"双行列表";
    doubleModel8.attributeText = @"指纹仅对本机有效，开通即视为同意《指纹相关协议》，巴拉巴拉巴拉巴拉巴拉啦巴拉巴拉搜索发~";
    doubleModel8.linkText = @"巴拉巴拉巴拉巴拉巴拉啦巴拉巴";
    doubleModel8.linkURL = @"https://yuque.antfin-inc.com/antui/auidoc/ios_aulistitem";
    doubleModel8.subtitleLines = 3;
    doubleModel8.leftImage = image; //[UIImage imageNamed:@"list_default_big"];
    //    doubleModel7.rightAssistString = @"辅助信息";
    
    doubleModel8.accessoryType = UITableViewCellAccessoryActivityIndicatorGray;
    
    AUListItemModel<AUDoubleTitleListItemModelDelegate> *doubleModel9 = [[AUListItemModel<AUDoubleTitleListItemModelDelegate> alloc] init];
    
    doubleModel9.title = @"双行列表";
    doubleModel9.subtitle = @"指纹仅对本机有效，开通即视为同意《指纹相关协议》，巴拉巴拉巴拉巴拉巴拉啦巴拉巴拉搜索发~";
    doubleModel9.subtitleLines = 2;
    doubleModel9.leftImage = image; //[UIImage imageNamed:@"list_default_big"];
    doubleModel9.rightAssistString = @"辅助信息";
    
    doubleModel9.accessoryType = AUListItemAccessoryDisclosureIndicator;
    
    _doubleLists = [[NSMutableArray alloc] initWithArray:@[doubleModel1,doubleModel2,doubleModel3,doubleModel4,doubleModel5,doubleModel6, doubleModel7, doubleModel8, doubleModel9]];
}

- (void)createMultiList
{
    AUListItemModel<AUMultiListItemDelagate> *doubleModel2 = [[AUListItemModel<AUMultiListItemDelagate> alloc] init];
    doubleModel2.title = @"标题";
    doubleModel2.subtitle = @"“全球未来机场计划”是指未来游客在海外机场，通过支付宝使用航班提醒等服务。";
    
    AUListItemModel<AUMultiListItemDelagate> *doubleModel1 = [[AUListItemModel<AUMultiListItemDelagate> alloc] init];
    doubleModel1.title = @"标题";
    doubleModel1.subtitle = @"“全球未来机场计划”是指未来游客在海外机场，通过支付宝使用航班提醒等服务。";
    doubleModel1.leftImage = [UIImage imageNamed:@"list_default_big"];
    
    AUMultiListItemModel *model3 = [[AUMultiListItemModel alloc] init];
    model3.leftImage = [UIImage imageNamed:@"certify"];
    model3.title = @"标题";
    model3.subtitle = @"4“全球未来机场计划”是指未来游客在海外机场，通过支付宝使用航班提醒等服务。";//
    model3.othersDesc = @"其他描述信息";
    model3.timeDesc = @"时间";
    model3.originalText = @"文字来源";
    
    _multiLists = [[NSMutableArray alloc] initWithArray:@[doubleModel2,doubleModel1, model3]];
}

- (void)createLineBreakData
{
    AUListItemModel<AULineBreakListItemModelDelegate> *model1 = [[AUListItemModel<AULineBreakListItemModelDelegate> alloc] init];
    model1.title = @"单行列表";
    model1.subtitle = @"详细信息";
    model1.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AULineBreakListItemModelDelegate> *model2 = [[AUListItemModel<AULineBreakListItemModelDelegate> alloc] init];
    model2.title = @"双行列表";
    model2.subtitle = @"详细信息";
    
    AUListItemModel<AULineBreakListItemModelDelegate> *model3 = [[AUListItemModel<AULineBreakListItemModelDelegate> alloc] init];
    model3.title = @"双行列表";
    model3.subtitle = @"详细信息文字很多很多很多很多很多很多很多很多很多";
    model3.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    AUListItemModel<AULineBreakListItemModelDelegate> *model4 = [[AUListItemModel<AULineBreakListItemModelDelegate> alloc] init];
    model4.title = @"双行列表，主文案内容很多很多很多很多很多很多很多很多很多很多很多很多很多";
    model4.subtitle = @"详细信息文字很多很多很多很多很多很多很多很多很多";
    model4.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    _linebreakLists = [[NSMutableArray alloc] initWithArray:@[model1, model2, model3, model4]];
}

#pragma mark - UITableViewDataSource

//
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    switch (section) {
        case 0:
            return _singleLists.count;
        case 1:
            return _doubleLists.count;
        case 2:
            return _multiLists.count;
        case 3:
            return _linebreakLists.count;
        case 4:
        case 5:
            return 5;
        default:
            return 0;
    }
}

//
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 6;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    if (indexPath.section >= 4) {
        BLListSelectCell *cell = (BLListSelectCell *) [tableView cellForRowAtIndexPath:indexPath];
        cell.checkBox.checked = !cell.checkBox.checked;
    }
}

//
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section  == 0) // 单行
    {
        AUListItemModel<AUSingleTitleListItemModelDelegate> *modelCell = _singleLists[indexPath.row];
        AUSingleTitleListItem *cell;
        if (indexPath.row == _singleLists.count-1) {
            cell = [tableView dequeueReusableCellWithIdentifier:@"AUSingleTitleListItemStyleValue1"];
            if (!cell) {
                cell = [[AUSingleTitleListItem alloc] initWithReuseIdentifier:@"AUSingleTitleListItemStyleValue1" customStyle:AUSingleTitleListItemStyleValue1];
            }
            
            //[cell setBadgeView:nil badgeNumber:@"测试测试红"];
            [cell setBadgeValue:@"."];

        }
        else if(indexPath.row == _singleLists.count-2) {
            cell = [tableView dequeueReusableCellWithIdentifier:@"AUSingleTitleListItemStyleValue1"];
            if (!cell) {
                cell = [[AUSingleTitleListItem alloc] initWithReuseIdentifier:@"AUSingleTitleListItemStyleValue1" customStyle:AUSingleTitleListItemStyleValue1];
            }
            
            //[cell setBadgeView:nil badgeNumber:@"测试测试红"];
            [cell setBadgeValue:@"测试测试红点红点"];
        }
        else {
            cell = [tableView dequeueReusableCellWithIdentifier:@"AUSingleTitleListItemStyleDefault"];
            if (!cell) {
                cell = [[AUSingleTitleListItem alloc] initWithReuseIdentifier:@"AUSingleTitleListItemStyleDefault" customStyle:AUSingleTitleListItemStyleDefault];
            }
        }
        
        [cell setModelBlock:^(AUListItemModel<AUSingleTitleListItemModelDelegate> *model) {
            model.title = modelCell.title;
            model.subtitle = modelCell.subtitle;
            model.leftImage = modelCell.leftImage;
            model.rightImage = modelCell.rightImage;
            model.rightAssistImage = modelCell.rightAssistImage;
            model.leftimageSize = modelCell.leftimageSize;
            model.accessoryType = modelCell.accessoryType;
        }];
        
        
        if (indexPath.row == 0 && indexPath.section == 0) {
            self.tableview.separatorColor = [UIColor clearColor];
            [cell setLayoutMargins:UIEdgeInsetsZero];
            [cell setSeparatorInset:UIEdgeInsetsZero];
        } else {
            self.tableview.separatorColor = [UIColor redColor];
        }
        
        [cell setupSeparatorAtIndexPath:indexPath tableView:_tableview];
        
        if (indexPath.row == 2) {
            cell.accessoryType = AUListItemAccessoryTypeNone;
            [cell setupActionButton:@"按钮" actionBlock:^{
                AUToastShow(self.view, AUToastIconNone, @"点击了button", @"Demo");
            }];
            NSLog(@"");
        }
        
        return cell;
    }
    else if (indexPath.section == 1)// 双行
    {
        NSInteger index = indexPath.row; //  - _singleLists.count;
        NSString *identify;
        AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *modelCell = _doubleLists[index];
        AUDoubleTitleListItem *cell ;
        AUDoubleTitleListItemStyle style = AUDoubleTitleListItemStyleDefault;
        switch (index) {
            case 0:
            case 1:
                identify = @"AUDoubleTitleListItemStyleValue1";
                style = AUDoubleTitleListItemStyleValue1;
                break;
            case 2:
            case 3:
                identify = @"AUDoubleTitleListItemStyleDefault";
                style = AUDoubleTitleListItemStyleDefault;
                break;
            case 4:
            case 5:
//            case 6:
                identify = @"AUDoubleTitleListItemStyleValue2";
                style = AUDoubleTitleListItemStyleValue2;
                break;
            default:
                identify = @"AUDoubleTitleListItemStyleDefault";
                style = AUDoubleTitleListItemStyleDefault;
                break;
        }
        cell =  [tableView dequeueReusableCellWithIdentifier:identify];
        if (!cell)
        {
            cell = [[AUDoubleTitleListItem alloc] initWithReuseIdentifier:identify customStyle:style];
        }
        
        [cell setModelBlock:^(AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *model) {
            model.title = modelCell.title;
            model.subtitle = modelCell.subtitle;
            model.subtitleLines = modelCell.subtitleLines;
            if (indexPath.row == 2) {
//                model.leftImage = [UIImage imageWithColor:RGB_A(0x108ee8, 0.5) size:CGSizeMake(30, 30)];
                AUImageRequestModel *model1 = [[AUImageRequestModel alloc] init];
                model1.key = @"https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png";
                model1.business = @"AntUIDemo";
                model1.placeholder = [UIImage imageWithColor_au:RGB_A(0x108ee8, 0.2) size:CGSizeMake(30, 30)];
                model1.zoom = CGSizeMake(-1, -1);
                model1.originalSize = CGSizeMake(-1, -1);
                model.leftImgRequest = model1;
            } else {
                model.leftImage = modelCell.leftImage;
            }
            
            model.leftimageSize = modelCell.leftimageSize;
            model.timeString = modelCell.timeString;
            if (indexPath.row != 2) {
                model.accessoryType = modelCell.accessoryType;
            } else {
                model.rightImage = [UIImage imageWithColor_au:RGB_A(0xd8d8d8, 0.8) size:CGSizeMake(30, 30)];
            }
            
            model.rightAssistString = modelCell.rightAssistString;
            model.attributeText = modelCell.attributeText;
            model.linkText = modelCell.linkText;
            model.linkURL = modelCell.linkURL;
            
        }];
        
        if (indexPath.row == 4) {
            cell.accessoryType = AUListItemAccessoryTypeNone;
            [cell setupActionButton:@"按钮" btnStyle:^(UIButton *btn) {
                [btn setBackgroundImage:[UIImage imageWithColor1x1_au:[UIColor blackColor]] forState:UIControlStateNormal];
                [btn setBackgroundImage:[UIImage imageWithColor1x1_au:[UIColor redColor]] forState:UIControlStateHighlighted];
                btn.layer.borderColor = [UIColor greenColor].CGColor;
            } actionBlock:^{
                AUToastShow(self.view, AUToastIconNone, @"点击了button", @"Demo");
            }];
            NSLog(@"");
        }
        
        if (indexPath.row == 3) {
            cell.leftAccessorType = AUListItemLeftAccessorTypeLabel;
            UILabel *label = [[UILabel alloc] init];
            label.text = @"左扩展区11";
            [label sizeToFit];
            cell.leftAccessorView = label;
            cell.leftImageView.auviewActionBlock = ^{
                AUToastShow(self.tableview, AUToastIconNone, @"点击了我", nil);
            };
            
//            cell.rightAccessorType = AUListItemRightAccessorTypeIcon;
//            cell.rightAccessorView = [[UIImageView alloc] initWithImage:[UIImage imageWithColor:RGB_A(0xd8d8d8, 0.8) size:CGSizeMake(30, 30)]];
        } else if (indexPath.row == 4) {
//            cell.leftAccessorType = AUListItemLeftAccessorTypeIcon;
//            cell.leftAccessorView = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];//[[UIImageView alloc] initWithImage:[UIImage imageWithColor:[UIColor colorWithRGB:0x108ee9] size:CGSizeMake(30, 39)]];
        } else if (indexPath.row == 2) {
            [cell.leftImageView setImage:[UIImage imageWithColor_au:RGB_A(0x108ee8, 0.2) size:CGSizeMake(30, 30)]];
        }
        
        [cell setupSeparatorAtIndexPath:indexPath tableView:_tableview];
        
        if (indexPath.row == 0) {
            cell.topLine.hidden = YES;
        }
        return cell;
    }
    else if (indexPath.section == 2)
    {
        NSInteger index = indexPath.row; //section - (_singleLists.count+_doubleLists.count);
        AUMultiListItemModel *model1 = _multiLists[index];
        AUMultiListItem *cell = [tableView dequeueReusableCellWithIdentifier:@"AUMultiListItem"];
        if (!cell)
        {
            cell = [[AUMultiListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AUMultiListItem"];
        }
        [cell setDataModel:^(AUMultiListItemModel *model) {
            model.originalText = model1.originalText;
            model.timeDesc = model1.timeDesc;
            model.othersDesc = model1.othersDesc;
            model.leftImage = model1.leftImage;
            model.title = model1.title;
            model.subtitle = model1.subtitle;
//            model.leftimageSize = model1.leftimageSize;
        }];
        
        return cell;
    }
    else if (indexPath.section == 3) {
//        AUListItemModel<AULineBreakListItemModelDelegate> *modelCell = _linebreakLists[indexPath.row];
//        AULineBreakListItem *cell = [tableView dequeueReusableCellWithIdentifier:@"AULineBreakListItemModelDelegate"];
//        
//        if (!cell) {
//            cell = [[AULineBreakListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AULineBreakListItemModelDelegate"];
//        }
//        
//        [cell setModelBlock:^(AUListItemModel<AUParallelTitleListItemModelDelegate> *model) {
//            model.title = modelCell.title;
//            model.subtitle = modelCell.subtitle;
//            model.accessoryType = modelCell.accessoryType;
//        }];
//        
//        return cell;
    } else if (indexPath.section == 4) {
        static NSString * kCellIdentifier = @"BLListSelectCell";
        BLListSelectCell *cell = [tableView dequeueReusableCellWithIdentifier:kCellIdentifier];
        if (!cell) {
            cell = [[BLListSelectCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:kCellIdentifier];
        }
        
        return cell;
    } else if (indexPath.section == 5) {
        AUCheckBoxListItem *cell = [tableView dequeueReusableCellWithIdentifier:@"AUCheckBoxListItem"];
        if (!cell) {
            cell = [[AUCheckBoxListItem alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AUCheckBoxListItem"];
        }
        cell.title = @"test";
        return cell;
    }
    
    return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"UITableViewCellStyleDefault"];
}

#pragma -mark -  UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 0)
    {
        if (indexPath.row == _singleLists.count-1)
        {
            return [AUSingleTitleListItem cellHeightForStyle:AUSingleTitleListItemStyleValue1];
        }
        else
        {
            return [AUSingleTitleListItem cellHeightForStyle:AUSingleTitleListItemStyleDefault];
        }
    }
    else if (indexPath.section == 1)
    {
        NSInteger index = indexPath.row; //.section - _singleLists.count;
        AUDoubleTitleListItemStyle style = AUDoubleTitleListItemStyleDefault;
        switch (index) {
            case 0:
            case 1:
                style = AUDoubleTitleListItemStyleValue1;
                break;
            case 2:
            case 3:
                style = AUDoubleTitleListItemStyleDefault;
                break;
            case 4:
            case 5:
                style = AUDoubleTitleListItemStyleValue2;
                break;
            case 6:
            case 7:
            case 8:
            {
                style = AUDoubleTitleListItemStyleDefault;
                AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *modelCell = _doubleLists[index];
                return [AUDoubleTitleListItem cellHeightForStyle:AUDoubleTitleListItemStyleDefault modelBlock:^(AUListItemModel<AUDoubleTitleListItemModelDelegate,TTTAttributeLabelDelagate> *model) {

                    model.title = modelCell.title;
                    model.subtitle = modelCell.subtitle;
                    model.subtitleLines = modelCell.subtitleLines;
                    model.leftImage = modelCell.leftImage;
                    model.leftimageSize = modelCell.leftimageSize;
                    model.timeString = modelCell.timeString;
                    model.accessoryType = modelCell.accessoryType;
                    model.rightAssistString = modelCell.rightAssistString;
                    model.attributeText = modelCell.attributeText;
                    model.linkText = modelCell.linkText;
                    model.linkURL = modelCell.linkURL;
                }];
            }
                break;
            default:
                style = AUDoubleTitleListItemStyleDefault;
                break;
        }
        return [AUDoubleTitleListItem cellHeightForStyle:style];
    }
    else if (indexPath.section == 2)
    {
        NSInteger index = indexPath.row; //section - (_singleLists.count+_doubleLists.count);
        AUMultiListItemModel *model1 = _multiLists[index];
//        return [AUMultiListItem cellHeightForModel:model1 withWidth:self.tableview.width];
        return [AUMultiListItem cellHeightForModel:^(AUMultiListItemModel *model) {
            model.originalText = model1.originalText;
            model.timeDesc = model1.timeDesc;
            model.othersDesc = model1.othersDesc;
            model.leftImage = model1.leftImage;
            model.title = model1.title;
            model.subtitle = model1.subtitle;
        }];
    }
    else if (indexPath.section == 3) {
//        return [AULineBreakListItem cellHeightForModel:_linebreakLists[indexPath.row]];
    }
    return 44;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return [AUAssitLableView viewHeightForType:AUAssitLableViewTypeHeader text:@"带说明的列表项点击可查看" totalWidth:self.view.width];
    }
    return [AUAssitLableView viewHeight];
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    if (section == 0)
    {
        return 0;
        AUAssitLableView *tttView = [[AUAssitLableView alloc] initWithViewType:AUAssitLableViewTypeHeader tttText:@"带说明的列表项点击可查看" linkText:@"点击查看"];
        tttView.tttLabel.delegate = self;
        [tttView.tttLabel addLinkToURL:[NSURL URLWithString:@"https://csmobile.alipay.com/detailSolution.htm?knowledgeType=1&scene=app_questionId_stats&questionId=478305"] withRange:[tttView.tttLabel.text rangeOfString:@"点击查看"]];
        return tttView;
    }
    NSString *string = @"带说明的列表项";
    AUAssitLableView *view = [[AUAssitLableView alloc] initWithViewType:AUAssitLableViewTypeHeader describeText:string];
    return view;
}

#pragma mark -- TTTAttributedLabelDelegate
- (void)attributedLabel:(TTTAttributedLabel *)label
   didSelectLinkWithURL:(NSURL *)url
{
    [AUToast presentToastWithin:self.tableview withIcon:AUToastIconNone text:label.text duration:2.0 logTag:@"AntUIDemo"];
}

@end
