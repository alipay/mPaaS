//
//  APMobileIdentifier+MPaaS.h
//  APMobileIdentifier
//
//  Created by shenmo on 5/5/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol APMobileIdentifierClass <NSObject>

+ (id<APMobileIdentifierClass>)shareIdentifier;

@property(nonatomic, copy) NSString *UTDID; // 获取SDK生成的设备唯一标识。
@property(nonatomic, copy) NSString *IMSI;  // 设备IMEI，取移动快捷的IMSI。
@property(nonatomic, copy) NSString *IMEI;  // 设备IMSI，取移动快捷的IMEI。
@property(nonatomic, copy) NSString *TID;   // 终端标识，取移动快捷TID。
@property(nonatomic, copy) NSString *deviceFingerprint; // 取移动快捷APDID。
@property(nonatomic, readonly) NSString *AWID;         // 无线awid。
@property(nonatomic, readonly) NSString *clientId;     // 设备clientId，IMEI|IMSI。
@property(nonatomic, strong, readonly) NSString *deviceModel;           // 设备类型
@property(nonatomic, assign, readonly) unsigned long memoryAwailable;   // 可用内存
@property(nonatomic, assign, readonly) int diskTotalSpace;              // 硬盘大小

@end