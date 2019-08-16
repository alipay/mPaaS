//
//  ATAppender.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/25.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATMessage.h"
#import "ATConfigMgr.h"

/**
 * 文件Appender
 */
@interface ATAppender : NSObject

@property (nonatomic, strong) NSString *name;   /**< 名称,对应bizId*/
@property (nonatomic, assign) NSUInteger count; /**< 条数*/
@property (nonatomic, strong) NSString *path;   /**< 文件路径*/

/**
 * 打开历史文件,记录最新count
 */
- (void)checkHistory;

/**
 * 写入一条msg
 * @param msg 待写入的埋点消息
 * @param created 文件是否新创建
 */
- (void)appendMsg:(ATMessage *)msg fileCreated:(BOOL*)created;

/**
 * Flush内存缓存,将文件移动到待上传目录
 */
- (void)flush;

@end
