//
//  NAMTask.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NAMTaskDataSource <NSObject>

@optional
- (NSDictionary *)relatedVersionForAppList:(NSArray *)arrList;

@end

@interface NAMTask : NSObject

+ (void)presetAppList;

/*
 * amr目录清理逻辑: 一个appId仅保留一个amr,清除多余低版本。
 *
 * @return 是否成功
 */
+ (BOOL)clearAmrStorage;

/*
 * unzip目录清理逻辑: 清除超过指定时间的目录
 *
 * @param expireTime 目录过期时间
 * @return 是否成功
 */
+ (BOOL)clearUnzipStorage:(NSTimeInterval)expireTime;

/*
 * 生成装机量数据, 供业务层上报
 *
 * @return NSArray 数组, 每条格式: appid_version_isDownloaded_isInstalled
 */
+ (BOOL)uploadWebstatZhuangjiliang:(id<NAMTaskDataSource>)dataSource;

/*
 * 预解压预置离线包 (预置包id及版本需通过代理函数配置: [[NAMConfigurationGet() appInterface] presetAmrApps])
 * 注意: 仅会在大于等于预置版本的包未安装态才触发预置包解压
 */
+ (void)preUnzipPresetApps;

@end
