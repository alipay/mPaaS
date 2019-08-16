//
//  H5AppDelegateEvent.h
//  NebulaBiz
//
//  Created by Glance on 2018/4/11.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kEvent_AppDelegate_Application_Create @"appdelgate.application.create"
#define kEvent_AppDelegate_LaunchMode_Decide @"appdelgate.launchmode.decide"// 监听该事件，可以调用preventDefault并修改`launchMode`，如果调用了preventDefault，则使用该事件轮询结束时的`launchMode`
#define kEvent_AppDelegate_shouldPresent @"appdelgate.application.shouldPresent"
#define kEvent_AppDelegate_didPresent @"appdelgate.application.didPresent"


@interface H5AppDelegateEvent : PSDEvent

@property (nonatomic, assign) DTMicroApplicationLaunchMode launchMode;
@property (nonatomic, weak) DTMicroApplication *app;
@property (nonatomic, strong) NSDictionary *launchOptions;
@property (nonatomic, weak) UINavigationController *navigationController;

+ (instancetype)appCreateAfterEvent:(DTMicroApplication *)app;

+ (instancetype)LaunchModeEvent:(DTMicroApplicationLaunchMode)launchMode
                    application:(DTMicroApplication *)app
                         params:(NSDictionary *)launchOptions;

+ (instancetype)shouldPresentEvent:(UINavigationController *)navigationController
                       application:(DTMicroApplication *)app
                            params:(NSDictionary *)launchOptions;

+ (instancetype)didPresentEvent:(DTMicroApplication *)app
                         params:(NSDictionary *)launchOptions;


@end
