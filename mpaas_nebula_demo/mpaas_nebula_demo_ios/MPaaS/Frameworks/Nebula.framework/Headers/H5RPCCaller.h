//
//  H5RPCCaller.h
//  H5Service
//
//  Created by soft on 14-3-1.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5RPCCaller : NSObject
@property (nonatomic, weak) PSDSession *session;

- (void)callRPC:(NSDictionary*)dict completeBlock:(PSDJsApiResponseCallbackBlock)completeBlock;
- (void)cancel;
- (BOOL)isFinished;
@end
