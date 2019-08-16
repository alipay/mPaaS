//com.alipay.mobilelbs.common.service.facade.vo.Location
/*
 *generation date:Sun Feb 15 17:04:47 CST 2015
 *tool version:4.2.0
 *template version:4.1.1
 */


@class APLBSBluetoothDevice;
@class APLBSGSMInfo;
@class APLBSWifiInfo;
@class APLBSCDMAInfo;
																			 


   
 @interface APLBSLocation : NSObject <NSCoding>

/** 
 * 经度 
 */

		@property(nonatomic, assign) double longitude;
	/** 
 * 纬度 
 */

		@property(nonatomic, assign) double latitude;
	/** 
 * 海拔 
 */

		@property(nonatomic, assign) double altitude;
	/** 
 * 精确度 
 */

		@property(nonatomic, assign) double accuracy;
	/** 
 * 速度 
 */

		@property(nonatomic, assign) double speed;
	/** 
 * 方向 
 */

		@property(nonatomic, assign) double direction;
	/** 
 * 附近蓝牙设备信息 
 */

        @property(nonatomic, strong) NSDate *timesnap;

		@property(nonatomic, strong) NSArray *bluetoothDevices;
		 		+ (Class)bluetoothDevicesElementClass;
		 	/** 
 * 邻居基站信息 
 */

		@property(nonatomic, strong) NSArray *gsmInfos;
		 		+ (Class)gsmInfosElementClass;
		 	/** 
 * wifi信息 
 */

		@property(nonatomic, strong) NSArray *wifiInfos;
		 		+ (Class)wifiInfosElementClass;
		 	/** 
 * CDMA基站信息 
 */

		@property(nonatomic, strong) NSArray *cdmaInfos;
		 		+ (Class)cdmaInfosElementClass;
		 	/** 
 * 附加信息 
 */

		@property(nonatomic, strong) NSDictionary *extraInfos;
		 		+ (Class)extraInfosElementClass;
		 	/** 
 * adcode 
 */

		@property(nonatomic, strong) NSString *adCode;
		 	/** 
 * 地址 
 */

		@property(nonatomic, strong) NSString *address;
		 	/** 
 * 城市 
 */

		@property(nonatomic, strong) NSString *city;
		 	/** 
 * 城市编码 
 */

		@property(nonatomic, strong) NSString *cityCode;
		 	/** 
 * 城市区 
 */

		@property(nonatomic, strong) NSString *district;
		 	/** 
 * 省份 
 */

		@property(nonatomic, strong) NSString *province;
		 	/** 
 * 省份的ADCode 
 */

		@property(nonatomic, strong) NSString *provinceAdCode;
		 	/** 
 * 街道 
 */

		@property(nonatomic, strong) NSString *street;
		 	/** 
 * 国家名称 
 */

		@property(nonatomic, strong) NSString *country;
		 	/** 
 * 国家代码 
 */

		@property(nonatomic, strong) NSString *countryCode;
		 	


        @property(nonatomic, strong) NSString *cityAdcode;


        @property(nonatomic, strong) NSString *districtAdcode;

        @property(nonatomic, strong) NSString *encryptLocation;

@end
	
	
