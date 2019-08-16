#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUView//程序自动生成
//
//  AUView.h
//  AntUI
//
//  Created by maizhelun on 2017/7/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

AntUI_BaseComponent
@interface AUView : UIView

@property (nonatomic, strong) UIView *aubadgeView; // 带有红点的共有view
@property (nonatomic, assign) CGRectEdge aubadgeViewEdge; // 设置红点的与旁边view的间距

@end



@interface UIView (AUBadgeView)

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

@end

typedef NS_ENUM(NSInteger, AUViewPaddingPostion) {
    AUViewPaddingPostionLeft,          // regular table view
    AUViewPaddingPostionRight,         // preferences style table view
    AUViewPaddingPostionTop,
    AUViewPaddingPostionBottom,
    AUViewPaddingPostionBadgeNumber,
    AUViewPaddingPostionBadgeWidgetId,
    AUViewPaddingPostionBottomLeft,
};

@interface UIView (PaddingView)

- (UIView *)au_paddingViewAtPostion:(AUViewPaddingPostion)postion;
- (void)au_setPaddingView:(UIView *)view atPostion:(AUViewPaddingPostion)postion;
- (void)au_removePaddingViewAtPosition:(AUViewPaddingPostion)postion;

@end


typedef void (^AUViewActionBlock)();
@interface UIView (AUAction)

@property (nonatomic, copy) AUViewActionBlock auviewActionBlock;  //点击事件

@end

#endif//程序自动生成
