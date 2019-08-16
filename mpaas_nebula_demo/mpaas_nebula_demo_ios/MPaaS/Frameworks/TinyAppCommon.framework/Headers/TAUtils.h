//
//  TAUtils.h
//  TinyappService
//
//  Created by 应俊康 on 2017/11/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TAUtils : NSObject

// 这个方法不依赖ViewController，因此可以在session create时调用
// 返回值YES：表示小程序 或者 enableDSL的支付宝内建应用等
//  不建议使用,用下面的新方法
+(BOOL)isTinyAppWithApp:(NAMApp*)app;


+(BOOL)isTinyAppWithStartParams:(NSDictionary*)startParam __attribute__((deprecated("使用isTinyAppWithSession")));

+ (BOOL)isTinyAppWithSession:(PSDSession*)session;

+(TA_APP_TYPE)appTypeWith:(NSString*)appId;

+(NSString*)currentUId;

+ (NSString *)currentProductVersion;

+ (NSString *)chInfo:(NSDictionary *)params;

+ (NSDictionary *)parseResultData:(NSError *)error success:(BOOL)success;

@end

NSArray * TAArray(id array);
NSNumber * TANumber(id number);
NSString * TAString(id string);
NSDictionary * TADictionary(id dic);

NSString * TAUrlEcode(NSString * url);
NSString * TAUrlDecode(NSString * str);
NSString * TAJsonStr(NSDictionary * dic);
NSDictionary * TAJsonDic(NSString * jsonStr);
NSDictionary * TAJsonDicWithData(NSData *data);

NSString *TASafaString(NSString *str, NSString *defaultValue);

