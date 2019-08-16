#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUView//程序自动生成
//
//  AUView+MaskView.h
//  AntUI
//
//  Created by 沫竹 on 2018/3/16.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUView.h"

@interface AUView (MaskView)

/**
 在父view上面显示一个遮罩层
 
 @param maskColor 遮罩层，传递nil，表示使用默认色
 @param hideByTouch 遮罩层是否支持点击就消失掉
 @param animated 是否使用动画显示
 @return 遮罩视图
 */
- (UIView *)showMaskView:(UIColor *)maskColor
                animated:(BOOL)animated
             hideByTouch:(BOOL)hideByTouch
               hideBlock:(dispatch_block_t)hideBlock;

/**
 隐藏遮罩层
 @param animated 是否使用动画隐藏
 */
- (void)hideMaskView:(BOOL)animated;

@end

#endif//程序自动生成
