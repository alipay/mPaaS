//
//  IconfontZoomingViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/9/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "IconfontZoomingViewController.h"
//#import "AUIconView.h"

@interface IconfontZoomingViewController ()

@property(nonatomic,strong) UISlider *slider;

@property(nonatomic,strong) UILabel *label;

@end

@implementation IconfontZoomingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.slider = [[UISlider alloc] initWithFrame:CGRectMake(25, 80, AUCommonUIGetScreenWidth()-50, 50)];
    self.slider.value = 0.1;
    [self.view addSubview:self.slider];
    
    [self.slider addTarget:self
                    action:@selector(sliderValueChanged:)
          forControlEvents:UIControlEventValueChanged];
    
    self.label = [[UILabel alloc] init];
    self.label.backgroundColor = [UIColor clearColor];
    self.label.text = self.iconName;
    self.label.textColor = self.iconColor;
    
    self.label.width = AUCommonUIGetScreenWidth()*self.slider.value;
    self.label.height = self.label.width;
    self.label.font = [AUIconFont iconFontWithFontName:kICONFONT_FONTNAME size:self.label.width];
    self.label.center = self.view.center;
    [self.view addSubview:self.label];
}

- (void)sliderValueChanged:(UISlider *)slider
{
    self.label.width = AUCommonUIGetScreenWidth()* (self.slider.value > 0.1 ?self.slider.value:0.1);
    self.label.height = self.label.width;
    self.label.font = [AUIconFont iconFontWithFontName:kICONFONT_FONTNAME size:self.label.width];
    self.label.center = self.view.center;
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
