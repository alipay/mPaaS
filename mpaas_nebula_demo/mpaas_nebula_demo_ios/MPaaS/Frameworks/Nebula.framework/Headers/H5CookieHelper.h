//
//  H5CookieHelper.h
//  NebulaBiz
//
//  Created by wrl on 2018/9/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5CookieHelper : NSObject

+ (instancetype)sharedInstance;

- (BOOL)isSafeCookieManageWithAppId:(NSString *)appId;
- (NSString *)cookieStringForAppId:(NSString *)appId url:(NSString *)url;
- (void)setCookieForString:(NSString *)setCookieString appId:(NSString *)appId url:(NSString *)url;
@end
