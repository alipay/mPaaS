//
//  NSStringUtils.h
//  MobileFoundation
//
//  Created by 孟嵩 on 15/11/11.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSStringUtils : NSObject
+ (NSString *)URLDecodedString:(NSString *)string;
+ (NSString *)URLEncodedString:(NSString *)string;
@end
