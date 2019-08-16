//
//  VCPreviewViewContainer.h
//  APMultimedia
//
//  Created by aspling on 16/1/19.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+APMGaussianBlur.h"

typedef void (^APMVideoPreviewAnimationCompleteBlock)(BOOL finish);
typedef void (^APMVideoPreviewAnimationStartBlock)();

#if __IPHONE_OS_VERSION_MAX_ALLOWED < 100000
@interface APMVideoPreviewViewContainer : UIView
#else
@interface APMVideoPreviewViewContainer : UIView <CAAnimationDelegate>
#endif

@property (nonatomic, weak) UIView *previewView;//weak属性，避免持有外部view，导致外部类释放不了
@property (nonatomic, strong) UIView *tipsView;// 各种tips
@property (nonatomic, assign) CGSize sizeOfTipsView;
@property (nonatomic, copy) APMVideoPreviewAnimationCompleteBlock animationFinishBlock;
@property (nonatomic, copy) APMVideoPreviewAnimationStartBlock animationStartBlock;

- (void)blur;
- (void)showBlur;
- (void)hideBlur;
@end
