//
//  APMobileFoundationAdaptor.h
//  Nebula
//
//  Created by 张光宇 on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef NB_INSIDE
NS_ASSUME_NONNULL_BEGIN

/**
 * XTPortalInfo，负责获取客户端Info.plist里的字段信息。
 */
@interface XTPortalInfo : NSObject

@property(nonatomic, strong) NSString *productId;           //Info中的Product ID
@property(nonatomic, strong) NSString *productVersion;      //Info中的Product Version
@property(nonatomic, strong) NSString *channelId;           //Info中的Channels

@end
@interface XTPortalService : NSObject

- (XTPortalInfo *)portalInfo;
NS_ASSUME_NONNULL_END

@end 
#endif
