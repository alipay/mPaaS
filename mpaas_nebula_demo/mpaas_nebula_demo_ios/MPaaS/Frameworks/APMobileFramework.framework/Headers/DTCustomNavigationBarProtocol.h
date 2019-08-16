//
//  DTCustomNavigationBarProtocol.h
//  APMobileFramework
//
//  Created by yangwei on 16/5/14.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DTCustomNavigationBarProtocol <NSObject>
@optional
/**
 *  自定义titleView，且自定义的返回item时，请实现此代理方法
 *
 *  @return
 */

- (UIBarButtonItem *)leftCustomNavigationBarButtonItem;

/**
 *  自定义titleView（如：目前为APNavSearchTitleView）
 *
 *  @return
 */
- (UIView *)middleNavSearchTitleView;


/**
 *  自定义titleview，且需设置rightBarButtonItem，请实现此代理方法
 *
 *  @return
 */
- (UIBarButtonItem *)rightCustomNavigationBarButtonItem;

/**
 *  自定义titleview，且导航栏右侧有多个item时，请实现此方法
 *
 *  @return 需要展示的icon
 */
- (NSArray <UIView *> *)rightCustomNavigationBarButtonItemWithViews;
@end
