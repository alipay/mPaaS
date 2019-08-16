#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Search_AUSearchBar//程序自动生成
//
//  AUSearchBar.h
//  AUlobalSearch
//
//  Created by zikong on 15/4/22.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_ausearchbar
//#########################################################


#define UI_AUSearchBar

@class AUSearchBar;

@protocol AUSearchBarDelegate <NSObject>

@optional

#pragma mark - 对应UITextField的代理方法
//
- (BOOL)searchBarTextShouldBeginEditing:(AUSearchBar *)searchBar;
//
- (BOOL)searchBarTextShouldEndEditing:(AUSearchBar *)searchBar;
// called when text starts editing
- (void)searchBarTextDidBeginEditing:(AUSearchBar *)searchBar;
// called when text ends editing
- (void)searchBarTextDidEndEditing:(AUSearchBar *)searchBar;
// called when text changes (including clear)
- (void)searchBar:(AUSearchBar *)searchBar textDidChange:(NSString *)searchText;

// 10.1.58 新加逻辑
// searchBar:textDidChange:只有在trim之后有变化，才会回调
// 本方法是只有有变化，就会回调
- (void)searchBar:(AUSearchBar *)searchBar textDidChangeWithoutTrim:(NSString *)searchText;

// called before text changes
- (BOOL)searchBar:(AUSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (BOOL)searchBarShouldClear:(AUSearchBar *)searchBar;

#pragma mark - 其他代理方法

// 键盘搜索按钮点击后的回调
- (void)searchBarSearchButtonClicked:(AUSearchBar *)searchBar;

// 取消按钮点击后的回调
- (void)searchBarCancelButtonClicked:(AUSearchBar *) searchBar;

// 返回按钮点击后的回调（AUSearchBarStyleDetail有效）
- (void)searchBarBackButtonClicked:(AUSearchBar *)searchBar;

// voice按钮点击后的回调（shouldShowVoiceButton为YES时有效）
- (void)searchBarOpenVoiceAssister:(AUSearchBar *)searchBar;

@end



typedef NS_ENUM(NSUInteger, AUSearchBarStyle) {
    AUSearchBarStyleNormal = 0,//normal
    AUSearchBarStyleDetail = 1, // has back Button
    AUSearchBarStyleNone = 2,  // without cancel button， and text aligment middle
};



/**
 搜索栏控件（默认宽度和屏幕宽度一致，高度44）
 */
@interface AUSearchBar : UIView

@property (nonatomic, strong) NSString *text;                           // 搜索框文本
@property (nonatomic, assign) BOOL isSupportHanziMode;                  // 是否支持汉字边输入边搜索模式，默认YES
@property (nonatomic, assign) AUSearchBarStyle style;                   // 搜索框样式
@property (nonatomic, assign) BOOL shouldShowVoiceButton;               // 是否显示voice按钮，默认NO
@property (nonatomic, strong, readonly) UITextField *searchTextField;   // 搜索框
@property (nonatomic, weak) id<AUSearchBarDelegate> delegate;
@property (nonatomic, assign) NSInteger inputMaxLength;                // 设置搜索框最大输入个数
@property (nonatomic, strong) NSString *placeHolder;
/**
 初始化方法

 @param style 搜索框样式

 @return AUSearchBar实例
 */
- (instancetype)initWithStyle:(AUSearchBarStyle)style;

// 调用 SearchTextField.text 是否要获得 textchange 回调
- (void)setTextFieldTextandEditingChanged:(NSString *)text;

// 隐藏搜索条底部分割线
- (void)hideBottomSeparator:(BOOL)isHide;


@end

#endif//程序自动生成
