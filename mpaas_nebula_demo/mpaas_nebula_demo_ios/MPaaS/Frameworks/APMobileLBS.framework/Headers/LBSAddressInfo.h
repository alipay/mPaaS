//
//  LBSAddressInfo.h
//  APMobileLBS
//
//  Created by wenbi on 14-9-25.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
//#import <APMobileLBS/AMapMpaasPOI.h>
#import <APMobileLBS/LBSLocationDefs.h>
//#import <APMap/APMap.h>
//@protocol APMapPOI;
@protocol APMapRoad;
@protocol APMapRoadInter;


/**
 *  地址信息。
 */
@interface LBSAddressInfo : NSObject <NSCoding, NSCopying>

/**
 *  是否是中国大陆（不包含港澳台）
 */
@property(nonatomic,assign)BOOL chineseMainLand;

/**
 *  是否是属于中国（包含港澳台）
 */
@property(nonatomic,assign)BOOL chinese;

/**
 *  是否是直辖市(这里的直辖市包括香港和澳门)，暂未使用
 */
@property(nonatomic,assign)BOOL isMunicipality;

/** 国家 */
@property(nonatomic, strong) NSString *country;

/** 国家码 (参见 iso 3166)*/
@property(nonatomic, strong) NSString *countryCode;

/** 省份 */
@property(nonatomic, copy) NSString *province;

/** 省份的 AdCode（参见：GB2260） */
@property(nonatomic, copy) NSString *provinceCode;

/** 省名称简称*/
@property(nonatomic, strong) NSString *provinceSimpleName;

/** 城市 */
@property(nonatomic, copy) NSString *city;

/** 城市 AdCode（参见：GB2260），由于历史数据来源问题已废弃，建议使用cityAdcode */
@property(nonatomic, copy) NSString *cityCode DEPRECATED_ATTRIBUTE;

/** 城市 AdCode（参见：GB2260） */
@property(nonatomic, copy) NSString *cityAdcode;

/** 城市名称简称 */
@property(nonatomic, strong) NSString *citySimpleName;

/** 区名称 */
@property(nonatomic, strong) NSString *district;

/** 区代码，已废弃，建议使用districtAdcode */
@property(nonatomic, strong) NSString *districtCode DEPRECATED_ATTRIBUTE;

/** 区代码 */
@property(nonatomic, strong) NSString *districtAdcode;

/** 区县简称 */
@property(nonatomic, strong) NSString *districtSimpleName;


/** Ad code. */
@property(nonatomic, copy) NSString *adcode;

/** 时间戳 */
@property(nonatomic, strong) NSDate *timestamp;


/** 经度 */
@property(nonatomic, assign) double longitude;

/** 纬度 */
@property(nonatomic, assign) double latitude;

/** 
 * 精确度 
 */
@property(nonatomic, assign) double accuracy;

/**
 *  街道
 */
@property(nonatomic,strong)NSString *street;

/** 街道代码 */
@property(nonatomic, strong) NSString *streetAdcode;

/** 街道简称 */
@property(nonatomic, strong) NSString *streeSimpleName;

/**
 *  门牌
 */
@property(nonatomic,strong)NSString *number;

/**
 * POI信息，只有在调用reGeoCodeAll时返回
 */
@property(nonatomic, strong) NSArray *pois;

/**
 * 道路信息，只有在调用reGeoCodeAll时返回
 */
@property(nonatomic, strong) NSArray <APMapRoad> *roads;

/**
 * 道路交回，只有在调用reGeoCodeAll时返回
 */
@property(nonatomic, strong) NSArray <APMapRoadInter> *roadInters;

/**
 * 完整格式化地址信息
 */
@property(nonatomic, strong) NSString* formatAddress;

/**
 *  逆地理查询类型
 */
@property(nonatomic,assign)APCoreLocationReGeoType reGeoCodeType;

/**
 *  逆地理查询级别
 */
@property(nonatomic,assign)LBSLocationReGeoLevel reGeoCodeLevel;
@end
