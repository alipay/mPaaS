//
//  NXKBridgeMethodInfo.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NXKMethodArgument;

NS_ASSUME_NONNULL_BEGIN

@interface NXKBridgeMethodInfo : NSObject
@property(nonatomic, copy)  NSString  *jsName;
@property(nonatomic, copy)  NSString  *objectClsName;
@property(nonatomic, copy)  NSString  *objectMethodName;
@property(nonatomic, assign)  SEL     targetSel;
//当前JSapi的参数列表从字典中得到的映射列表
@property(nonatomic, copy) NSArray<NXKMethodArgument *>    *argumentNameList ;
//当前暴露的JSApi是否可以重写，默认是NO
@property(nonatomic, assign) BOOL   canOverride;
//当前暴露的JSApi支持的别名
@property(nonatomic, copy) NSString   *alias;

@property(nonatomic, copy) NSString   *originOverrideAndAlias;
@end

NS_ASSUME_NONNULL_END
