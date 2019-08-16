#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUActionSheet//程序自动生成
//
//  AUWindowManager.h
//  AntUI
//
//  Created by QiXin on 2017/3/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AUWindowType) {
    AUWindowTypeNormal = 0,     // 普通 window
    AUWindowTypePopUp           // 弹层 window
};

@interface AUWindowManager : NSObject

+ (instancetype)sharedManager;
- (instancetype)init DEPRECATED_MSG_ATTRIBUTE("请使用 sharedManager 单例");

- (UIWindow *)dequeueWindowWithType:(AUWindowType)windowType;
- (void)enqueueWindow:(UIWindow *)window;

@end

@interface AUWindowViewController : UIViewController
@property (nonatomic, strong) UIView *backgroundView;
@end

#endif//程序自动生成
