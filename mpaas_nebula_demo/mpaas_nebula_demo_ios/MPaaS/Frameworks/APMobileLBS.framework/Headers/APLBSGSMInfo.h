//com.alipay.mobilelbs.common.service.facade.vo.GSMInfo
/*
 *generation date:Sun Feb 15 17:04:47 CST 2015
 *tool version:4.2.0
 *template version:4.1.1
 */


																			 


   
 @interface APLBSGSMInfo : NSObject <NSCoding>

/** 
 * 移动国家代码 
 */

		@property(nonatomic, assign) int mcc;
	/** 
 * 移动网络代码 
 */

		@property(nonatomic, assign) int mnc;
	/** 
 * 位置区域代码 
 */

		@property(nonatomic, assign) int lac;
	/** 
 * 基站编号 
 */

		@property(nonatomic, assign) int cid;
	/** 
 * 信号强度 
 */

		@property(nonatomic, assign) int rssi;
	

                               
@end
	
	
