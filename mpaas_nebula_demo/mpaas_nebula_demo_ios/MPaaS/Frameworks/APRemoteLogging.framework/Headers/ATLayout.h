//
//  ATLayout.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATEvent.h"
#import "ATMessage.h"

/**
 * 渲染器基类
 */
@interface ATLayout : NSObject

/**
 * 开始渲染前. 基类实现为空, 子类可覆盖实现填充埋点参数对象中的默认字段.
 * @param event 埋点参数对象
 */
- (void)beforeLayout:(ATEvent *)event NS_REQUIRES_SUPER;

/**
 * 执行渲染. 基类中取\c event 中各字段拼接成字符串
 * @param event 埋点参数对象
 * @return 内部消息对象.  @see \c ATMessage.
 */
- (ATMessage *)layout:(ATEvent *)event;

/**
 * 渲染后. 基类中对msg.content进行加密.
 * @param msg 经过渲染的内部消息对象
 */
- (void)afterLayout:(ATMessage *)msg NS_REQUIRES_SUPER;

/**
 * 获取一个自增的序列号
 */
- (NSString *)sequenceIdString;

/**
 * 将NSDate类型的时间戳转换成NSString类型.
 */
- (NSString *)stringFromDate:(NSDate *)date;

/**
 * 将NSDictionary转换成key=value^key=value格式的字符串
 */
- (NSString *)stringFromDictionary:(NSDictionary *)dict;

/**
 * 填充ABTestInfo
 */
- (void)fillABTestInfo:(ATEvent *)et forSpm:(NSString *)spmId;

/**
 * 填充configABTestInfo 
 */
- (void)fillConfigABTestInfo:(ATEvent *)et;


@end
