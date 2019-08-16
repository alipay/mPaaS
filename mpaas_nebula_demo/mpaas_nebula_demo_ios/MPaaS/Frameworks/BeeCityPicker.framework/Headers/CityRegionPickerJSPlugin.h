//
//  CityRegionPickerJSPlugin.h
//  BeeCityPicker
//
//  Created by 莜阳 on 16/11/17.
//  Copyright © 2016年 Alipay. All rights reserved.
//

@interface CityRegionPickerJSPlugin : NSObject <PSDPluginProtocol>

@property (nonatomic, strong) PSDJsApiResponseCallbackBlock regionPickerCallback;


@property (nonatomic,copy) PSDJsApiResponseCallbackBlock bankCardChannelCallback;

@property (nonatomic,copy) PSDJsApiResponseCallbackBlock multiLevelSelectCallback;

@end
