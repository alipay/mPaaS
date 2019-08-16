//
//  PSDLoggerProtocol.h
//  NebulaPoseidon
//
//  Created by theone on 16/11/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

@protocol PSDLoggerProtocol <NSObject>
- (void)doLogWithLogId:(NSString *)logId params:(NSDictionary *)params;
@end
