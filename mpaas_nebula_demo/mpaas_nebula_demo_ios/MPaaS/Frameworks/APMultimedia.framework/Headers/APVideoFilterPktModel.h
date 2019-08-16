//
//  APVideoFilterPktModel.h
//  APMultimedia
//
//  Created by Monster on 16/5/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APVideoFilterModel : NSObject
@property (nonatomic, strong) NSString* filterId;        //序号
@property (nonatomic, strong) NSString* iconId;     //图片ID
@property (nonatomic, strong) NSString* shortCut;   //描述
@end

@interface APVideoFilterPktModel : NSObject

/**
 *  获取滤镜配置信息
 *
 *  @return @[APVideoFilterModel,APVideoFilterModel,APVideoFilterModel]
 */
+ (NSArray*)getFilterPktModelInfo;


/**
 *  是否支持滤镜功能
 *
 *  @return YES 支持
 */
+ (BOOL)isSupport;
@end
