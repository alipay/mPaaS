//
//  ATUploadAction.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2018/5/15.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATActionMgr.h"
@class ATConfig;

/**
 * 上报操作
 */
@interface ATUploadAction : ATAction

//@property (nonatomic, strong) NSString *bizId;  /**< 业务名**/
//@property (nonatomic, strong) ATConfig *config; /**< 配置信息*/
//@property (nonatomic, strong) NSString *event;  /**< 上报触发原因*/
//@property (nonatomic, strong) NSString *url;    /**< 上报目的地址*/

/**
 * 初始化一个上报操作对象
 */
- (instancetype)initWithBizId:(NSString *)bizId
                       config:(ATConfig *)config
                        event:(NSString *)event
                          url:(NSString *)url;

@end
