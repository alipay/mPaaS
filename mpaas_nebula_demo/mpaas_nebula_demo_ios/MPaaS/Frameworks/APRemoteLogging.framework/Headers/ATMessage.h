//
//  ATMessage.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATEvent.h"

/**
 * 经过渲染的埋点内部消息对象
 */
@interface ATMessage : NSObject
@property (nonatomic, strong) ATEvent *event;    /**< 埋点参数对象*/
@property (nonatomic, strong) NSString *content; /**< 埋点内容字符串*/
@end
