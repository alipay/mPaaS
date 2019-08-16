//
//  APMCDNSetting.h
//  APMCDN
//
//  Created by Kris Tian on 2019/2/21.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APMCDNSetting : NSObject

@property (nonatomic, assign) BOOL domainEnable;         //域名收敛开关
@property (nonatomic, copy) NSDictionary* regularExpDic;//域名正则表达式字典，用作域名替换时的正则匹配规则

@property (nonatomic, copy) NSString* aftsCDNDomain;

@property (nonatomic, copy) NSString* aftsSourceDomain;

@property (nonatomic, assign) BOOL useOldCdnParseImageSizeRegex;         //使用旧的url解析正则表达式

@property (nonatomic, copy) NSString *tfsCdnParseImageSizeRegex;



/**
 *  共享对象
 *
 *  @return 共享的对象
 */
+ (instancetype)sharedInstance;

- (instancetype)init __attribute__((unavailable("init not available")));

/**
 根据url和bizType判断是否需要转换成AFTS CDN url

 @param urlStr 外部url
 @param bizType 业务标志
 @return 是否需要转换成AFTS CDN url
 */
- (BOOL)shouldConvertToAftsUrl:(NSString *)urlStr bizType:(NSString *)bizType;


//alicdn 域名白名单配置 集合
- (NSArray *)aliCdnDomain;
//alicdn 黑名单排除项：模糊
- (NSArray *)aliCdnFuzzyExcludePath;
//alicdn 黑名单排除项：精确
- (NSArray *)aliCdnExactExcludeDomain;

// oss cdn 域名白名单配置 集合
- (NSArray *)ossCdnDomain;
// oss cdn 黑名单排除项：模糊
- (NSArray *)ossCdnFuzzyExcludePath;
// oss cdn 黑名单排除项：精确
- (NSArray *)ossCdnExactExcludeDomain;

- (NSArray *)cdnWidthsOf10000Height;
- (NSArray *)cdnHeightsOf10000Width;
- (NSArray *)cdnImageSizes;
- (NSArray *)cdnXZImageSizes;
@end

NS_ASSUME_NONNULL_END
