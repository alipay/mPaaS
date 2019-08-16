//
//  AUNavigationConstants.h
//  AntUI
//
//  Created by niki on 2019/1/9.
//  Copyright © 2019年 Alipay. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 *  获取导航栏上返回按钮返回箭头调整单位值
 */
CGFloat AUBackButtonImageFixedSpace();

/**
 *  获取导航栏上返回按钮距离设备的间距
 */
CGFloat AUGetBackButtonToDeviceSpace();

/**
 *  获取导航栏上获取titleView与返回箭头的最小间距
 */
CGFloat AUGetTitleViewToBackBtnMinSpace();

/**
 *  获取导航栏上获取titleView与设备边沿的最小间距，用于没有返回箭头时的场景
 */
CGFloat AUGetTitleViewToDeviceMinSpace();

NS_ASSUME_NONNULL_END
