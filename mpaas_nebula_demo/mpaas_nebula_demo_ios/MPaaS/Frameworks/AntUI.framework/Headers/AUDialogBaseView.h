#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogBaseView.h
//  AntUI
//
//  Created by QiXin on 2016/9/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUDialogButton.h"
#import "AUDialogProtocol.h"

extern NSString * kDialogShowAnimationKey;
extern NSInteger  kDialogForceDismissIndex;    // dialog强行dissmiss(如dismissAll方法调用时)的回调index

@class AUDialogBuilder;
@interface AUDialogBaseView : UIView {
    @package
    AUDialogBuilder *_dialogBuilder;
    NSInteger        _cancelIndex;
}

@property (nonatomic, weak) id<AUDialogDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval animationDuration;
@property (nonatomic, strong) UIView *alertContainer;
@property (nonatomic, strong) UIScrollView *alertScrollView; // 内容超出屏幕范围支持滚动展示
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UIView *buttonView;

@property (nonatomic, assign, readonly) BOOL isDisplay;
@property (nonatomic, assign) BOOL    backgroundMark;
@property (nonatomic, assign) BOOL listButtonOrderFromBottom; // 是否从底部开始布局第一个按钮（默认从顶部开始）

@property (nonatomic, assign) BOOL    grayMessage;
@property (nonatomic, assign) BOOL    useUnifyShowAnimation;
@property (nonatomic, assign) BOOL    isSupportAutorotate;          // 设置是否需要支持屏幕旋转，默认不支持
@property (nonatomic, assign) NSTextAlignment messageAlignment;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *message;

/**
 * 是否来自桥接APAlertView
 * 如果YES，则回调delegate只回调UIAlertViewDelegate的那些回调方法
 * 避免有些业务混用APAlertView/AUNoticeDialog时两个delegate方法都回调
 */
// @property (nonatomic, assign) BOOL isBridgeFromAP;

- (void)show;
- (void)dismiss;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;
- (void)enableButton:(BOOL)enable atIndex:(NSInteger)index;
- (void)forceHidden; // 有其他 alertview 要显示到 window 上时调用

+ (void)dismissAll;
+ (BOOL)hasDialogShowing; // 判断当前 app 内各个界面中是否有弹窗展示

- (AUDialogNormalButton *)addCancelButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;
- (AUDialogNormalButton *)addButton:(NSString *)buttonTitle actionBlock:(AUDialogActionBlock)actionBlock;
//- (AUDialogActionButton *)addActionButton:(NSString *)aciontTitle actionBlock:(AUDialogActionBlock)actionBlock;
- (void)onButtonClicked:(AUDialogButton *)sender;

- (void)onCloseBtnClickedAction:(AUDialogActionBlock)actionBlock;

+ (BOOL)validString:(NSString *)string;

- (instancetype)initWithCustomView:(UIView *)customView; // 自定义内容区域

- (instancetype)initWithCustomView:(UIView *)customView type:(AUDialogBuilderType)type;

- (NSString *)descriptionWithInfo:(NSString *)info;



/**
 设置自定义视图距离上下左右的边距(AUImageDialog暂不支持)
 
 @param edge 自定义视图边距（如果不需要边距设置NULL，设置调用AUEdgeInsetsMake方法）
 */
- (void)setCustomViewEdge:(AUEdge *)edge;

@end

@interface AUDialogBaseView (TinyApp)

-(void) setButtonTextColor:(UIColor *)color forButtonIndex:(NSInteger) index;

@end

#endif//程序自动生成
