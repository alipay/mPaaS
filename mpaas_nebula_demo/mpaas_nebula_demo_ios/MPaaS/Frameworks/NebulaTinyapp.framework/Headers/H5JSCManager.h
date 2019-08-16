//
//  H5JSCManager.h
//  NebulaPlugins
//
//  Created by theone on 16/11/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class H5JSCBridge;
@class PSDSession;

typedef NS_OPTIONS(NSUInteger, H5JSCWORKERSTATE) {
    H5JSCWORKERSTATEUNINSTAL = 1 << 0,
    H5JSCWORKERSTATEINSTALLING = 1 << 1,
    H5JSCWORKERSTATEINSTALED = 1 << 2,
};

@interface H5JSCWorkerInfo : NSObject
@property(nonatomic, assign, readonly)  H5JSCWORKERSTATE state;
@property(nonatomic, copy, readonly)    NSString         *workerUrl;
@end

@interface H5JSCManager : NSObject
@property(nonatomic, readonly, assign)      BOOL  hasStartDebuger;
@property(nonatomic, weak)                  H5JSCBridge *bridge;
@property(nonatomic, strong)                NSMutableDictionary<NSString *,H5JSCWorkerInfo *> *workers;
- (instancetype)initWithSession:(PSDSession *)session;
- (void)addWorker:(NSString *)url;
- (BOOL)isWorkerExist:(NSString *)url;
- (BOOL)isWorkerInstalled:(NSString *)url;
- (BOOL)isWorkerInstalling:(NSString *)url;
- (void)setWorkderState:(NSString *)url state:(H5JSCWORKERSTATE)state;
- (void)loadBaseJS;
@end
