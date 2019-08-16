//
//  CacheUtils.h
//  APMultimedia
//
//  Created by brightzheng on 16/1/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_OPTIONS(NSUInteger, CacheDeleteOptions) {
    /**
     * 删除所有
     */
    CacheDeleteAll = 0,
    
    /**
     * 缩略图不删
     */
    CacheDeleteThumbnail = 1 << 0,
    
    /**
     * 视频首帧图不删除
     */
    CacheDeleteVideoThumbnail = 1 << 1,
    
    /**
     * 14天小视频不删除
     */
    CacheDeleteLocalHistoryVideo = 1 << 2,
    
};



@interface CacheUtils : NSObject

/**
 * 删除某bussId下所有的disk缓存
 * ***同步方法，等待清除之后再返回***
 */
+ (void)deleteCacheForBusiness:(NSString *)business;

/**
 * 删除oldTime之前所有bussId下的disk缓存
 * ***同步方法，等待清除之后再返回***
 */
+ (void)deleteCacheForBusiness:(NSString *)business oldTime:(NSTimeInterval)oldTime;

/**
 * 删除oldTime之前所有bussId下的disk缓存
 */
+ (void)deleteCacheForBusiness:(NSString *)business oldTime:(NSTimeInterval)oldTime deleteOption:(CacheDeleteOptions)deleteOption;


/**
 * 删除oldTime之前所有的disk缓存
 * ***同步方法，等待清除之后再返回***
 */
+ (void)deleteCacheForOldTime:(NSTimeInterval)oldTime;

/**
 * 通过bussId分组查询各个业务分组的存储大小，单位byte
 *
 * @return 返回为数组，数组中的元素为字典，字典格式为：
 * {@"business":@"业务", // NSString或者NSNull，缓存业务可能未填，所以返回了NSNull，使用时注意判断
 *  @"delOption":CacheDeleteThumbnail,
 *  @"fileSize":12335 // 大小为byte
 * }
 * **注意判断business的类型**
 */
+ (NSArray *)getCacheSizeGroupByBusiness;

/**
 * 获取oldTime之前的缓存大小
 */
+ (int64_t)getCacheSizeWithOldTime:(NSTimeInterval)oldTime;

@end
