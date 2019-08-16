//
//  APNextPagePullView.h
//  APCommonUI
//
//  Created by zikong on 14-1-20.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APNextPagePullView;
@protocol APNextPagePullViewDelegate <NSObject>

- (BOOL)isTableViewLoadingNextPage:(APNextPagePullView *)pullView;

/**
 *  上拉触发菊花转动的回调方法
 *
 *  @param pullView 上拉刷新view
 */
- (void)upPullTableDidTriggerRefresh:(APNextPagePullView *)pullView;

@end


@interface APNextPagePullView : UIView

/**
 *  如果不到一屏，tableview下拉也会触发loading；如果不希望这样，设置这个属性为NO。
 */
@property(nonatomic, assign) bool downPullInvalid;

/**
 *  上拉刷新代理
 */
@property(nonatomic, weak) id delegate;

/**
 *  底部加载标签
 */
@property(nonatomic, strong)UILabel *tipLabel;

/**
 *  滚动列表时,改变APNextPagePullView的状态
 *
 *  @param scrollView 滚动的列表
 */
- (void)refreshScrollViewDidScroll:(UIScrollView *)scrollView;

/**
 *  停止触摸列表时,改变APNextPagePullView的状态
 *
 *  @param scrollView 滚动的列表
 */
- (void)refreshScrollViewDidEndDragging:(UIScrollView *)scrollView;

/**
 *  数据源加载完成时，改变APNextPagePullView的状态
 *
 *  @param scrollView 滚动的列表
 */
- (void)refreshScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;

/**
 *  数据源加载完成时，推迟改变APNextPagePullView的状态，以免闪屏
 *
 *  @param scrollView 滚动的列表
 */
- (void)refreshScrollViewDataSourceDidFinishedLoadingAndDelay:(UIScrollView *)scrollView;

@end
