//
//  RecorderFocusView.h
//  APMultimedia
//
//  Created by Cloud on 15/9/10.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 100000
@interface APMRecorderFocusView : UIView
#else
@interface APMRecorderFocusView : UIView <CAAnimationDelegate>
#endif

@property (nonatomic, assign) CGFloat largestLength;
@property (nonatomic, assign) CGFloat smallestLength;

- (void)show;

@end
