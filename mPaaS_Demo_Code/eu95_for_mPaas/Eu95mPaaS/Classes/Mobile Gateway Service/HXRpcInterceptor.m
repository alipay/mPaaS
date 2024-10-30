//
//  HXRpcInterceptor.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/7/24.
//

#import "HXRpcInterceptor.h"
#import <MPMgsAdapter/MPRpcInterface.h>


@implementation HXRpcInterceptor
- (DTRpcOperation *)beforeRpcOperation:(DTRpcOperation *)operation{
    
    // 仅对业务网关做拦截处理
    NSString *currentGateway  = [operation.gatewayURL absoluteString];
//    NSString *mgwGateway = [MPLiteSettingService getRPCGateway];
//    if (![currentGateway isEqualToString:mgwGateway] && ![operation.rpcOperationType hasPrefix:@"com.mpaas.meeting.userInfo"]) {
//        return operation;
//    }
//    
//    NSMutableURLRequest *urlRequest = (NSMutableURLRequest *)operation.request;
//    NSString *userId = [APCommonPreferences objectForKey:kMeetingMGWUserId business:kMeetingStoreBiz];
//    NSString *userToken = [APCommonPreferences objectForKey:kMeetingMGWUserToken business:kMeetingStoreBiz];
//    
//    if ([userId length] > 0) {
//        [urlRequest setValue:userId forHTTPHeaderField:kMeetingMGWUserId];
//    }
//    if ([userToken length] > 0) {
//        [urlRequest setValue:userToken forHTTPHeaderField:kMeetingMGWUserToken];
//    }
    
    return operation;
}

- (DTRpcOperation *)afterRpcOperation:(DTRpcOperation *)operation{
    // 仅对业务网关做拦截处理
//    NSString *currentGateway  = [operation.gatewayURL absoluteString];
//    NSString *mgwGateway = [MPLiteSettingService getRPCGateway];
//    if (![currentGateway isEqualToString:mgwGateway] && ![operation.rpcOperationType hasPrefix:@"com.mpaas.meeting.userInfo"]) {
//        return operation;
//    }
//    
//    NSHTTPURLResponse *urlResponse = (NSHTTPURLResponse *)operation.response;
//    NSDictionary *allHeaders = urlResponse.allHeaderFields;
//    NSString *userId = [allHeaders objectForKey:kMeetingMGWUserId];
//    NSString *userToke = [allHeaders objectForKey:kMeetingMGWUserToken];
//        
//    if ([userId length] > 0) {
//        [APCommonPreferences setObject:userId forKey:kMeetingMGWUserId business:kMeetingStoreBiz];
//    }
//    if ([userToke length] > 0) {
//        [APCommonPreferences setObject:userToke forKey:kMeetingMGWUserToken business:kMeetingStoreBiz];
//    }
    
//    NSDictionary *responseJSON = operation.responseJSON[@"result"];
//    if ([responseJSON isKindOfClass:[NSDictionary class]] && [responseJSON count] >0) {
//
//        BOOL isSuccess = [responseJSON[@"success"] boolValue];
//        NSString *errorCode = responseJSON[@"errorCode"];
//        if (!isSuccess &&
//            errorCode &&
//            [errorCode isKindOfClass:[NSString class]] &&
//            [errorCode isEqualToString:@"NEED_LOGIN"]) {
//
////            [MPLoginUtil needToLogin];
////            MPLoginViewController *vc = [[MPLoginViewController alloc] init];
////            vc.modalPresentationStyle = UIModalPresentationFullScreen;
////            [DTContextGet().navigationController presentViewController:vc animated:YES completion:^{
////
////            }];
//        }
//    }
   
   return operation;
}


@end
