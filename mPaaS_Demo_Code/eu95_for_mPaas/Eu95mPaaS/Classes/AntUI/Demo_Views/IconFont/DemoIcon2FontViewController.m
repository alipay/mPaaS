//
//  DemoIcon2FontViewController.m
//  AntUIDemo
//
//  Created by Wang on 2019/3/21.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "DemoIcon2FontViewController.h"

@implementation DemoIcon2FontViewController

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

-(void) viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    self.view.backgroundColor = RGB(0x000000);
    UIImage *image = [UIImage iconWithName_au:kICONFONT_JIEPINGFANKUI width:30 color:RGB(0xFFFFFF)];
    UIImageView *imageView = [[UIImageView alloc]initWithImage:image];
    imageView.frame = CGRectMake(20, 100, 30, 30);
    [self.view addSubview:imageView];
}

@end
