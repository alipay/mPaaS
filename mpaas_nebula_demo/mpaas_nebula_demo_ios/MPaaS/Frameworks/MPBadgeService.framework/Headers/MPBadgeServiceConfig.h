//
//  MPBadgeServiceConfig.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/16/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MPBadgeServiceConfig <NSObject>

/**
 * 点击上报
 *
 * @param widgetIds  上报数据
 * @param completion 上报完成回调
 *
 * @return 无
 */
- (void)ack:(NSArray *)widgetIds completion:(void (^)(BOOL success))completion;

/**
 * 字符串加密
 *
 * @param string    待加密的字符串
 *
 * @return 加密后的字符串
 */
- (NSString *)encryptString:(NSString *)string;

@end
