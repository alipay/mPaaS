//
//  UIImageView+APMMWebImage.h
//  APMultimedia
//
//  Created by 慎一 on 16/7/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

//
//  此类只为APWebImage中UIImageView Category中接入APMultimedia，单独封装的接口，只为APWebImage单独使用
//
@interface UIImageView (APMMWebImage)

/*!
 设置UIImageView的image为对应key所标识的图片（支持django相关的cloudID 本地生成的LocalID 以及外部url图片）
 针对Django云端图片设置（key为Django CloudID）
 针对外部url图片（key为url（http/https）），zoom和originalSize参数可任意，建议CGSizeMake(-1,-1)
 
 @param key，可以是Django相关的CloudID 本地生成的LocalID 以及外部图片url（http/https）
 @param business    业务存储标识
 @param placeholder 占位图
 @param progress 获取图片的进度回调
 @param complete 获取图片的结果回调
 */
- (void)setImageWithKey:(NSString *)key
               business:(NSString *)business
       placeholderImage:(UIImage *)placeholder
               progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
             completion:(void (^)(UIImage *image, NSError *error))complete;

- (void)cancelCurrentImageLoading;

@end
