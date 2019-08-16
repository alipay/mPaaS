//
//  AMapMpaasCommonObj.h
//  AMapMpaasSearchKit
//
//  Created by xiaoming han on 15/7/22.
//  Copyright (c) 2015年 AutoNavi. All rights reserved.
//

/**
 *  该文件定义了搜索结果的基础数据类型。
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - AMapMpaasSearchObject


@interface AMapMpaasSearchObject : NSObject<NSCopying, NSCoding>

@end

#pragma mark - 通用数据结构

/// 经纬度
@interface AMapMpaasGeoPoint : AMapMpaasSearchObject

@property (nonatomic, assign) CGFloat latitude; //!< 纬度（垂直方向）
@property (nonatomic, assign) CGFloat longitude; //!< 经度（水平方向）

+ (AMapMpaasGeoPoint *)locationWithLatitude:(CGFloat)lat longitude:(CGFloat)lon;

@end

/**
 * 多边形
 * 当传入两个点的时候，当做矩形处理:左下-右上两个顶点；其他情况视为多边形，几个点即为几边型。
 */
@interface AMapMpaasGeoPolygon : AMapMpaasSearchObject

@property (nonatomic, strong) NSArray<AMapMpaasGeoPoint *> *points; //!< 坐标集, AMapMpaasGeoPoint 数组

+ (AMapMpaasGeoPolygon *)polygonWithPoints:(NSArray *)points;

@end

@class AMapMpaasDistrict;

/// 城市
@interface AMapMpaasCity : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString  *city;  //!< 城市名称
@property (nonatomic, copy)   NSString  *citycode; //!< 城市编码
@property (nonatomic, copy)   NSString  *adcode; //!< 城市区域编码
@property (nonatomic, assign) NSInteger  num;   //!< 此区域的建议结果数目, AMapMpaasSuggestion 中使用
@property (nonatomic, strong) NSArray<AMapMpaasDistrict *> *districts; //!< 途径区域 AMapMpaasDistrict 数组，AMepStep中使用，只有name和adcode。

@end


#pragma mark - 输入提示

/// 无用，已清除

#pragma mark - POI

/// POI图片信息
@interface AMapMpaasImage : AMapMpaasSearchObject

@property (nonatomic, copy) NSString *title; //!< 标题
@property (nonatomic, copy) NSString *url; //!< url

@end

/// POI扩展信息
@interface AMapMpaasPOIExtension : AMapMpaasSearchObject

@property (nonatomic, assign) CGFloat  rating;//!< 评分
@property (nonatomic, assign) CGFloat  cost;//!< 人均消费
@property (nonatomic, copy)   NSString *openTime;//!< 营业时间

@end

/// POI室内地图信息
@interface AMapMpaasIndoorData : AMapMpaasSearchObject

@property (nonatomic, assign) NSInteger floor; //!< 楼层，为0时为POI本身。
@property (nonatomic, copy)   NSString  *floorName; //!< 楼层名称。
@property (nonatomic, copy)   NSString  *pid; //!< 父ID

@end

/// 子POI
@interface AMapMpaasSubPOI : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *uid; //!< POI全局唯一ID
@property (nonatomic, copy)   NSString     *name; //!< 名称
@property (nonatomic, copy)   NSString     *sname; //!< 名称简写
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 经纬度
@property (nonatomic, copy)   NSString     *address;  //!< 地址
@property (nonatomic, assign) NSInteger     distance; //!< 距中心点距离
@property (nonatomic, copy)   NSString     *subtype; //!< 子POI类型

@end

/// 沿途POI
@interface AMapMpaasRoutePOI : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *uid; //!< POI全局唯一ID
@property (nonatomic, copy)   NSString     *name; //!< 名称
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 经纬度
@property (nonatomic, assign) NSInteger     distance; //!< 用户起点经过途经点再到终点的距离，单位是米
@property (nonatomic, assign) NSInteger     duration; //!< 用户起点经过途经点再到终点的时间，单位为秒

@end

/// POI
@interface AMapMpaasPOI : AMapMpaasSearchObject

// 基础信息
@property (nonatomic, copy)   NSString     *uid; //!< POI全局唯一ID
@property (nonatomic, copy)   NSString     *name; //!< 名称
@property (nonatomic, copy)   NSString     *type; //!< 兴趣点类型
@property (nonatomic, copy)   NSString     *typecode; //!< 类型编码
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 经纬度
@property (nonatomic, copy)   NSString     *address;  //!< 地址
@property (nonatomic, copy)   NSString     *tel;  //!< 电话
@property (nonatomic, assign) NSInteger     distance; //!< 距中心点的距离，单位米。在周边搜索时有效。
@property (nonatomic, copy)   NSString     *parkingType; //!< 停车场类型，地上、地下、路边
@property (nonatomic, copy)   NSString     *shopID; //!< 商铺id

// 扩展信息
@property (nonatomic, copy)   NSString     *postcode; //!< 邮编
@property (nonatomic, copy)   NSString     *website; //!< 网址
@property (nonatomic, copy)   NSString     *email;    //!< 电子邮件
@property (nonatomic, copy)   NSString     *province; //!< 省
@property (nonatomic, copy)   NSString     *pcode;   //!< 省编码
@property (nonatomic, copy)   NSString     *city; //!< 城市名称
@property (nonatomic, copy)   NSString     *citycode; //!< 城市编码
@property (nonatomic, copy)   NSString     *district; //!< 区域名称
@property (nonatomic, copy)   NSString     *adcode;   //!< 区域编码
@property (nonatomic, copy)   NSString     *gridcode; //!< 地理格ID
@property (nonatomic, copy)   AMapMpaasGeoPoint *enterLocation; //!< 入口经纬度
@property (nonatomic, copy)   AMapMpaasGeoPoint *exitLocation; //!< 出口经纬度
@property (nonatomic, copy)   NSString     *direction; //!< 方向
@property (nonatomic, assign) BOOL          hasIndoorMap; //!< 是否有室内地图
@property (nonatomic, copy)   NSString     *businessArea; //!< 所在商圈
@property (nonatomic, strong) AMapMpaasIndoorData *indoorData; //!< 室内信息
@property (nonatomic, strong) NSArray<AMapMpaasSubPOI *> *subPOIs; //!< 子POI列表
@property (nonatomic, strong) NSArray<AMapMpaasImage *> *images; //!< 图片列表

// 扩展信息只有在ID查询时有效
@property (nonatomic, strong) AMapMpaasPOIExtension *extensionInfo; //!< 扩展信息

@end

#pragma mark - 逆地理编码 && 地理编码

/// 兴趣区域
@interface AMapMpaasAOI : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *uid; //!< AOI全局唯一ID
@property (nonatomic, copy)   NSString     *name; //!< 名称
@property (nonatomic, copy)   NSString     *adcode;   //!< 所在区域编码
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 中心点经纬度
@property (nonatomic, assign) CGFloat      area; //!< 面积，单位平方米

@end

/// 道路
@interface AMapMpaasRoad : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *uid; //!< 道路ID
@property (nonatomic, copy)   NSString     *name; //!< 道路名称
@property (nonatomic, assign) NSInteger     distance; //!< 距离（单位：米）
@property (nonatomic, copy)   NSString     *direction; //!< 方向
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 坐标点

@end

/// 道路交叉口
@interface AMapMpaasRoadInter : AMapMpaasSearchObject

@property (nonatomic, assign) NSInteger     distance; //!< 距离（单位：米）
@property (nonatomic, copy)   NSString     *direction; //!< 方向
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 经纬度
@property (nonatomic, copy)   NSString     *firstId; //!< 第一条道路ID
@property (nonatomic, copy)   NSString     *firstName; //!< 第一条道路名称
@property (nonatomic, copy)   NSString     *secondId; //!< 第二条道路ID
@property (nonatomic, copy)   NSString     *secondName; //!< 第二条道路名称

@end

/// 门牌信息
@interface AMapMpaasStreetNumber : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *street; //!< 街道名称
@property (nonatomic, copy)   NSString     *number; //!< 门牌号
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!<  坐标点
@property (nonatomic, assign) NSInteger     distance; //!< 距离（单位：米）
@property (nonatomic, copy)   NSString     *direction; //!< 方向

@end

/// 商圈
@interface AMapMpaasBusinessArea : AMapMpaasSearchObject

@property (nonatomic, strong) NSString     *name; //!< 名称
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 中心坐标

@end

/// 地址组成要素
@interface AMapMpaasAddressComponent : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString         *province; //!< 省/直辖市
@property (nonatomic, copy)   NSString         *city; //!< 市
@property (nonatomic, copy)   NSString         *citycode; //!< 城市编码
@property (nonatomic, copy)   NSString         *district; //!< 区
@property (nonatomic, copy)   NSString         *adcode; //!< 区域编码
@property (nonatomic, copy)   NSString         *township; //!< 乡镇街道
@property (nonatomic, copy)   NSString         *towncode; //!< 乡镇街道编码
@property (nonatomic, copy)   NSString         *neighborhood; //!< 社区
@property (nonatomic, copy)   NSString         *building; //!< 建筑
@property (nonatomic, strong) AMapMpaasStreetNumber *streetNumber; //!< 门牌信息
@property (nonatomic, strong) NSArray<AMapMpaasBusinessArea *> *businessAreas; //!< 商圈列表 AMapMpaasBusinessArea 数组

@end

/// 逆地理编码
@interface AMapMpaasReGeocode : AMapMpaasSearchObject

// 基础信息
@property (nonatomic, copy)   NSString             *formattedAddress; //!< 格式化地址
@property (nonatomic, strong) AMapMpaasAddressComponent *addressComponent; //!< 地址组成要素

// 扩展信息
@property (nonatomic, strong) NSArray<AMapMpaasRoad *> *roads; //!< 道路信息 AMapMpaasRoad 数组
@property (nonatomic, strong) NSArray<AMapMpaasRoadInter *> *roadinters; //!< 道路路口信息 AMapMpaasRoadInter 数组
@property (nonatomic, strong) NSArray<AMapMpaasPOI *> *pois; //!< 兴趣点信息 AMapMpaasPOI 数组
@property (nonatomic, strong) NSArray<AMapMpaasAOI *> *aois; //!< 兴趣区域信息 AMapMpaasAOI 数组

@end

/// 地理编码
@interface AMapMpaasGeocode : AMapMpaasSearchObject

@property (nonatomic, copy) NSString     *formattedAddress; //!< 格式化地址
@property (nonatomic, copy) NSString     *province; //!< 所在省/直辖市
@property (nonatomic, copy) NSString     *city; //!< 城市名
@property (nonatomic, copy) NSString     *citycode; //!< 城市编码
@property (nonatomic, copy) NSString     *district; //!< 区域名称
@property (nonatomic, copy) NSString     *adcode; //!< 区域编码
@property (nonatomic, copy) NSString     *township; //!< 乡镇街道
@property (nonatomic, copy) NSString     *neighborhood; //!< 社区
@property (nonatomic, copy) NSString     *building; //!< 楼
@property (nonatomic, copy) AMapMpaasGeoPoint *location; //!< 坐标点
@property (nonatomic, copy) NSString     *level; //!< 匹配的等级

@end

#pragma mark - 公交查询

/// 无用，已清除

#pragma mark - 行政区划

@interface AMapMpaasDistrict : AMapMpaasSearchObject

@property (nonatomic, copy)   NSString     *adcode; //!< 区域编码
@property (nonatomic, copy)   NSString     *citycode; //!< 城市编码
@property (nonatomic, copy)   NSString     *name; //!< 行政区名称
@property (nonatomic, copy)   NSString     *level; //!< 级别
@property (nonatomic, copy)   AMapMpaasGeoPoint *center; //!< 城市中心点
@property (nonatomic, strong) NSArray<AMapMpaasDistrict *> *districts; //!< 下级行政区域数组
@property (nonatomic, strong) NSArray<NSString *> *polylines; //!< 行政区边界坐标点, NSString 数组

@end

#pragma mark - 路径规划

/// 无用，已清除

#pragma mark - 天气查询

/// 无用，已清除

#pragma mark - 云图基础数据类型

/// POI点的图片信息
@interface AMapMpaasCloudImage : AMapMpaasSearchObject

@property (nonatomic, copy) NSString *uid; //!< 图片的id标识
@property (nonatomic, copy) NSString *preurl; //!< 图片压缩后的url串
@property (nonatomic, copy) NSString *url; //!< 图片原始的url

@end

/// POI信息
@interface AMapMpaasCloudPOI : AMapMpaasSearchObject

@property (nonatomic, assign) NSInteger     uid; //!< 唯一表示
@property (nonatomic, copy)   NSString     *name; //!< 名称
@property (nonatomic, copy)   AMapMpaasGeoPoint *location; //!< 坐标位置
@property (nonatomic, copy)   NSString     *address;  //!< 地址
@property (nonatomic, strong) NSDictionary *customFields; //!< 用户自定义字段
@property (nonatomic, copy)   NSString     *createTime; //!< 创建时间
@property (nonatomic, copy)   NSString     *updateTime; //!< 更新时间
@property (nonatomic, assign) NSInteger     distance; //!< 离当前位置的距离(只在云图周边搜索时有效)
@property (nonatomic, strong) NSArray<AMapMpaasCloudImage *> *images;  //!< 图片信息

@end





