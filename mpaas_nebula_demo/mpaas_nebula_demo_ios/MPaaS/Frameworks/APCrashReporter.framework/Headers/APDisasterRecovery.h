//
//  APDisasterRecovery.h
//  APCrashReporter
//
//  Created by NianXi on 2018/11/24.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, APExceptionDescType) {
    APExceptionDescCrashType = 1001,
    APExceptionDescANRType,
    APExceptionDescOOMType
};

@interface APExceptionDesc : NSObject

@property (nonatomic, readonly) APExceptionDescType type;
@property (nonatomic, readonly) NSString *vc;
@property (nonatomic, readonly) NSString *viewId;

@end


@interface APDisasterRecovery : NSObject


/**
 在进程启动系统发送UIApplicationDidBecomeActiveNotification通知之后的生命周期中，
 可以通过此接口获取上次异常退出的信息，比如Crash、ANR、OOM；
 异常优先级等级从上至下递减，即Crash>ANR>OOM，当Crash和ANR同时发生，将认定异常为Crash
 如果上次是正常被系统回收无异常，则返回 nil

 参数意义：
 vc - 异常发生时的 view controller 类名
 viewId - 自动化埋点填充的view信息，异常发生在native页面会填充类名，如 LifeHomeViewController；
          异常发生在H5页面会填充URL，如 https://66666674.h5app.alipay.com/www/index.htm；
          异常发生在压后台之后，会填充 enter_background_page_id
 
 用法举例：
 if ([APDisasterRecovery lastestExceptionDesc].type == APExceptionDescCrashType ) {
    //上次进程发生了闪退
 }
 
 @return (APExceptionDesc*)型，异常信息结构
 */
+(APExceptionDesc *)lastestExceptionDesc;

@end


