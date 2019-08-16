//
//  APVideoInfo.h
//  APMultimedia
//
//  Created by Cloud on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

@interface APVideoInfo : NSObject

@property (strong, nonatomic) NSString *identifier; // 视频id
@property (strong, nonatomic) NSDate *creationTime; // 视频创建时间
@property (assign, nonatomic) CMTime duration;      // 时长
@property (assign, nonatomic) CGSize dimension;     // 视频长宽
@property (assign, nonatomic) int64_t size;         // 视频大小

/**
 *  根据id去查询视频相关信息
 *
 *  @param  identifier  视频的id
 *
 *  @return 返回该id对应的视频相关信息
 */
+ (instancetype)infoFromIdentifier:(NSString *)identifier;

@end

