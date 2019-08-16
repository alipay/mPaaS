//
//  APVideoMaterial.h
//  APMultimedia
//
//  Created by Monster on 16/4/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APVideoMaterialPktModel.h"

typedef enum : NSUInteger {
    APVideoMaterialPkgNotLoad,
    APVideoMaterialPkgLoading,
    APVideoMaterialPkgLoaded,
} APVideoMaterialPkgStatus;

// 带id的完成回调
typedef void (^APVideoMaterialloadCompletion)(NSString *identifier,
                                              NSError *error);
//progress blocks
typedef void (^APVideoMaterialProcessiveBlock)(double percentage,
                                               long long partialBytes,
                                               long long totalBytes);

@interface APVideoMaterialManager : NSObject

/**
 *  共享实例
 */
+ (instancetype)shareManager;



/**
 *  是否支持贴图功能
 *
 *  @return YES 支持
 */
+ (BOOL)isSupport;

/**
 *  获取business包信息
 *
 *  @param busnessId
 *
 *  @return APVideoMaterialBusinessModel
 */
- (APVideoMaterialBusinessModel*)getMaterialBusinessInfo:(NSString*)busnessId;


/**
 *  加载素材小包（按需下载）
 *
 *  @param materialId
 *  @param progress
 *  @param completion
 */
- (void)loadMaterial:(NSString*)materialId
            progress:(APVideoMaterialProcessiveBlock)progress
          completion:(APVideoMaterialloadCompletion)completion;

/**
 *  取消加载素材小包
 *
 *  @param materialId 素材小包id
 *
 *  @return 成功、失败
 */
- (BOOL)cancelLoadMaterial:(NSString*)materialId;

/**
 *  素材包加载状态
 *
 *  @param materialId 素材包id
 *
 *  @return APVideoMaterialPkgStatus
 */
+ (APVideoMaterialPkgStatus)getMaterialStatus:(NSString*)materialId;

/**
 *  获取素材包路径
 *
 *  @param materialId
 *
 *  @return path
 */
+ (NSString *)getCachePathForMaterial:(NSString *)materialId;
@end
