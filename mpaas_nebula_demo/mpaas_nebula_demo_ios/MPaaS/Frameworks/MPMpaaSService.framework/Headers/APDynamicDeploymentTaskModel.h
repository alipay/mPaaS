//
//  APDynamicDeploymentTaskModel.h
//  DynamicDeployment
//
//  Created by majie on 16/7/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentDef.h"

//各个业务通过sync下发的数据需要转成统一model
//然后调用通用下载器
@interface APDynamicDeploymentTaskModel : NSObject<NSCopying>

//业务线
@property (nonatomic, strong) NSString *business;
//资源名字
@property (nonatomic, strong) NSString *name;
//资源类型
@property (nonatomic, assign) APDynamicDeploymentResourceType resType;
//md5
@property (nonatomic, strong) NSString *md5;
//下载类型
@property (nonatomic, assign) APDynamicDeploymentDownloadType downloadType;
//下载地址
@property (nonatomic, strong) NSString *downloadUrl;
//网络类型
@property (nonatomic, assign) APDynamicDeploymentNetType netType;
//存储类型
@property (nonatomic, strong) NSString *storeType;
//扩展数据
@property (nonatomic, strong) NSString *extraData;
//zip文件解压标示
@property (nonatomic, assign) BOOL needUnZip;
//配置过期时间
@property (nonatomic, strong) NSNumber *expireTime;
//更新时间
@property (nonatomic, strong) NSNumber *updateTime;

- (BOOL)isValid;

@end
