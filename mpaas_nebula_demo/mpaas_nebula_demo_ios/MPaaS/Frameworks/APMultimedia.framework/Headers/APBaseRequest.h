//
//  APBaseRequest.h
//  APMultimedia
//
//  Created by 慎一 on 2017/4/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APBaseRequest : NSObject

/**
 业务标志 business用于缓存存储和清理
 */
@property (nonatomic, copy) NSString *business;

@property (nonatomic, copy) NSString *bizType;

/**
 *  缓存过期时间，unix时间戳，0表示永不过期，默认为0
 *  触发生成缓存时此设置有效，如：下载，上传非localId的文件，及生成由其它图片裁剪的图片
 */
@property (nonatomic, assign) int expirationTime;

/**
 当有bizType，返回biztype，否则返回business
 
 @return
 */
- (NSString *)businessIdentifier;

+ (NSString *)businessIdentifierFromBizType:(NSString *)bizType business:(NSString *)business;

@end
