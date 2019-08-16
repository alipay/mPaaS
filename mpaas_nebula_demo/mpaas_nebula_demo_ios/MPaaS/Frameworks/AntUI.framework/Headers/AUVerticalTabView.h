#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Navigate_AUVerticalTabView//程序自动生成
//
//  AUVerticalTabView.h
//  AntUI
//
//  Created by zhaolei on 2018/4/11.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auverticaltabview
//#########################################################


@protocol AUVerticalTabViewDataProtocol <NSObject>

@required
- (NSString *) tabName;

@end

@class AUVerticalTabView;

typedef void (^AUVerticalTabSelectedCallback)(AUVerticalTabView *verticalTabView);

@interface AUVerticalTabView : UIView

/**
 推荐初始化方法,布局参数为AntDNA规范:
 AUVerticalTabView : width=110pt
 TabCell : width=110pt,height=55pt
 
 @param verticalTabViewDatas 设置tab数据
 @param selectedCallback 设置点击回调
 @param height AUVerticalTabView高度
 @param business 业务标示,如:GoldWord,BeeCityPicker
 @return AUVerticalTabView
 */
+ (AUVerticalTabView *)verticalTabViewWithDatas:(NSArray <id<AUVerticalTabViewDataProtocol>>*) verticalTabViewDatas
                               selectedCallback:(AUVerticalTabSelectedCallback)selectedCallback
                                         height:(CGFloat)height
                                       business:(NSString *)business;

@property(nonatomic, strong) NSArray <id<AUVerticalTabViewDataProtocol>>* verticalTabViewDatas;
@property(nonatomic, assign) NSUInteger selectedIndex;//default 0
@property(nonatomic, copy) AUVerticalTabSelectedCallback selectedCallback;

@end

#endif//程序自动生成
