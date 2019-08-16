#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BadgeView_AUBadgeView//程序自动生成
//
//  AUBadgeView.h
//  AntUI
//
//  Created by jinzhidong on 2018/3/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    AUBadgeViewStyleNone,   //清除红点内容, attributes传nil
    AUBadgeViewStyleRedDot, //红点,无内容, attributes传nil
    
    /*
     红点+内容, attributes:@{kAUBadgeViewAttributeKeyText:@"热门"}
     value.length==0视为异常值直接return,本次调用不做任何操作,保持AUBadgeView原先状态.
     */
    AUBadgeViewStyleText,
    
    /*
     红点+数字, attributes:@{kAUBadgeViewAttributeKeyNumber:@(value)}
     value:1-99显示实际数字;大于99显示（...）;
     0或负数视为异常值,直接return,本次调用不做任何操作,保持AUBadgeView原先状态.
     */
    AUBadgeViewStyleNumber
} AUBadgeViewStyle;

#define kAUBadgeViewAttributeKeyText @"kAUBadgeViewAttributeKeyText"
#define kAUBadgeViewAttributeKeyNumber @"kAUBadgeViewAttributeKeyNumber"
/**
 *是否需要描边
 * @YES :需要描边
 */
#define kAUBadgeViewAttributeKeyStrokeEnabled @"kAUBadgeViewAttributeKeyStrokeEnabled"
//文本条件下最多几个汉字，最多设置6个。
//10.1.32
#define kAUBadgeViewAttributeKeyMaxTextLength @"kAUBadgeViewAttributeKeyMaxTextLength"

@interface AUBadgeView : UIView

@property(nonatomic,assign) AUBadgeViewStyle badgeViewStyle;

/**
 根据style绘制红点内容.
 
 @param style AUBadgeViewStyle
 @param attributes 见AUBadgeViewStyle定义
 @return YES:执行了绘制操作(建议重新布局); NO:判断为reuse,不重绘.
 */
- (BOOL)drawBadgeWithStyle:(AUBadgeViewStyle)style
                attributes:(NSDictionary *)attributes;

@end

#endif//程序自动生成
