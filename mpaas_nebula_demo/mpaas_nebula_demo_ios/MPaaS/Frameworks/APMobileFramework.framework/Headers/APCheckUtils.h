//
//  APCheckUtils.h
//  APMobileFramework
//
//  Created by liangbao.llb on 16/4/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APCheckUtils : NSObject

/**
 * 检查导航栏显示是否正常。
 * 注意：要在主线程里调用。
 *
 * @param navCtrl 导航控制器。
 *
 */
+ (void)checkNavigationBar:(UINavigationController *)navCtrl;

#pragma - 内部接口不要直接调用。
+ (BOOL)checkOperationInMainThread:(NSString *)operation object:(id)object;
+ (BOOL)checkNavigationItemStack:(UINavigationController *)navCtrl;
+ (BOOL)checkNavigationItemStackWithViewController:(UIViewController *)viewController;


@end
