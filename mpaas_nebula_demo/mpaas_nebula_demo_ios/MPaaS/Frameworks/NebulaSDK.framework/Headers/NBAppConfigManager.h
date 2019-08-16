//
//  NBAppConfigManager.h
//  NebulaSDK
//
//  Created by theone on 17/3/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBAppConfigManager : NSObject

- (instancetype)initWithConfig:(NSDictionary *)config;

/**
 *  合并配置文件中的参数到context中
 *
 *  @date 2017-03-07
 *
 */
- (void)mergeAppConfigParamsToContextParams:(NBSessionContext *)context;


/**
 *  依据Tag来合并的为最终参数
 *
 *  @date 2017-03-07
 *
 */
- (NSDictionary *)mergeParams:(NSDictionary *)params withTag:(NSString*)tag;
@end
