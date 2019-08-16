//
//  MPaaSConfigInfo.h
//  APMPaaS
//
//  Created by yangwei on 17/4/25.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPaaSConfigInfo : NSObject

/**
 *  当前App的无线保镖图片，是否需要区分平台。
 *  设置为NO，表示无线保镖SDK不需要区分平台，使用默认的 yw_1222.jpg 安全图片；
 *  设置为YES，表示无线保镖SDK需要区分平台，通过分配的 authCode，来指定在当前App中使用的无线保镖安全图片，并将图片设置为yw_1222_authCode.jpg；
 *
 *  默认返回为NO。钱包中不需要关心；
 *  mPaaS用户一般也不需要修改，只有在 yw_1222.jpg 图片与其他平台发生冲突时（如同时使用 mPaaS与阿里百川相关服务），需要在 category 中重写此方法，返回YES来区分图片。
 *
 * @return 默认返回NO
 */
+ (BOOL)enableMPaaSAuthCode;

/**
 *  获取设置无线保镖接口的authCode值
 *
 *  根据 < enableMPaaSAuthCode > 的返回值，若为NO，此方法返回nil；若为 YES，此方法返回 @"1000"；
 *  钱包中默认为nil，mPaaS 用户根据需要重写 < enableMPaaSAuthCode > 方法
 *
 *  @return 默认返回 nil
 */
+ (NSString *)openSecurityAuthCode;

@end
