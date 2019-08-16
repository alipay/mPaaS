//
//  LBSLocationDefs.h
//  APMobileLBS
//
//  Created by 去疾 on 17/3/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef LBSLocationDefs_h
#define LBSLocationDefs_h

typedef NS_ENUM(NSInteger, APCoreLocationCacheAvaliable) {
    APCoreLocationCacheAvaliableNone=0,
    APCoreLocationCacheAvaliableFiveSeconds=5,
    APCoreLocationCacheAvaliableTenSeconds=10,
    APCoreLocationCacheAvaliableDefault = 30,
    APCoreLocationCacheAvaliableSixty = 60,
    APCoreLocationCacheAvaliableOneHundredATwenty= 120,
    APCoreLocationCacheAvaliableTwoHundredAfourty = 240,
};

typedef NS_ENUM(NSInteger, APCoreLocationReGeoType) {
    APCoreLocationReGeoTypeReverse,
    APCoreLocationReGeoTypeReGeoCode,
    APCoreLocationReGeoTypeReGeoCodeToCity,
    APCoreLocationReGeoTypeReGeoCodeAll
};

typedef NS_ENUM(NSInteger, LBSLocationReGeoLevel) {
    LBSLocationReGeoLevelCountry = 2,       // 国家
    LBSLocationReGeoLevelProvince ,         // 省
    LBSLocationReGeoLevelCity ,             // 城市
    LBSLocationReGeoLevelDistrict ,         // 区县
    LBSLocationReGeoLevelTown ,             // 乡镇
    LBSLocationReGeoLevelStreet = 10,       // 街道
    LBSLocationReGeoLevelStreetWithPOIs ,   // poi
};


typedef NS_ENUM(NSInteger, APCoreLocationErrorCode) {
    APCoreLocationErrorCodeSuccess = 0,
    APCoreLocationErrorCodeTimeOut = 100,               //超时时间内没有可用位置
    APCoreLocationErrorCodeLocation,                    //系统错误，新版本不会再有
    APCoreLocationErrorCodeReGeoCode,                   //逆地理失败
    APCoreLocationErrorCodeWifiLocation,                //wifi补偿定位失败
    APCoreLocationErrorCodeOptimization,                //位置纠偏失败，不会影响结果
    APCoreLocationErrorCodeAuthorization,               //无权限
    APCoreLocationErrorCodeBackgourndTimeout,           //后台定位失败，如果应用在后台，目前的权限定位必然会失败
    APCoreLocationErrorCodeBiztypeInBlacklist,          //业务标识在黑名单中
    APCoreLocationErrorCodeCancel,                      //业务中途取消
    APCoreLocationErrorCodeLocationOnlyCacheFail,       //定位只取缓存失败
    APCoreLocationErrorCodeRegeoOnlyCacheFail,          //逆地理只取缓存失败
    APCoreLocationErrorCodeResident,                    //常驻位置RPC返回失败
    APCoreLocationErrorCodeBiztypeInBlacklistInBg,      //后台定位黑名单
    APCoreLocationErrorCodeOverAllTimeOut,              //整体超时时间没有回调
};

/**
 签到场景
 
 - MPLBSCheckInSceneLocating: 定位时签到
 - MPLBSCheckInSceneColdLaunch: 冷启动签到
 - MPLBSCheckInSceneWarmLauch: 热启动签到
 */
typedef NS_ENUM(NSUInteger, MPLBSCheckInScene) {
    MPLBSCheckInSceneLocating = 0,
    MPLBSCheckInSceneColdLaunch,
    MPLBSCheckInSceneWarmLauch,
};


#endif /* LBSLocationDefs_h */
