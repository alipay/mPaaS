//
//  NSURLSessionDownloadTask+Method.h
//  MASSProxy
//
//  Created by yangxiao on 2017/7/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MASSProxyClient.h"

@interface NSURLSessionTask(MASScompleteBlock)

+(instancetype)sessionDownloadTaskWithSession:(NSURLSession*)session request:(NSURLRequest*)req massMethod:(MASSDownBaseMethod*)method complete:(MASSDownloadCompletion)complete;

-(MASSDownloadCompletion)massCompleteBlock;

-(MASSDownBaseMethod*)massMethod;

-(BOOL)completeBlockExecuted;

-(void)setCompleteBlockExecuted:(BOOL)exed;

@end
