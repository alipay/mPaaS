//
//  APLanguage.h
//
//  Created by Jason Kaer on 15/7/2.
//  Copyright (c) 2015年 Jason Kaer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 *  取当前语言版本的文本.
 *  @param bundle  文本在字符串表所在\c bundle名,通常为模块资源bundle名称.
 *  @param key     文本在字符串表中的key
 *  @param comment 当找不到\c key 对应的文本内容时, commont作为默认返回内容.同时 \c commont 也作为\c genstrings自动生成\c .strings文件时的注释.
 *
 *  @return 当前语言版本的文本内容. 若字符串表中没有该\c key, 返回 \c comment .
 */
#undef	__TEXT
#define __TEXT(bundle,key,comment) \
[APLanguageSetting localizedStringForKey:(key) defaultValue:(comment) inBundle:(bundle)]

/**
 *  取当前语言版本的图片
 *
 *  @param key     图片名在字符串表中的key
 *  @param comment \c genstrings自动生成\c .strings文件时的注释.
 *  @param bundle  匹配图片名时所用的字符串表所在的bundle名称
 *
 *  @return 当前语言版本的UIImage对象, 若字符串表中没有该\c key, 返回名称为\c key的图片.
 */
#undef	__IMAGE
#define __IMAGE(bundle,key,comment) \
[APLanguageSetting localizedImageForKey:(key) inBundle:(bundle)]


extern NSString *const APLanguageSettingDidChangeNotification; /**< 语言切换时的通知名*/
extern NSString *const APLanguageSettingInfoOldKey;            /**< 语言切换时通知附加的userInfo中获取原语言名的key值*/
extern NSString *const APLanguageSettingInfoNewKey;            /**< 语言切换时通知附加的userInfo中获取新语言名的key值*/



// Base
extern NSString *const APLanguageChineseSimplified;     /**< 简体中文*/
extern NSString *const APLanguageChineseTranditional;   /**< 繁体中文(台湾)*/
extern NSString *const APLanguageChineseHongKong;       /**< 繁体中文(香港)*/
extern NSString *const APLanguageEnglish;               /**< 英文*/


// More ....
extern NSString *const APLanguageKorea;                 /**< 韩语*/
extern NSString *const APLanguageJapanese;              /**< 日本语*/
extern NSString *const APLanguageFrench;                /**< 法语*/
extern NSString *const APLanguageSpanish;               /**< 西班牙语*/
extern NSString *const APLanguagePortuguese;            /**< 葡萄牙语*/
extern NSString *const APLanguageItalian;               /**< 意大利语*/
extern NSString *const APLanguageGerman;                /**< 德语*/
extern NSString *const APLanguageDutch;                 /**< 荷兰语*/
extern NSString *const APLanguageVietnamese;            /**< 越南语*/
extern NSString *const APLanguageRussian;               /**< 俄语*/
extern NSString *const APLanguageSwedish;               /**< 瑞典语*/
extern NSString *const APLanguageDanish;                /**< 丹麦语*/
extern NSString *const APLanguageFinnish;               /**< 芬兰语*/
extern NSString *const APLanguageNorwegian;             /**< 挪威语*/
extern NSString *const APLanguageTurkish;               /**< 土耳其语*/
extern NSString *const APLanguageGreek;                 /**< 希腊语*/
extern NSString *const APLanguageIndonesian;            /**< 印度尼西亚语*/
extern NSString *const APLanguageMalay;                 /**< 马来语*/
extern NSString *const APLanguageThai;                  /**< 泰国语*/
extern NSString *const APLanguageHindi;                 /**< 北印度语*/
extern NSString *const APLanguageHungarian;             /**< 匈牙利语*/
extern NSString *const APLanguagePolish;                /**< 波兰语*/
extern NSString *const APLanguageCzech;                 /**< 捷克语*/
extern NSString *const APLanguageSlovak;                /**< 斯洛伐克语*/
extern NSString *const APLanguageUkrainian;             /**< 乌克兰语*/
extern NSString *const APLanguageCroatian;              /**< 克罗地亚人语*/
extern NSString *const APLanguageCatalan;               /**< 加泰罗尼亚语*/
extern NSString *const APLanguageRomanian;              /**< 罗马尼亚语*/
extern NSString *const APLanguageHebrew;                /**< 希伯来语*/
extern NSString *const APLanguageArabic;                /**< 阿拉伯语*/


@class APLanguage;

//////////////////////////////////////////////////////////////////////////

NS_INLINE CGRect MPRectForString(NSString * string, UIFont *font, CGRect boundingRect)
{
    CGRect targetRect = boundingRect;
    CGSize maxSize = boundingRect.size;
    
    if (NSFoundationVersionNumber > NSFoundationVersionNumber_iOS_6_1) {
        // Greater than iOS7.
        targetRect = [string boundingRectWithSize:maxSize
                                          options:NSStringDrawingUsesLineFragmentOrigin
                                       attributes:@{NSFontAttributeName:font}
                                          context:nil];
    }else{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"
        CGSize size = [string sizeWithFont:font
                         constrainedToSize:maxSize
                             lineBreakMode:NSLineBreakByWordWrapping];
#pragma clang diagnostic pop

        targetRect.size = size;
    }
    
    return targetRect;
}

@interface APLanguageSetting : NSObject

+ (APLanguageSetting *)sharedSetting;

+ (APLanguage *)currentLanguage;

+ (BOOL)setCurrentLanguage:(APLanguage *)lang;

+ (BOOL)setCurrentLanguageWithName:(NSString *)name;

+ (NSString *)localizedStringForKey:(NSString *)key
                       defaultValue:(NSString *)value
                           inBundle:(NSString *)bundleName;

+ (UIImage *)localizedImageForKey:(NSString *)key
                         inBundle:(NSString *)bundleName;

///App已经支持的语言列表,每个元素为支持的语言的名称, 如支持简体中文、英文: @[@"zh-Hans",@"en"]
+ (NSArray *)supportedLanguages;

///跟随系统语言,若不支持当前系统语言,默认设置成英文(\c APLanguageEnglish).
+ (BOOL)setSystemLanguage;

///是否当前语言环境是跟随系统语言的,跟随系统语言不一定与系统语言一致,如系统当前语言App不支持,会fallback到英文.
+ (BOOL)isFollowingSystemLanguage;

@end // APLanguageSetting

// 为了兼容性
@interface MPLanguageSetting : APLanguageSetting

@end

//////////////////////////////////////////////////////////////////////////


@interface APLanguage : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) BOOL isCurrentLanguage;
@property (nonatomic, strong, readonly) NSMutableDictionary *strings;
@property (nonatomic, strong, readonly) NSString *tableName;

+ (APLanguage *)languageWithData:(id)data;

+ (APLanguage *)languageWithName:(NSString *)name;

+ (APLanguage *)languageWithName:(NSString *)name
                       tableName:(NSString *)tableName;

- (NSString *)localizedStringForKey:(NSString *)key
                       defaultValue:(NSString *)value
                           inBundle:(NSString *)bundleName;
@end // APLanguage


//////////////////////////////////////////////////////////////////////////
