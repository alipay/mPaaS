//
//  AUMultimediaShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/2.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUMultimediaShell : NSObject

/*
 第三方适配下载图片接口
 主要对多媒体接口进行包装，由第三方实现
 */
+ (NSString *)getImage:(NSString *)identifier
                business:(NSString *)business
                    zoom:(CGSize)size
            originalSize:(CGSize)originSize
                progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
              completion:(void (^)(UIImage *image, NSError *error))complete;

/*
 第三方适配uiimageview下载图片接口
 由第三方去实现。
 */
+ (void)setWithImageView:(UIImageView * __nullable)fromImgView
           setImageWithKey:(NSString *)key
                  business:(NSString *)business
          placeholderImage:(UIImage *)placeholder
                      zoom:(CGSize)zoom
              originalSize:(CGSize)originalSize
                  progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
                completion:(void (^)(UIImage *image, NSError *error))complete;

/*
 第三方适配直接获取缓存中的image图片接口
 由第三方去实现。
 */
+ (UIImage *)getImageInCache:(NSString *)identifier
                       request:(id)request;

/// otherParams和response均为预留参数
+ (void)downloadFileWithCloudId:(NSString *)cloudId
                                     isZip:(BOOL)zip
                                 storePath:(NSString *)storePath
                                       md5:(NSString *)md5
                               otherParams:(NSDictionary *)otherParams
                                completion:(void(^)(NSError *error, NSString *filePath, NSDictionary *response))completion;

@end



NS_ASSUME_NONNULL_END
