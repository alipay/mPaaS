//
//  BEECitiesController.h
//  ALPDiscoveryWidget
//
//  Created by bingye.yu on 14-3-5.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "BEECity.h"
#import "BEECityBusiData.h"
#import <APMobileLBS/LBSLocationManager.h>

#define kBEE_SHOW_CURRENT_CITY                  @"showCurrentCity"
#define kBEE_SHOW_HOT_CITY                      @"needHotCity"
#define kBEE_SHOW_HISTORY_CITY                  @"showHistoryCity"
#define kBEE_SET_LOCATED_CITY                   @"setLocatedCity"
#define kBEE_SET_LOCATED_CITY_TIMEOUT           @"setLocatedCityTimeout"
#define kBEE_HOT_CITY_SECTION_TITLE             @"hotCitySectionTitle"
#define kBEE_HOT_CITY_INDEX_BAR_TITLE           @"hotCityIndexBarTitle"
#define kBEE_AUTH_GUIDE_BUSINESS_NAME           @"authGuideBusinessName"
#define kBEE_TITLEBAR_TEXT                      @"titleBarText"
#define kBEE_TABBAR_INDEX                       @"tabBarIndex"  // 全部/境外 tab 显示下标
#define kBEE_LOCATION_REGEOTYPE                 @"locationReGeoType" // 自定义定位类型，值取 BEELocationReGeoType 类型，不传默认 BEELocationReGeoTypeReGeoCodeToCity

#define kBEE_SET_LOCATED_CITY_NAME_NOTI         @"setLocatedCityNameNoti"  // 修改定位城市的通知名
#define kBEE_SET_LOCATED_CITY_NAME              @"locatedCityName"
#define kBEE_SET_LOCATED_CITY_ID                @"locatedCityId"
#define kBEE_SET_LOCATED_CITY_ADCODE            @"locatedCityAdCode"
#define kBEE_SET_LOCATED_CITY_PINYIN            @"locatedCityPinyin"

typedef NS_ENUM(NSInteger, BEELocationReGeoType) {
    BEELocationReGeoTypeReverse = APCoreLocationReGeoTypeReverse,
    BEELocationReGeoTypeReGeoCode = APCoreLocationReGeoTypeReGeoCode,
    BEELocationReGeoTypeReGeoCodeToCity = APCoreLocationReGeoTypeReGeoCodeToCity,
    BEELocationReGeoTypeReGeoCodeAll = APCoreLocationReGeoTypeReGeoCodeAll
};

@class BEECitiesController;

@protocol BEECityPickerDelegate <NSObject>

/**
 * @desc 完成城市选择后返回给业务方进行处理，组件自动将自己的VC pop出去
 */
- (void)citiesController:(BEECitiesController *)citiesController didSelectCity:(BEECity *)city DEPRECATED_MSG_ATTRIBUTE("Replaced by 'citiesController:didSelectCity:needPopCityPicker'");

/**
 * @desc 完成城市选择之后，返回给业务方处理，根据参数判断是否需要将城市选择的VC pop出去
 * @param needPop (BOOL *) 业务方告诉组件是否需要将组件的VC pop出去，Default=YES.
 */
@optional
- (void)citiesController:(BEECitiesController *)citiesController didSelectCity:(BEECity *)city needPopCityPicker:(BOOL *)needPop;
- (void)locatedCityLocation:(CLLocation *)location locatedCityId:(NSString *)locatedCityId;

@end

@interface BEECitiesController : DTViewController

@property (nonatomic, weak) id<BEECityPickerDelegate>citySelDelegate;

/**
 *  初始化选择城市VC
 *
 *  @param city           已定位城市BEECity实例（可选）
 *  @param selectDelegate delegate
 *  @param needed         是否显示热门城市
 *
 *  @return instance
 */
- (id)initWithLocatedCity:(BEECity *)city
           selectDelegate:(id<BEECityPickerDelegate>)selectDelegate
              needHotCity:(BOOL)needed;


/**
 *  初始化选择城市VC
 *
 *  @param city           已定位城市BEECity实例（未定位可以传`nil`）
 *  @param selectDelegate delegate
 *  @param cityList       自定义城市列表 (格式同自定义热门城市)
 *  @param hotCityList    自定义热门城市列表，格式如下:
 *                         [@"%城市码%,%城市中文名%,%城市名拼音小写%"
 *                          @"110100,北京市,beijing" ...]
 *                          这里传入的三个值，当用户选中城市之后，会作为BEECity实例的属性（分别是`adcode`, `city`, `pinyin`）传回
 *  @param config         UI元素显示配置，格式为 @{kBEE_SHOW_HOT_CITY:(BOOL)@YES/@NO, kBEE_SHOW_CURRENT_CITY:(BOOL)@YES/@NO, kBEE_SHOW_HISTORY_CITY:(BOOL)@YES/@NO @"hotCitySectionTitle":@"已开通城市", kBEE_HOT_CITY_INDEX_BAR_TITLE:@"开通"}
 *
 *  @return instance
 */
- (instancetype)initWithLocatedCity:(BEECity *)city
                     selectDelegate:(id<BEECityPickerDelegate>)selectDelegate
                     customCityList:(NSArray *)cityList
                  customHotCityList:(NSArray *)hotCityList
                           uiConfig:(NSDictionary *)config;

/**
 *  初始化选择城市VC
 *
 *  @param city           已定位城市BEECity实例（未定位可以传`nil`）
 *  @param selectDelegate delegate
 *  @param busiCityList   自定义城市列表 (参考BEECityBusiData说明)
 *  @param config         UI元素显示配置，格式为 @{kBEE_SHOW_HOT_CITY:(BOOL)@YES/@NO, kBEE_SHOW_CURRENT_CITY:(BOOL)@YES/@NO, kBEE_SHOW_HISTORY_CITY:(BOOL)@YES/@NO @"hotCitySectionTitle":@"已开通城市", kBEE_HOT_CITY_INDEX_BAR_TITLE:@"开通", kBEE_TABBAR_INDEX:(NSInterger)@0/@1}
 *
 *  @return instance
 */
- (instancetype)initWithLocatedCity:(BEECity *)city
                     selectDelegate:(id<BEECityPickerDelegate>)selectDelegate
                   businessCityData:(NSArray<BEECityBusiData *> *)busiCityList
                           uiConfig:(NSDictionary *)config;

/**
 *  刷新城市控件列表，必须在主线程调用
 *
 *  @param hotCityList 热门城市列表
 *  @param cityList    城市列表
 */
- (void)reloadWithHotCityList:(NSArray*)hotCityList cityList:(NSArray*)cityList;
- (void)reloadBusinessCityData:(NSArray<BEECityBusiData *> *)busiCityData;

@end


