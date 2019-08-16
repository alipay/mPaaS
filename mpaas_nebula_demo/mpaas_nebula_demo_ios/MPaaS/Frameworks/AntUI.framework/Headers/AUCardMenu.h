#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_CardMenu_AUCardMenu//程序自动生成
//
//  AUCardMenu.h
//  AntUI
//
//  Created by 祝威 on 16/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUWindow.h"

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aucardmenu
//#########################################################

AntUI_dependency(AUWindow)

@class AUMultiStyleCellView;
@class AUWindow;
/*！
 @class       AUCardMenu
 @abstract    AUWindow
 @discussion  带 蒙层 + 方向角 的弹出菜单
*/

@interface AUCardMenu : AUWindow
{
    
}

/**
 *  若需要响应点击事件，需要对 cellView 实现 AUMultiStyleCellDelegate 协议
 *  在自己的viewcontroller中赋值 popMenuView.cellView.delegate = self;
 */
@property (nonatomic, strong) AUMultiStyleCellView *cellView;

/**
 *  初始化方法（墙裂推荐此方法）
 *
 *  @param data      数组存放对象模型 CellDataModel
 *  @param location  方向角的基准点
 *  @param offset    方向角相对基准点的偏移量
 *
 *  @return self
 */

- (instancetype)initWithData:(NSArray *)data
                    location:(CGPoint)location
                      offset:(CGFloat)offset;

/**
 * 展示弹出菜单
 *
 *  @param superView  PopMenuView的superView
 */
- (void)showPopMenu:(UIView *)superView;

// 隐藏弹出菜单，最好在dealloc方法里也调用
- (void)hidePopMenu;

// 注意：带动画方式的展示或消失必须成对使用，即 动画出现必须动画消失，非动画出现必须非动画消失

// 带有动画方式的展示菜单
- (void)showPopMenu:(UIView *)superView animation:(BOOL) isAnimation;

// 带动画方式的消失菜单
- (void)hidePopMenuWithAnimation:(BOOL)isAnimation;

@end

#endif//程序自动生成
