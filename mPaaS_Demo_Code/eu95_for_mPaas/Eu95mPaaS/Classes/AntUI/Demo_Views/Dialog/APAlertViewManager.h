//
//  APAlertViewManager.h
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface APAlertViewManager : NSObject<UIAlertViewDelegate>

@property(nonatomic,assign)bool isBackGroundMode;//是否是后台模式

/**
 *  创建APAlertViewManager对象，用来管理屏幕上所有的alertView
 *
 *  @return 初始化的APAlertViewManager
 */
+ (APAlertViewManager *)sharedAPAlertViewManager;

/**
 *  显示alertView，若为后台模式，押入后台池保存；否则立即前台显示
 *
 *  @param alertview 需要显示的alertView
 */
- (void)pushAPAlertView:(UIAlertView *)alertview;

/**
 *  删除所有的alert，包括已经存在的AlertView界面窗口和后台预备的alerview
 */
- (void)removeAllAlertView;

@end
