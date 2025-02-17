//
//  DemoBasicViewCell.m
//  AntUI
//
//  Created by 莜阳 on 2017/7/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoBasicView.h"

#define DemoBasicViewTag        100989


@implementation DemoModel

@end

@implementation DemoBasicViewItem // 固定高度 44

- (instancetype)initWithTitle:(NSString *)title
{
    self = [super init];
    self.userInteractionEnabled = YES;
    self.titleLabel.text = title;
    [self.titleLabel sizeToFit];
    return self;
}

- (UILabel *)titleLabel
{
    if (!_titleLabel)
    {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.textColor = [UIColor colorWithRGB:0x000001];
        _titleLabel.font = [UIFont systemFontOfSize:15];
        [self addSubview:_titleLabel];
    }
    return _titleLabel;
}

- (UIImageView *)acesoryView
{
    if (!_acesoryView)
    {
        _acesoryView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"APCommonUI.bundle/Tables_Arrow"]];
        [self addSubview:_acesoryView];
    }
    return _acesoryView;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    self.height = 44;
    _titleLabel.frame = CGRectMake(18, (self.height-_titleLabel.height)/2, _titleLabel.width, _titleLabel.height);
    self.acesoryView.frame = CGRectMake(self.width-15-_acesoryView.width, (self.height-_acesoryView.height)/2, _acesoryView.width, _acesoryView.height);
}

@end




@implementation DemoBasicView

- (void)setupDataModel:(DemoModel *)model
{
    _model = model;
    [self createSubViews:model];
    self.backgroundColor = [UIColor whiteColor];
    self.layer.cornerRadius = 3;
}

- (void)createSubViews:(DemoModel *)model
{
    self.leftLogoView.image = model.logoImage;
    self.titleLabel.text = model.title;
    [self.titleLabel sizeToFit];
    [self.bottomListView removeAllSubviews];
    
    CGFloat startY = 0;
    NSArray *items = [[NSArray alloc] initWithArray:[model.itemList allKeys]];
    for (int i=0; i<model.itemList.count; i++)
    {
        DemoBasicViewItem *itemView = [[DemoBasicViewItem alloc] initWithFrame:CGRectMake(0, startY, self.width, 44)];
        itemView.titleLabel.text = items[i];
        [itemView.titleLabel sizeToFit];
        itemView.tag = DemoBasicViewTag + i;
        
        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(gotoNextViewController:)];
        [itemView addGestureRecognizer:gesture];
        
        [self.bottomListView addSubview:itemView];
        if (i < model.itemList.count-1)
        {
            UIView *line = [[UIView alloc] initWithFrame:CGRectMake(17, itemView.bottom, self.width-34, 1/[UIScreen mainScreen].scale)];
            line.backgroundColor = [UIColor colorWithRGB:0xe5e5e5];
            [self.bottomListView addSubview:line];
            startY = line.bottom;
        }
        else
        {
            startY = itemView.bottom;
        }
    }
    self.bottomListView.height = 44 * model.itemList.count;
    self.bottomListView.hidden = model.sectionHeight <= DemoViewDeaultHeight;
    _hideBottomlistView = model.sectionHeight <= DemoViewDeaultHeight;

}

- (void)gotoNextViewController:(id)sender
{
    DemoBasicViewItem *view = (DemoBasicViewItem *)((UITapGestureRecognizer *)sender).view;
    NSArray *array = [_model.itemList allKeys];
    NSString *key = array[view.tag - DemoBasicViewTag];
    NSString *vc = _model.itemList[key];
    if ([self.delegate respondsToSelector:@selector(didClickBasicViewItem:vcName:)])
    {
        [self.delegate didClickBasicViewItem:view vcName:vc];
    }
}

- (CGFloat)bottomListHeight
{
    return self.bottomListView.height;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.headerView.frame = CGRectMake(0, 0, self.width, DemoViewDeaultHeight);
    self.leftLogoView.frame = CGRectMake(18, (DemoViewDeaultHeight-_leftLogoView.image.size.height)/2, _leftLogoView.image.size.width, _leftLogoView.image.size.height);
    self.titleLabel.frame = CGRectMake(18 + self.leftLogoView.right, (DemoViewDeaultHeight-_titleLabel.height)/2, MIN(_titleLabel.width, self.width-self.leftLogoView.right-18-15-_rightAccessoryView.width) ? : 200, _titleLabel.height);
    self.rightAccessoryView.frame = CGRectMake(self.width-15-_rightAccessoryView.image.size.width, (DemoViewDeaultHeight-_rightAccessoryView.height)/2, _rightAccessoryView.image.size.width, _rightAccessoryView.image.size.height);
    self.bottomListView.frame = CGRectMake(0, self.headerView.bottom, self.width, _bottomListView.height);
    self.height = _hideBottomlistView ? DemoViewDeaultHeight : DemoViewDeaultHeight + _bottomListView.height;
}

- (void)setHideBottomlistView:(BOOL)hideBottomlistView
{
    _hideBottomlistView = hideBottomlistView;
    [UIView animateWithDuration:0.4 animations:^{
        self.bottomListView.hidden = hideBottomlistView;
    }];
    
    if ([_delegate respondsToSelector:@selector(viewDidUpdateLayout:viewHeight:)])
    {
        CGFloat height = self.bottomListView.hidden ? DemoViewDeaultHeight : DemoViewDeaultHeight + [self bottomListHeight];
        [_delegate viewDidUpdateLayout:self.headerView viewHeight:height];
    }
}


- (UIImageView *)rightAccessoryView
{
    if (!_rightAccessoryView)
    {
        _rightAccessoryView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"APCommonUI.bundle/Tables_Arrow"]];
        [self.headerView addSubview:_rightAccessoryView];
    }
    _rightAccessoryView.hidden = !_hideBottomlistView;
    return _rightAccessoryView;
}

- (UIControl *)bottomListView
{
    if (!_bottomListView)
    {
        _bottomListView = [[UIControl alloc] init];
        _bottomListView.hidden = YES;
        _bottomListView.userInteractionEnabled = YES;
        [self addSubview:_bottomListView];
        _bottomListView.backgroundColor = [UIColor whiteColor];
        _hideBottomlistView = YES;
    }
    return _bottomListView;
}

- (UILabel *)titleLabel
{
    if (!_titleLabel)
    {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.textColor = [UIColor colorWithRGB:0x999999];
        _titleLabel.font = [UIFont systemFontOfSize:15];
        _titleLabel.numberOfLines = 1;
        [self.headerView addSubview:_titleLabel];
    }
    return _titleLabel;
}

- (UIImageView *)leftLogoView
{
    if (!_leftLogoView)
    {
        _leftLogoView = [[UIImageView alloc] init];
        [self.headerView addSubview:_leftLogoView];
    }
    return _leftLogoView;
}

- (UIView *)headerView
{
    if (!_headerView)
    {
        _headerView = [[UIView alloc] init];
        _headerView.backgroundColor = [UIColor whiteColor];
        [self addSubview:_headerView];
    }
    return _headerView;
}

@end

@implementation DemoBasicViewCell

- (void)setupDataModel:(DemoModel *)model
{
    self.backgroundColor = kDemoGlobalBackgroundColor;
    
    self.basicView.frame = CGRectMake(15, 0, [UIScreen mainScreen].bounds.size.width-30, model.sectionHeight > 61 ? model.sectionHeight : 61);
    [self.basicView setupDataModel:model];
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.basicView.frame = CGRectMake(15, 0, [UIScreen mainScreen].bounds.size.width-30, _basicView.height);
}

- (DemoBasicView *)basicView
{
    if (!_basicView)
    {
        _basicView = [[DemoBasicView alloc] init];
        _basicView.userInteractionEnabled = YES;
        [self.contentView addSubview:_basicView];
    }
    return _basicView;
}

@end



