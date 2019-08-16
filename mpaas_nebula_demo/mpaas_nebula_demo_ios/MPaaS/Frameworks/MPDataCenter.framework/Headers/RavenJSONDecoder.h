//
//  RavenJSONDecoder.h
//  APJSONKit
//
//  Created by pucheng on 16/5/19.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, RavenJSONReadingMutabilityOptions)
{
    RavenJSONReadingImmutable = 0,
    RavenJSONReadingMutableContainers,
    RavenJSONReadingMutableContainersAndLeaves
};

extern NSString * const NSRavenClassCastExpcetion;

@interface RavenJSONDecoder : NSObject

/**
 *  创建获取一个反序列化对象。
 *
 *  @return 反序列化对象。
 */
+ (RavenJSONDecoder *)decoder;

/**
 *  将JSON格式字符串反序列化成OC对象。
 *
 *  @param string       指定的json字符串。
 *
 *  @return OC对象。
 */
- (id)decodeFromJSONString:(NSString *)JSONString options:(RavenJSONReadingMutabilityOptions)options;

@end
