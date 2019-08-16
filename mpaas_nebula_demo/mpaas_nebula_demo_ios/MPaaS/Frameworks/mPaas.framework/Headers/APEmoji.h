//
//  APEmoji.h
//  Emoji
//
//  Created by cuinacai on 14-9-4.
//  Copyright (c) 2014年 cuinacai. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString(APEmojiString)
/**
 *  将包Unified编码的Emoji转化为ubb编码
 *  eg: "abc😄" ---> "abc[emoji]\ud83d\ude04[/emoji]"
 *  @return 转化后的字符串
 */
- (NSString *)unified2ubb;
/**
 *  将包ubb编码转化为Unified编码的Emoji
 *  eg: "abc[emoji]\ud83d\ude04[/emoji]"  --->  "abc😄"
 *  @return 转化后的字符串
 */
- (NSString *)ubb2unified;
/**
 *  是否包含表情符号,仅限ios键盘输入的范围内
 *
 *  @return 结果
 */
- (BOOL)containsEmoji;
@end





