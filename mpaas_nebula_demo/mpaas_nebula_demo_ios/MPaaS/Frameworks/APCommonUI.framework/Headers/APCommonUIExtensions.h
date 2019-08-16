//
//  APView.h
//  APCommonUI
//
//  Created by WenBi on 14-1-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APVisualStyle;

/**
 * @addtogroup APCommonUI
 * @{
 */

/**
 *  对 <code>UIView</code> 的扩展，用于实现视图样式管理。
 *
 *
 *  视图样式会在这个函数中进行初始化：
 *  <blockquote>- (id)initWithFrame:(CGRect)frame</blockquote>
 *
 *
 *  视图样式会在下面的函数调用时，应用到视图上：
 *  <blockquote>- (void)setFrame:(CGRect)frame</blockquote>
 *
 *  当前的样式改变时，会自动将新的样式应用到当前视图。
 *
 *  如果你想让你的视图不创建默认样式，或者想自定义视图样式时，可以不调用<code>initWithFrame:</code>方法，
 *  而是按以下的方法写：
 *  <blockquote><pre>
 *  @@implementation MyControl
 *  -&nbsp;(id)initWithFrame:(CGRect)frame
 *  {
 *      self = [super init];
 *      if (self) {
 *          self.frame = frame;
 *      }
 *  }
 *  </pre></blockquote>
 */
@interface UIView (APCommonUIExtensions)

/** 视图样式 */
@property(nonatomic, strong) APVisualStyle *visualStyle;

@end

/**
 *  UIScrollView底部添加蚂蚁金服品牌文案说明
 *  默认不显示，需要显示的UIScrollView，请设置alipayShouldShow = YES
 */
//@interface UIScrollView (APCommonUIExtensions)
//
//@property(nonatomic, strong) UILabel *alipayBrandLabel;  // 底部品牌文案
//@property(nonatomic, assign) BOOL alipayShouldShow;      // 是否显示，默认不显示
//
//@end
