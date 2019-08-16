//
//  APBaseLoadingView.h
//  APMobileFramework
//
//  Created by liangbao.llb on 2017/8/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^DFLoadingPageAnimaCompleteBlock)();

@protocol APBaseLoadingViewDelegate;

@interface APBaseLoadingView : UIView

@property (nonatomic, strong) UIImageView   *iconImageView;
@property (nonatomic, strong) UILabel       *titleLabel;
@property (nonatomic, strong) UIPageControl *pageControl;
@property (nonatomic, assign) BOOL          isFirstStop; // 标识是否是stopLoading方法被先执行的。
@property (nonatomic, assign) BOOL          isLoading;
@property (nonatomic, weak) id<APBaseLoadingViewDelegate> delegate;

/**
 *  开始显示Loading 动画。注意：要主线程调用，否则无效。
 */
- (void)startLoading;

/**
 *  停止显示Loading 动画。注意：要主线程调用，否则无效。
 */
- (void)stopLoading;

/**
 *  执行页面将要推出动画。注意：要主线程调用，否则无效。
 *
 * @param completeBlock 动画完成block
 */
- (void)viewWillStopLoading:(void (^)(void))completeBlock;

/**
 *  更新loading 状态。
 *  注意：要主线程调用，否则无效；
 *       title和icon不能为nil；
 */
- (void)updateStatusWithTitle:(NSString *)title icon:(UIImage *)icon;

/**
 更新slogan

 @param slogan 新的slogan
 */
- (void)updateSlogan:(NSString *)slogan;

@end
