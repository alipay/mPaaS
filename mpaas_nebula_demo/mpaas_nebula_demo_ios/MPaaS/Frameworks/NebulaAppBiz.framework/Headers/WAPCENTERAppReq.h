//com.alipay.wapcenter.rpc.model.AppReq
/*
 *generation date:Thu Mar 10 21:15:46 CST 2016
 *tool version:5.1.1
 *template version:4.2.3
 */


																			 


   
 @interface WAPCENTERAppReq : NSObject

/** 
 * 系统版本
 */

		@property(nonatomic, strong) NSString *system;
		 	/** 
 * 客户端版本
 */

		@property(nonatomic, strong) NSString *client;
		 	/** 
 * sdk 版本
 */

		@property(nonatomic, strong) NSString *sdk;
		 	/** 
 * 平台（ios / android）
 */

		@property(nonatomic, strong) NSString *platform;
		 	/** 
 * 环境（prepub / production）
 */

		@property(nonatomic, strong) NSString *env;
		 	/** 
 * 渠道（rc / official）
 */

		@property(nonatomic, strong) NSString *channel;
		 	/** 
 * 当前客户端 id，目前已知5个，最多不会超过10个（com.alipay.xx）
 */

		@property(nonatomic, strong) NSString *bundleid;
		 	/** 
 * 指定应用 id 或版本来查询 可选，不传时就会返回所有应用的列表 格式为 json string，解析后的 json 格式为： {  "2000135": { "nbl_id": "2000135",  "version":"1.0.0.0"  } } version 为空时默认匹配最新的版本
 */

		@property(nonatomic, strong) NSString *query;
		    /**
 * 客户端已安装(下包并解压下包并解压)应用
 */

        @property(nonatomic, strong) NSString *existed;
		 	/**
 * 灰度规则 可选，不传时不进行灰度规则的过滤，默认调用方一定会传递 格式为 json string，解析后的 json 格式为： { "uid": 100, "nick": "foo" }
 */

		@property(nonatomic, strong) NSString *grayRules;
		 	
            /**
 * 本地应用版本信息 可选, 不传时不计算, 格式为 json string, 解析后的 json 格式为: { "20000878": "0.1.1.123456", "20000879": "0.1.1.123456" }
 */

        @property(nonatomic, strong) NSString *localAppInfo;


            /**
 * 是否开启强大的RPC功能, 可选,不传时不开启,传入字符串  /^YES$/i 开启  , 传入 /^NO$/i 不开启
*/
        @property(nonatomic, strong) NSString *stableRpc;

/**
 * 场景 (nil, ONLINE, DEBUG, TRIAL)
 */
        @property(nonatomic, strong) NSString *scene;

/**
 * 强大rpc是否只识别localAppInfo中应用
 */
        @property(nonatomic, strong) NSString *preferLocal;

/*
 *  请求同步/异步标识
 */
        @property(nonatomic, strong) NSString *reqmode;

@end
	
	
