#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BubbleView_AUBubbleView//程序自动生成
//
//  AUBubbleView.h
//  AntUI
//
//  Created by 沫竹 on 2018/5/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>

typedef NS_ENUM(NSInteger, AUBubbleViewPosition) {
    AUBubbleViewPositionLeft,
    AUBubbleViewPositionRight,
    AUBubbleViewPositionCenter
};

@interface AUBubbleView : AUView

AU_UNAVAILABLE_INIT


/**
 展示一个红点气泡

 @param text 文案
 @param view 从哪个视图开始展示
 @param postion 位置
 @return AUBubbleView实例
 */
+ (instancetype)showText:(NSString *)text
                fromView:(UIView *)view
                position:(AUBubbleViewPosition)postion;

- (void)dismiss:(BOOL)animated;

@end




#endif//程序自动生成
