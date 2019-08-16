#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Search_AUSearchController//程序自动生成
//
//  AUSearchDisplayViewController.h
//  AntUI
//
//  Created by niki on 16/11/22.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUSearchBar.h"

#define UI_AUSearchController

@class AUSearchController;

//
@protocol AUSearchControllerDelegate <NSObject>

@optional
// 当展示/隐藏AUSearchControllerDelegate的回调
- (void)AUSearchControllerDelegateWillBeginSearch:(AUSearchController *)controller;
- (void)AUSearchControllerDelegateDidBeginSearch:(AUSearchController *)controller;
- (void)AUSearchControllerDelegateWillEndSearch:(AUSearchController *)controller;
- (void)AUSearchControllerDelegateDidEndSearch:(AUSearchController *)controller;

// 点击蒙层
//- (void)didClickMaskView:(AUSearchController *)searchController;

@end


//
@interface AUSearchController : NSObject

@property(nonatomic, weak) id<AUSearchControllerDelegate>              delegate;
@property(nonatomic, getter=isActive) BOOL                          active;                     // 是否可点击，当正在搜索时或者动画过程中，默认为不可点击
@property(nonatomic, readonly) AUSearchBar                          *searchBar;                 // 包含的seacherBar
@property(nonatomic, weak, readonly) UIViewController               *searchResultsController;  // searchController的宿主VC (通常是 UITableViewController)
@property(nonatomic, readonly) UITableView                          *searchResultsTableView;    // 搜索结果的tableView，默认会返回一个，需要的话可以自定义
/*
 *  初始化一个APAUSearchControllerDelegate
 *
 *  @param searchBar      创建的searchBar
 *  @param viewController 展示结果的VC
 *
 *  @return APAUSearchControllerDelegate
 */
- (id)initWithSearchBar:(AUSearchBar *)searchBar searchResultsController:(UIViewController *)viewController;

- (void)setActive:(BOOL)visible animated:(BOOL)animated; // animate the view controller for searching

- (void)handleTap;

@end

#endif//程序自动生成
