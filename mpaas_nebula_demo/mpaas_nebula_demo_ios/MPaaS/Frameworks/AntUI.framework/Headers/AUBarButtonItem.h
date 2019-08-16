#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUBarButtonItem//程序自动生成
//
//  APBarButtonItem.h
//  APCommonUI
//
//  Created by WenBi on 13-12-8.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aubarbuttonitem
//#########################################################


#define UI_AUBarButtonItem

/**
 AUBarButtonItem为UIBarButtonItem在钱包的版本(包括了预定义颜色和字体等)。
 要求所有钱包都使用AUBarButtonItem而不是系统的UIBarButtonItem，方便后面扩展。
 需要和AUNavigationBar一起使用
 */
@interface AUBarButtonItem : UIBarButtonItem

@property(nonatomic, strong) NSString   *backButtonTitle;       // 返回按钮title
@property(nonatomic, strong) UIImage    *backButtonImage;       // 返回按钮图片
@property(nonatomic, strong) UIColor    *titleColor;            // 返回按钮文本颜色
@property(nonatomic, assign) BOOL       hideBackButtonImage;    //隐藏返回按钮图片，提供给框架使用
@property(nonatomic, strong) UIColor    *backButtonColor;       // 设置箭头颜色

/**
 设置红点
 
 @param wedgetId 红点的wedgetId
 @param badgeNumber @"."   显示红点
 @"new" 显示new
 @"数字" 显示数字，大于99都显示图片more（...）
 @"惠"/"hui"  显示“惠”字
 @"xin" 显示"新"字
 nil    清除当前显示
 */

/**
 *  如果设置了widgetId，就不需要设置badgeNumber
 */
@property (nonatomic, strong) NSString *aubadgeNumber;

/**
 *  红点显示的widgetId
 */
@property (nonatomic, copy) NSString *aubadgeWidgetId;

/**
 *  设置按钮间的间距
 *
 *  @return 返回UIBarButtonSystemItemFlexibleSpace风格的空按钮
 */
+ (AUBarButtonItem *)flexibleSpaceItem;

/**
 *  多个按钮间的默认间距
 *
 *  @return 返回UIBarButtonSystemItemFlexibleSpace风格的空按钮
 */
+ (AUBarButtonItem *)defaultSpaceItem;

/**
 *  创建默认的返回按钮样式
 *
 *  @param title   显示文本
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */
+ (AUBarButtonItem *)backBarButtonItemWithTitle:(NSString *)title target:(id)target action:(SEL)action;

/**
 *  创建默认的返回按钮样式
 *
 *  @param title   显示文本
 *  @param count   最大显示文字数
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */
+ (AUBarButtonItem *)backBarButtonItemWithTitle:(NSString *)title maxWordsCount:(NSInteger)count target:(id)target action:(SEL)action;


/**
 * 自定义返回箭头的颜色
 * @param title 标题,可以传空。
 * @param color 返回箭头的颜色
 */
+ (AUBarButtonItem *)backBarButtonItemWithTitle:(NSString *)title backArrowColor:(UIColor *)color target:(id)target action:(SEL)action;

/**
 *  创建默认的按钮样式
 *
 *  @param title   显示文本
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */
+ (AUBarButtonItem *)barButtonItemWithTitle:(NSString *)title target:(id)target action:(SEL)action;



+ (UIImage *) croppingBackImage:(UIImage *)image;

@end


////  生成带 image 的barButtonItem 推荐优先使用以下方式

typedef NS_ENUM(NSInteger, AUBarButtonImageType)
{
    AUBarButtonImageTypeUserSetting,                   // 用户设置
    AUBarButtonImageTypeUser,                          // 用户
    AUBarButtonImageTypeAdd,
    AUBarButtonImageTypeBill,
    AUBarButtonImageTypeCheck,                        // 勾选
    AUBarButtonImageTypeComment,
    AUBarButtonImageTypeCancelStyle1,                  // 无白色的取消，圆圈差
    AUBarButtonImageTypeCancelStyle2,                  // 带背景色的取消
    AUBarButtonImageTypeAnnouncement,                  // 公告
    AUBarButtonImageTypeSearch,
    AUBarButtonImageTypeShare,
    AUBarButtonImageTypeDelete,
    AUBarButtonImageTypeItemList,                      // 列表类目
    AUBarButtonImageTypeScanCode,                      // 扫码
    AUBarButtonImageTypeDragdown,                      // 下拉
    AUBarButtonImageTypePraise,
    AUBarButtonImageTypeMap,
    AUBarButtonImageTypeCheckBoxSelected,
    AUBarButtonImageTypeCheckBoxNormal,
    AUBarButtonImageTypeBack,                          // 返回
    AUBarButtonImageTypeComplaints,
    AUBarButtonImageTypeQRCode,                        // 二维码
    AUBarButtonImageTypeMore,
    AUBarButtonImageTypeVoice,
    AUBarButtonImageTypeCashier,                        // 收款
    AUBarButtonImageTypeUserAdd,                       // 添加后用户
    AUBarButtonImageTypeDetail,
    AUBarButtonImageTypeHelp,
    AUBarButtonImageTypeGroupChat,
    AUBarButtonImageTypeSetting,                      // 设置
};

@interface AUBarButtonItem (buttonType)

/**
 *  创建指定的按钮样式
 *
 *  @param type    按钮图片样式
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */

+ (AUBarButtonItem *)barButtonItemWithImageType:(AUBarButtonImageType)type target:(id)target action:(SEL)action;

@end


@interface AUBarButtonItem (iconfont)

/**
 *  创建指定的按钮样式，默认返回蚂蚁蓝
 *
 *  @param fontName  指定iconfont 的名称，目前所有的iconfont字体库都在AUIconView
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */

+ (AUBarButtonItem *)barButtonItemWithIconFontName:(NSString *)fontName target:(id)target action:(SEL)action;


/**
 *  创建指定的按钮样式，支持自定义iconfont icon的色值
 *
 *  @param fontName  指定iconfont 的名称，目前所有的iconfont字体库都在AUIconView
 *  @param target  点击接受者
 *  @param action  点击处理方法
 *
 *  @return AUBarButtonItem
 */

+ (AUBarButtonItem *)barButtonItemWithIconFontName:(NSString *)fontName
                                         iconColor:(UIColor *)iconColor
                                            target:(id)target
                                            action:(SEL)action;


@end

#endif//程序自动生成
