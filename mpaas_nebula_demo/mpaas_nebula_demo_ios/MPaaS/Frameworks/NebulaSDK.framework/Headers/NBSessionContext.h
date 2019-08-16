//
//  NBSessionParam.h
//  NBService
//
//  Created by chenwenhong on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NBAppDataSourceManager;
@class NBAppConfigManager;

typedef enum : NSUInteger {
    NBSessionType_Online = 0,
    NBSessionType_Offline,
} NBSessionType;

@interface NBSessionContext : NSObject

@property(nonatomic, copy) NSString                     *nbl_id;
@property(nonatomic, assign) NBSessionType              sessionType;
@property(nonatomic, strong) Class                      viewControllerClass;
@property(nonatomic, strong) Class                      contentViewClass;
@property(nonatomic, strong) NSDictionary               *params;
@property(nonatomic, weak) UIViewController             *rootViewController; // 根vc
@property(nonatomic, weak) PSDSession                   *psdSession; // 对应的session
@property(nonatomic, strong) NBAppDataSourceManager     *appDataSourceManager; // app离线资源包数据源
@property(nonatomic, strong) NBAppConfigManager         *appConfigManager; //app配置源
@property(nonatomic, strong) NSDictionary               *expando;

@end
