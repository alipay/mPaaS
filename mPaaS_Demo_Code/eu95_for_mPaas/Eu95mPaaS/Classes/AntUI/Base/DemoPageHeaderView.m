//
//  DemoPageHeaderView.m
//  
//
//  Created by 莜阳 on 2017/8/15.
//
//

#import "DemoPageHeaderView.h"

@implementation DemoPageHeaderView

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    [self.titleLabel sizeToFit];
    self.width = MAX(self.titleLabel.width, self.lineView.width);
    
    self.titleLabel.frame = CGRectMake(0, 0, self.titleLabel.width, self.titleLabel.height);
    self.lineView.origin_mp = CGPointMake((self.width-self.lineView.width)/2, 16+self.titleLabel.bottom);
    
    self.height = self.lineView.bottom + DemoHeaderViewMarginBottom;
}

- (UILabel *)titleLabel
{
    if (!_titleLabel)
    {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.font = [UIFont systemFontOfSize:15];
        _titleLabel.numberOfLines = 1;
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.textColor = [UIColor colorWithRGB:0x000000 alpha:0.3];
        [self addSubview:_titleLabel];
    }
    return _titleLabel;
}

- (UIView *)lineView
{
    if (!_lineView)
    {
        _lineView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 45, 1/[UIScreen mainScreen].scale)];
        _lineView.backgroundColor = [UIColor colorWithRGB:0x000000 alpha:0.3];
        [self addSubview:_lineView];
    }
    return _lineView;
}

@end
