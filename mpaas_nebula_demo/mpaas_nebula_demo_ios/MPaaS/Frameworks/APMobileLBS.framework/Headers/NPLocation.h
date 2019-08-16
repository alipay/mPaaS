//
//  H5Location.h
//  H5Service
//
//  Created by noahlu on 14-3-3.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#define kAutoNaviMapErrorCodeDelta                  1000000
#define kCLLocationErrorCodeDelta                   2000000
#define kLocationTimeOutErrorCode                   1000000

#define kAPMapServiceErrorDomain                    @"APMapService"
#define kLBSLocationManagerErrorDomain              @"LBSLocationManager"

typedef NS_ENUM(NSUInteger, APH5LocationRequestType) {
    APH5LocationRequestTypeCoordinateOnly = 0,
    APH5LocationRequestTypeRegeocode,
    APH5LocationRequestTypeRegeocodeToStreet,
    APH5LocationRequestTypeRegeocodeWithPOI
};

@interface NPLocation : NSObject

@property(nonatomic, strong) NSDate     *startLocateDate;
@property(nonatomic, strong) NSDate     *locateFinishDate;
@property(nonatomic, strong) NSDate     *startReGeocodeDate;
@property(nonatomic, strong) NSDate     *reGeocodeFinishDate;

/**
 * @brief 获取当前城市Name
 * @param block
 * @return
 */
- (void)locateCurrentGPS:(NSDictionary *)data complete:(void (^)(NSDictionary *addressInfo, CLLocation *location, NSError *error))block;



/**
 * @brief 获取当前位置，since 10.0.18
 * @param block
 * @return
 */

- (void)getCurrentLocation:(NSDictionary *)data complete:(void (^)(NSDictionary *addressInfo, CLLocation *location, NSError *error))block;

/**
 * @brief regeo, since 10.1.58
 * @param block
 * @return
 */
+ (void)regeoCodeWithLaitude:(double)latitude longitude:(double)longitude bizType:(NSString *)biz regeoLevel:(APH5LocationRequestType)level callBack:(void (^)(NSDictionary *addressInfos, CLLocation *location, NSError *error))block;

/**
 * @brief geo, since 10.1.58
 * @param block
 * @return
 */
+ (void)geoCodeWithAddress:(NSString *)address bizType:(NSString *)biz callBack:(void (^)(NSDictionary *addressInfos, CLLocation *location, NSError *error))block;


/**
 * @brief 清除所有回调
 * @return
 */
- (void)cancelAndClearBlocks;

@end
