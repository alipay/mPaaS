//
//  SCWebSocketControl.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SCWebSocketLogDelegate <NSObject>

/**
 *	@brief	打埋点日志接口，
 *
 *	@param 	pfx ,sybType, content, 扩展字段，共四个item，第四个item是字典，字典内容可自定义，
 字典会被转换成key-value的字符串计入日志
 *
 *	@return 返回value
 */
-(void)logwithSubType:(NSString*)pfx content:(NSArray*)content;
//用APLogInfo打日志
-(void)writeLocalLogInfo:(NSString *)tag params:(NSArray*)params;

@end

@protocol SCWebSocketStorageDelegate <NSObject>

/**
 *	@brief	key-value的存储
 *
 *	@param 	value           存储值
 *  @param 	defaultName     key
 *
 *	@return 返回
 */

- (void)setObject:(id)value forKey:(NSString *)defaultName;
/**
 *	@brief	key根据获取value
 *
 *	@param 	defaultName     key
 *
 *	@return 返回value
 */
- (id)objectForKey:(NSString *)defaultName;
/**
 *	@brief	key根据删除存储的value
 *
 *	@param 	defaultName     key
 *
 *	@return 返回value
 */
- (void)removeObjectForKey:(NSString *)defaultName;
@end

extern id<SCWebSocketLogDelegate> scWebSocketLoggerIns;
extern id<SCWebSocketStorageDelegate> scWebSocketStorage;

@interface SCWebSocketControl : NSObject

+(instancetype)shareInstance;

-(void)registLogger:(id<SCWebSocketLogDelegate>)logger;

-(void)registStorage:(id<SCWebSocketStorageDelegate>)storage;

-(void)freshConfig:(NSDictionary*)config;

@end
