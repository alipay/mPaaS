//
//  AUThemeService.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUThemeManager.h"

#define AU_THEME_1              @"themes/theme1.strings"
#define AU_THEME_2              @"themes/theme2.strings"
#define AU_BUNDLE_NAME          @"APCommonUI"

// 埋点信息定义
#define AUThemeSeed             @"AUThemeSeed" // 屏幕适配方案
#define AUChangeSkinSeed        @"changeSkin"
#define AUFPSeed                @"AU_FP" // 屏幕适配方案
#define AUThemeVersion          @"version"
#define AUReadSuccess           @"ReadSuccess"  // 在线主题读成功
#define AUReadError             @"ReadError"   // 在线主题读失败
#define AUDownloadError         @"DownloadError" // 主题下载失败
#define AUDownloadSuccess       @"DownloadSuccess" // 主题下载成功

@interface AUThemeService : NSObject

+ (AUThemeService *)themeService;

+ (AUTheme *)defaultTheme;
+ (AUTheme *)currentTheme;
+ (void)setCurrentTheme:(AUTheme *)theme;

// 设置某一bundle当前主题
+ (void)setCurrentThemeName:(NSString *)themeName inBundle:(NSString *)bundleName;

// 指定更新某一bundle下的主题
+ (void)updateThemes:(NSDictionary *)themes;

+ (id)themeForKey:(NSString *)key inBundle:(NSString *)bundle;

// 当前bundle下的主题
+ (AUTheme *)currentThemeInBundle:(NSString *)bundle;

// 当前bundle的当前主题名称(主题名称即配置文件名称)
+ (NSString *)currentThemeName:(NSString *)bundle;

+ (NSMutableDictionary *)loadStaticTheme;

@end


