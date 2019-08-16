//
//  TANavBarUtil.h
//  TinyappService
//
//  Created by niki on 2018/10/25.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TANavBarUtil : NSObject

// 重置导航栏底部分割线的颜色
+ (void)resetNavigationBarBottomLineColor;

//
+ (BOOL)enablePresentAnimation:(NSString *)appId;

// 小程序右上角三个点是否使用新样式，默认使用新样式
+ (BOOL)enabeNaviBarNewPopMenu:(NSString *)appId;

// 小程序右上角是否展示收藏icon
+ (BOOL)enableNaviBarShowFavorite:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
