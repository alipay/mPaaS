//
//  MASSErrorInterface.h
//  MASSChannel
//
//  Created by yangxiao on 16/1/15.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

@class MASSAccess;

@protocol MASSErrorInterface <NSObject>

/**
 *	@brief	错误回调接口
 *
 *	@param 	access     MASSAccess
 *  @param 	error     NSError
 *
 *	@return
 */
- (void)massAccessError:(NSError *)error;

@end

typedef NS_ENUM(NSInteger, NetAccessType)
{
    NetAccessNone,          //无网络
    NetAccess2G,            //2g
    NetAccess3G,            //3g
    NetAccess4G,            //4g
    NetAccessWifi,          //wifi
};

@protocol NetAccessInfo <NSObject>
/**
 *  iOS7以下      WIFI|WWAN|NotReachable
 *  iOS7及以上    WIFI|GPRS|WCDMA|HSDPA|HSUPA|CDMA1X|CDMAEVDOREV0|CDMAEVDOREVA|CDMAEVDOREVB|HRPD|LTE|UNKNOWN|NotReachable
 *
 *  @return 网络类型名称
 */
@property (nonatomic,strong,readonly) NSString* appleNetAccessInfo;
@property (nonatomic,readonly) NetAccessType accessType;
//@property (nonatomic,strong,readonly) NSString* appleMobileNetworkInfo;

-(CTTelephonyNetworkInfo*)getCTTelephonyNetworkInfo;

@optional
/**
 *  给域名取ip列表
 *
 *  @param host
 *
 *  @return <#return value description#>
 */
- (NSArray<NSString*>*)getIpListByHost:(NSString*)host;

@end

@protocol MAStorageDelegate <NSObject>
/**
 *    @brief    key-value的存储
 *
 *    @param     value           存储值
 *  @param     defaultName     key
 *
 *    @return 返回
 */

- (void)setObject:(id)value forKey:(NSString *)defaultName;
/**
 *    @brief    key根据获取value
 *
 *    @param     defaultName     key
 *
 *    @return 返回value
 */
- (id)objectForKey:(NSString *)defaultName;
/**
 *    @brief    key根据删除存储的value
 *
 *    @param     defaultName     key
 *
 *    @return 返回value
 */
- (void)removeObjectForKey:(NSString *)defaultName;
/**
 *    @brief    加密
 *
 *    @param     加密前的数据
 *
 *    @return 返回加密后的数据
 */
- (NSData*)enCryptForData:(NSData *)enData;
/**
 *    @brief    解密
 *
 *    @param     解密前的数据
 *
 *    @return 返回解密后的数据
 */
- (NSData*)DeCryptForData:(NSData *)deData;
@end

@protocol AMLogDelegate <NSObject>

/**
 *    @brief    打日志接口，
 *
 *    @param     pfx ,sybType, content, 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 */
-(void)logwithSubType:(NSString*)pfx content:(NSArray*)content;
/**
 *    @brief    打日志接口，
 *
 *    @param     sybType,扩展字段，第二个item是数组
 *
 */
-(void)writeLocalLogSubType:(NSString *) subType extraParams:(NSArray *) extraParams;

-(void)MTBIZ_Report:(NSString*)bizName subName:(NSString*)subName failCode:(NSInteger)failCode params:(NSDictionary*)params;
/**
 *    @brief    打日志接口，
 *
 *    @param     pfx ,sybType, content, 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 */
//-(void)logwithFootprintLogParam1:(NSString*)param1 param2:(NSString *)param2 param3:(NSString *)param3 paramKVMap:(NSDictionary *)map;
@end

@protocol MAInitInfo <NSObject>

@property(nonatomic)NSInteger channel;

@optional
@property(nonatomic,strong)NSDictionary *info;
@property(nonatomic,strong)NSData* bytes;

@end

@protocol MAInitInfoInterface <NSObject>
@required
/**
 *    @brief    获取init所需的NSDictionary
 *
 *    @return NSDictionary
 */
- (id<MAInitInfo>)getInitInfo;

@end

