#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AULoadingIndicatorView//程序自动生成
//
//  AUILoadingIndicatorView.h
//  AntUI
//
//  Created by 沫竹 on 2017/11/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>





typedef NS_ENUM(NSInteger, AUILoadingIndicatorType) {
    AUILoadingIndicatorTypeToast, // toast
    AUILoadingIndicatorTypeDragLoadMore, // 底部刷新
    AUILoadingIndicatorTypeButton, // button
};


@interface AUILoadingIndicatorView : UIView

AU_UNAVAILABLE_INIT


/**
 初始化函数（三个点进度视图）

 @param type 显示类型（每个类型size会不一样）
 @param bizName 业务标识
 @param config 预留参数（传NULL）
 @return AUILoadingIndicatorView 对象
 */
- (instancetype)initWithType:(AUILoadingIndicatorType)type
                     bizName:(NSString *)bizName
                  makeConfig:(dispatch_block_t)config;


/**
 可以等比改变默认的比例

 @param width 宽度
 */
- (void)setWidth:(CGFloat)width;


/**
 设置color

 @param color 颜色
 */
- (void)setColor:(UIColor *)color;

/**
 是否动画中
 */
@property(nonatomic, readonly, getter=isAnimating) BOOL animating;

/**
 开始执行动画
 */
- (void)startAnimating;

/**
 停止执行动画
 */
- (void)stopAnimating;

@end

#endif//程序自动生成
