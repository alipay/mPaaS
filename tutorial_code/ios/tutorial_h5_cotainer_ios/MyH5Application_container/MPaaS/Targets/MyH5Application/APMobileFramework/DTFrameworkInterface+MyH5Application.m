//
//  DTFrameworkInterface+MyH5Application.m
//  MyH5Application
//
//  Created by Evan on 2019/08/22.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "DTFrameworkInterface+MyH5Application.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTFrameworkInterface (MyH5Application)

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

- (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [MPNebulaAdapterInterface initNebula];
    NSString *pluginsJsapisPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"CustomJsApi.bundle/Poseidon-UserDefine-Extra-Config.plist"] ofType:nil];
    [MPNebulaAdapterInterface initNebulaWithCustomPresetApplistPath:@"" customPresetAppPackagePath:@""customPluginsJsapisPath:pluginsJsapisPath];

}

@end

#pragma clang diagnostic pop
