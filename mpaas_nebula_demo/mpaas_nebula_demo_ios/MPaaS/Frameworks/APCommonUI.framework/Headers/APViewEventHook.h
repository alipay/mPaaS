//
//  APViewEventHook.h
//  APCommonUI
//
//  Created by WenBi on 14-1-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol APViewEventHook <NSObject>

- (BOOL)beginTrackingWithTouch:(UITouch *)touch event:(UIEvent *)event;
- (BOOL)continueTrackingWithTouch:(UITouch *)touch event:(UIEvent *)event;
- (void)endTrackingWithTouch:(UITouch *)touch event:(UIEvent *)event;
- (void)cancelTrackingWithEvent:(UIEvent *)event;

@end
