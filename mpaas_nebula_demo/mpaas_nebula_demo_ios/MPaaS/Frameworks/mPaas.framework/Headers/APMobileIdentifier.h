//
//  APMobileIdentifier.h
//  APMobileIdentifer
//
//  Created by WenBi on 14-1-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMobileIdentifier : NSObject

+ (APMobileIdentifier *)shareIdentifier;
@property(nonatomic, copy) NSString *UUID;
@property(nonatomic, copy) NSString *UTDID; // 获取SDK生成的设备唯一标识。
@property(nonatomic, copy) NSString *IMSI;  // 设备IMEI，取移动快捷的IMSI。
@property(nonatomic, copy) NSString *IMEI;  // 设备IMSI，取移动快捷的IMEI。
@property(nonatomic, copy) NSString *TID;   // 终端标识，取移动快捷TID。
@property(nonatomic, copy) NSString *deviceFingerprint; // 取移动快捷APDID。
@property(readonly) NSString *AWID;         // 无线awid。
@property(readonly) NSString *clientId;     // 设备clientId，IMEI|IMSI。
@property(nonatomic, strong, readonly) NSString *deviceModel;           // 设备类型
@property(nonatomic, assign, readonly) unsigned long memoryAwailable;   // 可用内存
@property(nonatomic, assign, readonly) int diskTotalSpace;              // 硬盘大小

@end

// 为了兼容性
@interface MPMobileIdentifier : APMobileIdentifier

@end
