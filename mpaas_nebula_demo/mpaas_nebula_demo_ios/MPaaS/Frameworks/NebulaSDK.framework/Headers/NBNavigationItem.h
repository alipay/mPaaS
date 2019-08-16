//
//  NBNavigationItem.h
//  Nebula
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

@interface NBNavigationItem : NSObject

@property(nonatomic, strong) UIButton *customView;

+ (instancetype)normalNavigationItem;

+ (instancetype)backNavigationItem;

+ (instancetype)closeNavigationItem;

+ (instancetype)settingNavigationItem;

@end
