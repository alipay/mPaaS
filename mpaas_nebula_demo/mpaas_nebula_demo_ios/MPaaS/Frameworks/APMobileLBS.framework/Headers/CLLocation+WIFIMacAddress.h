//
//  CLLocation+WIFIMacAddress.h
//  APMobileLBS
//
//  Created by ronghui.zrh on 16/2/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@interface CLLocation (WIFIMacAddress)

@property(nonatomic,strong)NSNumber *location_from_alipay_client;

@property(nonatomic,strong)NSNumber *lbs_from_wifi;

@property(nonatomic,strong)NSString *lbs_wifi_address;

@property(nonatomic,strong)NSString *lbs_wifi_mac;

@property(nonatomic,strong)NSString *lbs_wifi_ssid;

@property(nonatomic,strong)NSString *lbs_optimized;



/**
 *  没有经过转换坐标系的纬度
 */
@property(nonatomic,assign)CLLocationDegrees lbs_unconverted_latitude;

/**
 *  没有经过转换坐标系的经度
 */
@property(nonatomic,assign)CLLocationDegrees lbs_unconverted_longitude;

@end
