#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_FloatMenu_AUFloatMenu//程序自动生成
//
//  AUFloatMenu.h
//  AntUI
//
//  Created by 祝威 on 16/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aufloatmenu
//#########################################################


#define UI_AUFloatMenu

/**popview消失的通知*/
static NSString * const APExtUIPopViewDissmissedNotification = @"APExtUIPopViewDissmissedNotification";



@class AUNavItemView;
/*！
 @class       AUFloatMenu
 @abstract    UIView
 @discussion  floatViewMenu浮层
 */
@interface AUFloatMenu : UIView<UIGestureRecognizerDelegate>

@property (nonatomic, copy) NSString *bizType;            // 业务标识，须传

@property(nonatomic, assign) CGFloat marginToRight;  // 白色popview距离屏幕右侧的距离，不设置默认为10

/**
 *  创建浮动菜单视图
 *
 *  @param position        方向角在屏幕上展示的位置
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *  @param withEdging      是否展示外边框
 *  @return 浮动菜单视图
 */
-(instancetype)initWithPostion:(CGPoint)position items:(NSArray<AUNavItemView *> *)items;

/*
 * 带动画展出
 */

- (void)showWithAnimated:(BOOL)animated withMskView:(BOOL)withMskView;
    
//- (void)showWithAnimated:(BOOL)animated; //

/**
 *  创建浮动菜单视图
 *
 *  @param position        浮动菜单在屏幕上展示的位置
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *
 *  @return 浮动菜单视图
 */
+(AUFloatMenu *)showAtPostion:(CGPoint)position items:(NSArray<AUNavItemView *> *)items;

/**
 *  创建浮动菜单视图
 *
 *  @param position        浮动菜单在屏幕上展示的位置
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *
 *  @return 浮动菜单视图
 */
+(AUFloatMenu *)showAtPostion:(CGPoint)position
                        items:(NSArray<AUNavItemView *> *)items
                      bizType:(NSString *) bizType;

/**
 *  创建浮动菜单视图
 *
 *  @param position        浮动菜单在屏幕上展示的位置
 *  @param orignY          浮动菜单在屏幕上y坐标值
 *  @param items           展示的内容数组，一般为APNavItemView对象
 *
 *  @return 浮动菜单视图
 */
+(AUFloatMenu *)showAtPostion:(CGPoint)position startOrignY:(CGFloat)orignY items:(NSArray<AUNavItemView *> *)items;

/**
 *  浮动菜单消失接口方法
 */
-(void)dismiss;

/**
 *  菜单点开后发rpc加载动态下发菜单项，rpc完成后调update，完成旧view移出，添加新view的过程
 */
- (void)updateWithItems:(NSArray<AUNavItemView*> *)items;


/**
 对外暴露方法，开放小三角形图标左右位置，供业务方定制

 @param xLeft  x轴位置
 */
- (void)updateArrIconFrameX:(CGFloat) xLeft;

/**
 对外暴露方法，供业务方获取菜单的实际宽度
 @return 菜单的宽度
 */
- (CGFloat)getContentWidth;

@end

#endif//程序自动生成
