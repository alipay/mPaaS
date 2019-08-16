//
//  NSString+Trim.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TRIM)

/**
 *  删除左侧的所有空格
 */
- (NSString*)spaceLeftEndTrimmed;

/**
 *  删除右侧的所有空格
 */
- (NSString*)spaceRightEndTrimmed;

/**
 *  删除两边的空格
 */
- (NSString*)spaceBothEndsTrimmed;

/**
 *  删除左侧的空格和换行符，制表符
 */
- (NSString*)spaceNewLineTabLeftEndTrimmed;

/**
 *  删除右侧的空格和换行符，制表符
 */
- (NSString*)spaceNewLineTabRightEndTrimmed;

/**
 *  删除两边的空格和换行符，制表符
 */
- (NSString*)spaceNewLineTabBothEndsTrimmed;

/**
 *  判断字符串是否全为空格
 */
- (BOOL)trimmedStringIsEmpty;

@end