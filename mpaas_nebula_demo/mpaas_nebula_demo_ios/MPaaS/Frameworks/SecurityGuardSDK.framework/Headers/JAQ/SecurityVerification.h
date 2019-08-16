//
//  SecurityVerification.h
//  SecurityGuardSDKPro
//
//  Created by lifengzhong on 15/8/13.
//  Copyright (c) 2015年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SecurityVerification : NSObject


/**
 *  聚安全防控接口
 *
 *  @param info           其他需要的信息，以key-v形式存于info中，可选
 *  @param timeout        接口调用超时时间，单位秒，最大不超过22，最小不小于1
 *
 *  @return 聚安全服务器返回的安全token
 */
+ (NSString*) doJAQVerfificationSync: (NSDictionary*) info
                             timeout: (NSInteger) timeout;

@end