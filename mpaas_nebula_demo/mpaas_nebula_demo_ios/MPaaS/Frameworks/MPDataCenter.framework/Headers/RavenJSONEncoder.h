//
//  RavenJSONEncoder.h
//  APJSONKit
//
//  Created by pucheng on 16/5/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  @return 一个需要被过滤的属性名的set
 */
@protocol RavenJSONEncoderPropertyFilterProtocol

- (NSSet *)RavenJSONEncoderPropertyFilter;

@end

@interface RavenJSONEncoder : NSObject

/**
 *  创建获取一个序列化对象
 *  encoder的对象不要层次超过10次 会assert。
 *  encoder的对象实现的协议不要是继承NSObject的, 这样的对象会加上NSObject协议里的四个属性hash superclass description debugDescription 层次很有可能会超过10层
 *
 *  @return 一个RavenJSONEncoder对象
 */
+ (RavenJSONEncoder *)encoder;

/**
 *  序列化一个OC对象为JSON格式，该OC对象中的非property变量和struct不进行序列化
 *
 *  @param OC对象
 *
 *  @return 序列化后的JSON格式字符串
 */
- (NSString *)encodeObject:(id)object;

@end

