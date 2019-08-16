//
//  APCommonManager.h
//  APMultimedia
//
//  Created by Monster on 15/4/17.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^getCacheDataCompleteHandler)(id response, NSError* error);
typedef void(^getImageCacheDataCompleteHandler)(UIImage *response, NSError* error);
typedef void(^storeImageToPhotoCompleteHandler)(NSString *identifier, NSError *error);
typedef void(^getVoiceCacheDataCompleteHandler)(NSData *response, NSError* error);

//图片存储类型
typedef enum : NSUInteger {
    ImageTypeSmall,     //小图
    ImageTypeBig,       //大图
    ImageTypeOriginal,  //原图
} ImageTypeEnum;

__attribute__ ( (deprecated) )
@interface APCommonManager : NSObject

#pragma mark - LocalId cache


/**
 *  通过localId检查本地是否有缓存
 *
 *  @param localId
 *
 *  @return YES NO
 */
+ (BOOL)isCacheExistWithLocalId:(NSString*)localId DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中isImageCacheExsitFor: size:originalSize:");


/**
 *  同步获取缓存Data
 *
 *  @param localId
 *
 *  @return cache data
 */
+ (NSData*)synchronousGetCacheDataWithLocalId:(NSString*)localId DEPRECATED_MSG_ATTRIBUTE("this method deprecated,you should never  use it!find suitable method at APImageManager class");


/**
 *  异步获取缓存Data
 *
 *  @param localId
 *  @param complete
 */
+ (void)asynchronousGetCacheDataWithLocalId:(NSString*)localId
complete:(getCacheDataCompleteHandler)complete DEPRECATED_MSG_ATTRIBUTE("this method deprecated,you should never  use it!find suitable method at APImageManager class");


#pragma mark - CloudId cache
/**
 *  通过localId检查本地是否有缓存
 *
 *  @param cloudId
 *
 *  @return YES NO
 */
+ (BOOL)isCacheExistWithCloudId:(NSString*)cloudId DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中isImageCacheExsitFor: size:originalSize:");

/**
 *  异步获取缓存Data
 *
 *  @param cloudId
 *  @param complete
 */
+ (void)asynchronousGetCacheDataWithCloudId:(NSString*)cloudId
                                   complete:(getCacheDataCompleteHandler)complete DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中getImageCacheForIdentifier:size:originalSize:complete:");

#pragma mark - iamge cache process
/**
 *  通过localId和size检查本地是否有图片缓存
 *  支持cloudId和localId
 *
 *  @param cloudId
 *
 *  @return YES NO
 */
+ (BOOL)isCacheExistImageWithCloudId:(NSString*)cloudId imageType:(ImageTypeEnum)imageType size:(CGSize)size DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中isImageCacheExsitFor: size:originalSize:");



/**
 *  同步获取图片缓存
 *  支持cloudId和localId
 *  @param cloudId
 *
 *  @return cache data
 */
+ (UIImage*)synchronousGetImageCacheDataWithCloudId:(NSString*)cloudId imageType:(ImageTypeEnum)imageType size:(CGSize)size DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中getImageCacheForIdentifier: size:originalSize:方法");


/**
 *  异步获取图片缓存
 *  支持cloudId和localId
 *
 *  @param cloudId
 *  @param complete
 */
+ (void)asynchronousGetImageCacheDataWithCloudId:(NSString*)cloudId imageType:(ImageTypeEnum)imageType size:(CGSize)size
                                        complete:(getImageCacheDataCompleteHandler)complete DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中getImageCacheForIdentifier:size:originalSize:complete:");


/**
 *  图片存储到相册
 *
 *  @param cloudId
 *  @param complete
 */
+ (void)storeImageToPhotoWithCloudId:(NSString*)cloudId imageType:(ImageTypeEnum)imageType size:(CGSize)size
                            complete:(storeImageToPhotoCompleteHandler)complete DEPRECATED_MSG_ATTRIBUTE("replace by APImageManager类中storeImageToPhotoWithIdentifier:size:originalSize:complete:");

@end
