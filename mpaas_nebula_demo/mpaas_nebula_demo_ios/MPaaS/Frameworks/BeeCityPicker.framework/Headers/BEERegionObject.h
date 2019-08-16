//
//  APRegionObject.h
//  BeeCityPicker
//
//  Created by NianXi on 15/5/4.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BEERegionObject : NSObject

@property (nonatomic ,copy)NSString *language;//当前显示语言
@property (nonatomic ,copy)NSString *regionCode;//当前地区代码
@property (nonatomic ,copy)NSString *title;//当前地区title
@property (nonatomic ,strong) NSMutableArray *subRegions;//当前地区包含的子区域


/**
 *  APRegionObject初始化函数，生成包含当前地区信息的实例
 *
 *  @param language   当前显示语言
 *  @param regionCode 当前地区代码
 *  @param title      当前地区title
 *
 *  @return 返回初始化的实例
 */
- (instancetype)initWithLanguage:(NSString *)language
                      regionCode:(NSString *)regionCode
                           title:(NSString*)title;

/**
 *  读取地区信息txt文件，并按国家－省－市－区进行格式化
 *
 *  @param path txt文件路径
 *
 *  @return 格式化后的地区列表信息
 */
+ (NSArray *)makeupDataWithFilePath:(NSString *)path;
@end
