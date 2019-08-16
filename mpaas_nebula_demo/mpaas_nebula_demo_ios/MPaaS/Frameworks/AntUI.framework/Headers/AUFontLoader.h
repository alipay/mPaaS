//
//  AUFontLoader.h
//  AntUI
//
//  Created by zhaolei on 2017/6/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUFontLoader : NSObject

/**
 使用字体路径注册字体
 
 @param path 字体路径
 @param error 注册失败的错误
 @return 字体名称
 */
+ (NSString *)registerFontWithPath:(NSString *)path error:(NSError **)outError;

/**
 必须与registerFontWithPath配对使用
 不能取消registerFontWithData的font
 
 @param path 字体路径
 @return 注册失败的错误码
 */
+ (NSError *)unregisterFontWithPath:(NSString *)path;

/**
 使用字体data注册字体
 
 @param data 字体data
 @param error 注册失败的错误
 @return 字体名称
 */
+ (NSString *)registerFontWithData:(NSData *)data error:(NSError **)error;


/**
 必须与registerFontWithData配对使用
 不能取消registerFontWithPath的font

 @param fontName 字体名称
 @return 注册失败的错误码
 */
+ (NSError *)unregisterFontWithName:(NSString *)fontName;


/**
 字体是否包含该unicode
 
 @param unicode 字体名称
 @return YES，包含；NO，不包含
 */
+ (BOOL)isUnicodeExists:(NSString *)unicode inFont:(NSString *)fontName;

@end
