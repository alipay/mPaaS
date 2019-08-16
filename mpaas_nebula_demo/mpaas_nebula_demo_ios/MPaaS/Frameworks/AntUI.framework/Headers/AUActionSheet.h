#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUActionSheet//程序自动生成
//
//  AUActionSheet.h
//  AntUI
//
//  Created by QiXin on 2016/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBadgeView.h"

#define UI_AUActionSheet

@class AUActionSheetItem;

/**
 AUAction Sheet，接口迁移自 APActionSheet，展示样式做了一些调整
 可参考文档:https://yuque.antfin-inc.com/antui/auidoc/ios_auactionsheet
 */

typedef NS_ENUM(NSInteger, AUActionSheetButtonType) {
    AUActionSheetButtonTypeDefault = 0,         // 默认
    AUActionSheetButtonTypeDisabled,            // 不可点击
    AUActionSheetButtonTypeDestructive,         // 红色删除性按钮
    AUActionSheetButtonTypeCustom,               // 自定义
    
    APActionSheetButtonTypeDefault  __attribute__((deprecated))      = AUActionSheetButtonTypeDefault,
    APActionSheetButtonTypeDisabled  __attribute__((deprecated))     = AUActionSheetButtonTypeDisabled,
    APActionSheetButtonTypeDestructive  __attribute__((deprecated))  = AUActionSheetButtonTypeDestructive,
    APActionSheetButtonTypeCustom  __attribute__((deprecated))       = AUActionSheetButtonTypeCustom
};


@interface AUActionSheet : UIView<UIAppearanceContainer>

/// 按钮高度 默认为 42
@property (nonatomic) CGFloat buttonHeight UI_APPEARANCE_SELECTOR;
/// 取消按钮高度
@property (nonatomic) CGFloat cancelButtonHeight UI_APPEARANCE_SELECTOR;
/// 分割线颜色 默认为 AU_COLOR_LINE
@property (strong, nonatomic) UIColor *separatorColor UI_APPEARANCE_SELECTOR;
/// 按钮点击背景色
@property (strong, nonatomic) UIColor *selectedBackgroundColor UI_APPEARANCE_SELECTOR;
// UI 组件的一些 Attributes
@property (copy, nonatomic) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *buttonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *disabledButtonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *destructiveButtonTextAttributes UI_APPEARANCE_SELECTOR;
@property (copy, nonatomic) NSDictionary *cancelButtonTextAttributes UI_APPEARANCE_SELECTOR;

/// 显示隐藏动画时间，默认为 0.5
@property (nonatomic) NSTimeInterval animationDuration UI_APPEARANCE_SELECTOR;
/// 标题
@property(nonatomic,copy) NSString *title;
/// 是否已经展示
@property(nonatomic, readonly, getter=isVisible) BOOL visible;
/// 自定义按钮上方顶部视图
@property (strong, nonatomic) UIView *headerView;
/// ActionSheet 实例显示前的 keyWindow
@property (weak, nonatomic, readonly) UIWindow *previousKeyWindow;
/// 协议代理
@property(nonatomic,weak)id<UIActionSheetDelegate> delegate;
/// 取消按钮标题
@property (copy, nonatomic) NSString *cancelButtonTitle;
/// 按钮个数
@property(nonatomic, readonly) NSInteger numberOfButtons;
/// 取消按钮索引,默认为 -1
@property(nonatomic) NSInteger cancelButtonIndex;
/// 破坏性红色按钮索引值,默认为 -1,如果只有一个按钮则忽略。
@property(nonatomic) NSInteger destructiveButtonIndex;
/// 第一个按钮的索引，返回为 0
@property(nonatomic, readonly) NSInteger firstOtherButtonIndex;

// fake 
@property(nonatomic) UIActionSheetStyle actionSheetStyle __deprecated;
/**
 AUActionSheet 初始化方法

 @param title 标题信息
 @param delegate 代理对象
 @param cancelButtonTitle 取消按钮标题
 @param destructiveButtonTitle 破坏性按钮标题
 @param otherButtonTitles 其他按钮标题参数列表
 @return AUActionSheet 实例
 */
- (instancetype)initWithTitle:(NSString *)title delegate:(id<UIActionSheetDelegate>)delegate cancelButtonTitle:(NSString *)cancelButtonTitle destructiveButtonTitle:(NSString *)destructiveButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

/**
 AUActionSheet 初始化方法
 
 @param title 标题信息
 @param delegate 代理对象
 @param cancelButtonTitle 取消按钮标题
 @param destructiveButtonTitle 破坏性按钮标题
 @param items customOption数据列表(自定义titleColor,红点)
 @return AUActionSheet 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                     delegate:(id<UIActionSheetDelegate>)delegate
            cancelButtonTitle:(NSString *)cancelButtonTitle
       destructiveButtonTitle:(NSString *)destructiveButtonTitle
                        items:(NSArray<AUActionSheetItem *> *)items;

/**
 增加一个按钮, 类型为默认类型

 @param title 按钮标题
 @return 按钮索引值,从 0 起
 */
- (NSInteger)addButtonWithTitle:(NSString *)title;

/**
 增加一个按钮

 @param title 按钮标题
 @param type 按钮类型
 @return 按钮索引值，从 0 起
 */
- (NSInteger)addButtonWithTitle:(NSString *)title type:(AUActionSheetButtonType)type;

/**
 通过索引值获取按钮标题

 @param buttonIndex 按钮索引值
 @return 按钮标题
 */
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;

/**
 设置某个位置的按钮

 @param item 封装信息后的按钮类型
 @param index 需要替换的索引值，小于现有按钮个数
 */
- (void)setButton:(AUActionSheetItem *)item atIndex:(NSInteger)index;

/** ActionSheet 展示方法 */
- (void)show;

- (void)showTillClose;

/**
 手动调用隐藏方法

 @param animate 隐藏是否带动画
 */
- (void)closeWithAnimate:(BOOL)animate;

/**
 手动模拟按钮点击隐藏方法 （会回调按钮点击相关的协议方法）

 @param buttonIndex 按钮索引
 @param animated 隐藏是否带动画
 */
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

/**
 *  动态添加item
 *  注意：请在actionSheet show出来后并显示在屏幕时调用；如需在show前addButton，请使用<code> addButtonWithTitle </code>
 *
 *  @param item  自定义item
 *  @param index 添加的位置
 */
- (void)addButton:(AUActionSheetItem *)item atIndex:(NSInteger)index;

/// 设置后台模式，如果为 YES 或者 @(YES) 则隐藏所有已经展示的 ActionSheet。默认为 NO
+(void)setIsBackGroundMode:(BOOL)isBackGroundMode;
/// 设置后台模式，如果为 YES 或者 @(YES) 则隐藏所有已经展示的 ActionSheet。默认为 NO
+(void)weakSetIsBackGroundMode:(id)isBackGroundMode;

/// 展示方法，传入参数并不会影响 ActionSheet 展示的位置
- (void)showFromToolbar:(UIToolbar *)view;
/// 展示方法，传入参数并不会影响 ActionSheet 展示的位置
- (void)showFromTabBar:(UITabBar *)view;
/// 展示方法，传入参数并不会影响 ActionSheet 展示的位置
- (void)showFromBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
/// 展示方法，传入参数并不会影响 ActionSheet 展示的位置
- (void)showFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated NS_AVAILABLE_IOS(3_2);
/// 展示方法，传入参数并不会影响 ActionSheet 展示的位置
- (void)showInView:(UIView *)view;

@end


typedef void (^AUActionSheetItemActionBlock)();

/** 封装后的 ActionSheet 按钮类 */
@interface AUActionSheetItem : NSObject
/// 按钮标题
@property (copy, nonatomic) NSString *title;
/// 按钮的类型
@property (nonatomic) AUActionSheetButtonType type;
/// 按钮标题颜色，如果设置该值，请手动将按钮类型调整为 AUActionSheetButtonTypeCustom
@property (strong,nonatomic) UIColor *titleColor;

/**
 * 设置显示“红点”样式
 *
 *        badgeValue:  @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 */
@property (nonatomic, copy) NSString *badgeValue __deprecated_msg("即将废弃,请使用badgeViewStyle,badgeViewAttributes");


/**
 AUBadgeViewStyleNone,   //清除红点内容, attributes传nil
 AUBadgeViewStyleRedDot, //红点,无内容, attributes传nil
 AUBadgeViewStyleText,   //红点+内容, attributes:@{kAUBadgeViewAttributeKeyText:@"热门"}
 AUBadgeViewStyleNumber  //红点+数字, 0:大于99都显示图片more（...）,attributes:@{kAUBadgeViewAttributeKeyNumber:@(99)}
 */
@property (nonatomic, assign) AUBadgeViewStyle badgeViewStyle;
@property (nonatomic, strong) NSDictionary *badgeViewAttributes;

@property (nonatomic, copy) AUActionSheetItemActionBlock actionBlock;

+ (AUActionSheetItem *)itemWithTitle:(NSString *) title
                         actionBlock:(AUActionSheetItemActionBlock) actionBlock;

@end


#endif//程序自动生成
