//
//  AUThemeService+remoteService.h
//  AntUI
//
//  Created by 莜阳 on 2017/12/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUThemeService.h"

#define  AU_REMOTE_THEME_NAME           @"theme_name"
#define  AU_REMOTE_THEME_URL            @"theme_url"
#define  AU_REMOTE_THEME_VALUE          @"theme_value" // configservice直接配置的主题
#define  AU_REMOTE_START_TIME           @"start_time" // 设置主题生效起始时间
#define  AU_REMOTE_END_TIME             @"end_time"  // 设置主题失效时间

#define  AU_REMOTE_THEME_BUNDLE         @"theme_bundle"
#define  AU_REMOTE_THEME_STORE_PATH     @"theme_store_path"
#define  AU_REMOTE_THEME_FILE_MD5       @"theme_file_md5"

// 标记当前主题是否已经更新过
#define  AU_REMOTE_THEME_HAS_UPDATE     @"remote_theme_has_updated"

// 本地存储的文件信息的总key值
#define  AU_REMOTE_THEME_INFO           @"au_remote_theme_info"
// 存储当前已经注册过的key
#define  AU_CONFIG_KEYS_LIST            @"au_config_keys_list"


typedef NS_ENUM(NSUInteger, AUTimeType) {
    AUTimeTypeEarlierStartTime,
    AUTimeTypeValid,
    AUTimeTypeLaterEnTime
};

@interface AUThemeService (remoteService)

+ (void)handleRemoteConfigValue:(NSString *)value key:(NSString *)key;

+ (void)checkNeedUpdateLayoutVC:(NSString *)bundleName;

// 检测当前时间是否处于预定之间范围内
+ (AUTimeType)curTimeBetweenStartTime:(NSString *)startTime endTime:(NSString *)endTime;

+ (void)remoteThemeDidFinishedDownload:(NSDictionary *)dic;

+ (void)clearThemeInfosInBundle:(NSString *)bundle themeName:(NSString *)themeName;

+ (void)clearThemeInfosInBundle:(NSString *)bundle
                      themeName:(NSString *)themeName
                     completion:(void(^)(void))completion;

// 根据指定bundle以及themeName读取当前主题信息
+ (NSDictionary *)themeInfoFromUserDefault:(NSString *)bundle themeName:(NSString *)themeName;

// 适配主题本地磁盘的加载
+ (NSDictionary *)adaptorNameForRemote:(NSString *)themeName bundle:(NSString *)bundle;

+ (void)registerObserver:(UIViewController *)vcObj;
+ (void)removeObserver:(UIViewController *)vcObj;

+ (void)saveCurTheme:(NSDictionary *)dic;

@end
