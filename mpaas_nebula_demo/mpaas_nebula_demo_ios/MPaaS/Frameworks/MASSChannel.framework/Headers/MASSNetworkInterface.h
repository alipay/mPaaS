//
//  MASSNetworkInterface.h
//  MASSChannel
//
//  Created by yangxiao on 2018/8/29.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CFNetwork/CFNetwork.h>

@interface MASSNetworkInterface : NSObject

+(instancetype) sharedInstance;

-(void)httpBeforeSendRequest:(CFHTTPMessageRef)cfHttpRequest;

-(NSString*)getSignString:(NSString*)str;

-(NSString*)getWorkspaceid;

-(NSString*)getAppid;

-(NSArray*)getHostWhiteList;

-(BOOL)downloadHostLegal:(NSString*)host;

@end
