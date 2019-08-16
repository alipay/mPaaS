//
//  H5SPDYManager.h
//  NebulaBiz
//
//  Created by theone on 16/6/13.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define H5DirectReqCacheTime    @"H5DirectReqCacheTime"
#define H5DirectReqCurrentTime  @"H5DirectReqCurrentTime"




@interface H5SPDYManager : NSObject
+ (nonnull instancetype)shareInstance;
- (BOOL)shouldRequestWithSPDYWithUrl:(nonnull NSURL *)url;
- (void)addDownGradeRequestwithKey:(nonnull NSDictionary *)config withKey:(nonnull NSString *)key;
- (void)addDirectRequestConfig:(nonnull NSString *)key;
+ (BOOL)shouldStartSPDYReq:(nullable NSURL *)url
             withWhiteList:(nullable NSArray *)whiteList
             withBlackList:(nullable NSArray *)blackList;
- (void)getCountryCode;
+ (BOOL)shouldStartReqInCurrentCountry;
- (BOOL)isMainUrlSPDYGo:(NSURL *)url;
- (void)addSPDYGoMainUrl:(NSURL *)url;
@end
