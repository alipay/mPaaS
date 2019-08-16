//
//  AUCustomRefreshView.h
//  AntUI
//
//  Created by jinzhidong on 2018/12/4.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

// 自定义下拉刷新view的状态
typedef NS_ENUM(NSUInteger, AUCustomRefreshViewState) {
    AUCustomRefreshViewStateNomal = 0,          // 自定义下拉刷新view为初始指定位置
    AUCustomRefreshViewStateOpen = 1,           // 自定义下拉刷新view为展开状态
    AUCustomRefreshViewStateBeginPulling = 2,   // 自定义下拉刷新view为下拉过程中
};

@protocol AUCustomRefreshViewDelegate;
typedef void(^AUCustomRefreshCompletion)(void);

/**
 自定义下拉刷新动画View
 10.1.52版本首页定制：view由业务提供，AUCustomRefreshView只负责动画
 */
@interface AUCustomRefreshView : UIView
// 控件的状态
@property (nonatomic, readonly) AUCustomRefreshViewState state;
// 控件相关事件的回调
@property (nonatomic, weak) id <AUCustomRefreshViewDelegate> delegate;

/**
 初始化自定义下拉刷新view：指定下拉刷新所在的父view，下拉刷新初始默认高度是scrollView的高度；默认将refreshView添加到父scrollView上
 
 @param scrollView 下拉刷新所在的父view
 @param customView 自定义view
 @param bizType 业务标识
 @return 下拉刷新view
 */
- (instancetype)initWithSuperView:(__kindof UIScrollView *)scrollView
                       customView:(__kindof UIView *)customView
                          bizType:(NSString *)bizType;

/**
 初始化自定义下拉刷新view：指定下拉刷新所在的父view，下拉刷新初始默认高度是scrollView的高度；默认将refreshView添加到父scrollView上
 
 @param scrollView 下拉刷新所在的父view
 @param customView 自定义view
 @param marginBottom 下拉刷新view下的空白距离（进度条需要贴着下一个view）
 @param bizType 业务标识
 @return 下拉刷新view
 */
- (instancetype)initWithSuperView:(__kindof UIScrollView *)scrollView
                       customView:(__kindof UIView *)customView
                     marginBottom:(CGFloat)marginBottom
                          bizType:(NSString *)bizType;

/**
 UIScrollView的delegate里面回调以下方法
 */
- (void)auRefreshScrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;
- (void)auRefreshscrollViewWillEndDragging:(UIScrollView *)scrollView
                              withVelocity:(CGPoint)velocity
                       targetContentOffset:(inout CGPoint *)targetContentOffset;
/**
 打开自定义刷新view

 @param animated 是否需要动画
 */
- (void)openCustomRefreshView:(BOOL)animated completion:(void(^)())completion;

/**
 关闭自定义刷新view
 
 @param animated 是否需要动画
 */
- (void)closeCustomRefreshView:(BOOL)animated completion:(void(^)())completion;

@end

@protocol AUCustomRefreshViewDelegate <NSObject>

@optional
// 下拉刷新控件在全部展开状态下的回调，首页卡片会根据rpc的生命周期去重，在展开状态下，只会回调一次
- (void)auRefreshViewDidTriggerloading:(AUCustomRefreshView *)view;
// 当刷新控件被收起时回调给首页卡片,告诉首页卡片刷新控件已收起（为了跟AURefreshView一致，后续看情况修改）
- (void)auRefreshViewDidFinishAnimation:(AUCustomRefreshView *)view;

@end
