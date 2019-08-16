//
//  JsApiHandler4RemoteLog.h
//  H5Service
//
//  Created by chenwenhong on 14-8-26.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


@interface NBLogJsApiHandler4RemoteLog : PSDJsApiHandler

- (void)remoteLog:(NSDictionary *)data url:(NSString *)url callback:(PSDJsApiResponseCallbackBlock)callback context:(PSDContext *)context;

@end
