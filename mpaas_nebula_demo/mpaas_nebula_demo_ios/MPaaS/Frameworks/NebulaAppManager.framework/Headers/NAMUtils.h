//
//  NAMUtils.h
//  NebulaAppManager
//
//  Created by chenwenhong on 15/9/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/******************************* Encode & Decode **********************************/

NSString *NAMMD5OfString(NSString *string);

NSString *NAMMD5OfData(NSData *data);

NSString *NAMBase64Encode(NSData *data);

NSData *NAMBase64Decode(NSString *string);

NSString *NAMMimeType(NSString *pathExtension);

/******************************** NSDate ******************************************/

NSString *NAMDateString(NSDate *date);

/******************************** NSString ****************************************/

NSString *NAMString(NSString *str, NSString *defaultValue);

/******************************** NSArray *****************************************/

NSArray *NAMArray(NSArray *arr, NSArray *defaultValue);

/******************************** NSDictionary ************************************/

NSDictionary *NAMDict(NSDictionary *dict, NSDictionary *defaultValue);

NSMutableDictionary *NAMMutableDict(NSDictionary *dictionary);

NSMutableArray *NAMMutableArray(NSArray *array);

CGFloat NAMFloatValue(id obj, CGFloat defaultValue);

int NAMIntValue(id obj, int defaultValue);

NSInteger NAMIntegerValue(id obj, NSInteger defaultValue);

BOOL NAMBoolValue(id obj, BOOL defaultValue);

double NAMDoubleValue(id obj, double defaultValue);

NSData *NAMData(NSData *data);

/******************************** Transfer ************************************/

NSString *NAMJsonObjToString(id object);
NSData *NAMJsonObjToData(id object);
id NAMDataToJsonObj(NSData *data);

/******************************** Other *******************************************/
void NAMLog(NSString *logId, NSDictionary *params);

NSString *NAMEnvironmentName(const NSInteger environment);

NSString *NAMChannelName(const NSInteger channel);

#pragma mark - Tool

void NAMMain(dispatch_block_t block);

void NAMPostNotification(NSString *name, id obj, NSDictionary *userinfo);

NSString *NAMBundleFile(NSString *name);

/**
 *  查询是否过期
 *
 *  优先级: 
 *     if 被限流: limited==YES: [[NAMContext configManager] limitReqRate]
 *     else if 业务配置了过期时间 preferUpdateRate: preferUpdateRate
 *     else 通用过期时间 [[NAMContext configManager] updateReqRate]
 */
BOOL NAMRequestExpired(NSTimeInterval lastRefreshDate, BOOL limited, NSNumber *preferUpdateRate);

#pragma mark - Url

NSString *NAMTrimTailingWhiteSpace(NSString *str);

NSURL *NAMURLWithFixedString(NSString *URLString);

/**
 *  入口安全校验
 *
 *  校验逻辑: 对于主入口url,首先匹配和main_url的scheme和host是否完全匹配,不匹配时再sub_url对比,都不匹配时候校验失败
 *  注意
 *      1. 如果urlString为/或file://开头,则直接通过校验
 *      2. SDK内默认对入口URL不做安全校验, 如业务方有安全校验需求可以调用该接口校验
 */
BOOL NAMIsMainUrlValid(NSString *urlString, NAMApp *app);

NAMAppAutoScene NAMSceneType(NSString *scene);
