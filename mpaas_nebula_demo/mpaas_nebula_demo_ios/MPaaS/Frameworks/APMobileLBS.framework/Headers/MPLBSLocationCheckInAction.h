//
//  MPLBSLocationCheckInAction.h
//  APMobileLBS
//
//  Created by shifei.wkp on 2019/4/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MPLBSCheckInMcu;

/**
 位置签到，必须登录才可以使用
 */
@interface MPLBSLocationCheckInAction : NSObject

+ (instancetype)sharedInstance;

/**
 位置签到

 @param scene 签到的场景，不同场景不同的上报间隔策略
 @param location 签到的位置，默认会先去获取位置，再进行签到
 @param block 回调
 */
- (void)checkInWithScene:(MPLBSCheckInScene)scene
                location:(nullable CLLocation *)location
       completionHandler:(nullable void(^)(BOOL))block;


@end

NS_ASSUME_NONNULL_END
