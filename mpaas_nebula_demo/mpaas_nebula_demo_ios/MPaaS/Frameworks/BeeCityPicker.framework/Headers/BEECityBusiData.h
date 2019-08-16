//
//  BEECityBusiData.h
//  BeeCityPicker
//
//  Created by Yanzhi on 16/4/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BEECustomItem.h"

@interface BEECityBusiData : NSObject

/**
 * @desc 用于显示在导航栏TabControl上的文本，如果只有一个Tab，则可以传入nil，使用默认标题
 */
@property (nonatomic, copy)   NSString  *title;

/**
 * @desc 是否可以加载内部默认的国内城市数据
 * 当BusiData的allCities或hotCities为空时，则通过该值判断是否读取内置缓存数据
 */
@property (nonatomic, assign) BOOL      canMockData;

/**
 * @desc 自定义区域section名称，默认展示"全球首页"
 */
@property (nonatomic, strong) NSString  *customSectionText;

/**
 * @desc 自定义区域在字母表中名称，默认展示"全球"
 */
@property (nonatomic, strong) NSString  *customSectionIndex;

/** 城市列表，格式如下:
 * [@"%城市码%,%城市中文名%,%城市名拼音小写%,%境内外%", @"%城市码%,%城市中文名%,%城市名拼音小写%,%境内外%", ...]
 * 例如：[@"310100,上海市,shanghai,0", @"110100,北京市,beijing,1", ...]
 */
@property (nonatomic, strong) NSArray<NSString *> *allCities;
@property (nonatomic, strong) NSArray<NSString *> *hotCities;
@property (nonatomic, strong) NSArray<NSString *> *historyCities;
@property (nonatomic, strong) NSArray<BEECustomItem *> *customItems; // 自定义补充列表，位于字母表上部

@end
