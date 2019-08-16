//
//  APRegionCutImageRequest.h
//  APMultimedia
//
//  Created by 慎一 on 16/8/16.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APImageCacheRequest.h"
//区域裁切
typedef NS_ENUM (NSInteger, APImageCropRegion) {
    APImageCropRegionMid, // 对应横竖图的从中间裁切
    APImageCropRegionHead, // 对应横图的从左部分裁切 竖图的头部分
    APImageCropRegionTail // 对应横图的从右部分裁切 竖图的底部分
};

//智能裁切 区域裁切的的默认类型为APImageRequestTypeCut，不会根据originalSize和zoom来决定
@interface APRegionCutImageRequest : APImageCacheRequest

/**
 *  当为横图 从什么区域裁切
 */
@property (nonatomic, assign) APImageCropRegion landscapeCropRegion;

/**
 *  当为竖图 从什么区域裁切
 */
@property (nonatomic, assign) APImageCropRegion portraitCropRegion;

/**
 *  是否支持智能裁切
 */
@property (nonatomic, assign) BOOL enableSmartCropHeadRegionWhenSupport;

/**
 是否支持显著性裁切算法，只有在enableSmartCropHeadRegionWhenSupport为YES的时候生效，做为智能裁切的一种补充，当人脸识别失败的时候，走显著性裁切。 默认为NO
 */
@property (nonatomic, assign) BOOL enableSaliencyCropWhenSmartCropFailed;

@end
