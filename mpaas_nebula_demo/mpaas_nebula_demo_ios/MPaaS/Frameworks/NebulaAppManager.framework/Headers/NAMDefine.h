//
//  NAMDefine.h
//  NebulaAppManager
//
//  Created by 扶瑶 on 16/3/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

@class NAMApp;

#pragma mark - Package Status

typedef NS_ENUM(NSUInteger, NAMAppStatus) {
    NAMAppStatusInstalled = 0,  // Installed
    NAMAppStatusUninstalled,    // Uninstalled
    NAMAppStatusInstalling,     // Installing (include Downloading and UnZipping)
    NAMAppStatusOffline,        // Offline
};

#pragma mark - App Update Source

typedef NS_ENUM(NSUInteger, NAMAppSource) {
    NAMAppSourceRequest = 0,    // http request or rpc
    NAMAppSourceSync,           // sync
    NAMAppSourceBuildIn         // built-in
};

// app update scene
typedef NS_ENUM(NSUInteger, NAMAppAutoScene) {
    NAMAppAutoSceneNormal = 0,      // normal, default
    NAMAppAutoSceneDebug,           // debug
};

/*
 * NAMNOTI_APP_UPDATED
 *
 * app update notification (include update and delete)
 *
 * userinfo params:
 *      NAMNOTI_APP_UPDATED_LIST:    appid list
 *      NAMNOTI_APP_UPDATED_SOURCE:  update source, NSNumber object of NAMAppSource
 */
extern NSString *const NAMNOTI_APP_UPDATED;
extern NSString *const NAMNOTI_APP_UPDATED_LIST;
extern NSString *const NAMNOTI_APP_UPDATED_SOURCE;


#pragma mark - Prepare (include Request & Install)

extern NSString *const NAMPREPARE_OFFTYPE;

typedef NS_ENUM(NSUInteger, NAMAppPrepareStep) {
    NAMAppPrepareStepUnknown,
    NAMAppPrepareStepStart,             // Start
    NAMAppPrepareStepAcquireInfo,       // AcquireInfo
    NAMAppPrepareStepAcquireInfoFinish, // AcquireInfoFinish
    NAMAppPrepareStepDownload,          // Download
    NAMAppPrepareStepDownloadFinish,    // DownloadFinish
    NAMAppPrepareStepUnzip,             // Unzip
    NAMAppPrepareStepUnzipFinish,       // UnzipFinish
    NAMAppPrepareStepFinished,          // Finished
    NAMAppPrepareStepBeforeLaunch,      // Before LaunchPrepare
    NAMAppPrepareStepLaunch             // LaunchPrepare
};

// prepare finish info key
extern NSString *const NAMPreFinishInfoKeyReqType;
extern NSString *const NAMPreFinishInfoKeyOfflineType;

typedef void (^NAMAppPrepareProcess)(NAMAppPrepareStep step, id info);                  // prepare step
typedef void (^NAMAppPrepareFinish)(NAMApp *app, NSError *error);                       // prepare finished
typedef void (^NAMAppPrepareFinishWithInfo)(NAMApp *app, NSError *error, id info);      // prepare finished (include info)


/*
 * return: can be interrupt
 * processor-dicInfo:
 *      key      value
 *      'error'  error
 */
typedef void (^NAMFinishBlock)(NSError *error);
typedef NSError *(^NAMAppPrepareProcessor)(NAMAppPrepareStep step, NAMApp *app, NSDictionary *dicInfo, NAMFinishBlock finish);  // prepare step


// request type
typedef NS_ENUM (NSInteger, NAMActionReqType) {
    NAMActionReqAsync = 0,      // async request
    NAMActionReqSyncTry,        // try sync request
    NAMActionReqSyncForce       // force sync request
};

// request trigger source
typedef NS_ENUM (NSInteger, NAMActionReqTriggerSource) {
    NAMActionReqTriggerSourceNormal = 0,
    NAMActionReqTriggerSourceSideMgw
};

// offline type
typedef NS_ENUM (NSInteger, NAMActionOfflineType) {
    NAMActionOfflineAsync = 0,  // async offline
    NAMActionOfflineSyncForce,  // sync force offline
    NAMActionOfflineSyncTry,    // sync try offline
    NAMActionOfflineNone        // don't download
};


#pragma mark - Install (include Download & Unzip)

typedef NS_ENUM(NSUInteger, NAMAppInstallStep) {
    NAMAppInstallStepDownload,          // Download
    NAMAppInstallStepDownloadFinish,    // DownloadFinish
    NAMAppInstallStepUnzip,             // Unzip
    NAMAppInstallStepUnzipFinish        // UnzipFinish
};

typedef void (^NAMAppInstallProcess)(NAMAppInstallStep step, id info);  // install step
typedef void (^NAMAppInstallFinish)(NAMApp *app, NSError *error);       // install finished


#pragma mark - Acquire PackageInfo (include synchronous rpc)

typedef NS_ENUM(NSUInteger, NAMAcquireAppStep) {
    NAMAcquireAppStepRequesting,        // Requesting
};

typedef void (^NAMAcquireAppProcess)(NAMAcquireAppStep step);
typedef void (^NAMAcquireAppFinish)(NAMApp *app, NSError *error);


#pragma mark - ZipArchive

extern NSString *const NAMNOTI_UNZIP_SUCCESS;

typedef void (^NAMZipArchiveFinish)(NAMApp *app, NSError *error);
typedef void (^NAMZipArchiveProcess)(float percent);   //  percent : 0.0 - 1.0


#pragma mark - Download

extern NSString *const NAMNOTI_DOWNLOAD_FINISHE;

typedef void (^NAMDownloadFinish)(NSString *path, NSError *error);
typedef void (^NAMDownloadProcess)(float percent); // percent : 0.0 - 1.0


#pragma mark - Request

typedef void (^NAMRequestFinish)(NSDictionary *data, NSError *error);

#pragma mark - Verify

extern NSString *const NAMNOTI_VERIFY_FINISHED;

// userinfo key: status, alert
extern NSString *const NAMNOTI_VERIFY_FINISHED_STATUS;
extern NSString *const NAMNOTI_VERIFY_FINISHED_ALERT;


#pragma mark - Network

typedef NS_ENUM (NSUInteger, NAMNetworkStatus) {
    NAMNetworkNotReachable = 0,
    NAMNetworkWWAN         = 1,
    NAMNetworkWiFi         = 2
};


#pragma mark - Notification

extern NSString *const NAMNOTI_USER_UPDATED;
extern NSString *const NAMNOTI_USER_STORAGE_RESET; // 用于内部用户重置通知, 业务不用关注

@interface NAMDefine : NSObject
@end
