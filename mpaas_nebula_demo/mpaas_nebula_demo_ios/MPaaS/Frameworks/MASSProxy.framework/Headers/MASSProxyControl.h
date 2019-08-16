//
//  MASSProxyControl.h
//  MASSProxy
//
//  Created by cuinacai on 16/3/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^MASSInitializeBlock)();


@protocol MASSProxyLogDelegate <NSObject>

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

extern id<MASSProxyLogDelegate>  massLogger;

@interface MASSProxyControl : NSObject
//单例
+ (instancetype)shareInstance;
//mass开关
+(BOOL)massSwitch;
//fetch wifi过滤
+(BOOL)fetchFilter;
@property(nonatomic,copy)MASSInitializeBlock channelInitBlock;
@property(nonatomic)BOOL hasInitMass;
//mass初始化block
-(void)setMASSChannelInitializeBlock:(MASSInitializeBlock)block;
//mass的logger
-(void)registerMASSLogWriter:(id<MASSProxyLogDelegate>)logger;
@end







