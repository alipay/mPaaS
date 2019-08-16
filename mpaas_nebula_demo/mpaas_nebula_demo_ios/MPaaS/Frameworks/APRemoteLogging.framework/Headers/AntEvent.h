//
//  AntEvent.h
//  APRemoteLogging
//
//  Created by LiMengtian on 2018/10/29.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import "ATEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface AntEvent : ATEvent

@property (nonatomic, copy) NSString *eventId;      /**< 字段10，事件ID 必填 */
@property (nonatomic, copy)   NSString *bizType;    /**< 字段11,业务类型,可用于控制日志分文件存储以及上报 必填*/
@property (nonatomic, assign) AntLogLevel logLevel; /**< 字段12,日志等级,可用于控制日志上报*/
@property (nonatomic, copy) NSDictionary *extParam4;/**< 字段37,扩展字段4,将key-value对转换成‘key=value^key1=value1’的形式落入日志.*/

@property (nonatomic, assign) BOOL needTrackABTestInfo; /**是否记录ABTestInfo 默认NO */

@end

NS_ASSUME_NONNULL_END
