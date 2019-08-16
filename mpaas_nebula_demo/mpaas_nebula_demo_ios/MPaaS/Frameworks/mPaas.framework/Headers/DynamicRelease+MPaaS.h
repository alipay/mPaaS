//
//  DynamicRelease+MPaaS.h
//  MPaaS
//
//  Created by shenmo on 5/8/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

typedef NS_ENUM(NSInteger, DRLocalBandageExecutionType)
{
    DRLocalBandageExecutionAll = 0,         // 执行所有本地脚本
    DRLocalBandageExecutionNonLazyload,     // 执行非Lazyload的脚本
    DRLocalBandageExecutionLazyload,        // 执行Lazyload的脚本
};

@protocol DynamicReleaseClass <NSObject>

+ (id<DynamicReleaseClass>)sharedInstance;

/**
 *  获取本地有哪些脚本，用","分隔的脚本ID。这个给日志模块上报使用，每条日志都会带上，所以直接拼好。
 */
- (NSString*)getLocalBandages;

/**
 *  获取已经执行了哪些脚本，返回ID数组。这个给Crash上报使用。
 */
- (NSArray*)getExecutedBandages;

/**
 *  执行本地已经下载的所有Hotpatch脚本，这个方法需要尽量早调用，建议放在应用的didFinishLaunching方法最前面。
 */
- (void)executeLocalBandage:(DRLocalBandageExecutionType)type;

/**
 *  与服务端同步脚本，包括脚本的下载与回滚，同步完成后会自动执行新的脚本。这个方法会异步执行，
 */
- (void)synchronizeBandage;

/**
 *  更多参数的同步方法，这个方法会异步执行，
 *
 *  @param forced    是否强制拉取
 *  @param execute   拉取到后是否自动执行
 *  @param failBlock 失败的回调方法
 */
- (void)synchronizeBandage:(BOOL)forced execute:(BOOL)execute onSuccess:(void(^)())successBlock onFailed:(void(^)(NSError*))failBlock;

/**
 *  判断应用是否正在执行本地脚本，执行完成返回NO。
 *  当监测到Crash时，校验这个方法的值，如果返回YES，表示极大可能因为Patch导致启动Crash。
 *
 *  @return 是否正在执行脚本。
 */
- (BOOL)executingBandages;

/**
 *  获取本地的hotpatch缓存工作目录，绝对路径
 */
- (NSString*)bandageLocalWorkspacePath;

/**
 *  重置Patch工作目录
 *
 *  @param reserveMetaInfo  是否保留元文件
 传YES时，删除本地已有脚本，但保留元文件，之后不会再拉取这些脚本；
 传NO时，删除整个目录，元文件也被删除，之后有脚本还是会同步回来。
 */
- (void)resetBandageWorkspace:(BOOL)reserveMetaInfo;

@end
