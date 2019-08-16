//
//  APImageCacheRequest.h
//  APMultimedia
//
//  Created by brightzheng on 16/8/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APImageRequest.h"

typedef NS_ENUM (NSInteger, APMImageCacheType) {
    /**
     * The image was obtained/store from memory or disk cache.
     */
    APMImageCacheTypeDefault,
    /**
     * The image was obtained/store from the disk cache.
     */
    APMImageCacheTypeDisk,
    /**
     * The image was obtained/store from the memory cache.
     */
    APMImageCacheTypeMemory
};

@interface APImageCacheRequest : APImageRequest

@property (nonatomic, assign) APMImageCacheType cacheType;

/**
 *  APImageCacheRequest
 *
 *  @param cacheType cache类型
 *  @param imageType 图片类型
 *
 *  @return APImageCacheRequest
 */
+ (instancetype)InstanceWithCacheType:(APMImageCacheType)cacheType imageType:(APImageRequestTypeEnum)imageType;

/**
 *  APImageCacheRequest
 *
 *  @param cacheType cache类型
 *  @param imageType 图片类型
 *  @param zoom      zoom
 *
 *  @return APImageCacheRequest
 */
+ (instancetype)InstanceWithCacheType:(APMImageCacheType)cacheType imageType:(APImageRequestTypeEnum)imageType zoom:(CGSize)zoom;

@end
