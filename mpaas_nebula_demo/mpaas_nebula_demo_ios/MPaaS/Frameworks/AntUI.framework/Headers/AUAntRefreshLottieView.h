//
//  AUAntRefreshLottieView.h
//  AntUI
//
//  Created by niki on 2019/2/27.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define     kRefreshHeight              62

typedef NS_ENUM(NSUInteger, AURefreshViewType) {
    AURefreshViewDefault,       // 页面内的刷新样式
    AURefreshViewTypeFeature1  // 用在带有一定背景的titlebar 如首页或者财富tab
};

// 蚂蚁下拉刷新专用lottie

@interface AUAntRefreshLottieView : UIView

/**
 蚂蚁下拉刷新动画LottieView
 */
@property (nonatomic, strong) UIView /*LOTAnimationView */ *antLottieView;

/*
 * @param type 小蚂蚁的状态
 * @param placeholderView 小蚂蚁的展位图，主要用于lottie加载异常时来展示
 */
- (instancetype)initWithLottieType:(AURefreshViewType)type;

// 下拉刷新文案
- (void)setupLabelText:(NSString *)text;

// 下拉字体颜色
// 如果设置为空，则还原字体颜色
- (void)setupLabelForeColor:(nullable UIColor *)color;

//
typedef void (^AnimateCompletionBlock)(BOOL animationFinished);

/**
 * 动态修改Type的方法
 * 为小程序提供
 * @param newType 新的Type类型
 * @param complete 切换完成的回调
 * 如果要目标type和目前type一致，complete不会调用
 */
- (void)changeType:(AURefreshViewType)type completion:(nullable void (^)())completion;

// 指定当前lottie从起始帧到结束帧播放，同时支持播放停下来时的回调，默认从指定帧数播放到结尾帧数
- (void)playWithStartFrame:(nonnull NSNumber *)startFrame
                completion:(nullable AnimateCompletionBlock)completion;

// 从当前帧播放到结尾帧
- (void)playFromCurrentToEndWithompletion:(nullable AnimateCompletionBlock)completion;

// 从lottie资源的第一帧播放到最后一帧
- (void)playFromStartFrameWithCompletion:(nullable AnimateCompletionBlock)completion;

// lottie视图动画的总帧数
- (NSNumber *)totalFrame;

// lottie视图动画当前在第几帧
- (NSNumber *)currentFrame;

// 下拉未松手时根据scrollview的偏移量来决定蚂蚁所在帧数
- (void)setAntProgressWithScrollViewOffset:(CGFloat)offset;

// 设置当前帧数
- (void)setProgressWithFrame:(NSNumber *)frame;

// 设置是否循环
- (void)setLoopAnimation:(BOOL)loop;

// 是否循环
- (BOOL)isLoopAnimation;

// 是否正在动画
- (BOOL)isAnimating;

// 停止动画
- (void)stop;

// 暂停动画
- (void)pause;

//
- (void)play;

@end

NS_ASSUME_NONNULL_END
