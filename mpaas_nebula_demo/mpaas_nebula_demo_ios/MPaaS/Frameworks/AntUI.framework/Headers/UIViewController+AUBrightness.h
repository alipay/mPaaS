//
//  ViewController+AUBrightness.h
//  AntUI
//
//  Created by 莜阳 on 2018/3/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (AUBrightness)

/* 调高屏幕亮度
 说明：1.在ViewDidAppear之前调用该方法，点亮效果在VC触发到ViewDidAppear之后生效
      2.在ViewDidAppear之后调用该方法，点亮效果立即生效
      3.屏幕亮度会在viewWillDisappear之后自动恢复
      4.如果业务需要在viewWillDisappear之前恢复屏幕亮度，请主动调用au_decreaseBrightness方法，否则业务不用关心亮度恢复
      5.当前默认屏幕亮度值为0.85，如果需要显性设置屏幕亮度值请调用au_increaseBrightness:方法
 */
- (void)au_increaseBrightness;

@end



