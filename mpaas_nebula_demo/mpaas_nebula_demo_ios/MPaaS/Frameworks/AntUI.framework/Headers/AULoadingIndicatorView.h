#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AULoadingIndicatorView//程序自动生成
//
//  APActivityIndicatorView.h
//  APCommonUI
//
//  Created by yangwei on 16/4/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auloadingindicatorview
//#########################################################


#define UI_AULoadingIndicatorView

typedef enum{
    AULoadingIndicatorViewStyleTitleBar,   //导航栏加载，  直径：36px，环宽：3px
    AULoadingIndicatorViewStyleRefresh,    //列表刷新加载， 直径：48px，环宽：4px
    AULoadingIndicatorViewStyleToast,      //toast加载    直径：72px，环宽：6px
    AULoadingIndicatorViewStyleLoading,    //页面加载      直径：90px，环宽：6px
    
    //导航栏加载，  直径：36px，环宽：3px
    APActivityIndicatorViewStyleTitleBar __attribute__((deprecated)) = AULoadingIndicatorViewStyleTitleBar,
    //列表刷新加载， 直径：48px，环宽：4px
    APActivityIndicatorViewStyleRefresh __attribute__((deprecated)) = AULoadingIndicatorViewStyleRefresh,
    //toast加载    直径：72px，环宽：6px
    APActivityIndicatorViewStyleToast __attribute__((deprecated))   = AULoadingIndicatorViewStyleToast,
    //页面加载      直径：90px，环宽：6px
    APActivityIndicatorViewStyleLoading __attribute__((deprecated)) = AULoadingIndicatorViewStyleLoading,
}AULoadingIndicatorViewStyle;



/**
 钱包自定义菊花控件
 */
AntUI_BaseComponent
@interface AULoadingIndicatorView : UIView

@property (nonatomic, assign) BOOL    hidesWhenStopped;    //是否停止的时候隐藏掉
@property (nonatomic, strong) UIColor *trackColor;         //圆环颜色
@property (nonatomic, strong) UIColor *progressColor;      //指示器颜色
@property (nonatomic, assign) float progressWidth;         //设置圆环的宽度，自定义圆圈大小时，默认为2
@property (nonatomic, assign) CGFloat progress;            //加载指示器的弧长与圆环的比值，默认为0.1

/**
 *  圆圈样式的loading框
 *  说明：如果不使用默认style，需要自定义圆圈的大小，请使用initWithFrame:初始化，此时圆环宽度默认为2，可设置progressWidth调整
 *
 *  @param style  当前loading类型。
 *
 */
- (instancetype)initWithLoadingIndicatorStyle:(AULoadingIndicatorViewStyle)style;

/**
 开始执行动画
 */
- (void)startAnimating;

/**
 停止执行动画
 */
- (void)stopAnimating;

/**
 是否正在执行动画

 @return YES，动画执行中；NO，没有执行动画
 */
- (BOOL)isAnimating;


@end

#endif//程序自动生成
