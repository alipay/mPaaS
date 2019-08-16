//
//  DTMicroApplication.h
//  Alipay Mobile Runtime Framework
//
//  Created by WenBi on 13-3-31.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTMicroApplicationLaunchMode.h"
#import "DTMicroApplicationDescriptor.h"

extern NSString * const kDTMicroApplicationDylibLoadFailNotification;   // 应用创建过程中动态库加载失败通知。
extern NSString * const kDTMicroApplicationDidCreateNotification;       // 应用创建完成通知。
extern NSString * const kDTMicroApplicationWillTerminateNotification;   // 应用将要退出通知。
extern NSString * const kDTMicroApplicationDidHideNotification;        // 需要保活的应用，在点击返回进入后台的时候的通知。
extern NSString * const kDTMicroApplicationDoesNotFoundNotification;    // 应用找不到通知，对本地app是app代理类找不到所致。
extern NSString * const kDTMicroApplicationWillStartNotification;       // 应用将要启动通知。
extern NSString * const kAPSceneID;
extern NSString * const kDTMicroApplicationKey;                         //应用声明周期通知的userInfo中app对象key
extern NSString * const kDTMicroApplicationParamsKey;                   //应用声明周期通知的userInfo中启动参数key

@protocol DTMicroApplicationDelegate;
@class DTViewController;

@interface DTMicroApplication : NSObject

/**
 * 应用的描述信息，如：AppId对应descriptor.name。
 */
@property(nonatomic, strong) DTMicroApplicationDescriptor *descriptor;

/**
 * 当前 app 的代理。
 */
@property(nonatomic, strong) id <DTMicroApplicationDelegate> delegate;

/**
 *  当前 app 所属的所有 view controller。
 */
@property(nonatomic, strong) NSMutableArray *viewControllers;

/**
 *  当前 app 所属的所有 view controller (满足viewController.isAlipayExiting=NO)。
 */
@property(nonatomic, strong) NSMutableArray *unExitingViewControllers;

/**
 *  为了修复小程序错误保活了已经被pop掉的VC，采用新的方式来获取需要保活的所有VC
 */
@property(nonatomic, strong) NSMutableArray *unExitingCachedViewControllers;

/**
 *  当前 app 是延迟释放时，需要将关联VC备份一下，确保viewControllers可以正常解绑定，保持已有的处理逻辑。
 */
@property(nonatomic, strong) NSMutableArray *cachedViewControllers;

/**
 *  应用类型。
 */
@property(nonatomic, strong) NSString *type;

/**
 * 启动 app 来源。
 * 注意：启动app时，可以由启动方指定，如果不指定，那么默认为启动时当前的appId；
 *      outerUrl：表示是外部通过scheme启动，应用内UIWebView里链接跳转也是这个标识；
 *      innerUrl：表示是内部通过scheme启动；
 *      push：表示点击push消息启动；
 */
@property(nonatomic, strong) NSString *sourceId;

/**
 * 外部应用通过通过scheme启动时，外部应用的bundle ID。
 */
@property(nonatomic, strong) NSString *sourceAppBundleId;

/**
 * 启动 app 场景，和sourceId含义相似。
 * 不同：通过scheme启动app时，如果scheme里可以用ap_sceneId来指定启动场景。用如下scheme启动时，
 *      alipays://platformapi/startApp?appId=20000235&ap_sceneId=scan
 *      sourceId 的值为outerUrl或innerUrl，而ap_sceneId 的值为scan
 * 注意：启动app时，可以由启动方指定，如果不指定，那么默认为启动时当前的appId；
 *      outerUrl：表示是外部通过scheme启动，应用内UIWebView里链接跳转也是这个标识；
 *      innerUrl：表示是内部通过scheme启动；
 *      push：表示点击push消息启动；
 */
@property(nonatomic, strong) NSString *ap_sceneId;

/**
 * 这个 app 的运行模式。
 */
@property(nonatomic, assign) DTMicroApplicationLaunchMode launchMode;


/**
 app 是否是延时释放
 */
@property(nonatomic, assign) BOOL shouldDelayRelease;


/**
 延时多长时间释放
 */
@property(nonatomic, assign) NSTimeInterval appSurvivalTimeInterval;

/**
 当接收到内存不足的时候，是否释放
 */
@property(nonatomic, assign) BOOL shouldReleaseWhenMemoryWarning;

/**
 延时释放timer
 */
@property(nonatomic, strong) NSTimer *delayReleaseTimer;

/**
 本次启动是否是从缓存中读取
 */
@property(nonatomic, assign) BOOL createFromCache;

/**
 * 如果当前的app栈是：A,B 那么当B在启动A时：
 * YES：默认值，会退出A上的所有App，结果：A；
 * NO： 不退出A上的App，而是退出自己，然后重新启动A，结果：B，A(注意：前后两个A不是同一个对象)；
 */
@property(nonatomic, assign) BOOL appClearTop;

/**
 场景参数字典,仅从native代码传入.不从scheme里解析.
 */
@property(nonatomic, strong) NSDictionary *sceneParams;

/**
 * 核心业务处理完成回调，暂时用框架全链路监控使用。
 * @param bizId    业务标识。
 * @param endTime  处理完成时间，为nil时，把调用时间作为处理完成时间。
 * @param userInfo 扩展参数。
 */
typedef void(^ueoAppBizCompletionBlock)(NSString *bizId, NSDate *endTime, NSDictionary *userInfo);
@property(nonatomic, copy) ueoAppBizCompletionBlock bizCompetionBlock;

/**
 全链路埋点监控关联Id，由框架生成，透传框架，容器和业务，用于日志关联上报
 */
@property(nonatomic, strong, readonly) NSString *fullLinkId;

/**
 * 获取当前应用的根控制器。
 *
 * @return 当前应用的根控制器对象，这个控制器<b>必须</b>是<code>DTViewController</code>的一个子类。
 */
- (UIViewController *)rootController;

/**
 * 退出本应用，应该不在栈顶，则无法退出。
 *
 * @param animated 指定退出应用时，是否需要动画。
 */
- (void)exitAnimated:(BOOL)animated;

/**
 * 退出本应用，无论应用是否在栈顶。
 * 注意：测试接口请勿直接使用。
 */
- (void)forceExit;

/**
 * 处理push消息。
 *
 * @param params push数据。
 *
 * @return 处理成功返回YES，否则NO。
 */
- (BOOL)handleRemoteNotifications:(NSDictionary *)params;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 *  返回当前栈顶应用。
 *
 *  @return 返回当前栈顶应用。
*/
DTMicroApplication * DTMicroApplicationGetCurrent();

#ifdef __cplusplus
}
#endif // __cplusplus
