#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_refreshLoadingView_AUPullLoadingView//程序自动生成
//
//  EGORefreshTableHeaderView.h
//  Demo
//
//  Created by Devin Doty on 10/14/09October14.
//  Copyright 2009 enormego. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "AULoadingIndicatorView.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aupullloadingview
//#########################################################


#define UI_AUPullLoadingView

typedef enum {
    AUEGOPullingDown = 1000,
    AUEGOPullingUp,
//    去掉，Mpaas那边会和第三方冲突
//    EGOPullingDown  __attribute__((deprecated)) = AUEGOPullingDown,//1000,
//    EGOPullingUp    __attribute__((deprecated)) = AUEGOPullingUp
} AUEGOPullDirection;

typedef enum{
	AUEGOOPullRefreshPulling = 0,
	AUEGOOPullRefreshNormal,
	AUEGOOPullRefreshLoading,
//    去掉，Mpaas那边会和第三方冲突
//    EGOOPullRefreshPulling __attribute__((deprecated)) = AUEGOOPullRefreshPulling,
//    EGOOPullRefreshNormal __attribute__((deprecated))  = AUEGOOPullRefreshNormal,
//    EGOOPullRefreshLoading __attribute__((deprecated)) = AUEGOOPullRefreshLoading,
} AUEGOPullRefreshState;

//@class AULoadingIndicatorView;
@protocol AURefreshLoadingViewDelegate;
/*！
 @class       AURefreshLoadingView
 @abstract    UIView
 @discussion  从第三方EGORefreshTableHeaderView，迁移过来的，命名统一而已，功能下拉、上拉加载更多的view
 */

@interface AUPullLoadingView : UIView {
	
	__weak id _delegate;
	AUEGOPullRefreshState _state;

	UILabel *_lastUpdatedLabel;
	UILabel *_statusLabel;
//    APActivityIndicatorView *_activityView;
    AUEGOPullDirection _pullDirection;
    
    BOOL    isAutoPullFlag;
}
@property(nonatomic, strong) AULoadingIndicatorView *activityView;

/**
 *  上拉加载时，设置初始状态文案信息，默认为“上拉加载更多”，显示
 *
 *  @param tip tips内容
 *
 */
- (void)setPullUp:(NSString *)tip;

/**
 *  下拉刷新时，设置初始状态文案信息，默认为“下拉刷新”。不显示
 *
 *  @param tip tips内容
 *
 */
- (void)setPullDown:(NSString *)tip;

/**
 *  设置松手后loading过程中的文案信息，默认为“加载中”。  
 *  注意：默认下拉刷新时不显示，上拉加载时显示
 *
 *  @param tip tips内容
 *
 */
- (void)setLoading:(NSString *)tip;

/**
 *  提示用户可以放手的文案信息，默认为“释放即可刷新”
 *
 *  @param tip tips内容
 *
 */
- (void)setRelease:(NSString *)tip;

/**
 *  是否显示上次刷新信息的文案，默认不显示
 *
 *  @param isOpen YES表示显示
 *
 */
- (void)ShowLastPullDate:(BOOL)isOpen;

/**
 *  是否显示加载状态信息的文案。
 *  
 *  默认：下拉刷新时不显示，上拉加载时，显示文案“加载中”
 *
 *  @param isShow YES表示显示
 *
 */
- (void)ShowStatusLabel:(BOOL)isShow;

- (void)setDateFormat:(NSDateFormatter *)dateFromatter;

- (void)setAutoPull:(BOOL)isAutoPull;

@property(nonatomic,weak) id <AURefreshLoadingViewDelegate> delegate;

- (void)refreshLastUpdatedDate;
- (void)egoRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;
- (void)egoRefreshScrollViewDataSourceDidFinishedLoadingWithoutUpdate:(UIScrollView *)scrollView;

- (void)autoUpdateScrollView:(UIScrollView *)scrollView;

#pragma Mark -- for LegacySystem not recommend
@property(nonatomic,assign) AUEGOPullRefreshState state;
@property(nonatomic,retain) NSString *statusText;
@property (nonatomic, retain) UILabel *lastUpdatedLabel;
@property (nonatomic, retain) UILabel *statusLabel;

- (void)setCurrentDate;

@end

@protocol AURefreshLoadingViewDelegate
- (void)egoRefreshTableHeaderDidTriggerRefresh:(AUPullLoadingView*)view;
- (BOOL)egoRefreshTableHeaderDataSourceIsLoading:(AUPullLoadingView*)view;
@optional
- (NSDate*)egoRefreshTableHeaderDataSourceLastUpdated:(AUPullLoadingView*)view;
@end

#endif//程序自动生成
