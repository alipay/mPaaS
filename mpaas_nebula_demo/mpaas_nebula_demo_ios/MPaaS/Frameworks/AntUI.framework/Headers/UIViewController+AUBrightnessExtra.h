//
//  UIViewController+AUBrightnessExtra.h
//  AntUI
//
//  Created by 莜阳 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (AUBrightnessExtra)

/* 恢复屏幕亮度接口
 说明：1.一般业务不需要主动调用该接口，程序会在viewWillDisappear方法之后自动调用该方法
      2.当业务需要在viewWillDisappear之前恢复屏幕亮度，请手动调用该方法
 */
- (void)au_decreaseBrightness;


/**
 带目标亮度值的调高屏幕亮度方法
 请注意：1.当业务所需默认屏幕亮度目标值不是0.85时才需要调用此接口，否则请调用au_increaseBrightness接口
 
 @param brightness target brightness (0.1 ~ 1.0)
 */
- (void)au_increaseBrightness:(CGFloat)brightness;

@end
