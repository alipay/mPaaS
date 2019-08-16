//
//  AUThemeManager.h
//  AntUI
//
//  Created by maizhelun on 2016/9/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUTheme.h"


//extern UIColor *AU_THEME_COLOR(NSString *colorKey);
//extern UIFont  *AU_THEME_FONT(NSString *fontKey);
//extern CGFloat  AU_THEME_SPACE(NSString *spaceKey);
//extern CGSize   AU_THEME_ICONSIZE(NSString *iconSizeKey);
//extern CGFloat  AU_THEME_CORNERRADIUS(NSString *cornerRadiusKey);


@interface AUThemeManager : NSObject

+ (void)loadTheme; // 加载样式

+ (void)loadResource;

+ (NSDictionary *)setupDefaultTheme;

+ (void)setCurrentTheme:(AUTheme *)theme;

@end


