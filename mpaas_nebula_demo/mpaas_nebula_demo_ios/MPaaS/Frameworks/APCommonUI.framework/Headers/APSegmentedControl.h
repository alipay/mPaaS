//
//  APSegmentedControl.h
//  APCommonUI
//
//  Created by 紫空 on 14-1-18.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APSegmentedControlType) {
    APSegmentedControlTypeCustomSystem = 0, //蚂蚁蓝
    APSegmentedControlTypeCustom,           //系统默认颜色
};

@interface APSegmentedControl : UISegmentedControl

@property(nonatomic, assign) APSegmentedControlType segmentedType;

@end
