//
//  APDAOVersionManager.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-26.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDAOResult.h"

@protocol APDAOVersionManager <NSObject>

/**
 *  判断一个表是否存在
 */
- (id)tableExists:(NSString*)tableName;

/**
 *  取一个表的版本，返回的数据是[NSNumber numberWithDouble:]的
 */
- (NSNumber*)versionOfTable:(NSString*)tableName;

/**
 *  设置一个表的版本
 *
 *  @param tableName 表名
 *  @param version   版本
 *
 *  @return 操作是否成功
 */
- (APDAOResult*)setTable:(NSString*)tableName version:(NSNumber*)version;

/**
 *  删除某个表的版本信息
 */
- (APDAOResult*)deleteTable:(NSString*)tableName;

/**
 *  取所有用户表名
 */
- (NSArray*)getAllUserTableNames;

@end

extern NSString* const APDAOVersionConfigXMLContent;
extern NSString* const APDAOVersionConfigTableName;