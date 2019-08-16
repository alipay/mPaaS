//
//  H5PayEvent.h
//  NebulaBiz
//
//  Created by Glance on 2018/3/1.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/PSDEvent.h>

#define kH5Event_Service_Pay_Start                      @"service.pay.start"

@interface H5PayEvent : PSDEvent

@property(nonatomic, copy) NSString *tradeNo;
@property(nonatomic, copy) NSString *orderStr;
@property(nonatomic, copy) NSString *requestUrl;
@property(nonatomic, copy) NSString *bizReqData;

+ (instancetype)payStartEvent;
@end
