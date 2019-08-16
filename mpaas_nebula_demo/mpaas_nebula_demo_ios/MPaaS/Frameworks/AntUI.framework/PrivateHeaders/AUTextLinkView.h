#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_PageFooter//程序自动生成
//
//  AUTextLinkView.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@class AUTextLinkView;
//
@protocol AUTextLinkDelegate <NSObject>

@optional
/* 文字链点击回调
 * textLinkView 文字链
 * index 点击下标，下标从0开始，对应params下标
 * button 点击按钮
 */
- (void)textLinkView:(AUTextLinkView *)textLinkView didClickOnIndex:(NSInteger)index atButton:(UIButton *)button;

@end

//
@interface AUTextLinkView : UIView

@property (nonatomic, strong) UIView *containerView;    // 容器
@property (nonatomic, weak) id <AUTextLinkDelegate> delegate;

// titles: 文字描述数组
- (instancetype)initWithFrame:(CGRect)frame params:(NSArray *)params;

@end

#endif//程序自动生成
