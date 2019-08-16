//
//  AUTPWrapper.h
//  AntUI
//
//  Created by maizhelun on 2017/3/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUThirdPartyAdapter.h"

@interface AUTPWrapper : NSObject <AUThirdPartyAdapter>

+ (instancetype)wrapper;

@end

#define AUShell [AUTPWrapper wrapper]
