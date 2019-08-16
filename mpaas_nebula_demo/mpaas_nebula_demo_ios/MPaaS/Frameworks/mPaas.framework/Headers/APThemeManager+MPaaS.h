//
//  APThemeManager+MPaaS.h
//  MPaaS
//
//  Created by shenmo on 5/9/16.
//  Copyright © 2016 Alipay. All rights reserved.
//
#import <UIKit/UIKit.h>

@protocol APThemeValuePathProtocol <NSObject>

- (NSString*)stringForPath:(NSString*)path;
- (UIColor*)colorForPath:(NSString*)path;
- (NSInteger)intForPath:(NSString*)path;
- (float)floatForPath:(NSString*)path;
- (BOOL)boolForPath:(NSString*)path;
- (UIImage*)imageForPath:(NSString*)path;
- (UIFont*)fontForPath:(NSString*)path;

// 某个路径的值是否在配置文件里定义了
- (BOOL)definedForPath:(NSString*)path;

// 某个路径是否在配置文件里定义了，当没定义时，不会回溯默认主题
- (BOOL)definedForPathNoRecursion:(NSString*)path;

@end

@protocol APThemeClass <NSObject, APThemeValuePathProtocol>

@property (nonatomic, strong, readonly) NSString* name;
@property (nonatomic, strong, readonly) NSDictionary* theme;
@property (nonatomic, assign, readonly) BOOL inherited; // 当某个值找不到时，是否继续搜索默认主题

- (id<APThemeValuePathProtocol>)fetchForPrefix:(NSString*)prefix;

@end

@protocol APThemeManagerClass <NSObject>

@property (nonatomic, strong, readonly) id<APThemeClass> defaultTheme;
@property (nonatomic, strong, readonly) id<APThemeClass> currentTheme;

+ (id<APThemeManagerClass>)sharedInstance;

/**
 *  加载主题，并作为Current Theme
 *
 *  @param path 主题.bundle的资源路径
 */
- (void)loadThemeWithPath:(NSString*)path;

@end