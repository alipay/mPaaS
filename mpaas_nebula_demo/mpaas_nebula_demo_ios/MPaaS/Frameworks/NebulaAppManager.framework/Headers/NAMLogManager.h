//
//  NAMLogManager.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/14.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NAMProtocol.h"

@interface NAMLogManager : NSObject <NAMLogProtocol>

+ (NAMLogManager *)shared;

- (void)log:(NAMLogContext *)context;

@end
