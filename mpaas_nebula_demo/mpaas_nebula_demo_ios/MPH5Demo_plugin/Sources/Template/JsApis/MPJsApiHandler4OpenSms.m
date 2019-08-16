//
//  MTJsApiHandler4OpenSms.m
//  MTPotal
//
//  Created by lizhen on 2017/9/5.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import "MPJsApiHandler4OpenSms.h"
#import <MessageUI/MessageUI.h>      

@implementation MPJsApiHandler4OpenSms

- (void)handler:(NSDictionary *)data context:(PSDContext *)context callback:(PSDJsApiResponseCallbackBlock)callback
{
    [super handler:data context:context callback:callback];
    
    // 打开系统短信
    NSURL *url = [NSURL URLWithString:@"sms://xxx"];
    BOOL reasult = [[UIApplication sharedApplication] openURL:url];
    callback(@{@"success":@(reasult)});
}

@end
