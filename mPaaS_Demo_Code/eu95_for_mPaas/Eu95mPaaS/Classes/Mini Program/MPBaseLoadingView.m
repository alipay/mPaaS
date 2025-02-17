//
//  MPBaseLoadingView.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/5/15.
//

#import "MPBaseLoadingView.h"


//@interface MPBaseLoadingView : APBaseLoadingView
//
//@end

@implementation MPBaseLoadingView

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.backgroundColor = [UIColor grayColor];
        self.titleLabel.text = @"加载中。。。";
        self.titleLabel.backgroundColor = [UIColor redColor];
        self.titleLabel.font = [UIFont boldSystemFontOfSize:8];

        self.iconImageView.backgroundColor = [UIColor blueColor];

        self.pageControl.backgroundColor = [UIColor orangeColor];

    }

    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    // 调整 view 的位置

    CGSize size  = self.bounds.size;
    CGRect frame = CGRectMake((size.width - 80)/2, 0, 80, 80);
    self.iconImageView.frame = frame;

    frame = CGRectMake(15, CGRectGetMaxY(self.iconImageView.frame) + 6, size.width - 30, 22);
    self.titleLabel.frame = frame;

    frame = CGRectMake((size.width-40)/2, CGRectGetMaxY(self.titleLabel.frame) + 21, 40, 20);
    self.pageControl.frame = frame;
}

@end
