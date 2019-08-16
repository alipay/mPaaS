#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Search_AUSearchTitleView//程序自动生成
//
//  APNavSearchTitleView.h
//  APExtUI
//
//  Created by yangwei on 16/4/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_ausearchtitleview
//#########################################################


#define UI_AUSearchTitleView

typedef NS_ENUM(NSInteger, AUSearchTitleStyle) {
    AUSearchTitleStyleDefault = 0,    // 默认样式，黑色文字, 使用于浅色背景(一般用于导航栏上)
    AUSearchTitleStyleMiddleAlign = 1,    // 深色文字, 使用于浅色背景（居中对齐样式已升级为左对齐样式，效果等同StyleDefault）
    AUSearchTitleStyleContent = 2,        // 白色文字, 适用于深色背景
    AUSearchTitleStyleDefaultInPage = 3, // 默认样式，一般用于导航栏下面，置于页面内部
    //以下两个是为了首页搜索框定制的两个Style
    AUSearchTitleStyleContentNew = 4,  // 默认样式，黑色文字, 使用于浅色背景(一般用于导航栏上),圆角弧度是4px,语音icon前景色是 #999999,搜索Icon #999999
    AUSearchTitleStyleContentOld = 5, // 默认样式，黑色文字, 使用于浅色背景(一般用于导航栏上),圆角弧度是4px,语音icon前景色是 #BBD9F1,搜索Icon #FFFFFF
};

@class AUSearchTitleView;

@protocol AUSearchTitleViewDelegate <NSObject>

@optional

// 点击搜索栏入口控件
- (void)didPressedTitleView:(AUSearchTitleView *)titleView;

// 点击搜索栏入口控件的voice按钮
- (void)didPressedVoiceButton:(AUSearchTitleView *)titleView;

@end



/**
 搜索栏入口控件（默认宽度宽度占据整个屏幕）
 */
@interface AUSearchTitleView : UIView

@property(nonatomic, assign)AUSearchTitleStyle style;          //搜索背景样式，若不设置，默认为浅色背景

@property(nonatomic,strong) NSString *placeHolder;            //搜索框placeholder，默认为“搜索”
@property(nonatomic,strong) UIColor *placeHolderColor;        //placeholder的颜色

@property (nonatomic, weak) id<AUSearchTitleViewDelegate> delegate;

@property(nonatomic,strong) UIImage *searchIconImage;         // 搜索icon
@property(nonatomic,strong) UIColor *normalBackgroundColor;   // 搜索框的背景颜色
@property(nonatomic,assign) BOOL isShowVoiceIcon;             // 是否显示语音搜索icon，默认不显示
@property(nonatomic,strong)UIButton *voiceIconButton;         // 语音icon


/**
 * 搜索框距外层透明View的左右内边距，默认为9。如业务需设置初始化的实例View与其他View的间距，请将内边距值考虑在内，否则视觉上会有误差
 * 说明：将初始化的实例设为navigationItem的titleview时，系统会自适应布局titlview与左右item的间距，为满足视觉需求，设置了搜索框距外层透明View的内边距。
 *
 * 如有特殊需求，可重设此内边距
 * 
 */
@property(nonatomic,assign) CGFloat marginBetweenItem;

/**
 *  获取实例的方法

 *
 *  @param style  搜索框的style
 *
 *  @return 获取的实例
 */
- (id)initWithSearchStyle:(AUSearchTitleStyle)style;

/**
 *  若业务需自定义点击搜索框的事件，请在子类中重写此方法
 */
- (void)onClicked;

@end

#endif//程序自动生成
