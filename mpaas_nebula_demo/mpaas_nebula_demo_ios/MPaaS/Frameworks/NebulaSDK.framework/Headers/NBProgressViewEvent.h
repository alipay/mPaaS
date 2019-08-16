//
//  NBProgressViewEvent.h
//  Nebula
//
//  Created by chenwenhong on 15/10/13.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>
#import "NBProgressViewProtocol.h"

@interface NBProgressViewEvent : PSDEvent

@property(nonatomic, strong) id<NBProgressViewProtocol> progressView;

+ (instancetype)allEvent:(id<NBProgressViewProtocol>)progressView;

+ (instancetype)createBeforeEvent:(id<NBProgressViewProtocol>)progressView;

+ (instancetype)createAfterEvent:(id<NBProgressViewProtocol>)progressView;

@end

