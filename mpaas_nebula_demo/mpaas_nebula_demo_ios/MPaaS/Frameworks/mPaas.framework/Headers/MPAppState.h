//
//  MPAppState.h
//  APMPaaS
//
//  Created by qiwei on 01/12/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 试图提供更准确的前后台状态
 以及一个关键的网络长连接状态
 */


typedef NS_ENUM(NSUInteger,MPAppStateEnum){
    MPAppState_Unknown,// 仅App启动过程中，到didFinishLaunching之间会出现这个值。也就是业务不应该获取到这个值，否则就是获取太早了。
    MPAppState_Foreground,
    MPAppState_Background,
};


@interface MPAppState : NSObject


/**
 App当前处于后台
 注意：！！如果main之前获取，认为是前台
 @return YES 后台 ; NO前台或回前台过程中
 */
+ (BOOL)isBackground;

/**
 状态变化通知

 @param listener 通知block，src与dest不会相同
 */
+ (void)addStateChangeListener:(void(^)(MPAppStateEnum src,MPAppStateEnum dest)) listener;


/**
 上一次进后台的时间戳
 这个时间戳是App可感知到的最早时机（直接挂接到AppDelegate）

 @return
 */
+ (NSTimeInterval)lastDidEnterBackgroundTimestamp;

/**
 上一次进后台的时刻（距离开机时间）
 这个时刻是App可感知到的最早时机（直接挂接到AppDelegate）
 
 @return
 */
+ (NSTimeInterval)lastDidEnterBackgroundRelativeTime;

/**
 处于后台无长连接状态
 若返回YES，则无网络层不建立长连接，即RPC都发不出去

 @return YES 无
 */
+ (BOOL)inBackgroundNoConnectionMode;

@end
