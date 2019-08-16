//
//  APThemeScreenCategory.h
//  APCommonUI
//
//  Created by shenmo on 10/10/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, APThemeScreenCategory)
{
    APThemeScreenNone = 0,
    APThemeScreenPadLow,        // 非Retina的iPad
    APThemeScreenPadRetina,
    APThemeScreenPhoneLow,      // 非Retina的iPhone
    APThemeScreenPhone4,
    APThemeScreenPhone5,
    APThemeScreenPhone6,
    APThemeScreenPhone6p,
};

//// 当前设备的屏幕类型
//extern APThemeScreenCategory APDeviceScreenCategory();


static APThemeScreenCategory APDeviceScreenCategory()
{
    static APThemeScreenCategory thisScreen = APThemeScreenNone;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
        {
            thisScreen = ([UIScreen mainScreen].scale == 1.0f) ? APThemeScreenPadLow : APThemeScreenPadRetina;
        }
        else if ([UIScreen mainScreen].scale == 1.0f)
        {
            thisScreen = APThemeScreenPhoneLow;
        }
        else
        {
            CGFloat screenHeight = [[UIScreen mainScreen] bounds].size.height;
            if (screenHeight == 480)
                thisScreen = APThemeScreenPhone4;
            else if (screenHeight == 568)
                thisScreen = APThemeScreenPhone5;
            else if (screenHeight == 667)
                thisScreen = APThemeScreenPhone6;
            else if (screenHeight >= 736)
                thisScreen = APThemeScreenPhone6p;
            else
                thisScreen = APThemeScreenPhoneLow;
        }
    });
    
    return thisScreen;
}
