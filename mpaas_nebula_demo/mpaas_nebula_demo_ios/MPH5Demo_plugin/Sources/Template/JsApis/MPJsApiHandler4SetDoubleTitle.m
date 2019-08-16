//
//  MPJsApiHandler4SetDoubleTitle.m
//  MPH5Demo_plugin
//
//  Created by yangwei on 2019/4/23.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPJsApiHandler4SetDoubleTitle.h"

@implementation MPJsApiHandler4SetDoubleTitle

- (void)handler:(NSDictionary *)data context:(PSDContext *)context callback:(PSDJsApiResponseCallbackBlock)callback
{
    [super handler:data context:context callback:callback];
    
    UIViewController *currentVC = context.currentViewController;
    currentVC.navigationItem.titleView = [[AUDoubleTitleView alloc] initWithTitle:@"主标题" detailTitle:@"副标题"];
    callback(@{@"success":@YES});
}

@end
