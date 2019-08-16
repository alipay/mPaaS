//
//  PPSearchBar.h
//  PPSearchDisplayController
//
//  Created by chenwenhong on 14-6-7.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#define PPSearchBarDelegate APSearchBarDelegate

@protocol APSearchBarDelegate;

/**
 *  用于展示APSearchBar，frame需要自己设置，高度为44
 */
@interface APSearchBar : UIView

@property(nonatomic, strong) UITextField            *searchTextField;
@property(nonatomic, copy) NSString                 *text;                  // 搜索框展示的文字，default is nil
@property(nonatomic, strong) UIColor                *textColor;             // 文字颜色
@property(nonatomic, strong) UIColor                *placeHolderTextColor;  // 占位符文字颜色
@property(nonatomic, strong) UIFont                 *font;                  // 文字的字体
@property(nonatomic, copy) NSString                 *placeholder;           // 占位符文字，default is nil
@property(nonatomic, assign) NSUInteger         backgroundCornerRadius;    // 背景的圆角
@property(nonatomic, strong) UIColor *          backgroundImageColor;      // 搜索框内背景的颜色
@property(nonatomic, strong) UIColor *          backgroundViewColor;       // 搜索框外背景的颜色
@property(nonatomic, strong) UIColor *          tintColor;                 // 光标和按钮的颜色
@property(nonatomic) BOOL                       showsCancelButton;      // 是否展示取消按钮，default is NO
@property(nonatomic) BOOL                       markedTextDidChange;      // 输入处于高亮状态TextDidChange不触发
@property(nonatomic) BOOL                       isAnimation;               //是否显示动画
@property(nonatomic) BOOL                       isAnimationing;            //是否处于动画过程中


@property(nonatomic, weak) id<APSearchBarDelegate>  delegate;
@property(nonatomic, strong) UIButton *cancelBtn;

- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;

- (void)cancelSearch;

@end


/**
 *  APSearchBar delegate
 */
@protocol APSearchBarDelegate <NSObject>

@optional
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;                      // 返回NO时，textfield不可以编辑
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;                        // 返回NO时，textfield不会resignFirstResponder

- (void)searchBarTextDidBeginEditing:(APSearchBar *)searchBar;                     // called when text starts editing
- (void)searchBarTextDidEndEditing:(APSearchBar *)searchBar;                       // called when text ends editing
- (void)searchBar:(APSearchBar *)searchBar textDidChange:(NSString *)searchText;   // called when text changes (including clear)
- (BOOL)searchBar:(APSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text NS_AVAILABLE_IOS(3_0); // called before text changes

- (void)searchBarSearchButtonClicked:(APSearchBar *)searchBar;                     // called when keyboard search button pressed
- (void)searchBarBookmarkButtonClicked:(APSearchBar *)searchBar;                   // called when bookmark button pressed
- (void)searchBarCancelButtonClicked:(APSearchBar *) searchBar;                    // called when cancel button pressed
- (void)searchBarResultsListButtonClicked:(APSearchBar *)searchBar NS_AVAILABLE_IOS(3_2); // called when search results button pressed

- (BOOL)textFieldShouldClear:(UITextField *)textField;

@end
