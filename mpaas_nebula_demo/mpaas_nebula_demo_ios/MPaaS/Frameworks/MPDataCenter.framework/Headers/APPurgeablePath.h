//
//  APPurgeablePath.h
//  MobileFoundation
//
//  Created by shenmo on 12/3/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, APPurgeableType)
{
    APPurgeableTypeManual = 0,          // 当用户手动清除缓存时清空
    APPurgeableTypeThreeDays = 3,       // 自动删除三天前的数据
    APPurgeableTypeOneWeek = 7,         // 自动删除一周前的数据
    APPurgeableTypeTwoWeeks = 14,       // 自动删除两周前的数据
    APPurgeableTypeOneMonth = 30,       // 自动删除一个月前的数据
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    /**
     *  根据用户的输入返回一个可被清理的存储路径，同时会自动判断目录是否存在，如果不存在会创建。
     *
     *  @param userPath 用户指定的路径，比如之前使用"Documents/SomePath"来拼接，现在使用APPurgeableStoragePath(@"Documents/SomePath")获得路径即可。
     *  @param type 指定自动清空的类型，可以是用户手动或每周，或每三天。
     *  @param size 指定当尺寸达到多大时，清空较老的数据，单位MB。0表示不设置上限。
     *
     *  @return 目标路径
     */
    NSString* APPurgeablePath(NSString* path);
    NSString* APPurgeablePathType(NSString* path, APPurgeableType type);
    NSString* APPurgeablePathTypeSize(NSString* path, APPurgeableType type, NSUInteger size /* MB */);
    
    /**
     *  清空并重置所有注册的目录
     */
    void ResetAllPurgeablePaths();
    
#ifdef __cplusplus
}
#endif // __cplusplus