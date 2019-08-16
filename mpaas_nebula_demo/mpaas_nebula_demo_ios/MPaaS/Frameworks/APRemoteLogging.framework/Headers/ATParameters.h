//
//  ATParameters.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const ATUserIdDidChangeNotification;                  /**< 用户切换通知名*/
extern NSString *const ATUserIdDidChangeNotificationInfoOldUserIdKey;  /**< 用户切换通知userInfo中老的userId key值*/
extern NSString *const ATUserIdDidChangeNotificationInfoNewUserIdKey;  /**< 用户切换通知userInfo中新的userId key值*/

/**
 * 全局参数
 */
@interface ATParameters : NSObject

/**
 * 设置全局参数,仅内存缓存. 有全局参数透传需要时可使用.
 * @param obj 参数值
 * @param key 参数key
 */
- (void)setParameter:(id)obj forKey:(NSString *)key;

/**
 * 获取key对应的全局参数值
 * @param key 参数key值
 */
- (id)parameterForKey:(NSString *)key;

@end

@interface ATParameters (/**DeviceInfo*/)

@property (nonatomic, strong) NSString *utdid;          /**< 设备ID*/

@property (nonatomic, strong) NSString *deviceModel;    /**< 设备类型*/

@property (nonatomic, strong) NSString *systemName;     /**< 系统类型*/

@property (nonatomic, strong) NSString *systemVersion;  /**< 系统版本*/

@property (nonatomic, strong) NSString *networkType;    /**< 网络类型*/

@property (nonatomic, strong) NSString *language;       /**< App语言*/

@property (nonatomic, strong) NSString *hpVersion;      /**< 已安装的Hotpatch版本*/

@property (nonatomic, strong) NSString *resolution;     /**< 设备屏幕分辨率*/

@end

@interface ATParameters (/**GlobalState*/)

@property (atomic, copy) NSString *appState;       /**< App前后台状态*/

@property (atomic, copy) NSString *sessionId;      /**< 会话ID*/

@property (atomic, copy) NSString *pageSerialNo;   /**< 页面序列号*/

@property (atomic, copy) NSString *lastViewId;     /**< 上一个页面ID*/

@property (atomic, copy) NSString *currentViewId;  /**< 当前页面ID*/

@property (atomic, copy) NSString *lastPageTitle;  /**< 上一个页面title*/

@property (atomic, copy) NSString *currentPageTitle;/**< 当前页面title*/

@property (atomic, copy) NSString *currentTrackId; /**< 最近一次点击事件ID*/

@property (atomic, copy) NSString *currentTrackToken;/**< 最近一次点击事件token*/

@property (nonatomic, assign) unsigned long long tokenTimestamp;/**< 最近一次点击事件时间戳*/

@property (atomic, copy) NSString *lastAppId;       /**< 上一个microApp ID*/

@property (atomic, copy) NSString *currentAppId;    /**< 当前microApp ID*/

@property (nonatomic, strong) NSString *currentAutoRefer;/**< 当前自动化埋点维护的refer*/

@property (nonatomic, strong) NSString *foundationExtended;/**< 基础扩展*/

@property (nonatomic, strong) NSString *sourceId;       /**< 营销来源ID*/

@end

@interface ATParameters (/**Customizable*/)

@property (nonatomic, strong) NSString *platformId;     /**< ProductID,默认取InfoPlist中的"Product ID",需向埋点平台申请*/

@property (nonatomic, strong) NSString *clientVersion;  /**< App版本号,默认取InfoPlist中的@"Product Version"*/

@property (nonatomic, strong) NSString *clientId;       /**< 默认实现为从APMobileIdentifier获取，如果没有APMobileIdentifier，会返回@""*/

@property (nonatomic, strong) NSString *userId;         /**< 用户ID,修改该值会触发ATUserIdDidChangeNotification通知*/

@property (nonatomic, strong) NSString *idfa;           /**< IDFA值,默认返回nil*/

@property (nonatomic, strong) NSString *uploadUrl;      /**< 埋点上报地址,默认@"https://mdap.alipay.com/loggw/logUpload.do"*/

@property (nonatomic, strong) NSString *configUrl;      /**< 埋点配置拉取地址,默认@"https://mdap.alipay.com/loggw/logConfig.do"*/

@property (nonatomic, assign) NSUInteger maxLengthOfLine;/**< 单行日志最大长度,默认16K*/

@property (nonatomic, assign) NSUInteger maxSizeOfLog;  /**< 本地log文件占用最大大小,超过大小后清理所有文件的1/4,默认30MB*/

@property (nonatomic, assign) NSUInteger maxLengthOfCustom; /**< 单行自定义日志最大长度,默认256K*/

#ifdef SDK_IS4_ALIPAY
@property (nonatomic, strong) NSDictionary *configABTestInfo; /**<APConfig ABTestInfo 默认返回nil */
@property (nonatomic, strong) NSDictionary *currentApplicationParams;
#endif

@end

@interface ATParameters()
@property (nonatomic, assign) CFAbsoluteTime lastUUIDUpdateTime;/**< 最近一个更新sessionId的时间戳*/

@end

@interface ATParameters (/**Update*/)

/**
 * 通知\c ATParameters 页面即将打开
 * @param viewId 页面ID
 * @param appId microAppID
 * @param title 页面title
 */
- (void)viewWillAppear:(NSString *)viewId
                 appId:(NSString *)appId
                 title:(NSString *)title;

@end
