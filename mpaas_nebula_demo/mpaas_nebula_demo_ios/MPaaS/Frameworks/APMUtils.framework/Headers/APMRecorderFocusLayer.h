//
//  RecorderFocusLayer.h
//  APMultimedia
//
//  Created by Cloud on 15/9/10.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIColor.h>

@interface APMRecorderFocusLayer : CALayer

@property (assign, nonatomic) CGFloat length;
@property (assign, nonatomic) CGPoint center;
@property (retain, nonatomic) UIColor* focusLineColor;
@end
