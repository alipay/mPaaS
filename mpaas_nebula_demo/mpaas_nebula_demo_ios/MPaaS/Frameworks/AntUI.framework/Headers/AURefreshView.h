#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_refreshLoadingView_AURefreshView//程序自动生成
//
//  AURefreshView.h
//  AntUI
//
//  Created by 莜阳 on 2017/11/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUAntRefreshLottieView.h"




//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aurefreshview
//#########################################################


typedef NS_ENUM(NSUInteger, AURefreshViewState) {
    AURefreshViewStateNomal = 0,    // 列表恢复为初始指定位置
    AURefreshViewStateBeginPulling = 1, // 用户开始下拉
    AURefreshViewStateLoading = 2,     // 触发用户RPC加载，列表contentInset设置在默认地方
    AURefreshViewStateFinishedLoading = 3, // RPC加载结束，列表contentInset即将恢复为原始默认的
    AURefreshViewStateBeginResetting = 4, // 列表contentInset正在开始恢复原始默认inset
};



@protocol AURefreshViewDelegate;
typedef void(^AURefreshCompletion)(void);

/**
 支付宝下拉刷新动画View
 */

@interface AURefreshView : UIView

@property (nonatomic, readonly) AURefreshViewState state;

@property (nonatomic, weak) id <AURefreshViewDelegate> delegate;

@property (nonatomic, assign,readonly) AURefreshViewType viewType;



/**
 下拉刷新动画Lottie控件
 */
@property (nonatomic, strong) UIView /*LOTAnimationView */ *lottieAnimationView;

/* 指定下拉刷新所在的父view，下拉刷新初始默认高度是scrollView的高度；默认将refreshView添加到父scrollView上
 * 默认初始frame为(0, 0 - scrollView.height, scrollView.width, scrollView.height)) */
- (instancetype)initWithSuperView:(UIScrollView *)scrollView
                             type:(AURefreshViewType)type
                          bizType:(NSString *)bizType;

// 下拉刷新文案
- (void)setupLabelText:(NSString *)text;

// 下拉字体颜色
// 如果设置为空，则还原字体颜色
- (void)setupLabelForeColor:(UIColor *)color;

// UIScrollView的delegate里面回调以下方法
- (void)auRefreshScrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;

// 业务调用以下方法告诉控件可以开始收起小蚂蚁了，但请注意：该方法只是开始收起动画，动画并没有立即结束，动画真正结束并且列表复位是在auRefreshViewDidFinishAnimation回调中。
- (void)auRefreshScrollViewDidFinishedLoading:(UIScrollView *)scrollView;

// 业务调用以下方法告诉控件可以开始收起小蚂蚁了，但请注意：该方法只是开始收起动画，动画并没有立即结束，动画真正结束之后的页面刷新操作请在completion中执行 （注明：即使是normal以下block仍会执行）
- (void)auRefreshScrollViewDidFinishedLoading:(UIScrollView *)scrollView completion:(AURefreshCompletion)completion;

// 需要业务方先滚动到初始位置，然后再调用自动下拉刷新，否则滚动会异常
- (void)autoPullRefreshScrollView:(UIScrollView *)scrollView;

//
- (void)pauseAnimation;

// 页面展开
- (void)resumeAnimation;

/**
 * 动态修改Type的方法
 * 为小程序提供
 * @param newType 新的Type类型
 * @param complete 切换完成的回调
 * 如果要目标type和目前type一致，complete不会调用
 */
-(void) changeType:(AURefreshViewType) newType completion:(void (^)(AURefreshView *view))complete;

@end

@protocol AURefreshViewDelegate <NSObject>

@optional
// 刚刚下拉到默认位置即(Lottie)View的高度时触发该协议
- (void)auRefreshViewDidTriggerloading:(AURefreshView *)view;
// 下拉刷新完成复位操作，RPC结束之后的页面刷新操作请确保在该回调中做
- (void)auRefreshViewDidFinishAnimation:(AURefreshView *)view;
- (void)auRefreshViewDidDidFinishAnimation:(AURefreshView *)view __deprecated_msg("废弃，业务请勿继续使用");

@end


#endif//程序自动生成
