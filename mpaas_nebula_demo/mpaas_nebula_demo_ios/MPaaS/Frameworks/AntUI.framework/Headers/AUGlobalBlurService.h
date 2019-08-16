//
//  GlobalMaskService.h
//  BlurredView
//
//  Created by ouxi on 2018/5/4.
//  Copyright © 2018年 ouxi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUGlobalBlurService : NSObject // <DTService>

+ (instancetype)blurService;

- (void)startService;
@property(nonatomic, strong) NSMutableArray* maskViews;

@end


// 支持业务定制化底部安全提示的图标和文案
@interface AUGlobalBlurService (AUCustomSafeTip)
// 定制化安全感提示icon
- (UIImage *)au_safeTipCustomIcon;

// 定制化安全感提示文案
- (NSString *)au_safeTipCustomText;

// 隐藏整条安全感提示条
- (BOOL)au_isHideSafeTipView;

@end
