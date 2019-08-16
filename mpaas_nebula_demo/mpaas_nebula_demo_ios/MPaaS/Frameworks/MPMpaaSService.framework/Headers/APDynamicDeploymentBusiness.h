//
//  APDynamicDeploymentBusiness.h
//  DynamicDeployment
//
//  Created by majie on 16/6/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDynamicDeploymentBusiness : NSObject

//名称用来标识不同的业务类型
//已确定业务名称bundle,nest,hotpatch,iosdynamic,cmd
@property (atomic, strong) NSString *name;

//业务和发布中心的交互类，业务使用APDynamicDeploymentBaseInteraction的派生类
@property (atomic, strong) NSString *interactionClassName;

//上次业务成功rpc同步的时间
@property (atomic, strong, readonly) NSDate *lastRequestDate;

/**
 *  更新rpc成功时间
 */
- (void)updateRequestDate;

@end
