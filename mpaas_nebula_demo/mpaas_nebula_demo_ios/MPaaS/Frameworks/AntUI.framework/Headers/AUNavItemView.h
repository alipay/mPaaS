#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_FloatMenu_AUFloatMenu//程序自动生成
//
//  AUNavItemView.h
//  AntUI
//
//  Created by 祝威 on 16/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, AUCurrentTabType)  {
    AUCurrentTabTypeHome = 0,
    AUCurrentTabTypeKouBei,
    AUCurrentTabTypeFriend,
    AUCurrentTabTypeWealth
};

/*！
 @class       AUNavItemView
 @abstract    UIView
 @discussion  floatMenu浮层中每栏的 view
 */
@interface AUNavItemView : UIView
/**
 *  title
 */
@property(nonatomic,strong)NSString *itemTitle;

@property(nonatomic,strong,readonly)UIFont *titleFont;

/**
 *  正常状态下的,
 */
@property(nonatomic,strong)UIImage *nomarlStateIconImage;

/*
 * iconFont Name  如果是iconFont话调用这个接口,不用调上面的接口
 */
@property(nonatomic,strong)NSString *nomarlStateIconFontName;

/**
 *  如果设置了widgetId，就不需要设置badgeNumber
 */
@property(nonatomic,strong)NSString *badgeNumber;

/**
 *  widgetId
 */
@property(nonatomic, copy) NSString *widgetId;

/**
 *VoiceOver需要的提示的文案,默认是itemTitle，如果没有设置itemTitle，需要手动设置此属性来支持VoiceOver
 */
@property(nonatomic,strong)NSString *voiceOverText;

@property(nonatomic,assign)BOOL isNavigationItem;

@property(nonatomic,assign,readonly)CGFloat touchEventMargin;

@property(nonatomic,assign)AUCurrentTabType currentTabType;

@property(nonatomic,assign,readonly)CGFloat marginBetweenIconTitle;

@property(nonatomic,assign,readonly)CGFloat marginBetweenLeftIcon;

@property(nonatomic,assign,readonly)CGFloat badgeViewWidth;

@property (nonatomic, strong) UIImage *badgeImage;

/**
 点击事件
 */
@property (nonatomic, copy) dispatch_block_t tapAction;

/**
 *  子类需重写此方法，然后处理点击的事件
 */
- (void)onClicked __deprecated_msg("请使用tapAction传递block");

/**
 返回Iconview的size

 @return size
 */
- (CGSize) iconViewSize;

/**
 设置icon

 @param nomarlStateIconImage icon
 @param size                 icon显示的大小
 */
- (void)setNomarlStateIconImage:(UIImage *)nomarlStateIconImage withSize:(CGSize)size;

/**
 设置iconFont 参数
 
 @param nomarlStateIconFontName iconFontName
 @param size                    icon显示的大小，默认 CGSizeMake(21,21)，传CGSizeZero则取默认size
 @param color                   iconFont对应的色值，默认 #108ee9，传nil则取默认色值
 */
- (void)setNomarlStateIconFontName:(NSString *)nomarlStateIconFontName withSize:(CGSize)size color:(UIColor *)color;


/**
 @param remoteImage 设置由网络下载的图片,使用此接口(注意,使用其他接口设置网络图片可能会有布局问题)
 @param size 图片size
 */
- (void)setRemoteImage:(UIImage *)remoteImage
                  size:(CGSize)size;

@end

#endif//程序自动生成
