//
//  APMAftsUrlBuilder.h
//  APMCDN
//
//  Created by Kris Tian on 2019/2/21.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMAftsUrlBuilder : NSObject

/**
 判断当前是否是线上环境

 @return 是否是线上环境
 */
+ (BOOL)isProductionEnv;

/**
 AFTS CDN域名地址

 @return  AFTS CDN域名地址
 */
+ (NSString *)aftsCDNDomain;

/**
 将外部url转换成AFTS CDN 文件url,具体规则见https://yuque.antfin-inc.com/docs/share/c56a6ef5-24d7-4e96-974f-86f803e24010

 @param url 需要转换的wurl
 @param bizType 业务标志
 @return 外部url对应的AFTS CDN文件url
 */
+ (NSString *)buildAftsCdnFileUrlWithUrl:(NSString *)url
                                 bizType:(NSString *)bizType;


/**
 将外部url转换成AFTS源站的文件url,具体规则见https://yuque.antfin-inc.com/docs/share/c56a6ef5-24d7-4e96-974f-86f803e24010
 
 @param url 需要转换的wurl
 @param bizType 业务标志
 @return 外部url对应的AFTS源站文件url
 */
+ (NSString *)buildAftsSourceFileUrlWithUrl:(NSString *)url
                                 bizType:(NSString *)bizType;
@end

