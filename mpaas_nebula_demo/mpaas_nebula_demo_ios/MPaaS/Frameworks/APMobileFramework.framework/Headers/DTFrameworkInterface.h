//
//  DTFrameworkInterface.h
//  APMobileFramework
//
//  Created by shenmo on 5/3/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DTBootLoader;

@interface DTFrameworkInterface : NSObject

+ (instancetype)sharedInstance;

#pragma mark - BootLoader

/**
 *  用于启动时控制bootLoader行为的bootOptions，可以修改字典内容。
 *  这个字典放在DTFrameworkInterface里，可以用来在启动过程中全局修改。
 *  默认，由框架调用的bootLoader start方法时，bootOptions里会有@"default"字段。
 *  当框架已经完成了bootLoader的调用，会向bootOptions里设置@"done"字段。
 */
@property (nonatomic, strong) NSMutableDictionary* bootOptions;

/**
 *  取得BootLoader对象。
 *  使用框架内部的默认实现即可，通常不需要覆盖。
 *  如果需要使用自己的bootLoader，需要实现DTBootLoader的子类。
 *
 *  @return DTBootLoader或其子类
 */
- (DTBootLoader*)bootLoader;

#pragma mark - 应用配置，微应用配置、服务配置、Scheme处理器配置，可用Category覆盖

/**
 *  应用是否是RC版本。对于一些应用，开发中的RC版本在Scheme跳转处理上可能与正式版本不同。
 *  如果应用不区分RC版本，不需要覆盖此方法。
 *  默认返回为NO。
 */
- (BOOL)isRCVersion;

/**
 *  读取预置的微应用列表配置
 *  默认读取MainBundle中的MobileRuntime.plist文件。
 *
 *  @return 列表配置字典，字典结构应该为：
        @{  @"Launcher": @"app1",
            @"Applications": @[
                                @{@"delegate": @"delegate1", @"name": @"app1"},
                                @{@"delegate": @"delegate2", @"name": @"app2"},
                                ...
                                ]
        }
        其中，Launcher记录哪个微应用作为启动应用（一般为UITabBarController）
 */
- (NSDictionary*)applicationsConfiguration;

/**
 *  读取预置的微应用动态库依赖配置
 *
 *  @return 微应用动态库依赖配置字典，字典结构应该为：
    @{ @"20000001": @[@"DylibName1",@"DylibName2"], ...}
 */
- (NSDictionary*)dylibConfiguration;

/**
 *  读取预置的Services列表
 *  默认读取MainBundle中MobileRuntime.plist文件字典内容的@"Services"字段
 *
 *  @return 列表配置数组，数组结构应该为：
 *      @[  
            @{@"class": @"class1", @"lazyLoading": @(YES), @"name": @"service1"},
            @{@"class": @"class2", @"lazyLoading": @(YES), @"name": @"service2"},
            ...
        ]
 */
- (NSArray*)servicesConfiguration;

/**
 *  如果除了lazyLoading，对服务有更详细的配置要求，可以使用servicesMap功能管理服务。
 *  默认读取MainBundler中MobileRuntime.plist文件字典内容的@"ServicesMap"字段
 *
 *  @return 列表配置字典，字典结构应该为：
        @{
            @"[AUTOSTART]": @[
                            @{@"name": @"group1", @"asynchronous": @(NO)},
                            @{@"name": @"group2", @"asynchronous": @(YES)},
                            ...],
            @"group1": @[
                        @{@"class": @"class1", @"name": @"service1"},
                        @{@"class": @"class2", @"name": @"service2"},
                        ...],
            @"group2": @[
                        @{@"class": @"class3", @"name": @"service3"},
                        ...],
            ...
        }
        
        1）"[AUTOSTART]"数组记录随应用启动自动启动的服务分组，如果asynchronous为YES，表示这个分组内所有服务在启动时异步启动。
            框架会将异步与同步的服务区分开，分成两组，分别启动。但同步服务之间或异步服务之间按照[AUTOSTART]描述的顺序启动。
        2）分组名可以任意取，每个分组是个数组，数组里每一项是个字典，字典配置service的实现类与名称，不需要配置lazyLoading属性。
        3）为了兼容性，ServicesMap里可以配置一个叫@"RunOnceServices"的分组。这个分组中的服务会先于所有服务启动，并且只运行一次。
            "RunOnceServices"这个分组不需要配置到"[AUTOSTART]"中。
 */
- (NSDictionary*)servicesMapConfiguration;

/**
 *  对于服务的配置，可以配置在@"Services"数组中，也可以放在@"ServicesMap"字典里。
 *
 *      1）配置在@"Services"中的服务需要配置是否是lazyLoading，对于非lazyLoading的服务，
 *          可以通过DTBootPhase的startNonlazyloadServicesg事件提前启动。
 *      2）配置在@"ServicesMap"中的服务，如果在"[AUTOSTART]"数组中进行了描述，会随应用自动启动。
 *          具体的处理方法是DTBootPhase的startAutostartServicesMapGroups。
 *
 *  该方法拿到所有服务的配置，默认实现为将servicesConfiguration与servicesMapConfiguration取到的服务信息进行合并。
 */
- (NSArray*)servicesAllConfiguration;

/**
 *  返回向DTSchemeService注册的DTSchemeHandler列表，处理scheme启动，该方法默认返回空数组。
 *
 *  @return @[DTSchemeHandler子类的类名NSString*]
 */
- (NSArray*)schemeHandlerClasses;

/**
 *  返回向DTSchemeService注册的DTSchemeHandler列表，处理domain启动，该方法默认返回空数组。
 *
 *  @return @[DTSchemeHandler子类的类名NSString*]
 */
- (NSArray*)domainHandlerClasses;

#pragma mark - 框架默认能力开关，可以用Category覆盖返回NO关闭

/**
 * 是否需要调用[window makeVisable],默认实现为 YES
 */
- (BOOL)shouldWindowMakeVisable;

/**
 * 是否需要显示Launcher
 */
- (BOOL)shouldShowLauncher;

/**
 *  是否使用日志记录默认的报活数据。报活分两种方式，一种是使用APRemoteLogging（日志报活），一种是使用RPC。
 *  默认在mPaaS中是使用日志报活，需要找mpaasweb同学开通。
 *  该方法默认实现为YES。
 */
- (BOOL)shouldLogReportActive;

/**
 *  当使用日志报活功能时，可以配置从后台切回前台的报活最小间隔时间。
 *  从后台切回前台时，距离上次报活时间少于多少秒时，不再报活。如果传0，每次后台切回前台都会报活。
 *  这个不影响冷启动，如果冷启动，每次都会报活。
 *  该方法默认返回0。
 */
- (NSTimeInterval)logReportActiveMinInterval;

/**
 *  是否使用日志记录启动时间消耗。在mPaaS中默认开启。
 *  该方法默认实现为YES。
 */
- (BOOL)shouldLogStartupConsumption;

/**
 *  当接入了Hotpatch后，是否自动执行Hotpatch的逻辑。包括脚本运行，同步，下载等。
 *  该方法默认返回YES。
 */
- (BOOL)shouldAutoactivateBandageKit;

/**
 *  启动过程是否挂起配置为lazyload的脚本，如果返回YES，启动时只执行非lazyload的patch脚本。
 *  对于lazyload的脚本，需要手动启动：
 *      [[DynamicRelease sharedInstance] executeLocalBandage:DRLocalBandageExecutionLazyload] 或
 *      [[DynamicRelease sharedInstance] executeLocalBandage:DRLocalBandageExecutionAll]
 *  该方法默认返回NO
 */
- (BOOL)suspendLazyloadBandages;

/**
 *  当接入了分享组件后，是否在框架里自动安装分享组件，并处理openURL事件。
 *  该方法默认返回YES。
 */
- (BOOL)shouldAutoactivateShareKit;

/**
 *  当应用为RC版本时，是否将应用要处理的URL里的scheme转成带@"rc"结尾的版本。
 *  pattern为scheme的模式，当scheme以pattern字符串为开头时才进行处理。
 *  默认返回NO。
 */
- (BOOL)shouldAutoconvertSchemesForRCVersion:(NSString**)pattern;

/**
 *  是否在ViewDidAppear事件里检查窗口栈，排除乱栈情况。
 *  默认返回NO。
 */
- (BOOL)shouldInspectStackOnViewDidAppear;

/**
 * 框架是否能处理此schema
 */
- (BOOL)shouldHandleUrl:(NSURL *)url;

#pragma mark - 用Category覆盖下列方法实现自定义效果

/**
 *  每个继承自DTViewController的子VC，都会被默认设置为一个背景色，如果实现这个方法，框架会回调并取到应用指定的颜色。
 *  同时这个颜色也是应用默认UIWindow的颜色。
 *  默认值为：[UIColor whiteColor]
 */
- (UIColor*)defaultBackgroundColor;

// VC的返回按钮样式
typedef NS_ENUM (NSInteger, DTNavigationBarBackTextStyle)
{
    DTNavigationBarBackTextStyleNone,           // 完全不显示返回按钮的文本（present的窗口还是会显示“取消”）
    DTNavigationBarBackTextStyleUniformBack,    // 统一显示为“返回”
    DTNavigationBarBackTextStyleAlipay,         // 支付宝风格，Tab的下一级窗口，返回按钮显示Tab的名称，其它级别的窗口统一显示返回
};

/**
 *  使用框架时，DTViewController自动添加的返回按钮的文本样式。
 *  默认返回支付宝样式。
 */
- (DTNavigationBarBackTextStyle)navigationBarBackTextStyle;

/**
 *  使用框架时，DTViewController自动添加的返回按钮默认的图片。
 *  框架获取返回按钮图片的调用顺序如下：
 *      1）如果使用了APCommonUI，会优先使用APCommonUI的主题管理功能。“APNavigationBar.Button.BackImage”路径指定的图片。
 *      2）navigationBarBackButtonImage方法
 *      3）如果仍然找不到，会使用框架自带的默认图片。
 *  本方法默认返回nil。
 */
- (UIImage*)navigationBarBackButtonImage;

/**
 *  使用框架时，DTViewController自动添加的返回按钮默认字体。
 *  框架获取返回按钮图片的调用顺序如下：
 *      1）如果使用了APCommonUI，会优先使用APCommonUI的主题管理功能。“APNavigationBar.Button.Font”路径指定的字体。
 *      2）navigationBarBackButtonTextFont方法
 *  本方法默认返回[UIFont systemFontOfSize:16.0f]。
 */
- (UIFont*)navigationBarBackButtonTextFont;

/**
 *  使用框架时，DTViewController自动添加的返回按钮默认字体颜色。
 *  框架获取返回按钮图片的调用顺序如下：
 *      1）如果使用了APCommonUI，会优先使用APCommonUI的主题管理功能。“APNavigationBar.Button.TextColor”路径指定的颜色。
 *      2）navigationBarBackButtonTextColor方法
 *  本方法默认返回[UIColor whiteColor]。
 */
- (UIColor*)navigationBarBackButtonTextColor;

/**
 *  使用框架的DTBaseViewController时，可以调用startTitleLoading方法在上面转菊花。
 *  现在可以通过这个方法定制菊花view的类型。只需要返回类名的字符串即可。
 *  该方法的默认实现为UIActivityIndicatorView。
 *  传进来的类至少要实现下面三个方法，如果不实现可能会crash。
 *      - (void)startAnimating;
 *      - (void)stopAnimating;
 *      - (BOOL)isAnimating;
 */
- (NSString*)navigationBarLoadingViewClass;

/**
 *  使用框架的DTBaseViewController时，导航栏上加载菊花的默认颜色。如果实现这个方法，框架会回调并取到应用指定的颜色
 *  本方法默认返回的颜色值如下：
 *  第一个颜色：圆环的颜色：#cccccc
 *  第二个颜色：旋转进度条的颜色:#108ee9
 *  如果使用APCommonUI中的APActivityIndicatorView，支持这两个颜色的设置。
 *  如果使用系统的UIActivityIndicatorView或其他自定义的菊花控件，框架只会向其发送setColor:消息，并传递数组中的第一个颜色。
 */
- (NSArray *)navigationBarLoadingViewColors;

#pragma mark - UIApplication生命期回调，可以用Category覆盖

typedef NS_ENUM(NSInteger, DTFrameworkCallbackResult)
{
    DTFrameworkCallbackResultContinue                       = 0,        // 继续执行
    DTFrameworkCallbackResultReturn                         = 1,        // 中断执行
    DTFrameworkCallbackResultReturnYES                      = 2,        // 中断之后的逻辑，并返回YES
    DTFrameworkCallbackResultReturnNO                       = 3,        // 中断之后的逻辑，并返回NO
};

/**
 *  框架在 didFinishLaunching 中最早的时机回调该方法，在 mPaaS 所有组件执行前调用
 */
- (void)application:(UIApplication *)application beginDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

// 关于didFinishLaunching中各回调事件的调用顺序
//      [DTFrameworkInterface shouldAutoactivateBandageKit]
//      [DTFrameworkInterface beforeDidFinishLaunchingWithOptions]
//      [DTFrameworkInterface shouldLogReportActive]
//      [DTFrameworkInterface checkInstallationStatus]
//      [DTFrameworkInterface handleDidFinishLaunchingWithOptions]
//      [DTBootLoader willStartBootLoader]
//      [DTBootLoader startWithOptions]
//      [DTBootLoader didStartBootLoader]
//      [DTFrameworkInterface shouldLogStartupConsumption]
//      [DTFrameworkInterface afterDidFinishLaunchingWithOptions]

/**
 *  框架有一些自己的初始化逻辑在didFinishLaunching里需要实现，但会在执行之前回调该方法。
 */
- (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  框架回调该方法，让接入应用可以接管自己的didFinishLaunching逻辑。
 *  并且当返回DTFrameworkCallbackResultReturnYES或DTFrameworkCallbackResultReturnNO时，直接给系统返回，不再执行接下来的逻辑。
 *  这个方法在框架启动BootLoader前回调，应用可以通过返回DTFrameworkCallbackResultReturnYES或DTFrameworkCallbackResultReturnNO让框架提前退出，不运行默认的BootLoader。
 *  使用框架内部的默认实现即可，通常不需要覆盖。
 *
 *  @return 是继续让框架执行，还是直接给系统返回YES或NO
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application handleDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  框架有一些自己的初始化逻辑在didFinishLaunching里需要实现，但会在所有逻辑完成后回调该方法。
 */
- (void)application:(UIApplication *)application afterDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  框架会率先回调该方法，让接入应用可以预先处理通知消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把通知消息通过UIApplicationDidReceiveRemoteNotification广播给全局监听者。并调用completionHandler(UIBackgroundFetchResultNoData)。
 *  当返回DTFrameworkCallbackResultReturn时，表示接入应用已经完全处理完通知消息，框架中止执行之后的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 *  框架会率先回调该方法，让接入应用可以预先处理通知消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把通知消息通过UIApplicationDidReceiveLocalNotification广播给全局监听者。
 *  当返回DTFrameworkCallbackResultReturn时，表示接入应用已经完全处理完通知消息，框架中止执行之后的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification;

/**
 *  框架会率先回调该方法，让接入应用可以预先处理通知消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把通知消息通过UIApplicationDidReceiveLocalNotification广播给全局监听者。并调用completionHandler()。
 *  当返回DTFrameworkCallbackResultReturn时，表示接入应用已经完全处理完通知消息，框架中止执行之后的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void (^)())completionHandler;

/**
 *  框架会率先回调该方法，让接入应用可以拿到deviceToken。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把deviceToken通过UIApplicationDidRegisterForRemoteNotifications广播给全局监听者。
 *  当返回DTFrameworkCallbackResultReturn时，表示接入应用已经完全处理完，框架中止执行之后的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 *  当取deviceToken失败时，框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/**
 *  框架会先给分享组件（如果有，并且shouldAutoactivateShareKit返回YES）通知，如果分享组件处理不了，再回调该方法，由接入应用处理openURL。
 *  当返回DTFrameworkCallbackResultReturnYES或DTFrameworkCallbackResultReturnNO时，框架直接给系统返回，不再执行接下来的逻辑。
 *  当返回DTFrameworkCallbackResultContinue时，继续由框架处理URL，并分发给SchemeHandler等类来处理。
 *
 *  这个方法相比系统方法，多了一个newURL参数，允许应用在处理后，返回一个不同的url。如果函数整体返回DTFrameworkCallbackResultContinue，并且给newURL赋值，框架会使用新的URL来做后续处理。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application openURL:(NSURL *)url newURL:(NSURL **)newURL sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 *  框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationWillResignActive:(UIApplication *)application;

/**
 *  框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationDidEnterBackground:(UIApplication *)application;

/**
 *  框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationWillEnterForeground:(UIApplication *)application;

/**
 *  框架先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，给分享组件事件（如果有，并且shouldAutoactivateShareKit返回YES）。并且当整个应用没被加载时，调用BootLoader
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationDidBecomeActive:(UIApplication *)application;

/**
 *  框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationWillTerminate:(UIApplication *)application;

/**
 *  框架率先回调该方法。
 *  当返回DTFrameworkCallbackResultContinue时，框架继续执行，目前无其它逻辑。
 *  当返回DTFrameworkCallbackResultReturn时，框架中止之后的逻辑，目前无其它逻辑。
 */
- (DTFrameworkCallbackResult)applicationDidReceiveMemoryWarning:(UIApplication *)application;

/**
 *  框架率先回调该方法，接入应用可以先行处理Watch的消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把Watch消息通过UIApplicationWatchKitExtensionRequestNotifications广播给全局监听者。
 *  当返回DTFrameworkCallbackResultReturn时，表示接入应用已经完全处理完通知消息，框架中止执行之后的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application handleWatchKitExtensionRequest:(NSDictionary *)userInfo reply:(void(^)(NSDictionary *replyInfo))reply;

/**
 *  框架率先回调该方法，接入应用可以先行处理消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会把消息通过UIApplicationUserActivityNotifications广播给全局监听者，并最后给系统返回NO。
 *  当返回DTFrameworkCallbackResultReturnYES或DTFrameworkCallbackResultReturnNO时，框架直接给系统返回，不再执行接下来的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray *restorableObjects))restorationHandler;

/**
 *  框架率先回调该方法，接入应用可以先行处理3D Touch快捷入口的消息。
 *  当返回DTFrameworkCallbackResultContinue时，框架会处理shortcutItem带过来的URL，并最后调用completionHandler()返回是否已经处理。
 *  当返回DTFrameworkCallbackResultReturn时，框架直接给系统返回，不再执行接下来的逻辑。
 */
- (DTFrameworkCallbackResult)application:(UIApplication *)application performActionForShortcutItem:(UIApplicationShortcutItem *)shortcutItem completionHandler:(void (^)(BOOL))completionHandler;

/**
 *  Background Fetch 机制回调
 *  必须在30s内回调completionHandler，否则进程将被terminate
 *  若要启用此机制，需要先配置Background Modes的fetch选项。其次在didFinishLaunching中调用下面的方法。更多信息参考文档。
 *  [application setMinimumBackgroundFetchInterval:UIApplicationBackgroundFetchIntervalMinimum];
 *  默认实现为空，需要接入方自己处理。
 */
- (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

#pragma mark - 功能方法，可以用Category覆盖

/**
 *  在启动时需要根据版本号判断是否是第一次安装，或者是覆盖安装。
 *  默认实现为将应用的CFBundleShortVersionString与CFBundleVersion合并为%@.%@组成完整的版本号V。如果NSUserDefaults里不存在老的版本号，认为是全新安装。如果V与NSUserDefaults里的值不相等，认为是覆盖安装。
 *  获取全新安装或覆盖安装，使用[UIApplication sharedApplication].bFirstInstalled和[UIApplication sharedApplication].bCoverInstallation属性。
 */
- (void)checkInstallationStatus;

/**
 *  框架在调用内置的DTSchemeService处理url前，会回调该方法。接入应用可以在回调方法种提前处理handleOpenURL。
 *
 *  @param url          传入的url
 *  @param newURL       如果需要对url进行修改，可以用这个指针返回新的url
 *  @param convertForRC 接下来的处理是否要自动将url进行RC包的转换，默认为YES。如果返回YES，会回调isRCVersion和shouldAutoconvertSchemesForRCVersion方法最终决定如何对url进行转换。
 *
 *  @return 如果返回DTFrameworkCallbackResultContinue，框架会继续处理，交给DTSchemeService，依次调用各Scheme Handler；
 *          如果返回DTFrameworkCallbackResultReturnYES或DTFrameworkCallbackResultReturnNO，框架退出执行。
 *
 *  该方法默认返回DTFrameworkCallbackResultContinue。
 */
- (DTFrameworkCallbackResult)handleOpenURL:(NSURL *)url newURL:(NSURL **)newURL convertForRC:(BOOL*)convertForRC;

#pragma mark - DFNavigationController代理回调

// 框架使用DFNavigationController类作为导航类，重写了其中一些方法。这里公开一些回调方法，供接入应用使用。

/**
 *  框架使用的是DFNavigationController的内部类，重写了navigationController:didShowViewController:animated:方法。
 *  如果接入应用想在这个方法里做一些事情，可以实现这个回调。DFNavigationController每次触发该方法，会回调两次，分别在方法开始，和方法结束。用begin字段区分。
 *
 *  @param navigationController navigationController，应该是DFNavigationController类
 *  @param viewController       viewController
 *  @param animated             animated
 *  @param begin                是否是DFNavigationController的开始回调的。
 */
- (void)navigationController:(UINavigationController*)navigationController didShowViewController:(UIViewController*)viewController animated:(BOOL)animated begin:(BOOL)begin;

/**
 *  框架使用通用配置，用于容错和异常屏蔽。
 *
 *  @param key 开关键
 *
 *  @return    配置返回开关，否则返回nil。
 */
- (NSString *)configForKey:(NSString *)key;

@end
