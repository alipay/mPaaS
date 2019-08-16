//
//  CommonDefined.h
//  BusinessCommon
//
//  Created by wangweixing on 13-4-23.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

extern NSString * const UIApplicationDidReceiveRemoteNotification;          // App收到Push通知。
extern NSString * const UIApplicationWillHandleResponseForNotification;     // App收到通知后的快捷响应，iOS8+
extern NSString * const UIApplicationDidReceiveSilentNotification;          // App收到静默Push通知。
extern NSString * const UIApplicationDidReceiveLocalNotification;           // App收到本地通知。

extern NSString * const DTApplicationRegisterForRemoteNotification;         // App去注册接收Push通知。
extern NSString * const UIApplicationDidRegisterForRemoteNotifications;     // App注册接收Push通知。

extern NSString * const UIApplicationWatchKitExtensionRequestNotifications; // App收到Watch请求通知。
extern NSString * const UIApplicationUserActivityNotifications;             // App收到UserActivity通知。
extern NSString * const DTViewControllerViewDidLoadNotifications;           // DTViewController已经加载通知。
extern NSString * const DTViewControllerWillAppearNotifications;            // DTViewController将要展示通知。
extern NSString * const DTViewControllerDidAppearNotifications;             // DTViewController已经展示通知。
extern NSString * const DTViewControllerWillDisappearNotifications;         // DTViewController将要消失通知。
extern NSString * const DTViewControllerDidDisappearNotifications;          // DTViewController已经消失通知。
extern NSString * const UIApplicationDidReceiveNotificationResponse;        // App收到Notification时的通知名。
extern NSString * const UIApplicationNotificationResponseInfoResponseKey;   // 获取UIApplicationDidReceiveNotificationResponse通知的UserInfo中的response的key.
extern NSString * const DTFrameworkWillBootUpNotification;                  // 框架将要启动通知。

// 定义不建议使用时的警告提醒
#define ALIPAYWALLET_DEPRECATED_CLASS(version,msg)  __attribute__((deprecated(msg)))
