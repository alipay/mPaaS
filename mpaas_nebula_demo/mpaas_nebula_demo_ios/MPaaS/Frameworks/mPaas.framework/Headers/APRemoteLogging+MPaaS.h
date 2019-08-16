//
//  APRemoteLogging+MPaaS.h
//  APRemoteLogging
//
//  Created by shenmo on 5/5/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#ifndef AP_REMOTE_LOGGING_DEFINE
#define AP_REMOTE_LOGGING_DEFINE
/*
 AP_REMOTE_LOGGING_DEFINE 包含的代码在下列两个文件是一致的。
 - APMonitorPointDataDefines.h
 - APRemoteLogging+MPaaS.h
 */

/**
 *  埋点预定义的可用actionID，只可以用预设的，否则服务器不识别
 */
static NSString * const kValue_CrashLogFlag = @"MonitorPoint_Crash";


static NSString * const kActionID_Manual_perf = @"monitorPerf"; //性能监控标志
static NSString * const kActionID_Clicked = @"clicked";
static NSString * const kActionID_LongClicked = @"longClicked";
static NSString * const kActionID_Submtted = @"submited";
static NSString * const kActionID_BizLaunched = @"bizLaunched";
static NSString * const kActionID_SetGesture = @"setGesture";
static NSString * const kActionID_CheckGesture = @"checkGesture";
static NSString * const kActionID_NetBroken = @"netBroken";
static NSString * const kActionID_Monitor = @"monitor";
static NSString * const KActionID_Slided = @"slided";
static NSString * const KActionID_None = @"none";
static NSString * const kActionID_OPENPAGE = @"openPage";
static NSString * const KActionID_AutoClicked = @"auto_clicked";
static NSString * const KActionID_AutoClick = @"auto_click";
static NSString * const KActionID_AutoOpenPage = @"auto_openPage";
static NSString * const KActionID_AutoEvent = @"auto_event";
static NSString * const KActionID_Event = @"event";
static NSString * const KActionID_FingerIdenty = @"fingerIdenty";
static NSString * const KActionID_MonitorReport = @"MonitorReport";
static NSString * const KActionID_Exposure = @"exposure";
static NSString * const KActionID_Page_monitor = @"page_monitor";


static NSString * const kActionID_Exception = @"exception";
static NSString * const KActionID_Error = @"error";
static NSString * const kActionID_FlashBroken = @"flashBroken";



//性能埋点的actionID
static NSString * const KActionID_PerformanceNetwork = @"network";
static NSString * const KActionID_PerformanceMobSDK = @"mobsdk";
static NSString * const KActionID_PerformanceWebApp = @"webapp";
static NSString * const KActionID_PerformancePackage = @"package";
static NSString * const KActionID_PerformancePage = @"page";
static NSString * const KActionID_PerformanceInterface = @"interface";
static NSString * const KActionID_PerformanceMemory = @"memory";
static NSString * const KActionID_PerformanceSdkMonitor = @"sdkmonitor";

#pragma mark -
#pragma mark 埋点id
#pragma mark -

static NSString * const kRecordTime = @"timestamp";
static NSString * const kPlatformID = @"platformID"; //客户端ID
static NSString * const kClientVersion = @"clientVersion";//客户端版本
static NSString * const kInternalVersion = @"InternalVersion";//内部版本
static NSString * const kLogModleVersion = @"logModelVersion";//日志版本
static NSString * const kClientId = @"clientId"; //设备ID
static NSString * const kUUID = @"UUID";     //会话ID
static NSString * const kUserID = @"userID";
static NSString * const kActionID = @"actionID";//行为id (clicked,submited,bizLaunched)
static NSString * const kActionStatus = @"actionStatus";
static NSString * const kStatusMsg = @"statusMsg";
static NSString * const kBizID = @"bizID";
static NSString * const kBizVersion = @"bizVersion";
static NSString * const kCurrentViewID = @"currentViewID";
static NSString * const kLastViewID = @"lastViewID";
static NSString * const kActionSeed = @"logID"; //埋点ID
static NSString * const kWapURL = @"wapURL";
static NSString * const kActionOwnerType = @"actionType";
static NSString * const kLogOwnerType = @"logType";
static NSString * const kExArg1 = @"stayDuration";
static NSString * const kExArg2 = @"arg2";
static NSString * const kExArg3 = @"renderConsume";
static NSString * const kExArg4 = @"arg4";
static NSString * const kExArg5 = @"sourceID";
static NSString * const kRequestid = @"unitID"; //流水号
static NSString * const UTDID = @"utdID"; //cookie
static NSString * const ucID = @"ucID";
static NSString * const kIndex = @"index";
static NSString * const kLogLastViewID = @"logLastViewID";
static NSString * const kLogCurrentViewID = @"logCurrentViewID";
static NSString * const kExceptionType = @"ExceptionType";
static NSString * const kAppStack = @"AppStack";
static NSString * const kVcStack = @"VcStack";
static NSString * const kAppPackageType = @"AppPackageType";
static NSString * const kAttachment = @"Attachment"; //附加信息
static NSString * const kHeader = @"header";
static NSString * const kExtension = @"extension";
static NSString * const kResolution = @"resolution";
static NSString * const kSessionid = @"session_id";

static const char kHotpatchPart1[] = "Hotpa";
static const char kHotpatchPart2[] = "tchVersion";
#define kHotpatchVersion ([NSString stringWithFormat:@"%s%s", kHotpatchPart1, kHotpatchPart2])
//static NSString * const kHotpatchVersion = @"HotpatchVersion";

#pragma mark -
#pragma mark Performance Log Key

static NSString * const kActionControlID = @"ActionControlID";
static NSString * const kActionToken = @"ActionToken";
static NSString * const kActionDescription = @"ActionDescription";
static NSString * const kMonitorType = @"MonitorType";
static NSString * const kMonitorSubType = @"MonitorSubType";
static NSString * const kSystemType = @"SystemType";
static NSString * const kSystemVersion = @"SystemVersion";
static NSString * const kNetworkType = @"NetworkType";
static NSString * const kDeviceModel = @"kDeviceModel";
static NSString * const kInnerVersion = @"InnerVersion";
static NSString * const kDistributionChannel = @"DistributionChannel";
static NSString * const kLanguage = @"Language";

#pragma mark -
#pragma mark other keys
// android only 仅仅是为了和安卓保持日志模型一致，此字段留空
static NSString * const kCPUCoreNum = @"CPUCoreNum";
static NSString * const kCPUMaxFreq = @"CPUMaxFreq";
static NSString * const kTotalMem = @"TotalMem";
static NSString * const kAPK = @"apk";
static NSString * const kExtendedArg = @"extendedArgument";// for server @尚清
//9.6.6之后行为埋点的基础扩展字段，字典类型，后续其它日志模型也可以用这个key
static NSString * const kFoundationExtended = @"FoundationExtended";
static NSString * const kFoundationExtendedVoiceOver = @"VoiceOver";

#pragma mark -
#pragma mark Diagnose Log Key
static NSString * const kChannelID = @"ChannelID";
static NSString * const kDiagnoseType = @"DiagnoseType";
static NSString * const kDiagnoseMessage = @"DiagnoseMessage";




static NSString * const kMonitorPoint_bizLaunched = @"MonitorPoint_bizLaunched";
static NSString * const kMonitorPoint_viewJump = @"MonitorPoint_viewJump";
static NSString * const kMonitorPoint_viewReturn = @"MonitorPoint_viewReturn";
static NSString * const kMonitorPoint_ConnectErr = @"MonitorPoint_ConnectErr";
static NSString * const kMonitorPoint_ClientsErr = @"MonitorPoint_ClientsErr";
static NSString * const kMonitorPoint_BizResult = @"MonitorPoint_BizResult";
static NSString * const kMonitorPoint_ButtonClicked = @"MonitorPoint_ButtonClicked";
static NSString * const kMonitorPoint_CheckUpdate = @"MonitorPoint_CheckUpdate";
static NSString * const kMonitorPoint_ShareInfo = @"MonitorPoint_ShareInfo";
static NSString * const kMonitorPoint_Exception = @"MonitorPoint_Exception";
static NSString * const kMonitorPoint_Event = @"MonitorPoint_Event";

#define logsFile @"LOGS.plist"

#pragma  mark -
#pragma  mark viewID
#pragma  mark -
static NSString * const kHomeView = @"homeView";
static NSString * const kAccountManagerHomeView = @"accountManagerHomeView";
static NSString * const kLoginView = @"loginView";
static NSString * const kRegisterView = @"registerView";
static NSString * const kGetRegisterSmsView = @"getRegisterSmsView";
static NSString * const kWaterInputView = @"waterInputView";
static NSString * const kWaterHistoryView = @"waterHistoryView";
static NSString * const kWaterSelectListView = @"waterSelectListView";
static NSString * const kWaterSubmitView = @"waterSubmitView";
static NSString * const kElectricityInputView = @"electricityInputView";
static NSString * const kElectricitySelectListView = @"electricitySelectListView";
static NSString * const kElectricityHistoryView = @"electricityHistoryView";
static NSString * const kElectricitySubmitView = @"electricitySubmitView";
static NSString * const kGasInputView = @"gasInputView";
static NSString * const kGasSelectListView = @"gasSelectListView";
static NSString * const kGasHistoryView = @"gasHistoryView";
static NSString * const kGasSubmitView = @"gasSubmitView";
static NSString * const kTelephoneInputView = @"widelineInputView";
static NSString * const kTelephoneSelectListView = @"widelineSelectListView";
static NSString * const kTelephoneHistoryView = @"widelineHistoryView";
static NSString * const kTelephoneSubmitView = @"widelineSubmitView";
static NSString * const kTradeRecordsView = @"tradeRecordsView";
static NSString * const KTradeRecordsAllView = @"tradeRecordsAllView";
static NSString * const kTradeRecordsWaitPayView = @"tradeRecordsWaitPayView";
static NSString * const KTradeRecordsWaitReceiveView = @"tradeRecordsWaitReceiveView";
static NSString * const kTradeDetailsView = @"tradeDetailsView";
static NSString * const kTradeTransportView = @"tradeTransportView";
static NSString * const kWithdrawView = @"withdrawView";
static NSString * const kHelpView = @"helpView";
static NSString * const kProtocolView = @"protocolView";
static NSString * const kSubstitutePayHomeView = @"substitutePayHomeView";
static NSString * const kOnePersonsubstitutePayView = @"onePersonsubstitutePayView";
static NSString * const kAnyBodysubstitutePayCreateUrlView = @"anyBodysubstitutePayCreateUrlView";
static NSString * const kAnyBodysubstitutePaySelectTypeView = @"anyBodysubstitutePaySelectTypeView";
static NSString * const kSubstitutePayShare_SMSView = @"substitutePayShare_SMSView";
static NSString * const kSubstitutePayShare_EmailView = @"substitutePayShare_emailView";
static NSString * const kBarcodeView =  @"barcodeView";
static NSString * const kCashRegisterView = @"cashRegisterView";
static NSString * const kScanBarCodeView = @"scanBarCodeView";
static NSString * const kSettingPasswordView = @"settingPassWordView";
static NSString * const kFeedbackView = @"feedbackView";
static NSString * const kNoPassWordView = @"noPassWordView";
static NSString * const kKaBaoTicketDetailView = @"kaBaoTicketDetailView";
static NSString * const kKaBaoMyTicketListView = @"kaBaoMyTicketListView";
static NSString * const kKaBaoTicketStoreView = @"kaBaoTicketStoreView";
#pragma  mark -
#pragma  mark 各种记录点需要的key
#pragma  mark -

static NSString * const kValue_pointType = @"pointType";
static NSString * const kValue_currentViewId = @"currentViewId";
static NSString * const kValue_gotoViewId = @"gotoViewId";
static NSString * const kValue_bizId = @"bizId";
static NSString * const kValue_isLogin = @"isLogin";
static NSString * const kValue_CurrentTime = @"time";
static NSString * const kValue_Errmemo = @"errMemo";
static NSString * const kValue_OperationType = @"operationType";
static NSString * const kValue_BizVersion = @"bizBundleVersion";
static NSString * const kvalue_BizResult = @"bizResult";
static NSString * const kvalue_ShareType = @"shareType";
static NSString * const kvalue_ButtonId = @"buttonId";
static NSString * const kvalue_Exception = @"exception";
static NSString * const kvalue_Index = @"index";
static NSString * const kvalue_UserId = @"userId";
static NSString * const kvalue_EventType = @"eventType";
static NSString * const kvalue_eventResult = @"eventResult";
static NSString * const kvalue_isHaveCoupon = @"isHaveCoupon";


static NSString * const kSharedType_Email = @"sharedType_Email";
static NSString * const KSharedType_SMS = @"sharedType_SMS";
static NSString * const kSharedType_Weibo = @"sharedType_Weibo";
static NSString * const kSharedType_URL = @"sharedType_URL";

static NSString * const kEventType_PaipaiScanResoult = @"eventType_PaipaiScanResoult";
static NSString * const kEventType_gotoNewTransferPage = @"eventType_gotoNewTransferPage";
static NSString * const kEventType_confirmTransferAccontButtonClick = @"eventType_confirmTransferAccontButtonClick";
static NSString * const kEventType_confirmTransferInfo_MobileNo = @"eventType_confirmTransferInfo_mobileNo";
static NSString * const kEventType_confirmTransferInfo_AlipayAccount = @"eventType_confirmTransferInfo_alipayAccount";
static NSString * const kEventType_transferCall = @"eventType_transferCall";
static NSString * const kEventType_historyContactButtonClick =@"eventType_historyContactButtonClick";
static NSString * const kEventType_localContactButtonClick = @"eventType_localContactButtonClick";
static NSString * const kEventType_superTransferReadyShake = @"eventType_superTransferReadyShake";
static NSString * const kEventType_ShakeSuccessUsedTime = @"eventType_ShakeSuccessUsedTime";
static NSString * const kEventType_KB_TicketZoneClicked = @"eventType_KB_TicketZoneClicked";
static NSString * const kEventType_KB_BillZoneClicked = @"eventType_KB_BillZoneClicked";
static NSString * const kEventType_KB_MyTicketClicked = @"eventType_KB_MyTicketClicked";
static NSString * const kEventType_KB_GestureSetting_success = @"eventType_KB_ GestureSetting_success";
static NSString * const kEventType_KB_TicketDetailSoundButtonClicked = @"eventType_KB_TicketDetailSoundButtonClicked";
static NSString * const kEventType_KB_TicketDetailReadDetailButtonClicked = @"eventType_KB_TicketDetailReadDetailButtonClicked";
static NSString * const kEventType_SendSmsButtonClickInCreditCardView = @"eventType_SendSmsButtonClickInCreditCardView";
static NSString * const kEventType_CallButtonClickInCreditCardView = @"eventType_CallButtonClickInCreditCardView";


#pragma mark -
#pragma mark other keys
//日志级别
static NSString * const kLoggerLevel = @"loggerLevel";
//关键业务日志级别
static NSString * const LoggerLevelHigh  = @"loggerLevelHigh";
//普通业务日志级别
static NSString * const LoggerLevelMedium  = @"loggerLevelMedium";
//诊断业务日志级别
static NSString * const LoggerLevelLow  = @"loggerLevelLow";

static NSString * const RemoteLoggingDisableAutoTrack = @"remoteLoggingDisableAutoTrack";


typedef NS_ENUM(int, PerformanceLogType){
    PerformanceLogTypeNone = 0,
    PerformanceLogTypeNetwork,
    PerformanceLogTypeMobSdk,
    PerformanceLogTypeWebApp,
    PerformanceLogTypePackage,
    PerformanceLogTypePage,
    PerformanceLogTypeInterface,
    PerformanceLogTypeMemory,
    PerformanceLogTypeSdkMonitor,
    PerformanceLogTypeDiagnose,
    PerformanceLogTypeSYNC_LINK,
    PerformanceLogTypeSYNC_PROTO,
    PerformanceLogCommon,
    PerformanceLogHomePage,
    PerformanceLogH5Diagnose,
    PerformanceLogH5Exception,
    PerformanceLogTypeCount
};

typedef NS_ENUM(int, APLogType){
    APLogTypeNone = 0,
    APLogTypeNetwork,
    APLogTypeMobSdk,
    APLogTypeWebApp,
    APLogTypePackage,
    APLogTypePage,
    APLogTypeInterface,
    APLogTypeMemory,
    APLogTypeSdkMonitor,
    APLogTypeDiagnose,
    APLogTypeSYNC_LINK,
    APLogTypeSYNC_PROTO,
    APLogTypePerformance,
    APLogTypeHomePage,
    APLogTypeH5Diagnose,
    APLogTypeH5Exception,
    APLogTypeBehavior,
    APLogTypeCrash,
    APLogTypeAuto,
    APLogTypeFootprint,
    APLogTypeMonitor,
    APLogTypeKeyBizTrace,
    APLogTypeNetMonitor,
    APLogTypeCount
};

typedef NS_ENUM(NSInteger, APRemoteLoggerPageInfomationType) {
    APRemoteLoggerPageInfomationMiniType
};

#endif // AP_REMOTE_LOGGING_DEFINE

@protocol APRemoteLoggerClass <NSObject>

/**
 *  新的行为埋点接口。8.3之前的老的打点不要修改成调用此接口。8.3以后（含）新开的页面调用此接口。
 客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     子应用ID（业务的bizID） 必填
 *  @param seed      埋点ID（后端定义的，找@君边@望乡生成）
 *  @param ucId      用例编号（后端定义的，找@君边@望乡生成） 必填
 *                   warning：埋点ID和用例编号请自己生成前缀，之后找@温皇来确认，上述两位已经不负责这部分了
 */
+(void)writeLogWithActionId:(NSString *)actionId
                  extParams:(NSArray *)extParams
                      appId:(NSString *)appId
                       seed:(NSString *)seed
                       ucId:(NSString *)ucId;


/**
 *  新的行为埋点接口。8.3之前的老的打点不要修改成调用此接口。8.3以后（含）新开的页面调用此接口。
 客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     子应用ID（业务的bizID） 必填
 *  @param seed      埋点ID（后端定义的，找@君边@望乡生成）
 *  @param ucId      用例编号（后端定义的，找@君边@望乡生成） 必填
 *                   warning：埋点ID和用例编号请自己生成前缀，之后找@温皇来确认，上述两位已经不负责这部分了
 *  @param bizType   业务类型
 */

+(void)writeLogWithActionId:(NSString *)actionId
                  extParams:(NSArray *)extParams
                      appId:(NSString *)appId
                       seed:(NSString *)seed
                       ucId:(NSString *)ucId
                    bizType:(NSString *)bizType;



/**
 *  新的行为埋点接口。8.3之前的老的打点不要修改成调用此接口。8.3以后（含）新开的页面调用此接口。
 客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param actionId  action ID 必填，标识一个埋点的类别，可用actionID定义在APMonitorPointDataDefines.h
 文件中
 *  @param extParams 扩展参数，业务自己根据需要填充。数组元素最多4个，第四个元素可以是字典，
 字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param appId     子应用ID（业务的bizID） 必填
 *  @param seed      埋点ID（后端定义的，找@君边@望乡生成）
 *  @param ucId      用例编号（后端定义的，找@君边@望乡生成） 必填
 *                   warning：埋点ID和用例编号请自己生成前缀，之后找@温皇来确认，上述两位已经不负责这部分了
 *  @param bizType   业务类型
 *  @param formatterDictionary  业务可以根据需求自定义formatter字典值，pageid可以通过此字典参数设置
 */

+ (void)writeLogWithActionId:(NSString *)actionId
                   extParams:(NSArray *)extParams
                       appId:(NSString *)appId
                        seed:(NSString *)seed
                        ucId:(NSString *)ucId
                     bizType:(NSString *)bizType
         formatterDictionary:(NSDictionary *)formatterDictionary;


/**
 *   注意：新的埋点不要调用此接口，为保持兼容以前的代码所以保留
 *              8.3之前的老的页面继续使用此接口，8.3新开的页面使用writeLogWithActionId:..这个接口
 *
 *  @param dict log 字典
 */
+(void)writeLogWithLogDictionary:(NSDictionary *) dict /*__deprecated*/;

/**
 *  性能埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型
 *  @param subType 子类型，业务可以自己定义
 *  @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 */
+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(NSString *)subType
                        extraParams:(NSArray *)extraParams;




/**
 *  性能埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型
 *  @param subType 子类型，业务可以自己定义
 *  @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义，字典会被转换成key-value的字符串计入日志
 *  @param formatterDictionary 业务可以根据需求自定义formatter字典值，格式头可以通过此字典参数设置
 *  @param perUploadNum达到number条日志时，触发一次日志上传，当number＝＝1时，实时上传日志。0表示忽略此参数.
 */
+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(NSString *)subType
                        extraParams:(NSArray *)extraParams
                formatterDictionary:(NSDictionary *)formatterDictionary
                       perUploadNum:(NSUInteger)number;



/**
 *  埋点接口，客户端版本、用户ID、设备ID、操作系统版本、网络类型、设备类型、软件版本会自动填充，不需要业务埋点。
 *
 *  @param tpye 类型,每种类型对应一个日志文件
 *  @param subType 子类型，业务可以自己定义，用于过滤筛选用
 ＊ @param extraParams 扩展字段，共四个item，第四个item是字典，字典内容可自定义， 字典会被转换成key-value的字符串计入日志
 *  @param perUploadNum 达到num条日志时，触发一次日志上传，当num＝＝1时，实时上传日志。0表示忽略此参数.
 */

+ (void)writeWithType:(APLogType)type subType:(NSString *) subType
           paramArray:(NSArray *) extraParams perUploadNum:(NSUInteger) num;



/**
 *  界面点击的ActionToken(TraceID)
 *
 *  @return 最近界面点击的ActionToken(TraceID)
 */
+(NSString *) currentActionToken;

/**
 *  界面点击的ActionToken的生成时间戳，为精简RPC包大小而提供
 *
 *  @return 最近界面点击的ActionToken的生成时间戳
 */
+(unsigned long long) tokenTimestamp;

/**
 *  界面点击的最近一个控件标识
 *
 *  @return 最近界面点击的最近一个控件标识
 */
+(NSString *) currentActionControlID;

/**
 *  当前页面的ID
 *
 *  @return 当前页面的ID
 */
+(NSString *) currentPageID;

+(NSString *) lastPageID;

+(NSString *) currentSubAppID;

+(void) resetCurrentPageId:(NSString *)pageId;


/**
 *  页面数据准备好到达可用状态，由业务主动调用
 *
 *  @return void
 */
+ (void)pageDidFinishInitializing;



/**
 *  字符串数组格式化转成str1|str2|str3格式字符串
 *
 *  @param array 字符串数组
 *
 *  @return 格式化后字符串
 */
+ (NSString *)convertToStringFromArray:(NSArray *)array;

/**
 *  设置扩展参数，支持扩展参数的日志模型（行为，性能）
 *  字典转成 key=value^key=value^key=value 格式字符串
 *
 *  @return void
 */
+ (void)setFoundationExtended:(NSDictionary *)dict;

/**
 *  字典格式化 转成 key:value&key:value&key:value 格式字符串
 *
 *  @param dictionary 字典
 *  @param kvSeparator 可以为空，默认使用:连接，字典key和value的连接字符（比如key:value）
 *  @param componentsSeparator 可以为空，默认使用&连接，每队key，value组合后的连接字符（比如key:value&key:value）
 *  @return 格式化后的字符串
 *
 */
+ (NSString *)convertToStringFromDictionary:(NSDictionary *)dictionary
                                kvSeparator:(NSString *)separator1
                        componentsSeparator:(NSString *)separator2;



/**
 *  页面打开
 *  @param spmId 代表当前页面的spm
 *  @param index  pageid索引
 *  @return void
 *
 */
+ (void)logPageStartWithSpmId:(NSString *)spmId index:(NSObject *)index;



/**
 *  页面结束，会生成openpage埋点
 *  @param spmId 代表当前页面的spm
 *  @param index  pageid索引
 *  @param param 手动埋点扩展参数4
 *  @return void
 */
+ (void)logPageEndWithSpmId:(NSString *)spmId index:(NSObject *)index bizType:(NSString *)bizType param:(NSDictionary *)param;



/**
 *  取索引的pageid
 *  @param index  pageid索引
 *  @return 页面流水号
 */
+ (NSString *)pageIdForIndex:(NSObject *)index;




/**
 *  取索引的pageid的时间戳
 *  @param index  pageid索引
 *  @return 页面流水号的时间戳
 */
+ (NSString *)pageIdTimestampForIndex:(NSObject *)index;




/**
 *  取索引的spmid
 *  @param index  pageid索引
 *  @return 页面spmid
 */
+ (NSString *)spmIdForIndex:(NSObject *)index;





/**
 *  取索引的信息
 *  @param index  pageid索引
 *  @param type  pageInfo类型
 *  @return 页面信息
 */
+ (NSString *)pageInfomationForIndex:(NSObject *)index forType:(APRemoteLoggerPageInfomationType)type;



/**
 *  清除所有无效的历史流水号
 */
+ (void)resetPageMonitorContext;



#pragma mark -
#pragma mark 以下函数业务不要调用

+(void)writeCrashLog:(NSString *) report vcStack:(NSString *) vcStack;
+(NSDictionary*)stateWhenCrashed:(NSString*)vcStack;
+(void)writeCrashLog:(NSString *) report state:(NSDictionary*)state;

+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(NSString *) subType
                        extraParams:(NSArray *) extraParams
                    actionControlID:(NSString *) controlID
                         actionToke:(NSString *) actionToken;

+(void) writeDiagnoseLog:(NSString *) logString;
+(void)upload;

+(void) logAutoEventWithBizType:(NSString*)bizType params:(NSArray*)params;
+(void) logPageBeginRenderWithPageName:(NSString *) name;
+(void) logPageStartWithPageId:(NSString *) pageId appId:(NSString *) appId
                   sourceAppId:(NSString *) sourceAppId pageName:(NSString *) pageName;

+ (void)logPageMonitorWithMonitorType:(NSString *)monitorType;

+ (void)logPageEndRenderWithPageName:(NSString *)name;

+(BOOL) statusForWriteLogSwitch:(NSString*) logType;
+(BOOL) statusForSendLogSwitch:(NSString*) logType;

+(void) checkCrashLogWithCompletionBlock:(void (^)(void)) block;

// 添加OC版本的接口，为了利用OC的动态特性实现模块间解耦合
+ (void)SLWriteMonitorLog:(NSDictionary*)attachDict appID:(NSString*)appID monitorType:(NSString*)monitorType subMonitorType:(NSString*)subMonitorType;
+ (void)APWriteNetLog:(NSString*)identifier size:(NSString*)size type:(NSString*)type owner:(NSString*)owner extDict:(NSDictionary*)extDict;

/**
 *   暂停日志上传，最大暂停时间为60s，时间过后自动打开日志上传
 *   设置这个机制的原因是防止调用方异常，没有调用resumeLogUploading等情况下，导致日志无法上传。
 *
 *  @param secondes 自定义的日志暂停上传时间，最大值为60s，最小值为1s，其余值将导致默认暂停10s
 */
+(void) suspendLogUploadingForSeconds:(int) seconds;

/**
 *   立即恢复日志上传功能
 */
+(void) resumeLogUploading;

@end
