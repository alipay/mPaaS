#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_IconFont_AUIconView//程序自动生成
//
//  AUIconFontLoader.h
//  a16
//
//  Created by majie on 14-12-30.
//  Copyright (c) 2014年 majie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AUIconFontLoader : NSObject

+ (AUIconFontLoader *)sharedInstance;

@property (nonatomic, copy, readonly) NSDictionary *ttfsPlist;

//每次调用都会加载字体，上边调用要处理好防止多次调用
- (BOOL)iconFontLoadWithFontName:(NSString *)fontName;
- (BOOL)isValidResources:(NSString *)path;

- (NSNumber *)unicodeWithKey:(NSString *)key fontName:(NSString *)fontName;
- (NSString *)colorWithKey:(NSString *)key fontName:(NSString *)fontName;
- (CGSize)sizeWithKey:(NSString *)key fontName:(NSString *)fontName;
- (NSDictionary *)fontsWithKey:(NSString *)key fontName:(NSString *)fontName;

- (void)configureDataWithPath:(NSString *)ttfPath;

@end

@interface AUIconFontLoader (Http)

- (void)startIconFontResourcesDownLoadWithUrl:(NSString *)url;

@end

@interface AUIconFontLoader (Files)

- (BOOL)copyFileAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)deleteFileAtPath:(NSString *)path;
- (BOOL)fileExistsAtPath:(NSString *)path;
- (BOOL)directoryExistsAtPath:(NSString *)path;
- (BOOL)createDirectoryAtPath:(NSString *)path;

@end

@interface AUIconFontLoader (Font)

- (CGSize)sizeWithFont:(UIFont *)font text:(NSString *)text size:(CGSize)size;
- (UIFont *)fitFontWithWidth:(float)givenWidth text:(NSString *)text font:(UIFont *)font;

+ (void)loadIconfont:(NSString *)ttfPath;

@end

#endif//程序自动生成
