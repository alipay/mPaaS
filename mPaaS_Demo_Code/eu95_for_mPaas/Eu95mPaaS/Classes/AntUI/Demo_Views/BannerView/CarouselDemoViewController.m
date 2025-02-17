//
//  CarouselDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/9/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "CarouselDemoViewController.h"

@interface CarouselDemoViewController ()<AUBannerViewDelegate>

@end

@implementation CarouselDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    NSInteger spaceY = 10;
    NSInteger height = 200;
    
    // 普通banner （深色）
    for (NSInteger i = 0; i < 1; i ++) {
        CGRect rect = CGRectMake(10, 10 + (height + spaceY) * i, self.view.width - 20, height);
        AUBannerView *bannerView = [[AUBannerView alloc] initWithFrame:rect
                                                               bizType:@"demo"
                                                            makeConfig:^(AUBannerViewConfig *config)
                                    {
                                        config.duration = 2;
                                        config.style = AUBannerStyleDeepColor;
                                        config.autoTurn = YES;
                                        config.autoStartTurn = YES;
                                    }];
        
        bannerView.delegate = self;
        bannerView.tag = 1;
        bannerView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
        [self.contentView addSubview:bannerView];
    }
    
    // 普通banner （浅色）
    for (NSInteger i = 1; i < 2; i ++) {
        CGRect rect = CGRectMake(10, 10 + (height + spaceY) * i, self.view.width - 20, height);
        AUBannerView *bannerView = [[AUBannerView alloc] initWithFrame:rect
                                                               bizType:@"demo"
                                                            makeConfig:^(AUBannerViewConfig *config)
                                    {
                                        config.duration = 2;
                                        config.style = AUBannerStyleLightColor;
                                        config.autoTurn = NO;
                                        config.pageControlDotTapEnabled = YES;
                                    }];
        
        bannerView.delegate = self;
        bannerView.tag = 2;
        bannerView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
        [self.contentView addSubview:bannerView];
    }

}

#pragma mark - AUBannerViewDelegate

- (NSInteger)numberOfItemsInBannerView:(AUBannerView *)bannerView
{
    return bannerView.tag == 1 ? 3 : 4;
}

- (UIView *)bannerView:(AUBannerView *)bannerView itemViewAtPos:(NSInteger)pos
{
    NSArray *array = nil;
    // 深色
    if (bannerView.tag == 1) {
        array = @[RGB(0x108EE9), RGB_A(0x108EE9, 0.5), [UIColor blueColor]];
    }
    // 浅色
    else {
        array = @[RGB(0xfFFFFF),RGB_A(0xeFFFFF, 0.8),RGB(0xcFFFFF),RGB_A(0xeFFFFF, 0.5),RGB_A(0xeFFFFF, 0.9)];
    }
    
    UIView *view = [[UIView alloc] init];
    view.backgroundColor = array[pos];
    return view;
}


- (void)bannerView:(AUBannerView *)bannerView didTapedItemAtPos:(NSInteger)pos
{
    NSLog(@"didTapedItemAtPos %@", @(pos));
}

@end
