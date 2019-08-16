//
//  MPDynamicLoader.h
//  APMPaaS
//
//  Created by shenmo on 18/11/2016.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPDynamicLoader : NSObject

/**
 加载动态库二进制，该方法可以重复调用，第二次调用如果动态库已经加载，会返回YES
 iOS8以下调用这个方法会直接返回NO
 
 @param name 动态库名字
 @return 加载是否成功
 */
+ (BOOL)loadBinaryWithName:(NSString*)name;

/**
 返回已经加载了哪些动态库
 */
+ (NSSet*)loadedBinaries;

/**
 * 返回加载了的动态库的句柄
 */
+ (void*)getBinaryHandleByName:(NSString*)name;

@end
