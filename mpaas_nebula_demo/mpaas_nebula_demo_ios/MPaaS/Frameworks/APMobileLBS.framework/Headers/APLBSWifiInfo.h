//com.alipay.mobilelbs.common.service.facade.vo.WifiInfo
/*
 *generation date:Sun Feb 15 17:04:47 CST 2015
 *tool version:4.2.0
 *template version:4.1.1
 */


																			 


   
 @interface APLBSWifiInfo : NSObject <NSCoding>

/** 
 * SSID 
 */

		@property(nonatomic, strong) NSString *ssid;
		 	/** 
 * MAC地址 
 */

		@property(nonatomic, strong) NSString *mac;
		 	/** 
 * 信号强度 
 */

		@property(nonatomic, assign) int rssi;
	

                               
@end
	
	
