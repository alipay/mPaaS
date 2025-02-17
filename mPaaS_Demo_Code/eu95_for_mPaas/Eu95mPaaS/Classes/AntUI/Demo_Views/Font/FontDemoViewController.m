//
//  FontDemoViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/12/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "FontDemoViewController.h"

@interface FontDemoViewController ()

@end

@implementation FontDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UILabel *textLabel = nil;
    {
        textLabel = [[UILabel alloc] init];
        textLabel.numberOfLines = 0;
        textLabel.width = self.view.width - 100;
        textLabel.x = 50;
        textLabel.font = [UIFont boldSystemFontOfSize:20];
        textLabel.text = @"默认加粗字体1234567890abcdefgABCDEFG";
        [textLabel sizeToFit];
        textLabel.y = self.topMargin;
        [self.view addSubview:textLabel];
    }
    
    {
        UIFont *font = [UIFont fontWithName:@"PingFangSC-Medium" size:20];
        CGFloat y = CGRectGetMaxY(textLabel.frame);
        textLabel = [[UILabel alloc] init];
        textLabel.numberOfLines = 0;
        textLabel.width = self.view.width - 100;
        textLabel.x = 50;
        textLabel.font = font;
        textLabel.text = @"平方加粗字体1234567890abcdefgABCDEFG";
        [textLabel sizeToFit];
        textLabel.y = y + 10;
        [self.view addSubview:textLabel];
    }
    
}

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
