//
//  MAOfflineMap.h
//
//  Copyright (c) 2013年 AutoNavi. All rights reserved.
//

#if MA_INCLUDE_OFFLINE

#import <Foundation/Foundation.h>
#import "MAOfflineProvince.h"
#import "MAOfflineItemNationWide.h"
#import "MAOfflineItemMunicipality.h"


typedef NS_ENUM(NSInteger, MAOfflineMapDownloadStatus)
{
    MAOfflineMapDownloadStatusWaiting,       //!< 以插入队列，等待中
    MAOfflineMapDownloadStatusStart,         //!< 开始下载
    MAOfflineMapDownloadStatusProgress,      //!< 下载过程中
    MAOfflineMapDownloadStatusCompleted,     //!< 下载成功
    MAOfflineMapDownloadStatusCancelled,     //!< 取消
    MAOfflineMapDownloadStatusUnzip,         //!< 解压缩
    MAOfflineMapDownloadStatusFinished,      //!< 全部顺利完成
    MAOfflineMapDownloadStatusError          //!< 发生错误
};

/**
 *  离线下载错误domain
 */
extern NSString * const MAOfflineMapErrorDomain;

typedef NS_ENUM(NSInteger, MAOfflineMapError)
{
    MAOfflineMapErrorUnknown = -1,              //!< 未知的错误
    
    MAOfflineMapErrorCannotWriteToTmp = -2,     //!< 写入临时目录失败
    
    MAOfflineMapErrorCannotOpenZipFile = -3,    //!< 打开归档文件失败
    
    MAOfflineMapErrorCannotExpand = -4          //!< 解归档文件失败
};

/**
 *  当downloadStatus == MAOfflineMapDownloadStatusProgress 时, info参数是个NSDictionary,
 *  如下两个key用来获取已下载和总和的数据大小(单位byte), 对应的是NSNumber(long long) 类型.
 *  当downloadStatus == MAOfflineMapDownloadStatusError 时, info参数是NSError
 */
extern NSString * const MAOfflineMapDownloadReceivedSizeKey;
extern NSString * const MAOfflineMapDownloadExpectedSizeKey;

typedef void(^MAOfflineMapDownloadBlock)(MAOfflineItem * downloadItem, MAOfflineMapDownloadStatus downloadStatus, id info);
typedef void(^MAOfflineMapNewestVersionBlock)(BOOL hasNewestVersion);

@interface MAOfflineMap : NSObject


/**
*  获取MAOfflineMap 单例
*
*  @return MAOfflineMap
*/
+ (MAOfflineMap *)sharedOfflineMap;

/**
 *  省份数组(每个元素均是MAOfflineProvince类型)
 */
@property (nonatomic, readonly) NSArray *provinces;

/**
 *  直辖市数组(每个元素均是MAOfflineItemMunicipality类型)
 */
@property (nonatomic, readonly) NSArray *municipalities;

/**
 *  全国概要图
 */
@property (nonatomic, readonly) MAOfflineItemNationWide *nationWide;

/**
 *  城市数组, 包括普通城市与直辖市
 */
@property (nonatomic, readonly) NSArray *cities;

/**
 *  离线数据的版本号(由年月日组成, 如@"20130715")
 */
@property (nonatomic, readonly) NSString *version;

/**
 *  初始化离线地图数据，如果第一次运行且offlinePackage.plist文件不存在，则需要首先执行此方法。
    否则MAOfflineMap中的省、市、版本号等数据都为空。
 *
 *  @param block 初始化完成回调
 */
- (void)setupWithCompletionBlock:(void(^)(BOOL setupSuccess))block;

/**
 *  启动下载
 *
 *  @param item                                  数据
 *  @param shouldContinueWhenAppEntersBackground 进入后台是否允许继续下载
 *  @param downloadBlock                         下载过程block
 */
- (void)downloadItem:(MAOfflineItem *)item shouldContinueWhenAppEntersBackground:(BOOL)shouldContinueWhenAppEntersBackground downloadBlock:(MAOfflineMapDownloadBlock)downloadBlock;

/**
 *  监测是否正在下载
 *
 *  @param item 条目
 *
 *  @return 是否在下载
 */
- (BOOL)isDownloadingForItem:(MAOfflineItem *)item;

/**
 *  暂停下载
 *
 *  @param item 条目
 */
- (void)pauseItem:(MAOfflineItem *)item;

/**
 *  删除item对应离线地图数据
 *
 *  @param item 条目
 */
- (void)deleteItem:(MAOfflineItem *)item;

/**
 *  取消全部下载
 */
- (void)cancelAll;

/**
 *  清除所有在磁盘上的离线地图数据, 之后调用[mapView reloadMap]会使其立即生效
 */
- (void)clearDisk;

/**
 *  监测新版本
 *
 *  @param newestVersionBlock 回调block
 */
- (void)checkNewestVersion:(MAOfflineMapNewestVersionBlock)newestVersionBlock;

@end

@interface MAOfflineMap (Deprecated)

/**
*  城市数组(每个元素均是MAOfflineCity类型)
*/
@property (nonatomic, readonly) NSArray *offlineCities __attribute__ ((deprecated("use cities instead")));

/*!
 @brief 启动下载 (进入后台就停止下载)
 @param city 城市数据
 @param downloadBlock 下载过程block
 */

/**
 *  启动下载 (进入后台就停止下载)
 *
 *  @param city                                  城市数据
 *  @param downloadBlock                          下载过程block
 */
- (void)downloadCity:(MAOfflineCity *)city downloadBlock:(MAOfflineMapDownloadBlock)downloadBlock __attribute__ ((deprecated("use - (void)downloadItem:(MAOfflineItem *)item shouldContinueWhenAppEntersBackground:(BOOL)shouldContinueWhenAppEntersBackground downloadBlock:(MAOfflineMapDownloadBlock)downloadBlock instead")));


/**
 *  启动下载
 *
 *  @param city                                  城市数据
 *  @param shouldContinueWhenAppEntersBackground 进入后台是否允许继续下载
 *  @param downloadBlock                          下载过程block
 */
- (void)downloadCity:(MAOfflineCity *)city shouldContinueWhenAppEntersBackground:(BOOL)shouldContinueWhenAppEntersBackground downloadBlock:(MAOfflineMapDownloadBlock)downloadBlock __attribute__ ((deprecated("use - (void)downloadItem:(MAOfflineItem *)item shouldContinueWhenAppEntersBackground:(BOOL)shouldContinueWhenAppEntersBackground downloadBlock:(MAOfflineMapDownloadBlock)downloadBlock instead")));

/**
 *  监测是否正在下载
 *
 *  @param city 城市数据
 *
 *  @return 是否在下载
 */
- (BOOL)isDownloadingForCity:(MAOfflineCity *)city __attribute__ ((deprecated("use - (BOOL)isDownloadingForItem:(MAOfflineItem *)item instead")));

/**
 *  暂停下载
 *
 *  @param city 城市数据
 */
- (void)pause:(MAOfflineCity *)city __attribute__ ((deprecated("use - (void)pauseItem:(MAOfflineItem *)item instead")));

@end

#endif
