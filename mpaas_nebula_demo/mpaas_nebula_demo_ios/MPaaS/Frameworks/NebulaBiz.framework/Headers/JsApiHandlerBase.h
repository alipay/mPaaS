//
//  JsApiHandlerBase.h
//  H5Service
//
//  Created by chenwenhong on 14-8-25.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Nebula/H5WebViewController.h>

//static void ErrorCallback(PSDJsApiResponseCallbackBlock callback, int code)
//{
//	callback(@{@"error": @(code)});
//}

#define e_invalid_api           1
#define e_inavlid_params        2
#define e_unknown_error         3

#define e_user_cancel           11

@interface JsApiHandlerBase : PSDJsApiHandler

@end
