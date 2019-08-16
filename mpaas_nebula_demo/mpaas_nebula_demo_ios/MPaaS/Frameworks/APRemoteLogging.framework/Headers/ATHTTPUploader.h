//
//  ATUploader.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATUploader.h"

@interface ATHTTPUploader : ATUploader

- (BOOL)preprocessRequest:(ATUploadRequest *)req;

- (NSURLRequest *)urlRequstForReq:(ATUploadRequest *)req;

- (void)executeURLRequest:(NSURLRequest *)urlReq
       completionHandler:(ATUploadCompletionBlock)block;

@end


