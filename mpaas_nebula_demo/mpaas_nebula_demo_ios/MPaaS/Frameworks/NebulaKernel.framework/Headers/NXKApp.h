//
//  NXKSession.h
//  NebulaKernel
//
//  Created by theone on 2018/8/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>
#import "NXKNode.h"


@interface NXKApp : PSDSession <NXKNodeProtocol>
@property(nonatomic, strong) PSDSessionParam    *sessionParamOverride;
@property(nonatomic, assign)  BOOL isNXKNode;
@end
