//
//  NBUtils.h
//  NBService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBMonitor.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

#pragma mark - Runtime
/************************************** Runtime ******************************************/

void NBSwizzle(Class c, SEL orig, SEL newSelector);

#pragma mark - URL
/************************************** URL **********************************************/

NSString *NBURLEncode(NSString *str);
NSString *NBURLURLDecode(NSString *string);

BOOL NBURLIsEqualsIgnoreHash(NSString *orig, NSString *dest);

BOOL NBURLIsValidateUrl(NSString *str); // http、https、file

BOOL NBURLIsOnlineUrl(NSString *str); // http、https

BOOL NBURLIsFileUrl(NSString *str); // file

NSString *NBURLString(NSString *urlString, NSURL *baseURL);

NSDictionary *NBURLGetQuery(NSString *queryString);

#pragma mark - UIImage
/************************************* UIImage ******************************************/

UIImage *NBImageNamed(NSString *imageName);
UIImage *NBCacheableImageNamed(NSString *imageName);


#pragma mark - Class
/************************************ Class ********************************************/


#pragma mark - NSString
/*********************************** NSString ******************************************/
NSString *NBString(NSString *str, NSString *defaultValue);

NSNumber *NBNumber(id number,NSNumber *defaultNum);

CGRect NBRectForString(NSString * string, UIFont * font, CGRect boundingRect);

#pragma mark - UIColor
/************************************** UIColor ****************************************/
UIColor *NBColorWithHex(NSInteger hex); // 0xAARRGGBB、0xRRGGBB

UIColor *NBColorWithWebString(NSString *colorString); // #aarrggbb 、 #rrggbb 、 rgb(rr,gg,bb) 、 argb(aa,rr,gg,bb)

#pragma mark - NSDictionary
/*********************************** NSDictionary **************************************/
NSDictionary *NBMergeDict(NSDictionary *origDict, NSDictionary *newDict);

CGFloat NBFloatValue(id obj, CGFloat defaultValue);

int NBIntValue(id obj, int defaultValue);

NSInteger NBIntegerValue(id obj, NSInteger defaultValue);

BOOL NBBoolValue(id obj, BOOL defaultValue);

NSArray *NBArray(id obj, NSArray *defaultValue);

NSDictionary *NBDictionary(id obj, NSDictionary *defaultValue);

NSDictionary *NBOptionsWithURL(NSString *url);

#pragma mark - Device
/************************************** Device ****************************************/
CGFloat NBDeviceSystemVersion();

#pragma mark - Environment
/*********************************** Environment *************************************/
NSString *NBEnvironmentName(const NSInteger environment);

NSString *NBChannelName(const NSInteger channel);

#pragma mark - Log
/************************************** Log *****************************************/
void NBLog(NSString *logId, NSDictionary *params);

#pragma mark - Encrypt & Decrypt
/********************************** Encrypt & Decrypt ********************************/
NSString *NBMD5(NSString *string);

NSString *NBMD5OfData(NSData *data);

NSString *NBBase64Encode(NSData *data);

NSData *NBBase64Decode(NSString *string);

UIImage *NBBase64Decode2Image(NSString *string);

BOOL NBIsBase64(NSString *string);

#pragma mark - Other
/************************************** Other *****************************************/
CTTelephonyNetworkInfo *NBTelephonyInfo();
NSString *NBTrimTailingWhiteSpace(NSString *str);
NSURL *NBURLWithFixedString(NSString *URLString);
BOOL NBRegexTest(NSString *target, NSArray *rules);
void NBLogInfo(NSString *message);





@interface NBUtils : NSObject

+ (BOOL)isTinyAppWithApp:(NAMApp*)app;

+(BOOL)isTinyAppWithStartParams:(NSDictionary *)startParam;

+ (BOOL)isTinyAppWithSession:(PSDSession *)session;

+ (NSString *)getAppLaunchValWithApp:(NAMApp *)app  params:(NSDictionary *)params key:(NSString *)key;
@end
