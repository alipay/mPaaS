#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Segment_AUSegment//程序自动生成
//
//  AUSegmentScrollDelegate.h
//  AntUI
//
//  Created by 莜阳 on 2018/1/16.
//  Copyright © 2018年 Alipay. All rights reserved.
//


@interface AUShadowView : UIControl

@end



@interface AUSegment ()

@property(nonatomic, strong) UIView *sliderView;
@property(nonatomic, strong) UIView *lineView;
@property(nonatomic, assign) CGFloat itemWidth;
@property(nonatomic, strong) NSMutableArray<AUSegmentedControlItem *> *items;
@property(nonatomic, assign) NSInteger currentSegmentIndex;
@property(nonatomic, assign) NSInteger scrollToIndex;//
@property(nonatomic, strong) AUShadowView *leftShadowView;
@property(nonatomic, strong) AUShadowView *rightShadowView;
@property(nonatomic, strong) AUButton *actionIcon;
@property(nonatomic, assign) NSInteger contentWidth;

- (UIControl *)createShadowView:(BOOL)left;
@end


#endif//程序自动生成
