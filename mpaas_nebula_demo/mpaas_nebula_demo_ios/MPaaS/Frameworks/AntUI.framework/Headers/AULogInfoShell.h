//
//  AULogInfoShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/3.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 注明：暂时无法做替换，因为定义的宏有其他工程用到

@interface AULogInfoBaseShell : NSObject

+ (void)logInfo:(NSString *)tag params:(NSString *)param, ...;

+ (void)logInfo:(NSString *)tag log:(NSString *)log;

@end

@interface AULogInfoShell : AULogInfoBaseShell

@end

Class AUGetLogInfo();

NS_ASSUME_NONNULL_END
