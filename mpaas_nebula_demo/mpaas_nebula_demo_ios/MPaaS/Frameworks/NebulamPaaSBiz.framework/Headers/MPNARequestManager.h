//
//  NARequestManager.h
//  NebulamPaaSBiz
//
//  Created by yangwei on 17/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MPMpaaSService/UnionResourceInfo.pb.h>
@interface MPNARequestManager : NSObject<NAMRequestProtocol>

+ (MPNARequestManager *)sharedInctance;

- (void)handleNebulaWithInfo:(UnionResourceInfo *)info error:(NSError **)error;
@end
