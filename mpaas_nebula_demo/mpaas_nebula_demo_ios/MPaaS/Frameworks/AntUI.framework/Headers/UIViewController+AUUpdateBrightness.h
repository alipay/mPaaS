//
//  UIViewController+AUUpdateBrightness.h
//  AntUI
//
//  Created by 莜阳 on 2018/5/30.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (AUUpdateBrightness)

/**
 设置当前屏幕亮度值
 注意，调用该方法设置当前亮度到目标亮度值，前后台切换、页面切换的亮度设置和恢复需要业务自行处理
 @param targetBrightness 屏幕亮度需要设置的目标亮度值
 */
- (void)au_updateBrightness:(CGFloat)targetBrightness;

// 设置是否自动锁屏
- (void)au_resetIdleTimerDisabled:(BOOL)idleTimerDisabled;

@end
