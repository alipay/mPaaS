//
//  NBLogManager.h
//  NebulaLogging
//
//  Created by Glance on 16/11/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

@protocol NBLogTrackAgentProtocol;
@interface NBLogService : NSObject<NBMonitorDelegate>


/**
 运行服务 e.g. [NBLogServiceGet() start]
 */
- (void)start;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    NBLogService * NBLogServiceGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus



#pragma mark - Unavalilable

@interface NBLogService (UNAVAILABLE)

/**
 *  不可分配内存空间
 */
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

/**
 *  不可分配内存空间
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

/**
 *  不可分配内存空间
 */
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 *  不可初始化
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  不可复制
 */
- (id)copy UNAVAILABLE_ATTRIBUTE;

@end
