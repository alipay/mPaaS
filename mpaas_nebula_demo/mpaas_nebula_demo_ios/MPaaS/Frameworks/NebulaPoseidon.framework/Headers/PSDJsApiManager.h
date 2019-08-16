//
//  PSDJsApiMgr.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/********************/
/*关于groupId
分组管理jsApi
 */
/********************/

@class PSDJsApi;

//JsApi管理类
@interface PSDJsApiManager : NSObject

@property(nonatomic, copy) NSString     *scope;

/**
 *  @brief 注册默认的已经配置的JsApi：JsApi Handler，只在调用的时候才初始化，并常驻.默认是在分组
 *
 *  @date 2014-08-20
 *
 *  @return 无
 */
- (void)registerDefaultJsApis;

/**
 *  @brief 注册一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param jsApi JsApi对象
 *
 *  @return 无
 */
- (void)registerJsApi:(PSDJsApi *)jsApi groupId:(NSString *)groupId;
- (void)registerJsApi:(PSDJsApi *)jsApi; // 默认分组

/**
 *  @brief 注册一组JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param jsApis JsApi对象数组
 *
 *  @return 无
 */
- (void)registerJsApis:(NSArray *)jsApis groupId:(NSString *)groupId; // PSDJsApi
- (void)registerJsApis:(NSArray *)jsApis; // PSDJsApi 默认分组

/**
 *  @brief 在指定分组下，反注册一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param jsApi JsApi对象
 *
 *  @return 无
 */
- (void)unregisterJsApi:(PSDJsApi *)jsApi groupId:(NSString *)groupId;
- (void)unregisterJsApi:(PSDJsApi *)jsApi; // 默认分组

- (void)unregisterJsApis:(NSString *)groupId;

/**
 *  @brief 根据JsApi名称，返回一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param jsApiName JsApi名称
 *
 *  @return 返回一个JsApi对象
 */
- (PSDJsApi *)jsApi:(NSString *)jsApiName groupId:(NSString *)groupId;
- (PSDJsApi *)jsApi:(NSString *)jsApiName; // 默认分组

- (NSArray *)jsApis:(NSString *)groupId;
- (NSArray *)jsApis; // 默认分组

@end
