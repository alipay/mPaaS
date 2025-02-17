//
//  DTFrameworkInterface+Eu95mPaaS.m
//  Eu95mPaaS
//
//  Created by fengguanhua on 2024/04/17. All rights reserved.
//

#import "DTFrameworkInterface+Eu95mPaaS.h"
#import <UserNotifications/UserNotifications.h>
#import <MPPushSDK/MPPushSDK.h>
#import <AriverMPNebulaAdapter/MPNebulaAdapterInterface.h>
#import <mPaas/MPLiteSettingService.h>
#import "HXRpcInterceptor.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTFrameworkInterface (Eu95mPaaS)

- (BOOL)shouldLogReportActive
{
    return YES;
}

- (NSTimeInterval)logReportActiveMinInterval
{
    return 0;
}

- (BOOL)shouldLogStartupConsumption
{
    return YES;
}

- (BOOL)shouldAutoactivateBandageKit
{
    return YES;
}

- (BOOL)shouldAutoactivateShareKit
{
    return YES;
}

- (DTNavigationBarBackTextStyle)navigationBarBackTextStyle
{
    return DTNavigationBarBackTextStyleAlipay;
}

-(DTFrameworkCallbackResult)application:(UIApplication *)application privacyAuthDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions completionHandler:(void (^)(void))completionHandler{
    
//    [MPNebulaAdapterInterface shareInstance].configDelegate = self;
    return DTFrameworkCallbackResultContinue;
}

-(void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
    
    [MPNebulaAdapterInterface shareInstance].configDelegate = self;
    
    //初始化网关
    [MPRpcInterface initRpc];
    
    HXRpcInterceptor *mpTestIntercaptor = [[HXRpcInterceptor alloc] init];
    [MPRpcInterface addRpcInterceptor:mpTestIntercaptor];

    //初始化容器
    [self configNebula];
    //智能投放 MCDP
//    [CDPPromotionInterface start];
    
    NSString *getWorkspaceId = [MPLiteSettingService getWorkspaceId];
    NSLog(@"%@",getWorkspaceId);
    
}


-(void)application:(UIApplication *)application afterDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
//    APWillKillSplashScreen();
    //消息推送
    [self registerRemoteNotification];
    
    //热修复
    [self initHotpatch];
    
    [MPNebulaAdapterInterface shareInstance].nebulaVeiwControllerClass = NSClassFromString(@"MPH5WebViewController");
    //    关闭验签
    [MPNebulaAdapterInterface shareInstance].nebulaNeedVerify = NO;
//    [MPNebulaAdapterInterface shareInstance].nebulaUserAgent = @"mPaaS/Portal";
    //强制更新所有离线包
    [[MPNebulaAdapterInterface shareInstance]requestAllNebulaApps:^(NSDictionary *data, NSError *error) {
        NSLog(@"data===>>>%@",data);
    }];
    
//    [[MPNebulaAdapterInterface shareInstance] requestNebulaAppsWithParams:@{@"2018080616290001":@"*"} finish:^(NSDictionary *data, NSError *error) {
        
//        if (!error) {
//            NSDictionary *dic = [[MPNebulaAdapterInterface shareInstance] allAppsForAppId:@[@"0000000111111101"]];
//            NAMApp *app = dic[@"0000000111111101"];
//            NSLog(@"%@",app);
//
//            NSLog(@"[mpaas] nebula rpc data :%@", data[@"data"]);
//            dispatch_async(dispatch_get_main_queue(), ^{
//                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"message" message:[NSString stringWithFormat:@"更新成功：%@", data[@"data"]] delegate:nil cancelButtonTitle:nil otherButtonTitles:@"ok", nil];
//                [alert show];
//            });
//    
//        }
//    }];
    
    [MPNebulaAdapterInterface shareInstance].nebulaUpdateReqRate = 120;
    
    
//    [MPAnalysisHelper enableRemoteLog:NO];
    
}
-(void)initHotpatch{
//    [MPDynamicInterface initDynamicSyncLocalFile];
    
    //本地测试热修复文件是否正确
//    NSString *jsFile = [[NSBundle mainBundle] pathForResource:@"TestCrash" ofType:@"js"];
//    [MPDynamicInterface runDynamicLocalFile:jsFile];
//    NSError *error = [MPDynamicInterface runWithResultDynamicLocalFile:jsFile];
    
//    NSString *jsFile = [[NSBundle mainBundle] pathForResource:@"TestCrash" ofType:@"zip"];
//    NSError *error = [MPDynamicInterface runWithResultDynamicLocalSecFile:jsFile];
//    [MPDynamicInterface runDynamicLocalSecFile:jsFile];
}


#pragma mark---初始化容器
- (void)configNebula
{
    // 自定义jsapi路径和预置离线包信息
    NSString *presetApplistPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DemoCustomPresetApps.bundle/h5_json.json"] ofType:nil];
    NSString *appPackagePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DemoCustomPresetApps.bundle"] ofType:nil];
    NSString *pluginsJsapisPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DemoCustomPlugins.bundle/Poseidon-UserDefine-Extra-Config.plist"] ofType:nil];
    [MPNebulaAdapterInterface initNebulaWithCustomPresetApplistPath:presetApplistPath
                                         customPresetAppPackagePath:appPackagePath
                                            customPluginsJsapisPath:pluginsJsapisPath];
}

#pragma mark MPS
- (void)registerRemoteNotification {
    // 注册推送
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0) {// 10.0+
        UNUserNotificationCenter* center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
        [center getNotificationSettingsWithCompletionHandler:^(UNNotificationSettings * _Nonnull settings) {
            [center requestAuthorizationWithOptions:(UNAuthorizationOptionAlert|UNAuthorizationOptionSound|UNAuthorizationOptionBadge) 
                                  completionHandler:^(BOOL granted, NSError * _Nullable error) {
                if (granted) {
                    dispatch_async(dispatch_get_main_queue(), ^{ 
                        [[UIApplication sharedApplication] registerForRemoteNotifications];
                    });
                }
            }];
        }];
    }
}

- (DTFrameworkCallbackResult)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[PushService sharedService] setDeviceToken:deviceToken];
    [[PushService sharedService] pushBindWithUserId:@"Eu95mPaaS" completion:^(NSException *error) {
        NSLog(@"绑定成功了吗=====>>>%@",error);
    }];
    return DTFrameworkCallbackResultContinue;
}

- (DTFrameworkCallbackResult)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    // userInfo 为推送消息内容，业务解析处理
    [self showAlert:userInfo];
    return DTFrameworkCallbackResultContinue;
}

- (void)showAlert:(NSDictionary *)userInfo {
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"通知详情" message:[NSString stringWithFormat:@"%@", userInfo] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
}

//-(NSString *)baseloadViewClass{
//    return @"MPBaseLoadingView";
//}

- (NSDictionary *)nebulaCustomConfig{
    return @{@"h5_fix_ios15_touchCallout" : @"NO"};
}

@end

#pragma clang diagnostic pop

