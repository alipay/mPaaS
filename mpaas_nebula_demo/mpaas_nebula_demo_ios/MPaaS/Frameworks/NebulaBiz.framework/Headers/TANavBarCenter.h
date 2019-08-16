//
//  TANavBarCenter.h
//  TinyappService
//
//  Created by 闻蹊 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TABaseNavBarRightButton.h"

#define TA_navbar_right_btn @"TA_navbar_right_btn"

#define TA_CATE(prefix,name) prefix##name
#define TA_NAVBAR_CATEGORY_INIT(category_name) \
-(void) TA_CATE(ta_categoryInitialCustom_,category_name)



typedef NS_ENUM(NSInteger, TANavBarCustomItemState) {
    TANavBarCustomItemStateNone = 0,  //
    TANavBarCustomItemStateKeepFavorite = 1, // 已收藏的状态
    TANavBarCustomItemStateUnKeepFavorite = 2, // 未收藏的状态
    TANavBarCustomItemStateCustomBtn = 3, // 当前开发者自定义
};

typedef void(^TASParamAction)(NSDictionary *valueDict);

@interface TANavBarCenter : NSObject {
@protected
    id _tinyActionSheet;
    id _tinyActionHandler;
    id _recentlyAppMenu;
    id _recentApps;
    id _popMenu;
    id _rightBtnItem;
    id _customBtnItem;
    NSArray *_dataSource;
    
    TANavBarCustomItemState _customItemState;
    NSString *_hardwareNoticetext;
}

@property (nonatomic, strong) NSDictionary *favoriteBadgeInfo;
@property (nonatomic, strong) NSArray *dataSource;
@property (nonatomic, strong) NSDictionary *badgeInfos;

///
@property (nonatomic, weak) PSDKernel             *target;

@property (nonatomic, copy) TASParamAction onCloseButtonLongPressedAction;
@property (nonatomic, copy) TASParamAction onNavBarColorDidChangedAction;
@property (nonatomic, copy) TASParamAction onSettingButtonClickedAction;

@property (nonatomic, copy) TASParamAction doChangeActionSheetTitle;
@property (nonatomic, copy) TASParamAction doShowActionSheet;
@property (nonatomic, copy) TASParamAction doHidePopTipMsgView;
@property (nonatomic, copy) TASParamAction doSetupBadgeInfo;

#pragma mark - PopMenu

#pragma mark - Option Menu

@property (nonatomic, assign) BOOL naviColorIsLight; // 记录下当前导航栏右上角按钮的颜色深浅
@property (nonatomic, copy) NSString              *appId;
@property (nonatomic, assign) BOOL needInvokeOptionMenu;

@property (nonatomic, weak) H5WebViewController   *webVC;

@property (nonatomic, copy) NSString *hardwareNoticetext;

- (instancetype)initWithAppid:(NSString *)appid
                       target:(PSDKernel *)target
                h5WebViewController:(H5WebViewController *)h5WebViewController;

///< 右上角按钮

- (void)showRightBarButtonItems;
- (void)showCustomBarButtonItem;
- (void)hideCustomBarButtonItem;

- (void)changeColor:(BOOL)isLight;
- (void)changeColorByBarButtonThemeSetting:(BOOL)isLight; // 标识一下是因为主题设置导致的
- (void)replayLastChangeColor; // replay最新的一次changeColor

@end
