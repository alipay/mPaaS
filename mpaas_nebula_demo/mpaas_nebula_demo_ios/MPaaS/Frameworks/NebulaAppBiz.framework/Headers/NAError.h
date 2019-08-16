//
//  NPError.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/2/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NAError : NSObject

+ (NSError *)errorCode:(NSInteger)code
               message:(NSString *)message
               options:(id)options;

+ (NSError *)errorCode:(NSInteger)code;

@end
