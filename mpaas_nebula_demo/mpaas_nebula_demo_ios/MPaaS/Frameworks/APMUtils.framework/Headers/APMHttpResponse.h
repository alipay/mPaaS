//
//  APHttpResponse.h
//  APWebImage
//
//  Created by 慎一 on 2016/12/6.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMHttpResponse : NSObject

@property (readonly) NSInteger statusCode;

@property (readonly) long long expectedContentLength;

@property (nonatomic, readonly) NSDictionary *allHeaderFields;

@property (readonly, copy) NSString *MIMEType;


- (instancetype)initWithHttpHeaderData:(NSData *)headerData;
@end
