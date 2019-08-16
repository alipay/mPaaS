//
//  APLanguage+MPaaS.h
//  MPaaS
//
//  Created by shenmo on 5/9/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol APLanguageClass <NSObject>

@property (nonatomic, copy            ) NSString            *name;              /**< 语言名称 */
@property (nonatomic, assign          ) BOOL                isCurrentLanguage;  /**< 是否为当前语言 */
@property (nonatomic, strong, readonly) NSMutableDictionary *strings;           /**< 该语言对应的字符串表的所有key-value对组成的字典(暂不支持,始终为nil) */
@property (nonatomic, strong, readonly) NSString            *tableName;         /**< 该语言对应的字符串表文件名,如 @"en" */

@end

@protocol APLanguageSettingClass <NSObject>

/**
 *  获取当前语言对象
 *
 *  @return 当前语言对象,APLanguage的一个实例
 */
+ (id<APLanguageClass>)currentLanguage;

/**
 *  在名称为 \c bundleName 的bundle中取当前语言状态下\c key 对应的字符串值.
 *
 *  @param key        字符串表中\c key
 *  @param value      默认值, 当找不到该 \c key 对应的 \c value 时返回该默认值.
 *  @param bundleName bundle名称字符串
 *
 *  @return 当前语言状态下\c key 对应的字符串值
 */
+ (NSString *)localizedStringForKey:(NSString *)key
                       defaultValue:(NSString *)value
                           inBundle:(NSString *)bundleName;

/**
 *  App已经支持的语言列表
 *
 *  @return 支持的语言数组,每个元素为支持的语言的名称, 如支持简体中文、英文: @[@"zh-Hans",@"en"]
 */
+ (NSArray *)supportedLanguages;

/**
 *  设置为跟随系统语言,若不支持当前系统语言,默认设置成英文(\c APLanguageEnglish). @see [APLanguageSetting isFollowingSystemLanguage]
 *
 *  @return 成功返回  \c YES , 失败返回  \c NO.
 */
+ (BOOL)setSystemLanguage;

/**
 *  是否当前语言环境是跟随系统语言的,跟随系统语言不一定与系统语言一致,如系统当前语言App不支持,会fallback到英文.
 *
 *  @return 正在跟随系统语言时返回 \c YES, 否则返回 \c NO .
 */
+ (BOOL)isFollowingSystemLanguage;

/**
 * 是否系统语言(非App内语言)在两次启动间隔中发生了语言切换.
 * @note 切换系统语言时系统会杀掉App进程,所以该种切换指的是前后两次启动的切换. 系统语言切换时,App内语言不一定切换.
 *
 *  @return 系统语言发生了切换时返回 \c YES, 否则返回 \c NO .
 */
+ (BOOL)systemLanguageDidChange;

/**
 *  是否多语言环境是打开的,在服务端下发关闭多语言环境的开关后的下一次冷启动生效,关闭多语言环境时,当前语言默认返回 \c 简体中文.
 *
 *  @return 多语言环境打开时返回 \c YES, 关闭时返回 \c NO.
 */
+ (BOOL)isMultiLanguageEnabled;

/**
 *  一个语言名称对应的显示在UI上的字符串,如: \c APLanguageChineseSimplified (\c @"zh-Hans") 显示为 \c @"简体中文" .)@note 暂不支持
 *
 *  @param langName 语言名称
 *
 *  @return 语言名称对应的显示在UI上的字符串
 */
+ (NSString *)displayNameForLanguageName:(NSString *)langName;

@end
