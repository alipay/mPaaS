//
//  TYBackgroundActivity.h
//  TianYan
//
//  Created by qiwei on 2018/7/11.
//  Copyright © 2018 Alipay. All rights reserved.
//
/*
 Usage:
 
 @interface TTTTTTTTTTTTTTTTT : NSObject
 @end
 @implementation TTTTTTTTTTTTTTTTT
 +(void)load{
     [TYBackgroundActivity addEventListener:^(TYBackgroundEventSource source, TYBackgroundEventTime time) {
        NSLog(@"TYBackgroundActivityOnEvent: %@ - %@",@(source),@(time));
     }];
 }
 @end
 */


#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,TYBackgroundEventSource){
    TYBackgroundEventSource_BackgroundFetch = 0,
    TYBackgroundEventSource_Hotspot = 1,
    TYBackgroundEventSource_HealthKit = 2,
    TYBackgroundEventSource_WatchApp = 3,   // only TYBackgroundEventTime_Begin
    TYBackgroundEventSource_PushReply = 4,  // only TYBackgroundEventTime_Begin
    TYBackgroundEventSource_VoIPPush = 5,   // only TYBackgroundEventTime_Begin
};

typedef NS_ENUM(NSUInteger,TYBackgroundEventTime){
    TYBackgroundEventTime_Begin,
    TYBackgroundEventTime_End,
};

typedef void (^TYBackgroundActivityEventListener)(TYBackgroundEventSource source, TYBackgroundEventTime time);

@interface TYBackgroundActivity : NSObject

+ (void)addEventListener:(TYBackgroundActivityEventListener)listener;

@end
