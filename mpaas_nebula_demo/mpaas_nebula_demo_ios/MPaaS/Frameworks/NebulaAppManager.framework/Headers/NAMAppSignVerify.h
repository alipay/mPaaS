//
//  SHH5AppSignatureVerification.h
//  MYBHybridService
//
//  Created by theone on 14-7-9.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NAMAppSignVerify : NSObject

/**
 *  验签
 *  
 *  说明: 验签范围以CERT.json文件为准, 其中带android字符的文件除外
 *
 *  @param path 验签地址, unzipPath
 */
- (BOOL)verify:(NSString *)path;

@end
