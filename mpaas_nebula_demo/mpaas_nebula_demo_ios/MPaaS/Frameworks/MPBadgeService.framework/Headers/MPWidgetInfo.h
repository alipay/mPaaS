//
//  MPWidgetInfo.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/14/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPWidgetInfo : NSObject

@property(nonatomic, strong) NSString *widgetId;                // 红点控件ID
@property(nonatomic, strong) NSString *style;                   // 红点显示样式
@property(nonatomic, strong) NSDictionary *styleCountMap;       // 红点显示样式详情
@property(nonatomic, assign) BOOL bNeedAck;                     // 标示处理点击事件
@property(nonatomic, assign) NSUInteger temporaryBadgeNumber;   // 临时红点总数
@property(nonatomic, assign) NSUInteger persistentBadgeNumber;  // 持久红点总数

/**
 * 创建红点控件信息
 *
 * @param widgetId 红点控件ID
 *
 * @return 红点控件信息
 */
- (id)initWithId:(NSString *)widgetId;

@end
