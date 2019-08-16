#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUActionSheet//程序自动生成
//
//  AUActionSheetAnimation.h
//  AntUI
//
//  Created by QiXin on 2017/3/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUActionSheetAnimation : NSObject

@property (nonatomic, strong, readonly) UIView *curContentView;
@property (nonatomic, assign) NSTimeInterval animationDuration; // default 0.5

- (void)showWithContentView:(UIView *)contentView;
- (void)dismiss;

@end

#endif//程序自动生成
