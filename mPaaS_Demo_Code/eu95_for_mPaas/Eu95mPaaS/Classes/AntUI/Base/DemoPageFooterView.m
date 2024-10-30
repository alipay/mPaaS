//
//  DemoPageFooterView.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoPageFooterView.h"

@implementation DemoPageFooterView

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        [self setupSubView];
    }
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        [self setupSubView];
    }
    return self;
}

- (void)setupSubView
{
    [self.titleLabel sizeToFit];
    [self.subtitleLabel sizeToFit];
    self.height = MAX(self.iconView.image.size.height+2+2, self.titleLabel.height+self.subtitleLabel.height);
    self.width = self.iconView.image.size.width + 6 + MAX(self.titleLabel.width, self.subtitleLabel.width);
    self.iconView.origin_mp = CGPointMake(0, (self.height-self.iconView.image.size.height)/2);
    self.titleLabel.origin_mp = CGPointMake(6+self.iconView.right, 0);
    self.subtitleLabel.origin_mp = CGPointMake(self.titleLabel.left, self.titleLabel.bottom);
}

- (UIImageView *)iconView
{
    if (!_iconView)
    {
        _iconView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"footer_icon"]];
        _iconView.size_mp = CGSizeMake(15, 15);
        [self addSubview:_iconView];
    }
    return _iconView;
}

- (UILabel *)titleLabel
{
    if (!_titleLabel)
    {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.font = [UIFont systemFontOfSize:7];
        _titleLabel.textColor = [UIColor colorWithRGB:0x333333];
        _titleLabel.numberOfLines = 1;
        [self addSubview:_titleLabel];
        _titleLabel.text = @"Alipay AntUI Mobile";
        [_titleLabel sizeToFit];
    }
    return _titleLabel;
}

- (UILabel *)subtitleLabel
{
    if (!_subtitleLabel)
    {
        _subtitleLabel = [[UILabel alloc] init];
        _subtitleLabel.font = [UIFont systemFontOfSize:6];
        _subtitleLabel.textColor = [UIColor colorWithRGB:0x9197A3];
        _subtitleLabel.numberOfLines = 1;
        [self addSubview:_subtitleLabel];
        _subtitleLabel.text = @"Updated August 31, 2017";
        [_subtitleLabel sizeToFit];
    }
    return _subtitleLabel;
}

@end
