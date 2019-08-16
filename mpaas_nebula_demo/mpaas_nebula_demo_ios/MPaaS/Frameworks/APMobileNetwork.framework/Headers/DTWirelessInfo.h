//
//  DTWirelessInfo.h
//  APMobileNetwork
//
//  Created by wenbi on 14-3-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTWirelessInfo : NSObject

@property(nonatomic, copy) NSString *wirelessMac;
@property(nonatomic, copy) NSString *wifiNodeName;
@property(nonatomic, copy) NSString *lacId;
@property(nonatomic, copy) NSString *cellId;

@end
