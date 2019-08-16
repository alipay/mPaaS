//
//  UIViewController+AUTheme.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/26.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUTheme.h"

/** 建议，bundle 配置主题规则如下
 *  新建themes文件夹
 *  设置默认主题肤色文件名:theme1.strings
 *  设置常规主题肤色文件名:theme2.strings
 */


@interface UIViewController (AUTheme)

@property (nonatomic, strong) AUTheme *auTheme; // 当前 VC 的当前主题
@property (nonatomic, strong) NSString *auThemeName;    //默认值：themes/theme1.strings，注意：设置的时机要比auBundleName早！！！
@property (nonatomic, strong) NSString *auBundleName; // 所在的bundle，默认为空

/*  推荐业务方在VC的ViewDidLoad中调用以下方法设置当前主题名称以及bundle名称
 *  注意：auThemeName是主题相对路径名，文件类型只支持.strings后缀
 *  注意：bunldeName当前主题所在bundle，比如在AntUI.bundle下则直接传@"AntUI"即可，无须再传后缀.bunlde
 */
- (void)setAUThemeName:(NSString *)auThemeName bunldeName:(NSString *)bunleName;

//- (void)au_changeTheme:(NSString *)themeName;

/**
 setTheme会自动调用updateThemeIfNeeded
 外部，请勿直接调用
 */
- (void)au_updateThemeIfNeeded;

// 自动更新主题机制
- (void)au_updateNewThemeIfNeed;

@end

#define  AU_THEME_UPDATE_FINISHED   @"AU_THEME_UPDATE_FINISHED"

// 远程配置换肤变化的通知
@interface UIViewController (AURemoteConfig)

// ViewWillAppear的通知会回调多次，可能导致ViewWillAppear页面重复刷updateView方法
@property (nonatomic, assign) BOOL au_themeUpdate;

// 内部方法，页面即将展示重刷主题的处理方法
- (void)au_updateViewControllerLayout;
// 内部方法，页面即将消失删除消息监听的处理方法
- (void)au_removeObserverAtDiappear;

@end

