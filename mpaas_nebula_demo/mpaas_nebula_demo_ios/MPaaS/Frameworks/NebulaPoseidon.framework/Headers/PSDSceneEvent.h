//
//  PSDSceneEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

@interface PSDSceneEvent : PSDEvent

+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)appearBeforeEvent;

+ (instancetype)appearAfterEvent;

+ (instancetype)loadEvent;

+ (instancetype)didLoadEvent;

+ (instancetype)readyEvent;

+ (instancetype)layoutEvent;

+ (instancetype)didUnLoadEvent;

+ (instancetype)disappearBeforeEvent;

+ (instancetype)disappearAfterEvent;

+ (instancetype)destroyEvent;

+ (instancetype)destroyBeforeEvent;

+ (instancetype)startFirstRequestEvent;
@end
