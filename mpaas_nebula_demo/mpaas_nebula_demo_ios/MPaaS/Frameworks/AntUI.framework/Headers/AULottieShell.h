//
//  AULottieShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^LottieSetupBlock)(NSError *error, UIView *lottieView);
typedef void (^LOTAnimationCompletionBlock)(BOOL animationFinished);

@interface AULottieShell : NSObject
// lottie视图同步加载
+ (UIView *)lottieViewWithFilePath:(NSString *)filePath;

// lottie视图异步加载
+ (void)lottieViewWithFilePath:(NSString *)filePath
                    completion:(LottieSetupBlock)completion;

+ (BOOL)lottieViewIsAnimationPlaying:(UIView *)lottieView;

//
+ (void)lottieViewSetLoopAnimation:(UIView *)lottieView animation:(BOOL)animation;
//
//+ (CGFloat)lottieViewAnimationProgress:(UIView *)lottieView;

//
//+ (void)lottieViewSetAnimationProgress:(UIView *)lottieView
//                              progress:(CGFloat)progress;
//
//+ (void)lottieViewPlayFromProgress:(UIView *)lottieView
//                     beginProgress:(CGFloat)beginProgress
//                       endProgress:(CGFloat)endProgress;

//
+ (void)lottieViewSetProgress:(UIView *)lottieView withFrame:(NSNumber *)currentFrame;

//+ (void)lottieView:(UIView *)lottieView
//        startFrame:(nonnull NSNumber *)startFrame
//           toFrame:(nonnull NSNumber *)toEndFrame;
//
+ (NSNumber *)lottieViewTotalFrame:(UIView *)lottieView;

//
+ (NSNumber *_Nullable)getLottieViewCurrentFrame:(UIView *_Nullable)lottieView;

//+ (void)lottieView:(UIView *_Nullable)lottieView
//       playToFrame:(nonnull NSNumber *)toFrame
//    withCompletion:(nullable LOTAnimationCompletionBlock)completion;

+ (void)lottieView:(UIView *)lottieView
playWithStartFrame:(nonnull NSNumber *)startFrame
           toFrame:(nonnull NSNumber *)toEndFrame
    withCompletion:(nullable LOTAnimationCompletionBlock)completion;

//+ (BOOL)lottieViewReadFileFail:(UIView *_Nullable)lottieView;

//
+ (BOOL)lottieViewIsLoopAnimation:(UIView *_Nullable)lottieView;


@end



NS_ASSUME_NONNULL_END
