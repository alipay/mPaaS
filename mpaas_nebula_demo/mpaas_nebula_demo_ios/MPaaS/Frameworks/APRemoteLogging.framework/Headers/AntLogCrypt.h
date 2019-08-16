//
//  AntLogCrypt.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/10/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AntLogCrypt AntLogDancer
#define antlog_encrypt antlog_dance
#define antlog_decrypt antlog_de_dance

@interface AntLogCrypt : NSObject

+ (NSString *)antlog_encrypt:(NSString *)string;
+ (NSString *)antlog_decrypt:(NSString *)encrypted;

@end

