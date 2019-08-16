//
//  AUPopMsgView.h
//  AntUI
//
//  Created by niki on 2018/11/21.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUPopDrawBoardView.h"

NS_ASSUME_NONNULL_BEGIN

// 主副标题同时居左或者h同时居中
typedef NS_ENUM(NSInteger, AUPopMsgViewLabelAlignment) {
    AUPopMsgViewLabelAlignmentLeft = 1, // default
    AUPopMsgViewLabelAlignmentCenter = 2,
};


// 左边支持自定义icon + 右边支持
@interface AUPopMsgView : AUPopDrawBoardView

+ (instancetype)showFromView:(UIView *)fromView
                   fromPoint:(CGPoint)fromPoint
                      toView:(UIView *)toView
                    withIcon:(UIImage *)image
                       title:(NSString *)title
                    descText:(NSString *)descText;
//
- (void)dismiss;

//
- (void)setPopMsgViewLabelAlignment:(AUPopMsgViewLabelAlignment)alignment;

@end

NS_ASSUME_NONNULL_END
