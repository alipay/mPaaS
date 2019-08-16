//
//  APRegion.h
//  BeeCityPicker
//
//  Created by NianXi on 15/5/4.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BEERegionObject.h"

/**
 *  文档及demo详见：
 *  http://gitlab.alibaba-inc.com/wuqian.wq/APRegionDocument/wikis/home*
 *  国家名称＋二级地区＋最末级地区
 */
#define BEERegionResultKey_Country           @"country"
#define BEERegionResultKey_SecondaryRegion   @"secondaryRegion"
#define BEERegionResultKey_ThirdRegion       @"thirdRegion"


#define BEERegionResultKey_FullCode        @"fullCode" //地区码

/**
 *  选择地区完成后的回调block
 *
 *  @param region 地区信息字典 @{ @"country":国家名称, @"secondaryRegion":二级地区名称, @"thirdRegion":三级地区名称或最末级地区名称 }
 *                       如: @{ @"country":@"中国", @"secondaryRegion":@"北京", @"thirdRegion":@"朝阳",@"fullCode":@"CN_BEIJING_CHAOYANG" }
 */
typedef void(^BEERegionHandler) (NSDictionary *region);

@interface BEERegion : NSObject

/**
 *  唤起地区选择控件，自动push展示
 *
 *  @param navi                当前 ViewController 的 NavigationController
 *  @param backVC              当前 ViewController
 *  @param curSelectedResult   当前显示的已选地区信息
 *  @param handler             结果回调
 */
+ (void)showRegionControllerWithNavigationController:(UINavigationController *)navi
                                backToViewController:(UIViewController *)backVC
                                   curSelectedRegion:(NSDictionary *)curSelectedResult
                                     completionBlock:(BEERegionHandler)handler;

/**
 *  唤起地区选择控件，自动push展示
 *
 *  @param navi                当前 ViewController 的 NavigationController
 *  @param backVC              当前 ViewController
 *  @param curSelectedResult   当前显示的已选地区信息
 *  @param customRegionDatas   业务自定义区域选择数据
 *  @param config              配置
 *  @param handler             结果回调
 */
+ (void)showRegionControllerWithNavigationController:(UINavigationController *)navi
                                backToViewController:(UIViewController *)backVC
                                   curSelectedRegion:(NSDictionary *)curSelectedResult
                                              config:(NSDictionary *)config
                                   customRegionDatas:(NSArray *)customRegionDatas
                                     completionBlock:(BEERegionHandler)handler;
/**
 *  唤起地区选择控件，自动push展示
 *
 *  @param navi                当前 ViewController 的 NavigationController
 *  @param backVC              当前 ViewController
 *  @param curSelectedResult   当前显示的已选地区信息
 *  @param config              配置参数，目前支持:
 *                             最大深度 @"Level": BEERegionResultKey_Country/BEERegionResultKey_SecondaryRegion/BEERegionResultKey_ThirdRegion
                               是否需要定位 @"SkipLocation" : @"true":@"fasel"
 *  @param handler             结果回调
 */
+ (void)showRegionControllerWithNavigationController:(UINavigationController *)navi
                                backToViewController:(UIViewController *)backVC
                                   curSelectedRegion:(NSDictionary *)curSelectedResult
                                              config:(NSDictionary *)config
                                     completionBlock:(BEERegionHandler)handler;


+ (void)showRegionSubRegionControllerWithNavigationController:(UINavigationController *)navi
                                         backToViewController:(UIViewController *)backVC
                                            curSelectedRegion:(NSDictionary *)curSelectedResult
                                                   regionItem:(BEERegionObject *)regionItem
                                              completionBlock:(BEERegionHandler)handler;

+(NSArray<NSString *> *) contryAndStateCodeForFullPath:(NSString *)fullCode;


@end

