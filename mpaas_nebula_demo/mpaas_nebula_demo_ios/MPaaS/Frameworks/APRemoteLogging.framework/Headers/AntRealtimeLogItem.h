//
//  AntRealtimeLogItem.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/7/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AntRealtimeLogItem : NSObject

@property (nonatomic, strong) NSString *bizType;
@property (nonatomic, strong) NSArray<NSString *> *logs;

@end
