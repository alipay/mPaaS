//
//  NBFullLinkUtil.h
//  NebulaLogging
//
//  Created by 张光宇 on 2018/12/18.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NBFullLinkUtil : NSObject

/**
 * 在全链路上添加*业务*埋点
 * infoKey: 业务Key
 * value: 埋点值
 * appId: 当前appId
 */

+ (void)addBizAttr:(NSString *)infoKey value:(NSString *)infoValue appId:(NSString *)appId;

+ (void)addTimeStub:(NSString *)stubName appId:(NSString *)appId;

//+ (void)markPerfStub:(NSString *)stubName withTime:(CFTimeInterval)mediaTime appId:(NSString *)appId;
//
//+ (void)markPerfCost:(NSString *)stubName costInMs:(NSUInteger)costInMs appId:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
