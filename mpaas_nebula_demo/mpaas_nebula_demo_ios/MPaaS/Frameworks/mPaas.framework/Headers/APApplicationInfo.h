//
//  APApplicationInfo.h
//  MobileFoundation
//
//  Created by liangbao.llb on 9/22/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, APProductType) {
    APProductTypeNone = 0,  // 未定义
    APProductTypeDev,       // 开发包
    APProductTypeTest,      // 测试包
    APProductTypeRC,        // RC包
    APProductTypeRelease,   // 正式包或灰度包
    APProductTypeBeta,      // 内测版
};


@interface APApplicationInfo : NSObject

/**
 *  获取应用程序相关信息单例对象，为较少内存占用修改成类方法。
 *
 *  @return 返回应用程序相关信息单例对象。
 */
//+ (instancetype)sharedInstance;

/**
 *  获取当前包类型。
 *
 *  @return 返回当前包的类型。
 */
+ (APProductType)productType;

/**
 *  获取当前客户端的ID，info.plist中对应Key："Product Name"。
 *  注意：作为客户端标识，不区分平台和版本。
 *
 *  @return 返回当前客户端的ID。
 */
+ (NSString *)productName;

/**
 *  获取配置文件里原始Product Id。
 *
 *  @return 返回原始Product Id。
 */
+ (NSString *)originalProductId;

/**
 *  获取配置文件里原始APProductType。
 *
 *  @return 返回原始APProductType。
 */
+ (NSString *)originalProductType;

/**
 *  判断当前客户端系统设置推送开关是否打开。
 *
 *  @return 打开返回YES，否则返回NO。
 */
+ (BOOL)isPushEnabled;

/**
 *  判断当前客户端能否打开“通知”设置或当前App的系统设置。
 *
 *  @return 能打开返回YES，否则返回NO。
 */
//+ (BOOL)canOpenPushSetting;

@end
