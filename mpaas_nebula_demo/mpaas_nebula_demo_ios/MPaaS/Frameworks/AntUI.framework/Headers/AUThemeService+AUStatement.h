//
//  AUThemeService+AUStatement.h
//  AntUI
//
//  Created by 莜阳 on 2017/12/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//


#define AU_CURRENT_THEME            @"currentTheme"
#define AU_CURRENT_THEME_NAME       @"currentThemeName"
#define AU_CURRENT_ADAPTOR_DIC      @"currentAdaptorDic"
#define AU_CURRENT_VC               @"currentViewController"
#define AU_THEME_1                  @"themes/theme1.strings"
#define AU_THEME_NAME_1             @"theme1.strings"
#define AU_THEME_2                  @"themes/theme2.strings"
#define AU_THEME_NAME_2             @"theme2.strings"



@interface AUThemeService ()

@property (nonatomic, strong) NSMutableDictionary *themes;          // 当前已经加载的主题资源
//@property (nonatomic, strong) NSMutableDictionary *configKeys; // { bundle:key1, bundle2:key2 }


// 加载AntUI 内部默认主题
+ (NSDictionary *)loadTheme:(NSString *)themeName inBundle:(NSString *)bundleName;

// 内部接口
+ (NSDictionary *)readThemeKVWithPath:(NSString *)path bundleName:(NSString *)bundleName;

@end


@interface AUThemeService (AUOldThemeFormat)

+ (id)themeRealValueForKey:(NSString *)key inBundle:(NSString *)bundle;

@end
