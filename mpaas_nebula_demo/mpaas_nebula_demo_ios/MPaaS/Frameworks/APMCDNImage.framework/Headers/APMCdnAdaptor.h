//
//  APMCdnAdaptor.h
//  APMCDN
//
//  Created by Kris Tian on 2019/2/21.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "APMCDNConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface APMCdnAdaptor : NSObject


/**
 是否可以开启域名收敛。

 @return 是否可以开启域名收敛。
 */
+ (BOOL)enabelConvergeDomain;
/**
 将url收敛到另外一个域名下的url, 如果urlStr支持域名收敛，则返回域名收敛后的url，否则返回原始url. 需要先调用enabelConvergeDomain是否可以q开启域名收敛
 
 @param urlStr 被收敛的url
 @return 如果urlStr支持域名收敛，则返回域名收敛后的url，否则返回原始url;
 */
+ (NSString *)convergeDomainWithUrl:(NSString *)urlStr;

/**
 将url转换到高保障url下，如果url和业务标志支持，则h返回对应的高保障url，否则则返回原始传入的url

 @param urlStr 需要转换的url，
 @param bizType 业务标志
 @param isPicture 是否是图片
 @return 如果url和业务标志支持，则h返回对应的高保障url，否则则返回原始传入的url
 */
+ (NSArray *)highAvailabilityUrlForUrl:(NSString *)urlStr bizType:(NSString *)bizType isPicture:(BOOL)isPicture;




/**
 是否支持生成CDN对应的url+size，部分CDN不支持任意尺寸

 @param url 图片请求链接
 @param size 需要适配的尺寸
 @param cutType 图片裁切类型
 @return 是否支持适配
 */
+ (BOOL)canExecAdaptForURL:(NSURL *)url size:(CGSize)size cutType:(APMImageCutType)cutType;

/**
 *  Native 图片 URL 解析接口
 *
 *  @param url            图片请求链接
 *  @param format         需要请求图片的格式
 *  @param imageSize      指定图片大小 （注意：指定图片大小时为实际尺寸，不会做 Retina 判断，只有视图尺寸才会判断。比如：视图大小100x100时，
 Retina 下图片大小200x200，非 Retina 下为100x100）
 *  @param viewSize       指定视图大小
 *  @param cutType        指定裁剪类型
 *
 *  @return 解析好的符合CDN规则的URL
 */
+ (NSURL *)parseImageURLForCDNURL:(NSURL *)url
                           format:(APMImageFormat)format
                        imageSize:(CGSize)imageSize
                         viewSize:(CGSize)viewSize
                          cutType:(APMImageCutType)cutType;


+ (NSString *)optimizedUrlWithOriginURL:(NSString *)originURL format:(APMImageFormat)imageFormat;

@end

NS_ASSUME_NONNULL_END
