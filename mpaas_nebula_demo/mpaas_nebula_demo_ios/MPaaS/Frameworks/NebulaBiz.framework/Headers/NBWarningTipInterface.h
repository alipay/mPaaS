//
//  NBWarningTipInterface.h
//  NebulaBiz
//
//  Created by 张光宇 on 2019/2/21.
//  Copyright © 2019 Alipay. All rights reserved.
//

@protocol NBWarningTipInterface <NSObject>


/**
 添加三方页面访问提示公告投放
 
 @param vc 展示的窗口对象
 @param autoHide 是否5秒内自动隐藏
 */
+ (void)addVisitTipWithVC:(H5WebViewController *)vc
                 autoHide:(BOOL)autoHide;


/**
 添加三方页面输入提示公告投放
 
 @param vc 展示的窗口对象
 */
+ (void)addInputTipWithVC:(H5WebViewController *)vc;

- (BOOL) isWarningVisit;

@end
