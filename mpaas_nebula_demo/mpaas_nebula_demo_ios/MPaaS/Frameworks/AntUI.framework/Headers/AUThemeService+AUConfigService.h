//
//  AUThemeService+AUConfigService.h
//  AntUI
//
//  Created by 莜阳 on 2017/12/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AUThemeService (AUConfigService)

//
+ (void)setupConfigKey:(NSString *)configKey;
+ (void)removeConfigKey:(NSString *)configKey;

//
+ (NSDate *)stringToNsDate:(NSString *)stringDate;
+ (BOOL)checkTodayIsEarlierForDate:(NSDate *)date;

// 根据key去远端拉取
+ (void)downloadRemoThemeByKey:(NSString *)configKey vcInstant:(UIViewController *)vcInstant;

@end
