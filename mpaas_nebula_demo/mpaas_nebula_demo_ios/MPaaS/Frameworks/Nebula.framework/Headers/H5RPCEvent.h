//
//  H5RPCEvent.h
//  NebulaNetwork
//
//  Created by 扶瑶 on 16/9/19.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface H5RPCEvent : PSDEvent
@property (strong, nonatomic) NSDictionary *responseHeader;

+ (instancetype)rpcFinishedEvent;

@end
