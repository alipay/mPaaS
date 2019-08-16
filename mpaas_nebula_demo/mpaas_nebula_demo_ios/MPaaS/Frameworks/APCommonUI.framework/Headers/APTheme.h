//
//  APTheme.h
//  APCommonUI
//
//  Created by shenmo on 10/8/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol APThemeValuePath <NSObject>

- (NSString*)stringForPath:(NSString*)path;
- (UIColor*)colorForPath:(NSString*)path;
- (UIColor*)colorForPath:(NSString*)path defaultColor:(UIColor *)defaultColor;
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

@interface APThemeFetch : NSObject <APThemeValuePath>

@end

@interface APTheme : NSBundle <APThemeValuePath>

@property (nonatomic, strong, readonly) NSString* name;
@property (nonatomic, strong, readonly) NSDictionary* theme;
@property (nonatomic, assign, readonly) BOOL inherited; // 当某个值找不到时，是否继续搜索默认主题

- (instancetype)initWithPath:(NSString*)path;

- (APThemeFetch*)fetchForPrefix:(NSString*)prefix;

@end
