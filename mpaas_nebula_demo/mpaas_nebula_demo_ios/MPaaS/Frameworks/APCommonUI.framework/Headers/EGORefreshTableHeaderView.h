//
//  EGORefreshTableHeaderView.h
//  Demo
//

#import <UIKit/UIKit.h>
#import <AntUI/AntUI.h>
//#import <QuartzCore/QuartzCore.h>
//#import <AntUI/AUPullLoadingView.h>

__deprecated_msg("EGORefreshTableHeaderDelegate 已经废弃，请直接使用 AURefreshLoadingViewDelegate")
@protocol EGORefreshTableHeaderDelegate <AURefreshLoadingViewDelegate>
@end

//__deprecated_msg("EGOPullDirection 已经废弃，请直接使用 AUEGOPullDirection")
//typedef AUEGOPullDirection EGOPullDirection;
//
//__deprecated_msg(" EGOPullRefreshState 已经废弃，请直接使用 AUEGOPullRefreshState")
//typedef AUEGOPullRefreshState EGOPullRefreshState;

__deprecated_msg("EGORefreshTableHeaderView 已经废弃，请直接使用 AUPullLoadingView")
@interface EGORefreshTableHeaderView : AUPullLoadingView

@end

