//
//  PSDPageEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

@interface PSDPageEvent : PSDEvent

@property(nonatomic, strong) NSError *error;

+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)loadStartEvent;

+ (instancetype)loadFirstByteEvent;

+ (instancetype)loadProgressEvent;

+ (instancetype)loadDomReadyEvent;

+ (instancetype)loadCompleteEvent;

+ (instancetype)loadErrorEvent:(NSError *)error;

+ (instancetype)destroyEvent;

@end
