//
//  H5NavigationTitleView.h
//  URLProtocolTest
//
//  Created by chenwenhong on 15-3-5.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NebulaSDK/NBNavigationTitleView.h>

// titleView构成说明
// 菊花：主标题：子标题：右Icon

@interface H5NavigationTitleView : NBNavigationTitleView

@property(nonatomic, assign) BOOL shouldUseAUSearch;
@property(nonatomic, strong) NSDictionary *auSearchAttributes;
@property(nonatomic, strong) AUSearchTitleView *mainTitleSearchView;
@property(nonatomic, strong) UIImageView       *mainTitleImageView;
@property(nonatomic, strong) NSString          *mainTitleImageDesc;
@property(nonatomic, weak) H5WebViewController          *currentViewController;

- (void)setIndicatorViewTrackColor:(UIColor *)color;
- (void)setIndicatorViewProgressColor:(UIColor *)color;
- (void)createAUSearchTitleView;
- (BOOL)canSetImageTitle:(NSString *)title;


@end

