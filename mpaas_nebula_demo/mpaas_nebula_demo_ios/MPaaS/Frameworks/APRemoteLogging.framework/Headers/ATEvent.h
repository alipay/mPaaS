//
//  ATEvent.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"
#import "ATConfigMgr.h"

/**
 * 埋点参数对象基类
 */
@interface ATEvent : NSObject

@property (nonatomic, copy) NSString *log;      /**< 自定义日志内容*/
@property (nonatomic, copy) NSString *bizType;    /**< 所属业务类型*/
@property (nonatomic, assign) AntLogLevel logLevel; /**< 日志等级*/
@property (nonatomic, copy) NSString *ABTestInfo;
@property (nonatomic, copy) NSDictionary *extParam4;

/**
 * 最终渲染到日志中时取ATEvent的属性名称列表. 各日志模型自行覆盖实现.
 * 如基类中返回 @[@"bizType",@"logLevel",@"log"]
 */
+ (NSArray<NSString *> *)fieldNames;

@end

@interface ATEvent (/**internal*/)
@property (nonatomic, strong) ATConfig *config; /**< 配置信息,私有*/
@end

@interface ATEvent (/**Deprecated*/)
@property (nonatomic, assign) NSUInteger maxLogCount; /**< 上报条数阈值,兼容老keybiztrace埋点*/
@end

