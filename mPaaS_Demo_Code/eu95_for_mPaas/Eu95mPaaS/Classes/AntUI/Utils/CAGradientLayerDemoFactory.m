//
//  AUCAGradientLayer.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "CAGradientLayerDemoFactory.h"


@implementation AUCAGradientLayer

@end

@implementation CAGradientLayerDemoFactory

+ (AUCAGradientLayer *)createDemoDefaultLayer:(UINavigationBar *)navigationBar
{
    [self removeCurrentNaviLayer:navigationBar];
    
    AUCAGradientLayer *_gradientLayer = [AUCAGradientLayer layer];
    _gradientLayer.frame = CGRectMake(0, 0, AUCommonUIGetScreenWidth(), 64);
    
    _gradientLayer.colors = @[
                              (id)[UIColor colorWithRGB:0x9EA7FC].CGColor,
                              (id)[UIColor colorWithRGB:0x86ADFA].CGColor,
                              (id)[UIColor colorWithRGB:0x68B5F7].CGColor
                              ];
    // 设置渐变方向(0~1)
    _gradientLayer.startPoint = CGPointMake(0, 0);
    _gradientLayer.endPoint = CGPointMake(1, 0);
    
    // 设置渐变色的起始位置和终止位置(颜色的分割点)
    _gradientLayer.locations = @[@(0.3f),@(0.6f),@(0.9f)];
    _gradientLayer.borderWidth  = 0.0;
    
    for (UIView *view in navigationBar.subviews)
    {
        if ([view isKindOfClass:NSClassFromString(@"_UIBarBackground")])
        {
            [view.layer addSublayer:_gradientLayer];
        }
    }
    return _gradientLayer;
}

+ (void)removeCurrentNaviLayer:(UINavigationBar *)navigationBar
{
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (UIView *view in navigationBar.subviews)
    {
        if ([view isKindOfClass:NSClassFromString(@"_UIBarBackground")])
        {
            for (CAGradientLayer *layer in view.layer.sublayers)
            {
                if ([layer isKindOfClass:[AUCAGradientLayer class]])
                {
                    CAGradientLayer *mlayer = layer;
                    [array addObject:mlayer];
                }
            }
        }
    }
    
    for (CAGradientLayer *layer in array)
    {
        [layer removeFromSuperlayer];
    }
}

@end
