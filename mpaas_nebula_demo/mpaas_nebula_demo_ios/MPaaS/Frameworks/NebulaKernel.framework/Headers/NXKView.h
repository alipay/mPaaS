//
//  NXKView.h
//  NebulaKernel
//
//  Created by theone on 2018/8/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>
#import "NXKNode.h"

@interface NXKView : PSDView <NXKNodeProtocol>
@property(nonatomic, assign)  BOOL isNXKNode;
@end
