//
//  NPUtils.h
//  NebulaPlugins
//
//  Created by theone on 16/9/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NPUtils : NSObject
+ (void)reportReqStart:(UIViewController *)vc;
+ (void)reportReqEnd:(UIViewController *)vc;
+ (void)reportLocStart:(UIViewController *)vc;
+ (void)reportLocEnd:(UIViewController *)vc;
+ (void)addVCCodeSnippet:(UIViewController *)vc code:(NSString *)code key:(NSString *)key;
+ (id)getProxyExpando:(NBViewControllerProxy *)proxy key:(NSString *)key clsName:(NSString *)clsName ;
+ (NSData *)getSourceDataFromCacheWithUrl:(NSURL *)url session:(NBSession *)session;
+ (NSDictionary *)getLocalIdAndTypeFromLocalUrl:(NSString *)url;
+ (NSString *)crateUrlWithLocalId:(NSString *)localId type:(NSString *)type;
+ (NSString *)contentTypeForImageData:(NSData *)data;
+ (void)saveMapRelationToShareDB:(NSString *)key value:(NSString *)value;
+ (NSString *)getMapRelationVal:(NSString *)key;
+ (void)removeMapRelationVal:(NSString *)key;
+ (NSString *)getFallbackUrlWithApp:(PSDSession *)session url:(NSURL *)url;

+ (PSDScene *)getSceneWithViewId:(NSString *)viewId withSession:(PSDSession *)session;

+ (UIImage *)snapShotWithSize:(CGSize)size view:(UIView *)view isWK:(BOOL)isWK;

+ (NSString *)SWUserAgent;

+ (NSURL *)getAppexFrameworkFallbackUrl:(NSString *)url;
+ (BOOL)isInlocationDialogPermitWhiteList:(NSURL *)url;
+ (BOOL)isAppletWithSession:(PSDSession *)session;
+ (NSString *)getCleanURLWithUrl:(NSString *)url;
+ (BOOL)isAppletWithScene:(PSDScene *)scene;

/**
 保存数据到本地临时目录
 
 @param data 需要临时存储的数据
 @param identifier 数据对应的标识符，用于去重和文件名生成　cancat(md5(userid), md5(identifier))
 @param pathExtension 数据对应的文件扩展名，默认为other
 @param appId 应用appId, 用于数据隔离，非空字符串
 @param callback 操作结果，输出约定与downloadFile jsapi相同
 */
+ (void)saveTemporaryData:(NSData * _Nonnull)data
               identifier:(NSString * _Nonnull)identifier
            pathExtension:(NSString * _Nullable)pathExtension
                    appId:(NSString * _Nonnull)appId
                 callback:(void (^ _Nullable)(NSDictionary *_Nonnull responseData))callback;
@end
