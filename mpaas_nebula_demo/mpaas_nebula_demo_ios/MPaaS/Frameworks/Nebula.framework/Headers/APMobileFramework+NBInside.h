//
//  APMobileFramework+NBInside.h
//  Nebula
//
//  Created by 张光宇 on 2019/3/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifdef NB_INSIDE
//#define DFOpenURLOptionsSceneParamsKey @"APSceneParamsKey"
//#define DFOpenURLOptionsSkipAuthKey @"APSkipAuthKey"
//#define DFOpenURLOptionsSkipAuthKey @"APSkipAuthKey"
//#define kSceneParamsIsFromExternalKey @"kSceneParamsIsFromExternalKey"

NS_ASSUME_NONNULL_BEGIN

@interface DTContext(NBInside)

- (BOOL)startApplication:(NSString *)name
                  params:(NSDictionary *)params
             appClearTop:(BOOL)appClearTop
              launchMode:(DTMicroApplicationLaunchMode)launchMode
                sourceId:(NSString *)sourceId
             sceneParams:(NSDictionary *)sceneParams;


/**
 * 获取当前保活应用的缓存列表
 */
- (NSArray *)acquireCurrentDelayReleaseApplications;

/**
 * 根据appid清空保活应用
 */
- (void)clearDelayReleaseApplicationsWithAppIdList:(NSArray *)appIdList;

/**
 * 清空保活应用
 */
- (void)clearDelayReleaseApplications;

@end

NS_ASSUME_NONNULL_END
#endif
