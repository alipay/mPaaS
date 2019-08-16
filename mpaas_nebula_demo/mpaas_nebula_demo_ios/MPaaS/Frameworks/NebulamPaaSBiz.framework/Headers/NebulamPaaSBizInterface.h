//
//  NebulamPaaSBizInterface.h
//  NebulamPaaSBiz
//
//  Created by yangwei on 2019/5/23.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NebulamPaaSBizInterface : NSObject

/**
 *  是否设置离线包的vhost header为 @"http://"
 *  vhost header默认为 @"https://"。当此值设为YES时，vhost header修改为 @"http://"
 *  注意：此属性请在尽早设置，建议应用启动完成后
 */
@property(nonatomic, assign) BOOL customHttpVhostHeader;

+ (NebulamPaaSBizInterface *)sharedInctance;

@end

NS_ASSUME_NONNULL_END
