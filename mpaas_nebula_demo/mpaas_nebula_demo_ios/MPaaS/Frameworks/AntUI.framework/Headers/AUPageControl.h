#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUPageControl//程序自动生成
//
//  AUPageControl.h
//  AntUI
//
//  Created by maizhelun on 2017/6/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

AntUI_BaseComponent
@interface AUPageControl : UIControl

@property(nonatomic) NSInteger numberOfPages;          // default is 0
@property(nonatomic) NSInteger currentPage;

@property(nonatomic) BOOL hidesForSinglePage;

@property(nullable, nonatomic,strong) UIColor *pageIndicatorTintColor;
@property(nullable, nonatomic,strong) UIColor *currentPageIndicatorTintColor;

/**
 是否订阅圆点的点击事件
 */
- (void)subscribeDotTapAction:(void(^_Nullable)(NSInteger index))dotTapAction;

@end

@interface AUPageControl (AUSimpleControl)

// 支持简单模型的pageControl，去除item的特殊阴影效果
- (instancetype)initSimpleControl;

@end


NS_ASSUME_NONNULL_END

#endif//程序自动生成
