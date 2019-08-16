//
//  APMonitorPointDataDefines.h
//  AlipayPortal
//
//  Created by  tudou on 12-1-5.
//  Copyright (c) 2012年 aliPay. All rights reserved.
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
static NSString * const kValue_IgnoreCrashLogFlag = @"MonitorPoint_Ignore_Crash";

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
static NSString * const KActionID_MergeExposure = @"mergeExpose";
static NSString * const KActionID_Page_monitor = @"page_monitor";//deprecated
extern NSString * const kActionID_PageMonitor;
extern NSString * const kActionID_Count;
extern NSString * const kActionID_SemClicked;   /**SEM 点击*/
extern NSString * const kActionID_SemExposured; /**SEM 曝光*/

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
static NSString * const kWapURL = @"wapURL"/**<Deprecated*/;
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
extern NSString * const kLogEntityIdKey;/**<formatter中EntityId对应key值*/
extern NSString * const kLogPageIdKey;  /**<formatter中pageId对应的key值*/
extern NSString * const kABTestInfoKey; /**<formatter中ABTestInfo对应的key值*/
extern NSString * const kLogSequenceIdKey; /**<formatter中埋点序列号对应的key值*/
extern NSString * const kFormatterSampleRateKey; /**<formatter中抽样率对应的key值*/
extern NSString * const kFormatterLogLevelKey;/**<formatter中日志等级对应的key值*/
extern NSString * const kLogRenderBizKey;/**<formatter中日志renderBiz对应的key值*/
extern NSString * const kLogIDFAKey;/**<formatter中IDFA对应的key值*/

static const char kHotpatchPart1[] = "Hotpa";
static const char kHotpatchPart2[] = "tchVersion";
#define kHotpatchVersion ([NSString stringWithFormat:@"%s%s", kHotpatchPart1, kHotpatchPart2])

#pragma mark -
#pragma mark Performance Log Key
static NSString * const kActionControlID = @"ActionControlID";
static NSString * const kActionToken = @"ActionToken";
static NSString * const kActionDescription = @"ActionDescription"/**<deprecated*/;
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
#pragma mark Notification
extern NSString * const kCurrentControlActionIDDidChanged;/**< 点击事件通知名*/
extern NSString * const kLastClickSpmKey; /**< 从点击事件通知的userInfo中获取spm的key*/
extern NSString * const kLastClickSemKey; /**< 从点击事件通知的userInfo中获取sem的key*/

#pragma mark -
#pragma mark other keys
// android only 仅仅是为了和安卓保持日志模型一致，此字段留空
static NSString * const kCPUCoreNum = @"CPUCoreNum";
static NSString * const kCPUMaxFreq = @"CPUMaxFreq";
static NSString * const kTotalMem = @"TotalMem";
static NSString * const kAPK = @"apk";
static NSString * const kExtendedArg = @"extendedArgument";// for server @尚清
static NSString * const kThreadName = @"ThreadName";
static NSString * const kJavaOrNative = @"JavaOrNative";
static NSString * const kBootReason = @"bootReason";
extern NSString * const kProcessNameKey; //进程名, Android特有, 仅为保持对齐.
//9.6.6之后行为埋点的基础扩展字段，字典类型，后续其它日志模型也可以用这个key
static NSString * const kFoundationExtended = @"FoundationExtended";
static NSString * const kFoundationExtendedVoiceOver = @"VoiceOver";
static NSString * const kFoundationExtendedTimeZone = @"TimeZone";
static NSString * const kBundleUpdates = @"bundleUpdates";

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

//#define logsFile @"LOGS.plist"

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

#pragma mark - AntLog
static const char kIAMPart1[] = "ia";
#define kIAM ([NSString stringWithFormat:@"%sm", kIAMPart1])
extern NSString * const kReferSpmKey;   /**<扩展4中referSpm对应的key值*/
extern NSString * const kLogTraceIdKey; /**<扩展4中traceId对应的key值, 10.1.0新增*/

extern NSString * const kBizTypeKey;         /**<8.3之前老接口传入bizType时使用的key*/
extern NSString * const kBizTypePerformance; /**<性能埋点默认bizType*/
extern NSString * const kBizTypeBehavior;    /**<行为埋点默认bizType*/
extern NSString * const kBizTypeAutoTrack;   /**<自动化埋点默认bizType*/
extern NSString * const kBizTypeCrash;       /**<crash埋点默认bizType*/
extern NSString * const kBizTypeNetMonitor;  /**<流量监控埋点默认bizType*/
extern NSString * const kBizTypeMonitor;     /**<性能管理埋点默认bizType*/

extern NSString * const kH5PageURLKey;  /**<自动化埋点context.param中H5页面的URL对应的key值*/

#pragma mark - Upload Events
extern NSString * const kLogUploadEventForce;//强制上报
extern NSString * const kLogUploadEventDefault;//缺省值
extern NSString * const kLogUploadEventEnterBg;//压后台
extern NSString * const kLogUploadEventBgLaunch;//后台唤起, iOS特有
extern NSString * const kLogUploadEventCrash;//crash
extern NSString * const kLogUploadEventMaxLogCount;//达到日志上报阈值条数
extern NSString * const kLogUploadEventHistoryCheck;//检查历史文件,iOS特有
extern NSString * const kLogUploadEventBoot;//启动上报
extern NSString * const kLogUploadEventFloodDischarge;//泄洪上报
extern NSString * const kLogUploadEventPeriodUpload;//满足时间条件上报
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

static NSString * const kExternalSwitchValueChange = @"kExternalSwitchValueChange";

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

extern NSString * const kBizTypeAlipaySDK;      /**<收银台监控日志bizType*/
extern NSString * const kAbtestconfigKey;       /**abtestconfig key值*/

#endif // AP_REMOTE_LOGGING_DEFINE
