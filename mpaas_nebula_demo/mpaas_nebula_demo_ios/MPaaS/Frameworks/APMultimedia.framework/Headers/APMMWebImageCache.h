//
//  APMMWebImageCache.h
//  APMultimedia
//
//  Created by Monster on 16/3/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//
//  此类只为APWebImage接入APMultimedia缓存管理，单独封装的接口，只为APWebImage单独使用
//

//
//  此类只为APWebImage接入APMultimedia缓存管理，单独封装的接口，只为APWebImage单独使用
//

@interface APMMWebImageCache : NSObject


+ (instancetype)createWithBusiness:(NSString *)business;

- (void) storeImageDataToDisk:(NSData *)data forkey:(NSString*)key;

- (void) storeImageToMem:(id)image forkey:(NSString*)key;

- (void) storeImageToDisk:(id)image forkey:(NSString*)key;

- (id) queryDataFromMemForKey:(NSString*)key;

- (UIImage *)queryImageFromDiskCacheForKey:(NSString *)key;

- (UIImage *) queryImageFromCacheForKey:(NSString *)key;

- (void)removeImageForKey:(NSString *)key;

- (NSString*)cachePathForKey:(NSString*)key;

+ (void)deleteCacheForBusiness:(NSString*)business;

@end
