//
//  AUBrightnessService.h
//  AntUI
//
//  Created by 莜阳 on 2018/5/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


#define kAUSourceBrightness                  @"AUSourceBrightness"
#define kAUTargetBrightness                  @"AUTargetBrightness"
#define kAUIsRiseupBrightness                @"kAUIsRiseupBrightness"

#define AUScreenMaxBrightness   0.85
#define AU_BRIGHTNESS_TIME_STEP  0.016 //0.016
#define AU_BRIGHTNESS_STEP  0.025 //0.02

#define AU_ApplicationWillResignActiveNotification @"AU_ApplicationWillResignActiveNotification"
#define AU_UIApplicationDidBecomeActiveNotification @"AU_UIApplicationDidBecomeActiveNotification"

typedef NS_ENUM(NSInteger, AUBrightnessState) {
    AUBrightnessStateNone = 0,  //
    AUBrightnessStateIncrease = 1, // 当前是调高亮度状态
    AUBrightnessStateDecrease = 2, // 当前是调低亮度状态
};

@interface AUBrightnessService : NSObject
{
    NSTimer *_timer;
    NSMutableArray *_brightnessList;
    AUBrightnessState _state;
    BOOL _isRiseup; // 标记最近一次是升还是降
}

// 记录下最近一次的起始亮度值
@property (nonatomic, assign) CGFloat latestSourceBrightness; // 最近一次的起始值
@property (nonatomic, assign) CGFloat latestTargetBrightness; // 最近一次的目标值

+ (AUBrightnessService *)brightnessService;

//
- (void)updateCurrentState:(AUBrightnessState)state;

// 销毁定时器资源
- (void)destroyTimer;

// 调节屏幕亮度
- (void)startTimerWithSourceValue:(CGFloat)sourceValue
                      targetValue:(CGFloat)targetValue
                         isRiseup:(BOOL)isRiseup;

// 判断当前是否有页面正在降低亮度
- (BOOL)isDecreaseBrightness;

// 判断当前是否有页面正在点亮亮度
- (BOOL)isIncreaseBrightness;

@end
