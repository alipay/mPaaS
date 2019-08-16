//
//  MASSMethod.h
//  MASSProxy
//
//  Created by cuinacai on 16/2/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MASSChannel/MASSDataCallback.h>

@interface MASSMethod : NSObject
@property(nonatomic) BOOL needCrypto;               //是否需要加密传输
@property(nonatomic) NSString* bizType;             //业务类型，区分具体业务
@property(nonatomic) MMTCRouterDirect router;         //多媒体指定使用MMTC或是改良版
@property(nonatomic) BOOL  needCookieManager;           //是否需要管理cookie，一般不需要管理
@property(nonatomic) NSURL* mainDocumentUrl;            //如果需要cookie管理，需要填写主文档url，对应于NSURLRequest中的mainDocumentUrl
@property(nonatomic) BOOL   ignoreMdapLog;              //是否不需要埋点上报，为mdap日志上报业务专门做的开关，其他业务不要管
@end
