//
//  AUIUtilShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// AntUI组件内部i依赖的第三方配置

@interface AUIUtilShell : NSObject

@property (nonatomic, weak) UIWindow *dialogBackWindow;

/*
 通知协议 (AUCardMenu/AUFloatMenu)
 */

/*
 AUCardMenu 注册退出登录的通知，保证退出登录AUCardMenu能够及时销毁
 */
+ (NSString *)cardMenuDismissNotiName;


/*
 AUFloatMenu 注册alerView kShareTokenAlertViewShownNotification
 */
+ (NSString *)floatMenuDismissFromAlertNotiName;

/*
 AUFloatMenu 注册alerView SALoginAppWillStartNotification
 */
+ (NSString *)floatMenuDismissFromLoginNotiName;


/**
 Dialog Window 即将展示
 */
+ (void)dialogWindowWillShow;

/**
 Dialog Window 即将消失
 */
+ (void)dialogWindowDidDismiss;

/**
 Dialog 配置开关，当开关打开的时候同时检测 delegate 是否实现了系统的，避免有些业务只是简单替换名称而忘记替换 delegate 的情况
 */
//+ (BOOL)dialogConfigerService;


//是否有关键业务正在执行，阻止弹窗
+ (BOOL)preventWindowPopup;

//
+ (NSArray<NSString *> *)notificationsForQueueWindows;

+ (NSArray<NSString *> *)notificationsForPopWindows;

@end

NS_ASSUME_NONNULL_END
