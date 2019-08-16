//
//  APMapRoadInter.h
//  APMap
//
//  Created by Wanlei on 14-5-5.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//



@protocol APMapRoadInter <NSObject>


/**
 * 方位
 */

@property(nonatomic, strong) NSString *direction;
/**
 * 距离
 */

@property(nonatomic, assign) double distance;
/**
 * 纬度
 */

@property(nonatomic, assign) double latitude;
/**
 * 经度
 */

@property(nonatomic, assign) double longitude;
/**
 * 第一节点ID
 */

@property(nonatomic, strong) NSString *firstId;
/**
 * 第一节点名称
 */

@property(nonatomic, strong) NSString *firstName;
/**
 * 第二节点ID
 */

@property(nonatomic, strong) NSString *secondId;
/**
 * 第二节点名称
 */

@property(nonatomic, strong) NSString *secondName;



@end
