//
//  ScreenClassify.h
//  APCrashReporter
//
//  Created by NianXi on 2017/8/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef ScreenClassify_h
#define ScreenClassify_h
#include <stdio.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ScreenClassifyType) {
    ScreenClassifyTypeBlack,
    ScreenClassifyTypeWhite,
    ScreenClassifyTypeGray,
    ScreenClassifyTypeUnknown
};

ScreenClassifyType checkScreenshot(UIImage* screenshot);
#endif /* ScreenClassify_h */
