//
//  APMD5.h
//  MobileFoundation
//
//  Created by WenBi on 14-1-14.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMD5 : NSObject

+ (NSString *)calculateDigestFromString:(NSString *)string;
+ (NSString *)calculateDigestFromData:(NSData *)data;

@end
