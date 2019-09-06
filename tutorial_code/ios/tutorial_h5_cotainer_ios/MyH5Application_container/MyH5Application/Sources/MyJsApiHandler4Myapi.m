#import "MyJsApiHandler4Myapi.h"

@implementation MyJsApiHandler4Myapi

- (void)handler:(NSDictionary *)data context:(PSDContext *)context callback:(PSDJsApiResponseCallbackBlock)callback
{
    [super handler:data context:context callback:callback];
    
    NSString *userId = @"admin";
    if ([userId length] > 0) {
        callback(@{@"success":@YES, @"userId":userId});
    } else {
        callback(@{@"success":@NO});
    }
}

@end
