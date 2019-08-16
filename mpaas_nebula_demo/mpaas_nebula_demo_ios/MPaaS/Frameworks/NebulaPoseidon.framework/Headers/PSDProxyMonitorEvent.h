//
//  PSDProxyMonitorEvent.h
//  Poseidon
//
//  Created by chenwenhong on 15-1-29.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

@class PSDConnectionProfile;

@interface PSDProxyMonitorEvent : PSDEvent

@property(nonatomic, readonly, copy) NSString   *channelId;
@property(nonatomic) PSDConnectionProfile       *profile;

+ (instancetype)monitorEvent:(NSString *)channelId profile:(PSDConnectionProfile *)profile;

@end
