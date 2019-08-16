// 验签失败通知
#define kAPPVerifyFailed                        @"kAPPVerifyFailed"

// 公共资源包appId
#define kH5OfflineResAppId @"20000196"

// 运营资源包
#define kH5BOOfflineResAppId @"20000202"

// 小程序公共资源包
#define kH5TinyPubResAppId @"66666692"

// Cube公共资源包
#define kH5CubePubResAppId @"68687209"

// 对齐透传UIWebViewNavigationType/WKNavigationType。0-4,UIWeView与WKWebView定义相同。区别点：UIWebView用5表示other，WKWebView用-1表示other，使用other判断时建议合并other1和other2
typedef NS_ENUM(NSInteger, H5WebViewNavigationType) {
    H5WebViewViewNavigationTypeLinkClicked,
    H5WebViewNavigationTypeFormSubmitted,
    H5WebViewNavigationTypeBackForward,
    H5WebViewNavigationTypeReload,
    H5WebViewNavigationTypeFormResubmitted,
    H5WebViewNavigationTypeOther1,
    H5WebViewNavigationTypeOther2 = -1,
} API_UNAVAILABLE(tvos);


typedef enum
{
    H5ServiceCallEnumCall,
    H5ServiceCallEnumCallback,
    H5ServiceCallEnumMax
} H5ServiceCallEnum;

typedef enum
{
    H5ServiceEventEnumViewDidLoad,
    H5ServiceEventEnumViewWillAppear,
    H5ServiceEventEnumViewDidAppear,
    H5ServiceEventEnumViewWillDisappear,
    H5ServiceEventEnumViewDidDisappear,
    H5ServiceEventEnumViewBack,
    H5ServiceEventEnumMax
} H5ServiceEventEnum;

typedef enum
{
    H5ServiceSeedingEnumPayServiceStart,
    H5ServiceSeedingEnumPayServiceFinish,
    H5ServiceSeedingEnumMax
} H5ServiceSeedingEnum;

typedef enum
{
    H5ServicePropertyEnumFontChange,
    H5ServicePropertyEnumMax
} H5ServicePropertyEnum;

typedef enum
{
    H5Mode_Normal = 0,
    H5Mode_SubView,
} H5Mode;

typedef void (^loadUrlBlock)(NSString *result, NSDictionary *launchParams);

@protocol H5WebViewInterface;
@protocol H5ServiceDelegate;
@class H5WebViewController;
@class NAMApp;
@class WKWebView;
@interface H5Service : NSObject <DTService>
/**
 *  创建H5WebViewController实例
 *
 *  @param params   session和webview启动参数
 *  @param JSApis   JSAPI接口字典
 *  @param delegate 代理
 *
 *  @return H5WebViewController实例
 */
- (H5WebViewController *)createWebViewController:(NSDictionary *)params JSApis:(NSDictionary *)JSApis withDelegate:(id<H5ServiceDelegate>)delegate;
/**
 *  创建H5WebViewController实例
 *
 *  @param params   session和webview启动参数
 *  @param JSApis   JSAPI接口字典
 *  @param delegate 代理
 *
 *  @return H5WebViewController实例
 */
+ (H5WebViewController *)createWebViewController:(NSDictionary *)params JSApis:(NSDictionary *)JSApis withDelegate:(id<H5ServiceDelegate>)delegate;

/**
 *  创建H5WebView实例，用于插入到其他view中
 *  !! 请勿在从supperview中remove以后继续使用
 *  @param params   session和webview启动参数
 *  @param JSApis   JSAPI接口字典
 */
- (UIView<H5WebViewInterface> *)createWebViewWithParams:(NSDictionary *)params JSApis:(NSDictionary *)JSApis DEPRECATED_ATTRIBUTE; // 废弃方法，请使用下面方法


- (UIView<H5WebViewInterface> *)createWebViewWithVC:(UIViewController *)currentVC params:(NSDictionary *)params JSApis:(NSDictionary *)JSApis;


/**
 *  创建H5WebView实例，用于插入到其他view中
 *  !! 请勿在从supperview中remove以后继续使用
 *  @param params   session和webview启动参数
 *  @param JSApis   JSAPI接口字典
 */
+ (UIView<H5WebViewInterface> *)createWebViewWithParams:(NSDictionary *)params JSApis:(NSDictionary *)JSApis DEPRECATED_ATTRIBUTE;

+ (UIView<H5WebViewInterface> *)createWebViewWithVC:(UIViewController *)currentVC params:(NSDictionary *)params JSApis:(NSDictionary *)JSApis;

/**
 * 判断当前打开的url是否是启动h5
 * !!目前只针对 通用容器20000067 和 服务窗20000095
 * @param url 当前要判断的url（alipays://或者alipaysrc://）
 */
+ (BOOL)isH5ApplicationURL:(NSURL *)url;

/**
 * 为H5Service注册一个API
 *
 *  @param appId  业务包appId
 *  @param JSApi  API接口字典
 *
 */
- (void)registerApi:(NSString *)appId Apis:(NSDictionary *)Apis;
/**
 * 为H5Service反注册一个API
 *
 *  @param appId  业务包appId
 *  @param Api  API名字
 *
 */
- (void)unregisterApi:(NSString *)appId Api:(NSString *)ApiName;

/**
 * 为H5Service注册一个API，H5页面感知
 *
 *  @param JSApis  API接口字典，{@"jsApiName": PSDJsApiHandlerBlock}
 *
 */
- (void)registerApis:(NSDictionary *)Apis;
/**
 * 为H5Service反注册一个API，H5页面感知
 *
 *  @param Api  API名字
 *
 */
- (void)unregisterApiName:(NSString *)ApiName;

/**
 * 移除appId关联的所有Api
 *
 *  @param appId  业务包appId
 *
 */
- (void)unregisterApi:(NSString *)appId;
/**
 * 通过appId得到相关的JsApi
 *
 *  @param appId  业务包appId
 *
 */
- (NSDictionary *)getApis:(NSString *)appId;

/**
 * 通过H5Service写入共享数据
 * @param shareData  待设置的数据
 * @param writeToFile  是否保存为文件
 */
- (void)setSharedData:(NSString *)value forkey:(NSString *)key writeToFile:(BOOL)writeToFile;

/**
 * 通过H5Service读取共享数据
 * @param key   读取的 key
 */
- (NSString *)sharedDataForKey:(NSString *)key;

/**
 * 通过H5Service 删除共享数据
 * @param key  删除的 key
 */
- (void)removeSharedDataForKey:(NSString *)key;

/**
 * 获取输入框提示白名单
 * @param publicId 服务窗ID
 */
//- (NSArray *)inputBoxWhitelistForPublicId:(NSString *)publicId;

/**
 * 获取公众号对应的白名单
 * @param publicId 服务窗ID
 */
//- (NSArray *)jsApiListForPublicId:(NSString *)publicId;

/**
 * 得到最终某个启动参数的值
 * @param app 当前app
 * @param params 当前传入的启动参数
 * @param key 启动参数的key
 */
- (NSString *)getAppLaunchValWithApp:(NAMApp *)app  params:(NSDictionary *)params key:(NSString *)key;

@end

@protocol H5ServiceDelegate <NSObject>

@optional

/**
 *	外部业务层可能需要处理的消息 9.6.9开始废除
 *
 *	@param 	context 	（输入）上下文，一般是当前的H5ServiceWebController
 *  return : YES        业务层认为可以重置titlebarStyle
 *           NO         业务层认为不可用重置titlebarStyle
 */
-(BOOL)shouldResetNavigationBarDefaultStyle:(H5WebViewController *)context;

/**
 *	外部业务层可能需要处理的消息 9.6.9开始废除
 *
 *	@param 	context 	（输入）上下文，一般是当前的H5ServiceWebController
 *  return : UIColor        业务层返回的titlebar背景色

 */
-(UIColor *)shouldSetNavigationBarColor:(H5WebViewController *)context;

/**
 *	外部业务层可能需要处理的消息
 *
 *	@param 	context 	（输入）上下文，一般是当前的H5ServiceWebController
 *	@param 	event       （输入）消息枚举，参见H5ServiceEventEnum定义
 *  return : YES        业务层处理了本消息，那么H5Service就不会处理
 *           NO         业务层不需要处理的消息，那么H5Service就会处理
 */
- (BOOL)serviceEventDidComeWithController:(H5WebViewController *)context event:(H5ServiceEventEnum)event;

/**
 *	外部业务层可能需要处理的埋点消息
 *
 *	@param 	context 	（输入）上下文，一般是当前的H5ServiceWebController
 *	@param 	event       （输入）消息枚举，参见H5ServiceSeedingEnum定义
 *	@param 	paramDict   （输入）参数信息，定义参考http://ux.alipay-inc.com/index.php/H5%E5%AE%B9%E5%99%A8#X1._.E5.9F.8B.E7.82.B9.E6.94.AF.E6.8C.81－－X1. 埋点支持
 *          备注：paramDict[@“interceptedUrl”]为NSString对象数据
 *               paramDict[@"result"]为SPOrder/MQPResult对象数据
 *  return : YES        业务层处理了本消息，那么H5Service就不会处理
 *           NO         业务层不需要处理的消息，那么H5Service就会处理
 */
- (BOOL)serviceSeedingEventDidComeWithController:(H5WebViewController *)context
                                           event:(H5ServiceSeedingEnum)event
                                       paramDict:(NSDictionary *)paramDict;

- (BOOL)webView:(UIView<H5WebViewInterface> *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(H5WebViewNavigationType)navigationType;
- (void)webViewDidStartLoad:(UIView<H5WebViewInterface> *)webView;
- (void)webViewDidFinishLoad:(UIView<H5WebViewInterface> *)webView;
- (void)webView:(UIView<H5WebViewInterface> *)webView didFailLoadWithError:(NSError *)error;
/**
 *    subView模式下会回调ContentSize的变化 WKWebview only
 *    @param     size     当前WebView的Size
 */
- (void)webView:(UIView<H5WebViewInterface> *)webView didChangeContentSize:(CGSize)size;
@end
