//
//  TASandBoxManager.h
//  TinyAppCommon
//
//  Created by 应俊康 on 2018/3/29.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TASandBox.h"

// 小程序rpc appId宏 TINY_APP_RPC_STORAGE
#define TINY_APP_RPC_STORAGE @"TINY_APP_RPC_STORAGE"

// 小程序共用存储 appId宏
#define TINY_APP_COMMON_STORAGE @"TINY_APP_COMMON_STORAGE"

// 小程序授权信息公用存储
#define TINY_APP_AUTHORIZE_STORAGE @"TINY_APP_AUTHORIZE_STORAGE"

// 小程序真机辅助工具存储
#define TINY_APP_ASSISTANT_STORAGE  @"TINY_APP_ASSISTANT_STORAGE"

// 小程序内嵌webview存储公共后缀
#define  EMBEDDED_WEBVIEW_SANDBOX_SUFFIX    @"_EMBEDDED"

@interface TASandBoxManager : NSObject

+(instancetype)shareInstance;

-(TASandBox*)sandBox4AppId:(NSString*)appId;
@end
