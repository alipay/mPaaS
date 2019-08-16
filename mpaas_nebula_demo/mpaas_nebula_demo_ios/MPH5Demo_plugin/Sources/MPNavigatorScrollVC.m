//
//  MPNavigatorScrollVC.m
//  MPAntUIDemo
//
//  Created by yangwei on 2019/2/21.
//  Copyright © 2019年 alipay. All rights reserved.
//

#import "MPNavigatorScrollVC.h"

@interface MPNavigatorScrollVC ()<UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollview;  //the scrollview

@end

@implementation MPNavigatorScrollVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"渐变导航栏";
    self.edgesForExtendedLayout = UIRectEdgeAll;
    
    CGRect screenRect = self.view.frame;
    self.scrollview = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, screenRect.size.width, screenRect.size.height + 1260)];
    self.scrollview.backgroundColor = [UIColor orangeColor];
    self.scrollview.contentSize = self.scrollview.frame.size;
    self.scrollview.delegate = self;
    NSLog(@"%f, %f", _scrollview.contentSize.width, _scrollview.contentSize.height);
    [self.view addSubview:_scrollview];
    
    UIImageView *imageView = [[UIImageView alloc] initWithImage:APCommonUILoadImage(@"ilustration_ap_expection_alert")];
    imageView.frame = CGRectMake(0, 0, self.scrollview.width, 100);
    [self.scrollview addSubview:imageView];
    
    
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (UIColor *)opaqueNavigationBarColor
{
    return [UIColor colorWithRGB:0xff0000 alpha:0];
}

- (UIColor *)customNavigationBarTitleColor
{
    return [UIColor whiteColor];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    int alpha = 0;
    CGFloat offsetY = scrollView.contentOffset.y;
    NSLog(@"offsetY: %f", offsetY);
    if (offsetY <= 0) {
        alpha = 0;
    } else if (offsetY > 0 && offsetY < 64) {
        alpha = offsetY / 64;
    } else if (offsetY >= 64 ) {
        alpha = 1;
    }
    
    [self.navigationController.navigationBar setNavigationBarStyleWithColor:[UIColor colorWithRGB:0xff0000 alpha:alpha] translucent:YES];
}

@end
