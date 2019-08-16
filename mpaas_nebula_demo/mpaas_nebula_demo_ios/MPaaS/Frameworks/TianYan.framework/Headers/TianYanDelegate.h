//
//  TianYanDelegate.h
//  TianYan
//
//  Created by myy on 16/4/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//



/**
 *  实时获取各类标识参数或配置参数的delegate（这里的参数，可能会变，所以需要实时获取）
 */
@protocol TianYanRealtimeParamDelegate
@optional

/**
 *  获取当前业务ID。方便发生问题时，标识发生在哪个业务。
 *  建议实现。不实现则不知道问题发生时所处业务。
 */
- (NSString*)currentBizID;

/**
 *  获取当前ViewController的类型名。方便发生问题时，标识发生在哪个ViewController。
 *  建议实现。不实现则不知道问题发生时所处ViewController。建议对于H5ViewController返回ViewController类型＋Url。
 */
- (NSString*)currentViewController;

/**
 *  获取当前界面栈里所有ViewController的描述。方便发生问题时，标识界面情况。
 *  建议实现。不实现则不知道问题发生时界面情况。
 */
- (NSString*)allAliveViewControllers;

/**
 *  获取CPU监控的开关。
 *  建议实现。SDK会实时获取开关。
 */
- (BOOL)monitorCpuSwitch;

/**
 *  获取Performance监控的开关。
 *  建议实现。SDK会实时获取开关。
 */
- (BOOL)monitorPerSwitch;

/**
 *  获取内存监控的开关。
 *  建议实现。SDK会实时获取开关。
 */
- (BOOL)monitorMemSwitch;

/**
 * 获取是否压后台抛内存warning的开关。
 * 建议实现。SDK会实时获取开关。
 */
- (BOOL)monitorBgPostMemWarnSwitch;

/**
 *  获取耗电判断的峰值，<=100。
 *  可以不实现。SDK会实时获取。
 */
- (float)monitorPowerPeakValue;


/**
 * 获取BackgroundFetch的次数 (performFetchWithCompletionHandler的执行次数)
 * 建议实现。SDK会实时获取。
 */
- (NSUInteger)monitorBackgroundFetchCounter;

/**
 * 获取Hotspot的次数
 * 建议实现。SDK会实时获取。
 */
- (NSUInteger)monitorHotspotCounter;


/**
 *  获取回前台监控的开关。
 */
- (BOOL)monitorEnterForegroundLagSwitch;

/**
 * 卡顿监控
 */
- (BOOL)monitorLagSwitch;

/**
 * 流畅度监控
 */
- (BOOL)monitorFPSSwitch;

@end



/**
 *  性能监控专项里各子项类型定义。
 */
typedef NS_ENUM(NSUInteger, TYPerformanceMonitorType)
{
    TYPerformance_Unknown = 0,
    TYPerformance_BootCost,
    TYPerformance_FPS,
    TYPerformance_Lag,
};

/**
 *  电量监控专项里各子项类型定义。
 */
typedef NS_ENUM(NSUInteger, TYPowerMonitorType)
{
    TYPower_Unknown = 0,
    TYPower_Consume,
    TYPower_Health,
    TYPower_Issue,
    TYPower_Diagnose,
};

/**
 *  内存监控专项里各子项类型定义。
 */
typedef NS_ENUM(NSUInteger, TYMemoryMonitorType)
{
    TYMemory_Unknown = 0,
    TYMemory_Health,
    TYMemory_Leak,
    TYMemory_Warn,
    TYMemory_Occasion
};

/**
 *  存储监控专项里各子项类型定义。
 */
typedef NS_ENUM(NSUInteger, TYStorageMonitorType)
{
    TYStorage_Unknown = 0,
    TYStorage_Info,
};



/**
 *  本地log和埋点上报的delegate
 */
@protocol TianYanLogAndReportDelegate

/**
 *  调试日志通知。
 *  建议实现。建议将日志打到文件日志里，方便SDK定位问题。
 *
 *  @param tag 标识日志关键字
 *  @param str 日志字符串
 */
- (void)onDebugLog:(NSString*)tag str:(NSString*)str;

/**
 *  调试日志通知。
 *  建议实现。建议将日志“在DEBUG时”打到文件日志里，方便SDK定位问题，线上版本不打到文件日志中。
 *
 *  @param tag 标识日志关键字
 *  @param str 日志字符串
 */
- (void)onDevDebugLog:(NSString*)tag str:(NSString*)str;

/**
 *  性能专项记录通知。
 *  建议实现。建议将各参数按协定格式上传到后台做统计。
 *
 *  @param type  性能子项的类型
 *  @param param 具体参数
 *
 *  type == TYPerformance_FPS
 *  Printing description of param:
 *  {
 *      ActiveInterval = "117.5551210045815";
 *      fluencyUsage = 100;
 *  }
 *
 *  type == TYPerformance_Lag
 *  Printing description of param:
 *  {
 *      lagActivity = WWAssetsViewController;
 *      lagApp = 20000004;
 *      lagTime = "1462256304626.916992";
 *      stackFrame = "";
 *  }
 */
- (void)onPerformanceReport:(TYPerformanceMonitorType)type param:(NSDictionary*)param;

/**
 *  电量专项记录通知。
 *  建议实现。建议将各参数按协定格式上传到后台做统计。
 *
 *  @param type  电量子项的类型
 *  @param param 具体参数
 *
 *  type == TYPower_Consume
 *  Printing description of param:
 *  {
 *      consumeBatteryLevel = "0.000000";
 *      startTimeInPeriod = "483962189.584129";
 *  }
 *
 *  type == TYPower_Health
 *  Printing description of param:
 *  {
 *      ActiveInterval = "53.36726701259613";
 *     "power-score-fg" = 93;
 *      powerDetail = "locationCount:2|processTime:56.43798702955246|threadsCost:-";
 *      powerHealth = 93;
 *  }
 *  Printing description of param:
 *  {
 *      "power-score-bg" = 97;
 *      powerHealth = 97;
 *  }
 *
 *  type == TYPower_Issue
 *  Printing description of param:
 *  {
 *      powerIssue = 5;
 *      startTimeMonitorPowerIssue = "483974204.075600";
 *  }
 *
 *  type == TYPower_Diagnose
 *  Printing description of param:
 *  {
 *      PowerDiagnoseReport = "--89--483962189.593798|||--94--483962219.609486|||--94--483962249.627026|||--94--483962279.639342|||--94--483962309.650086|||--98--483962339.661952|||--96--483962369.676082|||--94--483962399.786974|||--94--483962429.803177|||--94--483962459.815957|||--95--483962489.831195|||--94--483962519.843254|||--93--483962549.859111|||--94--483969338.245495|||--94--483969416.934227|||--98--483969446.990982|||--99--483969552.935679|||--91--483969583.003420|||--94--483969668.386822|||--94--483969698.406547|||--94--483969728.419888|||--94--483969758.433958|||--95--483969788.447658|||--96--483969818.458574|||--96--483969848.466219|||--96--483969878.473193|||--96--483969908.487737|||--96--483969938.504982|||--96--483969968.520179|||--96--483969998.532995|||--96--483970028.549798|||--96--483970058.565142|||--96--483970088.582005|||--96--483970118.597892|||--96--483970148.613709|||--96--483970178.629496|||--96--483970208.644313|||--96--483970238.660484|||--96--483970268.679666|||--96--483970298.695880|||--96--483970328.712782|||--96--483970358.731581|||--96--483970388.745637|||--96--483970418.763393|||--96--483970448.782132|||--97--483970478.797248|||--96--483970508.810361|||--95--483970538.827942|||--95--483970568.847911|||--95--483970598.863825|||--100--483970628.881201|||--100--483971060.505202|||--98--483971522.902142|||--98--483972355.018436|||--100--483972385.129334|||--100--483972415.202586|||--75--483972445.315500|||--82--483973443.898265|||--77--483973547.088432|||--84--483973577.111156|||";
 *  }
 */
- (void)onPowerReport:(TYPowerMonitorType)type param:(NSDictionary*)param;

/**
 *  内存专项记录通知。
 *  建议实现。建议将各参数按协定格式上传到后台做统计。
 *
 *  @param type  内存子项的类型
 *  @param param 具体参数
 *
 *  type == TYMemory_Health
 *  Printing description of param:
 *  {
 *      memoryHealth = "91.32708";
 *      memoryHealthDesc = "Dist:80.000000|max:400.000000|98.078125&90.113281&117.968750&118.078125&118.234375&105.839844&105.960938&";
 *      startTimeInPeriod = "483962189.584129";
 *  }
 *
 *  type == TYMemory_Leak
 *  Printing description of param:
 *  {
 *      count = 2;
 *      memVC = TYTestViewController;
 *      reason =     (
 *                    "TYTestViewController-alloc",
 *                    "TYTestViewController-alloc"
 *                    );
 *  }
 *
 *  type == TYMemory_Warn
 *  Printing description of param:
 *  {
 *      allvc = "[UIWindow: 0x14f2110e0; frame = (0 0; 320 568); gestureRecognizers = [NSArray: 0x14f212510]; layer = [UIWindowLayer: 0x14f210510]] [DFNavigationController: 0x14e0b3000]  : {    0. [ALPLauncherController: 0x14e0caa00]  +  [HPHomeWidgetGroup: 0x14f7f58f0]  +  [HCHomeCardViewController: 0x14e97ec00]  } [UITextEffectsWindow: 0x14fb07910; frame = (0 0; 320 568); opaque = NO; autoresize = W+H; layer = [UIWindowLayer: 0x14fb07fe0]] [UIInputWindowController: 0x14e99f600]";
 *      memUsed = "306.46875";
 *  }
 */
- (void)onMemoryReport:(TYMemoryMonitorType)type param:(NSDictionary*)param;

/**
 *  存储专项记录通知。
 *  建议实现。建议将各参数按协定格式上传到后台做统计。
 *
 *  @param type  存储子项的类型
 *  @param param 具体参数
 *
 *  type == TYStorage_Info
 *  Printing description of param:
 *  {
 *      SUAvailable = 814837760;
 *      coreStorageUsage = 3821989;
 *      multimediaStorageUsage = 140606;
 *      storageDetail = "Library/Caches_com.alipay.iphoneclient22:68|Document_.UTSystemConfig:265|Library_Preferences:19562|Library/Caches_com.alipay.downloads:190154|Document_com.alipay.iphoneclient22.apsharekit:612|Document_APP_CENTER_AMR:190154|Document_FALCON_DATA_UNZIP:0|Document_CommandCenter:476|Document_Chat:57496|Document_DynamicRelease:867|Document_FALCON_DATA_ZIP:0|Library/Caches_com.alipay.iphoneclient.multimedia.cache:140606|Document__LLSync_:16384|Library_crash:0|Document_Preferences:316152|Document_DP_MODELS:39204|Document_CTabBarConfig:0|Document_BioAuth:2497431|Document_CurrentVersion:115176|Library_Offline:0|Library_log:86748|Root_temp:68|Document_APAutoPage:49256|Library_Cookies:384|Library/Caches_alumonitorlog:393|Document_SGDocuments:221|Document_APP_CENTER_UNZIP:0|Library_file:163162|Document_LongLinkTempleCache:77824";
 *      storageScore = "99.855010";
 *      storageUsage = 3962663;
 *  }
 */
- (void)onStorageReport:(TYStorageMonitorType)type param:(NSDictionary*)param;

/**
 *  抓取到调用堆栈时通知。
 *  建议实现。建议将各参数按协定格式上传到后台做统计。
 *
 *  @param appId   发生时的业务ID
 *  @param type    专项类型   performance/memory/traffic/power/unknown
 *  @param subType 专项子类型 cpu_usage/unknown
 *  @param dict    具体参数
 *
 *  type == performance
 *  subType == unknown
 *  Printing description of dict:
 *  {
 *      arch = arm64;
 *      baseAddress = 0x000000010006c000;
 *      currentPage = APContactRecentViewController;
 *      lagId = "C4AD6301-FEC9-46AF-A0E4-E786B97F2D31";
 *      stackFrame = "0   libsystem_platform.dylib        0x00000001839be8f4 <redacted> + 0\n1   libsystem_malloc.dylib          0x0000000183925534 <redacted> + 148\n2   0x0000000000000000              0x000000013d036800 0x0 + 5318600704\n";
 *      threadQueueName = "com.apple.main-thread";
 *      uuid = "85B60392-E5B7-30B2-819D-C7CA4EFA2CD7";
 *  }
 */
- (void)onExceptionStackReport:(NSString*)appId exceptionType:(NSString*)type subExceptionType:(NSString*)subType attachDict:(NSDictionary*)dict;

/*
    需要额外检查的本地文件是否存在的组合，返回一个string
 */
- (NSString *)onStorageCheckResourceList;

@end



/**
 *  监控过程中的各类事件通知delegate
 *  不需要可以不实现。主要为监控过程中的一些执行点通知。
 */
@protocol TianYanEventDelegate
@optional

/**
 *  流畅度监控开始的通知。
 */
- (void)onFPSBegin;

/**
 *  流畅度监控过程中，卡顿发生时的通知。
 *
 *  @param lagSeconds 卡住时长。单位：秒。
 */
- (void)onFPSLagHappen:(double)lagSeconds;

/**
 *  流畅度监控过程中，App进入后台后又回到前台的通知。
 */
- (void)onFPSEnterFg;

/**
 *  流畅度监控结束的通知。
 */
- (void)onFPSEnd;

/**
 *  流畅度监控过程中，App进入后台，interval是前台时间
 */
- (void)onFPSEnterBgWithFgTime:(CFTimeInterval)interval;

/**
 *  标记为卡顿监控用户，卡顿监控是非全量的，为了保障计算卡顿率的准确性
 */
- (void)onLagMonitorMark;

/**
 *  子app启动时间监控开始
 */
- (void)onUnitAppLaunchMonitorBegin;

/**
 *  子app启动时间监控结束
 */
- (void)onUnitAppLaunchMonitorEnd;

/**
 *  每个周期检测完内存大小后，抛出的通知。
 */
- (void)onCheckMemoryEndPerTime;


/**
 * 检查本地存储大小的事件
 **/
- (void)onStorageCheckCompletedWithLastCleanDiskTime:(CFTimeInterval)time;

@end




