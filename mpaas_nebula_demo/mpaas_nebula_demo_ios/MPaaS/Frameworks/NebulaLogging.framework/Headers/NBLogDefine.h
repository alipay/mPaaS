//
//  NBLogDefine.h
//  NebulaLogging
//
//  Created by Glance on 2017/7/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef NBLogDefine_h
#define NBLogDefine_h

// SPM
static const char * _Nonnull kNBLogContentViewExpando_KEY = "kNBLogContentViewExpando_KEY";
static NSString * const _Nonnull kHeader4TrackAndClick = @"H5-AM";

// 日志头
#define kNBLogHeaderError @"H-EM"
#define kNBLogHeaderBehavior @"H5-VM"
#define kNBLogHeaderBehaviorAuto @"HD-VM"
#define kNBLogHeaderCommon @"H-MM"

// 日志类型
#define kNBLogBizType135 @"135"
#define kNBLogBizTypeBehavior @"H5behavior"

// 网络自定义信息
#define kNBLogNetInfo       @"NBLogNetInfo"
#define kNBLogNetErrorLog   @"NBLogNetErrorLog"

typedef NS_ENUM(NSUInteger, NBNetChannelType) {
    NBNetChannelConnection = 0,
    NBNetChannelMassProxy           // massProxy
};

// 首页标识
#define kNBLogSessionDidShowEntrance @"NBLogSessionDidShowEntrance"
#define kNBLogPageIsEntrance @"NBLogPageIsEntrance"

#endif /* NBLogDefine_h */
