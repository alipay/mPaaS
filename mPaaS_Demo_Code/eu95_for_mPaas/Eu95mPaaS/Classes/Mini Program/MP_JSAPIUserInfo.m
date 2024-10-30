//
//  MP_JSAPIUserInfo.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/6/21.
//

#import "MP_JSAPIUserInfo.h"

@implementation MP_JSAPIUserInfo

- (void)handler:(NSDictionary *)data context:(PSDContext *)context callback:(PSDJsApiResponseCallbackBlock)callback
{
    [super handler:data context:context callback:callback];
    
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"我是原生的弹框" message:@"前端向原生发送的事件已收到"];
    [dialog addButton:@"知道了" actionBlock:^{
        NSString *message = [NSString stringWithFormat:@"tinyToNative:%@+%@,was handled by native.",[data objectForKey:@"param1"],[data objectForKey:@"param2"]];
        callback(@{@"message":message});
    }];
    [dialog show];
}



@end
