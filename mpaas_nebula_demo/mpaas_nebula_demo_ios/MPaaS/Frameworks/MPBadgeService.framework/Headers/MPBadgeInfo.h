//
//  MPBadgeInfo.h
//  MPBadgeService
//
//  Created by liangbao.llb on 12/9/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPBadgeInfo : NSObject

@property(nonatomic, copy)   NSString *badgeId;  // 红点路径ID
@property(nonatomic, copy)   NSString *style;    // 控件显示样式；五种：hui(惠) > xin(新) > new > num > point
@property(nonatomic, copy)   NSString *bizId;    // 业务ID
@property(nonatomic, copy)   NSString *userId;   // 用户ID
@property(nonatomic, assign) NSUInteger temporaryBadgeNumber;   // 临时红点，点击即消失，不上报服务端
@property(nonatomic, assign) NSUInteger persistentBadgeNumber;  // 持久红点，点击上报服务端，服务端控制消失

/**
 * 创建红点数据
 *
 * @param badgeId 红点路径ID
 *        注意：若存在父子关系时，用逗号分割，如:"#M_PUBLIC_RD#2013112300002181,#M_TRANS_RD#2088502524001315"
 *
 * @return 红点数据
 */
+ (MPBadgeInfo *)badgeInfoWithBadgeId:(NSString *)badgeId;

/**
 * 获取红点路径上的所有红点控件ID，内部使用函数
 *
 * @param 无
 *
 * @return 返回红点控件ID
 */
- (NSArray *)allWidgetIds;

@end
