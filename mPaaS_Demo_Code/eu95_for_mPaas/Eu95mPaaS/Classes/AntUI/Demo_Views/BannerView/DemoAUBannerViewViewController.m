//
//  DemoAUBannerViewViewController.m
//  AntUI
//
//  Created by maizhelun on 2017/6/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoAUBannerViewViewController.h"
//#import "AUBannerView.h"

@interface DemoAUBannerViewViewController () <AUBannerViewDelegate>

@end

@implementation DemoAUBannerViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = RGB(0xF5F5F9);
    // Do any additional setup after loading the view.

    self.title = @"幻灯片";
    self.edgesForExtendedLayout = UIRectEdgeNone;

    NSInteger spaceY = 10;
    NSInteger height = 200;

    DEMO_START

    // 普通banner （深色）
    for (NSInteger i = 0; i < 1; i ++) {
        CGRect rect = CGRectMake(10, 10 + (height + spaceY) * i, self.view.width - 20, height);
        AUBannerView *bannerView = [[AUBannerView alloc] initWithFrame:rect
                                                               bizType:@"demo"
                                                            makeConfig:^(AUBannerViewConfig *config)
                                    {
                                        config.duration = 1.5;
//                                        config.contentViewMargin = UIEdgeInsetsMake(5, 5, 10, 5);
//                                        config.contentViewPadding = UIEdgeInsetsMake(0, 50, 0, 50);
                                        config.style = AUBannerStyleDeepColor;
                                        config.autoTurn = YES;
                                        config.autoStartTurn = YES;
                                    }];

        bannerView.delegate = self;
        bannerView.tag = 1;
        bannerView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
        [self.view addSubview:bannerView];
    }

    // 普通banner （浅色）
    for (NSInteger i = 1; i < 2; i ++) {
        CGRect rect = CGRectMake(10, 10 + (height + spaceY) * i, self.view.width - 20, height);
        AUBannerView *bannerView = [[AUBannerView alloc] initWithFrame:rect
                                                               bizType:@"demo"
                                                            makeConfig:^(AUBannerViewConfig *config)
                                    {
                                        config.duration = 1.5;
                                        config.style = AUBannerStyleLightColor;
                                        config.autoTurn = NO;
                                        config.pageControlDotTapEnabled = YES;
                                    }];

        bannerView.delegate = self;
        bannerView.tag = 2;
        bannerView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
        [self.view addSubview:bannerView];
    }

    // 纯图片banner
    for (NSInteger i = 2; i < 3; i ++) {
        CGRect rect = CGRectMake(10, 10 + (height + spaceY) * i, self.view.width - 20, height);
        NSMutableArray *images = [NSMutableArray array];
        for (NSInteger j = 0; j < 5; j ++) {
            UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"%@", @(j + 1)]];
            [images addObject:image];
        }
        AUBannerView *bannerView = [AUBannerView bannerViewWithFrame:rect
                                                             bizType:@"demo"
                                                              images:images
                                                         placeholder:nil
                                                          actionURLs:nil
                                                          makeConfig:NULL];
        bannerView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.1];
        [self.view addSubview:bannerView];
    }

    DEMO_END
}


DEMO_START

#pragma mark - AUBannerViewDelegate

- (NSInteger)numberOfItemsInBannerView:(AUBannerView *)bannerView
{
    return bannerView.tag == 1 ? 2 : 4;
}

- (UIView *)bannerView:(AUBannerView *)bannerView itemViewAtPos:(NSInteger)pos
{
    NSArray *array = nil;
    // 深色
    if (bannerView.tag == 1) {
        array = @[RGB(0x108EE9), RGB_A(0x108EE9, 0.5), [UIColor blueColor], [UIColor yellowColor]];
    }
    // 浅色
    else {
        array = @[RGB(0xfFFFFF),RGB_A(0xeFFFFF, 0.7),RGB(0xcFFFFF),RGB_A(0xeFFFFF, 0.5),RGB_A(0xeFFFFF, 0.9)];
    }

    UIView *view = [[UIView alloc] init];
    view.backgroundColor = array[pos];
    return view;
}


- (void)bannerView:(AUBannerView *)bannerView didTapedItemAtPos:(NSInteger)pos
{
    NSLog(@"didTapedItemAtPos %@", @(pos));
}

//- (CGFloat)bannerView:(AUBannerView *)bannerView durationOfItemAtPos:(NSInteger)pos
//{
//    return 1;
//}

DEMO_END


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
