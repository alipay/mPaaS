//
//  UIImageView+APImageCache.h
//  APMultimedia
//
//  Created by Wang Yuanqiu on 15/3/31.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "APImageRequest.h"

@interface UIImageView (APImageCache)

/**
 根据设置的cloud ID或者url 去设置当前UIIImageView的image，如果缓存存在，则从缓存中获取UIImage， 如果缓存不存在，则从网络下载UIImage。 同时这个类内部处理了在列表中存在的串图问题：指View加载A图片，实际显示的是B图片。出现这个问题主要是和UIView的重用有关。
 */
@property (nonatomic, retain) NSString *originIdentifier;
/**
 *  根据CloudId设置UIImageView的Image
 *
 *  @param identifier  cloudId
 *  @param business 业务存储标识
 *  @param placeholder 默认图片
 *  @param cutSize     裁剪size
 *  @param imageSize   原图size
 *  @param progress    进度
 *  @param complete    完成
 *  优先判断imageSize，当imageSize为0时，将原图下载
 *  然后判断cutSize，当cutSize为0时，将大图下载
 *  然后判断imageSize和cutSize是否等比，来判断下载小图是否需要等比还是裁剪
 */
- (void)setImageCloudId:(NSString *)identifier
               business:(NSString *)business
       placeholderImage:(UIImage *)placeholder
                cutSize:(CGSize)cutSize
              imageSize:(CGSize)imageSize
               progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
             completion:(void (^)(UIImage *image, NSError *error))complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'setImageWithKey: business: placeholderImage: zoom: originalSize: progress: completion:'");


///**
// *  根据CloudId设置UIImageView的Image
// *
// *  @param identifier  cloudId
// *  @param placeholder 默认图片
// *  @param cutSize     裁剪size
// *  @param imageSize   原图size
// *  @param progress    进度
// *  @param complete    完成
// */
//- (void)setImageCloudId:(NSString *)identifier
//       placeholderImage:(UIImage *)placeholder
//                   size:(CGSize)imageSize
//               progress:(void(^)(double percentage,long long partialBytes,long long totalBytes))progress
//             completion:(void(^)(UIImage *image, NSError *error))complete;

/**
 *  根据CloudId设置UIImageView的Image
 *
 *  @param identifier  cloudId
 *  @param business    业务存储标识
 *  @param placeholder 默认图片
 *  @param progress    进度
 *  @param complete    完成
 */
- (void)setImageCloudId:(NSString *)identifier
               business:(NSString *)business
       placeholderImage:(UIImage *)placeholder
               progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
             completion:(void (^)(UIImage *image, NSError *error))complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'setImageWithKey: business: placeholderImage: zoom: originalSize: progress: completion:'");


/**
 *  在上传未完成之前，可以通过Upload Task ID来获取图片
 *
 *  @param localId
 *  @param complete
 */
- (void)setImageWithUploadLocalId:(NSString *)localId completion:(void (^)(UIImage *image, NSError *error))complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'setImageWithKey: business: placeholderImage: zoom: originalSize: progress: completion:'");

/**
 *  在上传未完成之前，可以通过Upload Task ID来获取图片
 *
 *  @param localId
 *  @param size
 *  @param complete
 */
- (void)setImageWithUploadLocalId:(NSString *)localId size:(CGSize)size completion:(void (^)(UIImage *image, NSError *error))complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'setImageWithKey: business: placeholderImage: zoom: originalSize: progress: completion:'");



/**
 *  外部图片URL设置
 *
 *  @param url
 *  @param business    业务存储标识
 *  @param placeholder
 *  @param complete
 */
- (void)setImageExternUrl:(NSString *)url
                 business:(NSString *)business
         placeholderImage:(UIImage *)placeholder
                 progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
               completion:(void (^)(UIImage *image, NSError *error))complete DEPRECATED_MSG_ATTRIBUTE("Replaced by 'setImageWithKey: business: placeholderImage: zoom: originalSize: progress: completion:'");

/*!
   设置UIImageView的image为对应key所标识的图片（支持django相关的cloudID 本地生成的LocalID 以及外部url图片）
   针对Django云端图片设置（key为Django CloudID）
   优先判断originalSize，当originalSize为CGSizeZero时，将原图下载
   然后判断zoom，当zoom为CGSizeZero时，将大图下载
   然后判断zoom和originalSize是否等比，来判断下载小图是否需要等比还是裁剪
   譬如：如果想得到一个UIImageView frame大小的等比图片，zoom和originalSize可设置为UIImageView的frame

   针对本地上传的图片（key为本地生成的LocalID）
   直接从cache中去查找，如果找不到，则回调失败。业务只需传入zoom参数（譬如UIImageView的frame）,orginalSize参数可任意，建议CGSizeMake(-1,-1)，最终originalSize是从cache中的该key对应的大图或者原图获取，从而来计算出图片是等比还是非等比。
   本地图片从cache中生成，速度非常快，progress参数可置为nil，非空的话只会收到100%的进度，没有中间进度。

   针对外部url图片（key为url（http/https）），zoom和originalSize参数可任意，建议CGSizeMake(-1,-1)

   @param key，可以是Django相关的CloudID 本地生成的LocalID 以及外部图片url（http/https）
   @param business    业务存储标识
   @param placeholder 占位图
   @param zoom 图片尺寸 该参数针对Django图片下载有效，传CGSizeZero表示下载大图并设置image，最大size为（1280,1280）；外部url图片可任意填，建议CGSizeMake(-1,-1)
   @param originalSize 原图尺寸，该参数针对Django图片下载有效，传CGSizeZero表示下载原图并设置image；外部url图片可任意填，建议CGSizeMake(-1,-1)
   @param progress 获取图片的进度回调
   @param complete 获取图片的结果回调
 */
- (void)setImageWithKey:(NSString *)key
               business:(NSString *)business
       placeholderImage:(UIImage *)placeholder
                   zoom:(CGSize)zoom
           originalSize:(CGSize)originalSize
               progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
             completion:(void (^)(UIImage *image, NSError *error))complete;

/**
 *  设置UIImageView的image为对应key所标识的图片（支持django相关的cloudID 本地生成的LocalID 以及外部url图片）
 *  针对Django云端图片设置（key为Django CloudID）
 *  优先判断originalSize，当originalSize为CGSizeZero时，将原图下载
 *  然后判断zoom，当zoom为CGSizeZero时，将大图下载
 *  然后判断zoom和originalSize是否等比，来判断下载小图是否需要等比还是裁剪
 *  譬如：如果想得到一个UIImageView frame大小的等比图片，zoom和originalSize可设置为UIImageView的frame

 *  针对本地上传的图片（key为本地生成的LocalID）
 *  直接从cache中去查找，如果找不到，则回调失败。业务只需传入zoom参数（譬如UIImageView的frame）,orginalSize参数可任意，建议CGSizeMake(-1,-1)，最终originalSize是从cache中的该key对应的大图或者原图获取，从而来计算出图片是等比还是非等比。
 *  本地图片从cache中生成，速度非常快，progress参数可置为nil，非空的话只会收到100%的进度，没有中间进度。

 *  针对外部url图片（key为url（http/https）），zoom和originalSize参数可任意，建议CGSizeMake(-1,-1)
 *
 *  @param key     可以是Django相关的CloudID 本地生成的LocalID 以及外部图片url（http/https）
 *  @param request APImageRequest
 */
- (void)setImageWithKey:(NSString *)key
                request:(APImageRequest*)request;

@end
