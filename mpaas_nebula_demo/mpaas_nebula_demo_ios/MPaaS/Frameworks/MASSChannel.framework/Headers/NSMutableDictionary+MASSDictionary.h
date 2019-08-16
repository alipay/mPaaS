//
//  NSMutableDictionary+MASSDictionary.h
//  MASSChannel
//
//  Created by feisong on 2017/6/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (MASSDictionary)
/**
 * 设置埋点
 *
 */
-(void)setLog:(double)value forKey:(NSString *)key;

@end
