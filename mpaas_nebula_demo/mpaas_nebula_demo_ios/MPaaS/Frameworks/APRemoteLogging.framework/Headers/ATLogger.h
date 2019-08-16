//
//  ATLogger.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATEvent.h"
#import "ATLayout.h"

/**
 * Logger基类
 */
@interface ATLogger : NSObject

/**
 * 渲染器
 */
@property (nonatomic, strong) ATLayout *layout;

/**
 * 写入log
 * @param event 埋点参数对象
 */
- (void)log:(ATEvent *)event;

@end

