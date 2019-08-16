//
//  PPSearchDisplayController.h
//  PPSearchDisplayController
//
//  Created by chenwenhong on 14-6-7.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#define PPk_notifySearchBarResignFirstResponder @"kNotificationPPSearchBarResignFirstResponder"
#define PPk_notifySearchBarBecomeFirstResponder @"kNotificationPPSearchBarBecomeFirstResponder"

@class APSearchBar;

@protocol APSearchDisplayControllerDelegate;

/**
 *  3个view之间的切换
 */
typedef enum {
    APSearchShowDimming,        //遮罩层，进入searchVC默认的背景view
    APSearchShowAutoComplete,   //自动完成的tableView
    APSearchShowSearching       //点了查询按钮后的tableView
}APSearchShow;


/**
 *  APSearchDisplayController，用于展示搜索结果以及自动提示的结果
 */
@interface APSearchDisplayController : NSObject

@property(nonatomic, weak) id<APSearchDisplayControllerDelegate>    delegate;
@property(nonatomic, getter=isActive) BOOL                          active;                     // 是否可点击，当正在搜索时或者动画过程中，默认为不可点击
@property(nonatomic, readonly) APSearchBar                          *searchBar;                 // 包含的seacherBar
@property(nonatomic, weak, readonly) UIViewController               *searchContentsController;  // searchController的宿主VC (通常是 UITableViewController)
@property(nonatomic, readonly) UITableView                          *searchResultsTableView;    // 搜索结果的tableView，默认会返回一个，需要的话可以自定义
@property(nonatomic, readonly) UITableView                          *autoCompleteTableView;     // 自动完成的tableView，默认会返回一个，需要的话可以自定义

@property(nonatomic, readonly) UITapGestureRecognizer *dimmingTapRecognizer;

/**
 *  初始化一个APSearchDisplayController
 *
 *  @param searchBar      创建的searchBar
 *  @param viewController 展示结果的VC
 *
 *  @return APSearchDisplayController
 */
- (id)initWithSearchBar:(APSearchBar *)searchBar contentsController:(UIViewController *)viewController;

- (void)setActive:(BOOL)visible animated:(BOOL)animated; // animate the view controller for searching

/**
 *  显示指定搜索的view
 *
 *  @param show 展示的view的enum
 */
- (void)showView:(APSearchShow)show; //

@end

/**
 *  APSearchDisplayControllerDelegate
 */
@protocol APSearchDisplayControllerDelegate <NSObject>

/**
 *  阴影层，初始化的时候展示的背景view，自定义可以改变颜色、展示默认的推荐或者其他需求
 */
- (UIView*)dimmingView;

/**
 *  搜索文字改变的回调
 *
 *  @param searchBar  搜索文字所属的APSearchBar
 *  @param searchText 搜索的文字
 */
- (void)searchBar:(APSearchBar *)searchBar textDidChange:(NSString *)searchText;

/**
 *  点击搜索按钮，通常用于改变数据源，reload searchResultsTableView的datasoure
 *
 *  @param searchBar 搜索所属的APSearchBar
 */
- (void)searchBarSearchButtonClicked:(APSearchBar *)searchBar;

/**
 *  点击取消搜索按钮，通常用来清空所有的数据源，reload 所有的结果tableview
 *
 *  @param searchBar 搜索所属的APSearchBar
 */
- (void)searchBarCancelButtonClicked:(APSearchBar *)searchBar;


@optional


- (BOOL)searchBar:(APSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (BOOL)textFieldShouldClear:(UITextField *)textField;

// 当展示/隐藏searchDisplayController的回调
- (void)searchDisplayControllerWillBeginSearch:(APSearchDisplayController *)controller;
- (void)searchDisplayControllerDidBeginSearch:(APSearchDisplayController *)controller;
- (void)searchDisplayControllerWillEndSearch:(APSearchDisplayController *)controller;
- (void)searchDisplayControllerDidEndSearch:(APSearchDisplayController *)controller;

// 当加载/卸载搜索结果tableview时的回调
- (void)searchDisplayController:(APSearchDisplayController *)controller didLoadSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(APSearchDisplayController *)controller willUnloadSearchResultsTableView:(UITableView *)tableView;

// 当加载/卸载搜索结果tableview时的回调
- (void)searchDisplayController:(APSearchDisplayController *)controller willShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(APSearchDisplayController *)controller didShowSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(APSearchDisplayController *)controller willHideSearchResultsTableView:(UITableView *)tableView;
- (void)searchDisplayController:(APSearchDisplayController *)controller didHideSearchResultsTableView:(UITableView *)tableView;

// return YES to reload table. called when search string/option changes. convenience methods on top PPSearchBar delegate methods
- (BOOL)searchDisplayController:(APSearchDisplayController *)controller shouldReloadTableForSearchString:(NSString *)searchString;
- (BOOL)searchDisplayController:(APSearchDisplayController *)controller shouldReloadTableForSearchScope:(NSInteger)searchOption;
- (BOOL)searchDisplayController:(APSearchDisplayController *)controller shouldShowDimmingViewWhenSearchTextLengthIsZero:(BOOL)isZero;// called when search text didchanged

@end
