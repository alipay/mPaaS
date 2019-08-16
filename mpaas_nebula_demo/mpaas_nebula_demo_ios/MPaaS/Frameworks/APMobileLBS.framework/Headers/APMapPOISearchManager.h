//
//  APMapPOISearchManager.h
//  APMap
//
//  Created by ronghui.zrh on 16/8/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APMapPOISearchRequest;
@class AMapMpaasPOI;

typedef void (^APMapPOIRequestBlock)(APMapPOISearchRequest *request);

typedef void (^APMapPOIResponseBlock)(NSArray<AMapMpaasPOI *> *pois, NSUInteger nextPageIndex, NSString *keywords, NSString *type, NSError *error, NSString *dtLogMonitor);

typedef NS_ENUM(NSUInteger, APMapPOISearchType) {
    APMapPOISearchTypeAll,   //类型是全部
    APMapPOISearchTypeSpecific,  //指定的类型
};
@interface APMapPOISearchRequest : NSObject

/**
 *  关键字
 */
@property(nonatomic,strong)NSString *keywords;
/**
 *  城市
 */
@property(nonatomic,strong)NSString *city;
/**
 *  每页的index，从1开始
 */
@property(nonatomic,assign)NSUInteger pageIndex;
/**
 *  每页的大小
 */
@property(nonatomic,assign)NSUInteger pageSize;
/**
 *  经纬度
 */
@property(nonatomic,assign)CLLocationCoordinate2D coordinate;
// 默认YES
@property(nonatomic,assign)BOOL coordinateConverted;

/**
 *精度
 */
@property(nonatomic,assign) CLLocationAccuracy horizontalAccuracy;

/**
 *  是搜索全部，还是某个特定的type
 */
@property(nonatomic,assign)APMapPOISearchType poiSearchType;

/**
 *  多个types间用竖线分隔
 *  141200 学校  120302 住宅小区  120201 商务写字楼
 */
@property(nonatomic,strong)NSString *poiTypes;

/**
 *  是不是中国，默认YES
 */
@property(nonatomic,assign)BOOL china;

/**
 *  超时时间，默认5秒
 */
@property(nonatomic,assign)NSTimeInterval timeout;

//是否限制城市,默认YES
@property(nonatomic,assign)BOOL cityLimit;

//业务方appKey
@property(nonatomic,strong)NSString *appKey;


@end

@interface APMapPOISearchManager : NSObject


/**
 *  POI Search 接口
 *        [manager poiSearchWitRequest:^(APMapPOISearchRequest *request) {
 *              request.poiSearchType = APMapPOISearchTypeAll;
 *              //            request.coordinate = CLLocationCoordinate2DMake(39.992706, 116.396574);
 *              request.coordinate = kCLLocationCoordinate2DInvalid;
 *              request.city = @"北京";
 *              request.keywords = @"周大生";
 *              request.pageIndex = 1;
 *              request.pageSize = 15;
 *        } poiCallback:^(NSArray<AMapPOI *> *pois, NSUInteger nextPageIndex, NSString *keywords, NSString *type) {
 *              NSLog(@"%@", pois);
 *        }];
 *
 */
- (void)poiSearchWitRequest:(APMapPOIRequestBlock)request
                poiCallback:(APMapPOIResponseBlock)poiBlock;


@end
