//
//  MASSConfigCenter.h
//  MASSChannel
//
//  Created by yangxiao on 15/11/25.
//  Copyright © 2015年 ppp. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import <APBaseInterfaceAdapter/APBaseInterfaceAdapter.h>
#import "MASSErrorInterface.h"

#define RTT_TIMEOUT_CONF_KEY @"toc"     //超时默认10s
#define RTT_TIMEOUT_2G @"to2g"
#define RTT_TIMEOUT_3G @"to3g"
#define RTT_TIMEOUT_4G @"to4g"
#define RTT_TIMEOUT_WIFI @"towi"
#define RTT_TIMEOUT_DEFAULT @"todft"
#define UNIT_SIZE_CONF_KEY @"uzk"       //任务大小默认100k
#define UNIT_SIZE_2G @"u2g"
#define UNIT_SIZE_3G @"u3g"
#define UNIT_SIZE_4G @"u4g"
#define UNIT_SIZE_WIFI @"uwi"
#define UNIT_SIZE_DEFAULT @"udft"
#define PIECE_SIZE_CONF_KEY @"pzk"      //分片大小默认 10k
#define PIECE_SIZE_2G @"p2g"
#define PIECE_SIZE_3G @"p3g"
#define PIECE_SIZE_4G @"p4g"
#define PIECE_SIZE_WIFI @"pwi"
#define PIECE_SIZE_DEFAULT @"pdft"
#define DOWNLOAD_TASK_CUNCURENT @"dlc"
#define TFS_DOWNLOAD_TASK_CUNCURENT @"tfsc"
#define TFS_CAN_CRYPTO_HOSTS @"tfsch"
#define USING_CHUNK_LOGIC @"ucl"
#define USING_URL_ENCODE_LOGIC @"uuel"
#define TFS_USING_URL_ENCODE_LOGIC @"tuul"
#define MAX_CUNCURRENT_LINK_COUNT @"mclc"
#define DELTA_PERCENT_PARTLY_IMG_SHOW @"dltp"
#define NBNET_FREQUENCE_CONNECT_SWITCH @"nfcs"
#define USING_NEW_RUNLOOP_FUNC @"unrf"
#define NETSERVICE_UPERR_REPORT @"massup"

//从这条开始配置值就是存储值
#define BIZ_NOT_USE_MASS @"bnum"
#define TFS_COOKIE_SWITCH @"tcs"
#define LOW_PRIORITY_LIST @"lpl"
#define LOW_PRIORITY_HOST @"lph"
#define LOW_PRIORITY_BIZ @"lpb"
#define TFS_USE_GZIP @"tzip"
#define RECORDING_USE_FILE_UPLOAD @"rufu"
#define TFS_USE_DNS_BEFORE @"tudb"
#define BIZ_ID_USE_DJANGO @"biud"
#define ABROAD_USE_MMDP @"aumd"
#define ABROAD_USE_MMUP @"aumu"
#define BACK_GROUD_FETCH_TOKEN @"bgft"
#define BACK_GROUND_DOWNLOAD @"bgd"
#define TIMEOUT_ERROR_CLASSFY @"tec"
#define FLOW_STATIS_KEY @"fsk"
// cdn续传逻辑开关
#define CONTINUS_CDN_SWITCH @"ccs"
#define CONTINUS_SERVICE_LIST @"csl"

#define USE_MMDP_DIRECT_BIZS @"umdb"

#define TFS_HOST_IP_LIST_CACHE_TIME 10

#define MASS_API_SERVER_HOST @""
#define MASS_UP_SERVER_HOST @""
#define MASS_DOWN_SERVER_HOST @""

@interface ServerAddressInfo : NSObject

@property (nonatomic) NSString* ip;
@property (nonatomic) NSInteger port;

@end

//由于次tfs域名查询是需要查文件的，所以减少频率，在一段时间用这里的缓存
@interface TfsIpListInfo : NSObject
@property (nonatomic) NSMutableArray<NSString*>*    ipList;
@property (nonatomic) NSInteger                     timeoutTime;
/**
 *  构造
 *
 *  @param list
 *  @param t
 *
 *  @return
 */
+(instancetype)TfsIplistInfoWithIplist:(NSMutableArray<NSString*>*)list TimeoutTime:(NSInteger)t;
@end

@interface FlowStatisticInfo : NSObject

@property (nonatomic,assign) NSInteger  tcpCount;

@property (nonatomic,assign) NSInteger  sslCount;

@property (nonatomic,assign) NSInteger  upFlow;

@property (nonatomic,assign) NSInteger  downFlow;

@property (nonatomic,assign) NetAccessType netType;

@end


@interface MASSConfigCenter : NSObject

@property (nonatomic) NetAccessType             netType;                        //网络类型

@property (atomic) NSMutableDictionary*      rttTimeOutConf;                 //一个网络来回的超时时间设置

@property (nonatomic) NSString*                 registHostUp;                   //上传的域名

@property (nonatomic) NSMutableArray*           upIpList;                       //上传的服务端地址列表

@property (nonatomic) NSString*                 registHostDown;                 //下载的域名

@property (nonatomic) NSMutableArray*           downIpList;                     //下载的服务端地址列表

@property (nonatomic) NSString*                 registHostDownCrypto;           //加密下载需要跟换域名的

@property (nonatomic) NSMutableArray*           downIplistCrypto;               //加密下载的ip列表

@property (nonatomic) NSString*                 registTokenHost;                //指令服务域名

@property (nonatomic) NSMutableArray*           tokenIpList;                    //指令服务地址列表

@property (atomic) NSMutableDictionary*      dataPiceUnitSize;               //数据最小分片大小

@property (atomic) NSMutableDictionary*      dataPartUnitSize;               //任务分片大小

@property (nonatomic) float                     tokenRequestInternal;           //请求token的时间间隔

@property (nonatomic) float                 deltaPercentPartlyImgShow;      //渐显的最小百分比

@property (nonatomic) NSInteger                 downloadTasksSameTime;          //能同时进行的下载数量

@property (nonatomic) NSInteger                 tfsDownloadTasksSameTime;       //能同时进行的tfs下载数量

@property (nonatomic) id<NetAccessInfo>         tfsHostInfoInterface;           //提供域名查询iplist接口

@property (nonatomic) NSMutableSet<NSString*>*  tfsCanCryptoHosts;              //tfs下载的时候能降级的域名

@property (nonatomic) BOOL                      usingChunkLogic;                //tfs是否处理chunked回包

@property (nonatomic) BOOL                      djangoUsingUrlEncodeLogic;            //对dj url是否需要进行特殊字符编码

@property (nonatomic) BOOL                      tfsUsingUrlEncodeLogic;                 //对tfs url是否需要进行特殊字符编码

@property (nonatomic) BOOL                      useNewRunloopFunc;                      //是否使用阻塞式runloop

@property (nonatomic) NSMutableArray*           bizNotUseMASS;                          //哪些业务不用MASS通道，用苹果通道

@property (nonatomic) BOOL                      tfsUseCookieManager;                    //是否管理cookie的开关

@property (nonatomic) NSArray*                  lowPriorityHosts;                       //tfs请求中低优先级的域名列表

@property (nonatomic) NSArray*                  lowPriorityBiztypes;                    //tfs请求中优先级低的业务列表

@property (nonatomic,assign) BOOL               tfsUseGzip;                             //url下载是否需要使用gzip回包压缩

@property (nonatomic,assign) BOOL               recordingUseFileUpload;                 //边录边传直接使用文件上传

@property (nonatomic,assign) BOOL               tfsUseDnsBefore;                        //在进行url资源下载时，先做dns解析

@property (nonatomic,assign) BOOL               massUpErrReport;                        //上传不可用上报开关

@property (nonatomic) NSArray*    bizIdUseDjangoEnforce;                  //buzid的开关，没有值表示不需要,如果bizid在列表中，这个业务强制走改良版

@property (nonatomic,assign) BOOL               abroadUseMMDP;              //海外用户是否用mmdp

@property (nonatomic,assign) BOOL               abroadUseMMUP;              //海外用户是否用mmup

@property (nonatomic,assign) BOOL               backGroudTokenGet;          //是否在后台刷token

@property (nonatomic,assign) BOOL               downloadBackground;         //是否开启后台下载功能

@property (nonatomic,assign) BOOL               errorTimeoutClassfy;               //是否做错误细分

@property (nonatomic,assign) BOOL               flowStatisticSwitch;                //是否做流量统计的开关

@property (nonatomic,assign) BOOL               continusSwitch;                     //是否开启cdn跨任务续传

@property (atomic,strong) NSArray*              continusServiceList;                //支持续传的域名列表，是支持类似 *.alipay.com 这种通配的

@property (atomic,strong) NSArray*              mmdpDirectBizs;                     //对于这些业务，必须打开mmdp开关

//@property (nonatomic) NSMutableArray*           bizDealCookies;                         //哪些业务需要管理cookie

/**
 *  单例
 *
 *  @return
 */
+(instancetype)shareInstance;

/**
 *  初始化
 */
-(void)initFromFileStorage;

/**
 *  获取分片大小
 *
 *  @return
 */
-(NSUInteger)getPiceUnitSize;

/**
 *  获取分任务大小
 *
 *  @return
 */
-(NSUInteger)getPartUnitSize;

/**
 *  获取ip
 *
 *  @param retrys
 *
 *  @return
 */
-(NSString*)getUploadSvrIpRetrytimes:(NSUInteger)retrys;

/**
 *  获取ip
 *
 *  @param retrys
 *
 *  @return
 */
-(NSString*)getDownloadSvrIpRetrytimes:(NSUInteger)retrys;

/**
 *  获取ip
 *
 *  @param retrys
 *
 *  @return
 */
-(NSString*)getDownloadSvrIpCryptoRetrytimes:(NSUInteger)retrys;

/**
 *  获取ip
 *
 *  @param retrys
 *
 *  @return
 */
-(NSString*)getTokenSvrIpRetrytimes:(NSUInteger)retrys;

/**
 *  获取ip
 *
 *  @param retrys
 *
 *  @return
 */
-(NSString*)getTfsDownloadSvrIp:(NSString*)host retryTimes:(NSUInteger)retrys succ:(BOOL*)succ;

/**
 *  建连超时
 *
 *  @return
 */
-(float)getConnectTimeout;

/**
 *  回包超时
 *
 *  @return
 */
-(float)getRspTimeout;

/**
 *  刷配置
 *
 *  @param conf
 */
-(void)freshConfig:(NSDictionary*)conf;

/**
 *  打日志用
 *
 *  @return
 */
-(NSString*)toString;

/**
 *  tfs
 *
 *  @param hosts
 */
-(void)setTfsCryptoHosts:(NSArray*)hosts;

/**
 *  tfs是否可以降级tls
 *
 *  @param host
 *
 *  @return 
 */
-(BOOL)canCryptoOnHost:(NSString*)host;

-(BOOL)isBizNotUseMASS:(NSString*)biz;

-(BOOL)isLowPriorityWithHost:(NSString*)host andBiz:(NSString*)biz;

//该业务是否禁止走新通道
-(BOOL)bizIdEnforceDjango:(NSString*)biz;

//该域名是否支持续传
-(BOOL)hostCanContinus:(NSString*)host;

// 某些业务要直接使用mmdp协议
-(BOOL)bizUseMMDPDirect:(NSString*)biz;

@end
