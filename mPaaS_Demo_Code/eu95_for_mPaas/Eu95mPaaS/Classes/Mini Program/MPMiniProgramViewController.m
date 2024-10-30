//
//  MPMiniProgramViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/4/18.
//

#import "MPMiniProgramViewController.h"
#import "MP_TinyScanDebugHelper.h"
#import <AriverMPNebulaAdapter/MPNebulaAdapterInterface.h>

@interface MPMiniProgramViewController ()

@end

@implementation MPMiniProgramViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = NSLocalizedString(@"小程序", nil);
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"启动小程序Demo", nil), openTinyAppAction)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"启动小程序插件Demo", nil), openTinyPluginAction)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"更新小程序插件", nil), updateTinyAction)
        BUTTON_WITH_ACTION(NSLocalizedString(@"调试/预览小程序", nil), debugTinyAppAction)
    })
}

//打开小程序
- (void)openTinyAppAction
{
    NSDictionary * dict = @{
//        @"page" : @"/pages/index/index"
    };
    [MPNebulaAdapterInterface startTinyAppWithId:@"8899889988998899" params: dict];
    
//    [MPNebulaAdapterInterface startTinyAppWithId:@"20000067" params:@{}];
//    NSString *path = [[NSBundle mainBundle].bundlePath stringByAppendingFormat:@"/%@", @"error_page.html"];
//    path = [NSString stringWithFormat:@"file://%@", path];
//    if ([path length] > 0) {
//        [MPNebulaAdapterInterface startTinyAppWithId:@"0000000111111100" params: @{@"url":path}];
//    }
}

-(void)openTinyPluginAction{
    NSDictionary *param = @{ @"appxRouteFramework": @"YES", @"appxRouteBizPrefix": @"",};
    [MPNebulaAdapterInterface startTinyAppWithId:@"8888888888888888" params:param];
}

//更新小程序
-(void)updateTinyAction{
    [[MPNebulaAdapterInterface shareInstance] requestNebulaAppsWithParams:@{@"2018080616290001":@"*"} finish:^(NSDictionary *data, NSError *error) {
        NSLog(@"data=====>>>%@,error=====>>>>%@",data,error);
    }];
}

//调试小程序
- (void)debugTinyAppAction
{
    [[MP_TinyScanDebugHelper sharedInstance] startScanWithNavVc:self.navigationController];
}

- (void)customJsApiAction
{
//    [MPNebulaAdapterInterface startTinyAppWithId:@"0000000000000002" params:@{}];
}

@end
