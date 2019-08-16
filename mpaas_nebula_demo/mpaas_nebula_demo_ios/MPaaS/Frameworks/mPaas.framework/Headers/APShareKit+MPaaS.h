//
//  APShareKit+MPaaS.h
//  MPaaS
//
//  Created by shenmo on 5/9/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol APSKClientClass <NSObject>

+ (BOOL)registerAPPConfig:(NSDictionary*)configDic;

+ (BOOL)handleOpenURL:(NSURL *)aURL;

@end