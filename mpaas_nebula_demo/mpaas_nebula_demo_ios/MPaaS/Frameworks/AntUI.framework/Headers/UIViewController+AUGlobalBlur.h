//
//  UIViewController+AUGlobalMask.h
//  AntUI
//
//  Created by 莜阳 on 2018/6/6.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, AUGlobalBlurEffectStyle) {
    AUGlobalBlurEffectStyleDefault = 0, // 默认的毛玻璃效果
    AUGlobalBlurEffectStyleExtraMurky = 1,  // 毛玻璃效果非常模糊，适用场景：字体特别大，模糊效果需要非常明显的页面(如余额首页数字金额非常大)
};


@interface UIViewController (AUGlobalBlur)

@property (nonatomic, assign) AUGlobalBlurEffectStyle auBlurStyle;

@end
