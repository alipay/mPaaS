//
//  NBSession.h
//  NBService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBSessionContext.h"

@class NBSessionDelegate;

@interface NBSession : NSObject

@property(nonatomic, strong) NBSessionDelegate          *delegate;
@property(nonatomic, readonly, strong) NBSessionContext *context;

- (void)loadDataSourceForApps:(NSArray *)arrApps;
/**
 *  @brief 返回当前资源管理中指定url的离线缓存
 *  @return 自定义离线数据源(子类重写该方法，返回新容器的离线数据)
 */
- (id<NebulaAppResponseProtocol>)appResponseForUrl:(NSString *)url;
@end
