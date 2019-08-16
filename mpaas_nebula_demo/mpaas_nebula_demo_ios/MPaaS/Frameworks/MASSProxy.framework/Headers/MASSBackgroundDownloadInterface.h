//
//  MASSBackgroundDownloadInterface.h
//  MASSProxy
//
//  Created by yangxiao on 2017/7/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MASSDownMethod.h"
#import "MASSProxyClient.h"
#import "NSURLSessionDownloadTask+ComleteBlock.h"

typedef void(^sessionCompleteHandler)();

@interface MASSBackgroundDownloadInterface : NSObject

+(instancetype _Nullable )shareInstance;

-(NSString*_Nonnull)backgroundURLDownload:(MASSTFSDownMethod *_Nonnull)method
               timeoutInterval:(NSTimeInterval)tout
                    completion:(MASSDownloadCompletion _Nullable )complete;

-(NSString*_Nonnull)backgroundFileIdDownload:(MASSDownMethod *_Nonnull)method
               timeoutInterval:(NSTimeInterval)tout
                    completion:(MASSDownloadCompletion _Nullable )complete;

-(void)setCompleteHandler:(nonnull void(^)())completeHandler;

-(const NSString*_Nonnull)getSessionIdentifier;

@end
