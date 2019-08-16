//
//  MPRemoteLoggingInterface.h
//  MPMasAdapter
//
//  Created by kuoxuan on 2019/2/22.
//  Copyright © 2019 mPaaS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPRemoteLoggingInterface : NSObject


/**
 *  行为埋点接口。客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *  @param bizType  可选，业务类型，默认为 behavior，建议业务方填写业务标识
 *  @param eventId  必填, 埋点ID
 *  @param extParam 可选，扩展参数，业务自己根据需要填充。元素是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志。
 */
+ (void)writeLogWithBizType:(NSString *)bizType
                     eventId:(NSString *)eventId
                    extParam:(NSDictionary *)extParam;


/**
 *  行为埋点接口。客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *  bizType 默认为 behavior
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param eventId      可选，埋点ID
 *  @param extParam 可选，扩展参数，业务自己根据需要填充。元素是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志。
 */
+ (void)writeLogWithActionId:(NSString *)actionId
                        eventId:(NSString *)eventId
                    extParam:(NSDictionary *)extParam  __attribute__((deprecated("请使用 writeLogWithBizType:eventId:extParam 方法")));


/**
 * 强制上报内存中还未上报的日志
*/
+ (void)upload;


@end

NS_ASSUME_NONNULL_END
