//
//  APMCacheItem.h
//  APMCache
//
//  Created by Cloud on 16/8/31.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMCacheItem : NSObject

@property (nonatomic, assign) NSUInteger record_id;///< 表纪录主键
@property (nonatomic, strong) NSString *key;       ///< key
@property (nonatomic, strong) NSString *aliasKey;  ///< key的别名
@property (nonatomic, strong) NSData *value;       ///< 存储的对象，可能为nil
@property (nonatomic, strong) NSString *filename;  ///< 文件名
@property (nonatomic, assign) int64_t size;        ///< 存储对象的大小，可能存储在数据的value中，也可能存在磁盘中，单位字节
@property (nonatomic, assign) int modifyTime;      ///< 文件最后修改时间，unix时间戳
@property (nonatomic, assign) int accessTime;      ///< 文件最后访问时间，unix时间戳
@property (nonatomic, assign) int expirationTime;  ///< 文件过期时间，unix时间戳

@property (nonatomic, assign) NSUInteger type;     ///< 存储的对象类型
@property (nonatomic, strong) NSString *business;  ///< 业务标示
@property (nonatomic, assign) NSUInteger tag;      ///< 文件对应的标签
@property (nonatomic, strong) NSString *info;      ///< 文件信息，比如图片宽高的组合信息，各类文件自定义

@end
