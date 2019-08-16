//
//  TYTinyAppMonitor.h
//  TianYan
//
//  Created by qiwei on 2017/3/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYTinyAppMonitor : NSObject

/**
 启动监控

 @param appInfo {
    @"app_id" : @"32342342",
    @"app_type":@(1),
 }
 
代码中app_type 定义：
    不存在 - 主程序的卡顿流畅埋点中
    0 - 目前没有此值
    1 - 小程序
    2 - H5
    3 - ReactNative（目前没有，猜测未来会有）

详细文档见：
    http://gitlab.alipay-inc.com/qiwei.zf/somedoc/blob/master/%E5%B0%8F%E7%A8%8B%E5%BA%8F%E6%80%A7%E8%83%BD%E5%9F%8B%E7%82%B9.md
 */
+ (void)start:(NSDictionary *)appInfo;
+ (void)stop;

+ (BOOL)isTinyAppNow:(NSString **)tinyAppId tinyAppType:(NSNumber**)tinyAppType;

@end
