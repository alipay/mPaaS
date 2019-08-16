//
//  AUTheme.h
//  AntUI
//
//  Created by maizhelun on 2016/9/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

///
/// 定义换肤的KEY
///

#pragma mark - 状态栏

extern NSString * STATUSBAR_DEFAULT_COLOR;        // 状态栏默认色

#pragma mark - 导航栏

extern NSString * TITLEBAR_BACKGROUND_COLOR;         // AUTitleBar背景色
extern NSString * TITLEBAR_TITLE_TEXTCOLOR;          // AUTitleBar标题色
extern NSString * TITLEBAR_TITLE_TEXTSIZE_BOLD;           // AUTitleBar标题大小
extern NSString * TITLEBAR_TEXTCOLOR;                // AUTitleBar文本色，不包含标题
extern NSString * TITLEBAR_TEXTSIZE;                 // AUTitleBar文本大小，不包含标题
extern NSString * TITLEBAR_ICON_COLOR;               // AUTitleBar图标颜色（左右navItem）
extern NSString * TITLEBAR_PROGRESS;                 // AUTitleBar圆形进度(菊花，应该是android特有)
extern NSString * TITLEBAR_ICON_SIZE;                // AUTitleBar图标大小
extern NSString * TITLEBAR_LINE_COLOR;               // AUTitleBar分割线或边线的颜色
extern NSString * TITLEBAR_BACK_BUTTON_IMAGE_PATH;   // AUTitleBar返回箭头图标路径

#pragma mark - 搜索栏

extern NSString * SERACHBAR_INPUT_BACKGROUND_COLOR;  // AUSerachBar背景色
extern NSString * SERACHBAR_INPUT_HEIGHT;            // AUSerachBar输入框高度
//extern NSString * SERACHBAR_INPUT_WIDTH;             // AUSerachBar输入框高度
extern NSString * SERACHBAR_HINT_COLOR;              // AUSerachBar输入框暗提示颜色
extern NSString * SERACHBAR_INPUT_TEXTCOLOR;         // AUSerachBar输入框输入文案颜色
extern NSString * SERACHBAR_ICON_COLOR;              // AUSerachBar输入框输入图标颜色

#pragma mark - TabBar

extern NSString * TABBAR_BACKGROUND_COLOR;           // AUTabBar背景色
extern NSString * TABBAR_HEIGHT;                     // AUTabBar高度
extern NSString * TABBAR_TEXTCOLOR;                  //AUTabBar文本色
extern NSString * TABBAR_TEXTCOLOR_SELECTED;                  //AUTabBar文本色
extern NSString * TABBAR_TEXTSIZE;                   // AUTabBar文本大小
extern NSString * TABBAR_ICON_COLOR;                 // AUTabBar图标颜色
extern NSString * TABBAR_ICON_COLOR_SELECTED;                 // AUTabBar图标颜色
extern NSString * TABBAR_ICON_SIZE;                  // AUTabBar图标大小
extern NSString * TABBAR_LINE_COLOR;                 // AUTabBar分割线或边线的颜色

#pragma mark - FloatMenu

extern NSString * FLOATMENU_MASK_COLOR;              // AUFloatMenu遮盖颜色
extern NSString * FLOATMENU_BACKGROUND;              // AUFloatMenu菜单背景（Andorid，不需要使用）
extern NSString * FLOATMENU_BACKGROUND_COLOR;        // AUFloatMenu菜单背景（iOS）
extern NSString * FLOATMENU_ITEM_BACKGROUND_COLOR_HIGHLIGHT;   // AUFloatMenu菜单条目背景色
extern NSString * FLOATMENU_TEXTCOLOR;               // AUFloatMenu文本色
extern NSString * FLOATMENU_TEXTSIZE;                // AUFloatMenu文本大小
extern NSString * FLOATMENU_ICON_COLOR;              // AUFloatMenu图标颜色
extern NSString * FLOATMENU_ICON_SIZE;               // AUFloatMenu图标大小
extern NSString * FLOATMENU_LINE_COLOR;              // AUFloatMenu分割线或边线的颜色

#pragma mark - LoadingView (iOS可能用不到)

extern NSString * PULLLOADINGVIEW_PROGRESS;          // AUPullLoadingView圆形进度
extern NSString * LOADINGVIEW_PROGRESS;              // AULoadingView圆形进度
extern NSString * DRAGLOADINGVIEW_PROGRESS;          // AUDragLoadingView圆形进度

#pragma mark - 按钮

extern NSString * MAIN_BTN_BACKGROUND;               // 主按钮背景(Android，不需要使用)
extern NSString * MAIN_BTN_BACKGROUND_COLOR_NORMAL;  // 主按钮背景Normal态（iOS）
extern NSString * MAIN_BTN_BACKGROUND_COLOR_HIGHLIGHT;//主按钮背景Highlight态（iOS）
extern NSString * MAIN_BTN_BACKGROUND_COLOR_DISABLED; //主按钮背景Disable态（（iOS）
extern NSString * MAIN_BTN_TEXTSIZE;                 // 主按钮文案大小
extern NSString * MAIN_BTN_TEXTCOLOR;                // 主按钮文案颜色(Android，不需要使用)
extern NSString * MAIN_BTN_TEXTCOLOR_NORMAL;         // 主按钮文案颜色Normal态（iOS）
extern NSString * MAIN_BTN_TEXTCOLOR_HIGHLIGHT;      // 主按钮文案颜色Highlight态（iOS）
extern NSString * MAIN_BTN_TEXTCOLOR_DISABLED;       // 主按钮文案颜色Disable态（（iOS）
extern NSString * MAIN_BTN_HEIGHT;                   // 主按钮高度

extern NSString * SUB_BTN_BACKGROUND;                // 次按钮背景(Android，不需要使用)
extern NSString * SUB_BTN_BACKGROUND_COLOR_NORMAL;   // 次按钮背景Normal态（iOS）
extern NSString * SUB_BTN_BACKGROUND_COLOR_HIGHLIGHT;// 次按钮背景Highlight态（iOS）
extern NSString * SUB_BTN_BACKGROUND_COLOR_DISABLED; // 次按钮背景Disable态（（iOS）
extern NSString * SUB_BTN_TEXTSIZE;                  // 次按钮文案大小
extern NSString * SUB_BTN_TEXTCOLOR;                 // 次按钮文案颜色(Android，不需要使用)
extern NSString * SUB_BTN_TEXTCOLOR_NORMAL;          // 主按钮文案颜色Normal态（iOS）
extern NSString * SUB_BTN_TEXTCOLOR_HIGHLIGHT;       // 主按钮文案颜色Highlight态（iOS）
extern NSString * SUB_BTN_TEXTCOLOR_DISABLED;        // 主按钮文案颜色Disable态（（iOS）
extern NSString * SUB_BTN_HEIGHT;                    // 次按钮高度

extern NSString * WARN_BTN_BACKGROUND_COLOR_NORMAL;  // 警告类按钮背景Normal态（iOS）
extern NSString * WARN_BTN_BACKGROUND_COLOR_HIGHLIGHT;//警告类按钮背景Highlight态（iOS）
extern NSString * WARN_BTN_BACKGROUND_COLOR_DISABLED;//警告类按钮背景Disabled态（iOS）

#pragma mark - Segment

extern NSString * SEGMENT_TEXTCOLOR_NORMAL;          // AUSegment文本颜色默认色
extern NSString * SEGMENT_TEXTCOLOR_SELECTED;        // AUSegment文本选中颜色
extern NSString * SEGMENT_COLOR_NORMAL;              // AUSegment颜色默认色
extern NSString * SEGMENT_COLOR_SELECTED;            // AUSegment选中颜色
extern NSString * SEGMENT_HEIGHT;                    // AUSegment高度

#pragma mark - CheckBox

extern NSString * CHECKBOX_COLOR_NORMAL;             // AUCheckBox图标普通颜色
extern NSString * CHECKBOX_COLOR_SELECTED;           // AUCheckBox图标选中颜色
extern NSString * CHECKBOX_COLOR_DISABLE;            // AUCheckBox图标不可选颜色


@interface AUTheme : NSObject

@property (nonatomic, copy) NSMutableDictionary *dictionary;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (UIColor *)colorForKey:(NSString *)key;
- (UIFont *)fontForKey:(NSString *)key;
- (CGSize)iconSizeForKey:(NSString *)key;
- (CGFloat)spaceForKey:(NSString *)key;
- (CGFloat)cornerRadiusForKey:(NSString *)key;
- (NSString *)imageNameForKey:(NSString *)key;

@end








