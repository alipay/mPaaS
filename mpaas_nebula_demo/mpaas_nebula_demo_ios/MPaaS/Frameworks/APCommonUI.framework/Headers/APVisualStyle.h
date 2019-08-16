//
//  APVisualStyle.h
//  APCommonUI
//
//  Created by WenBi on 14-1-16.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @addtogroup APCommonUI
 * @{
 *
 * @defgroup APVisualStyle
 * @{
 */

/**
 *  控件的显示样式。
 *
 *  一个<code>APVisutalStyle</code>的对象会在<code>-[UIView initWithFrame:]</code>中被创建出来，
 *  创建的工作由<code>APVisualStyleFactory</code>类完成。
 *
 *  你不能在<code>apply</code>方法中修改目标view对象的frame，
 *  因为这个方法是在目标view的frame改变时调用的，如果在这个方法中改变目标view的frame，
 *  会产生死循环。
 */
@interface APVisualStyle : NSObject

/**
 *  附加当前样式的view对象。
 */
@property(nonatomic, weak) UIView *target;

/**
 *  应用样式。（基类并未实现）
 */
- (void)apply;

@end

/**
* @}
* @}
*/
