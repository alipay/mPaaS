//
//  DTMicroApplicationLaunchMode.h
//  MobileFramework
//
//  Created by WenBi on 13-6-17.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

// App的rootViewController启动时的展示方式
typedef NS_ENUM(NSInteger, DTMicroApplicationLaunchMode) {
	kDTMicroApplicationLaunchModeClearTop,              // 保留定义，暂时不支持。
	kDTMicroApplicationLaunchModePushWithAnimation,     // 有动画的Push方式展示。
	kDTMicroApplicationLaunchModePushNoAnimation,       // 无动画的Push方式展示。
	kDTMicroApplicationLaunchModePresentWithAnimation,  // 有动画的Present方式展示。
	kDTMicroApplicationLaunchModePresentNoAnimation,    // 无动画的Present方式展示。
    kDTMicroApplicationLaunchModeFlipFromLeft,          // 左侧弹出的Push方式展示。
    kDTMicroApplicationLaunchModeFlipFromRight,         // 右侧弹出的Push方式展示。
};