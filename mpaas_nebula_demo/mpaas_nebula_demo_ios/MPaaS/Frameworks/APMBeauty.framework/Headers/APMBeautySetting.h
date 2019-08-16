//
//  APMBeautySetting.h
//  APMBeauty
//
//  Created by Cloud on 16/7/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    APMBeautyAlgorithmTypeFalcon, // 猎鹰团队算法
} APMBeautyAlgorithmType;

/**
 * 美颜算法配置，指定不同机型下用不同类型的配置
 */
@interface APMBeautySetting : NSObject

/**
 *  美颜算法类型
 */
@property (nonatomic, assign) APMBeautyAlgorithmType algorithm;

/**
 *  新美颜，使用 复杂还是简单 算法, falcon算法的配置项
 */
@property (nonatomic, assign) BOOL isHighDegree;

/**
 *  共享对象
 *
 *  @return 共享的对象
 */
+ (instancetype)sharedInstance;

/**
 *  使用sharedInstance，别用init
 *
 *  @return 对象
 */
- (instancetype)init __attribute__((unavailable("init not available")));

@end

