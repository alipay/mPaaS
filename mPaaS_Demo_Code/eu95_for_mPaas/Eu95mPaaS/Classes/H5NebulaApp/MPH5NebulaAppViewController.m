//
//  MPH5NebulaAppViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/4/18.
//

#import "MPH5NebulaAppViewController.h"
#import <AriverMPNebulaAdapter/MPNebulaAdapterInterface.h>
#import "MPWKWebViewViewController.h"

@interface MPH5NebulaAppViewController ()

@end

@implementation MPH5NebulaAppViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = NSLocalizedString(@"H5容器和离线包", nil);
    
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"打开H5离线包", nil), openOfflinePackageAction)
        BUTTON_WITH_ACTION(NSLocalizedString(@"打开H5预置离线包", nil), openOfflineIfamePackageAction)
        BUTTON_WITH_ACTION(NSLocalizedString(@"打开在线页面", nil), openOnlineAction)
        BUTTON_WITH_ACTION(NSLocalizedString(@"更新单个应用", nil), uploadOnlineAction)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"删除单个应用", nil), delOnlineAction)
        BUTTON_WITH_ACTION(NSLocalizedString(@"打开本地页面", nil), openLocalFileAction)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"自定义JSAPI", nil), customJsApiAction)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"定制导航栏", nil), customNavigatorBar)
        BUTTON_WITH_ACTION(NSLocalizedString(@"WKWebView", nil), openWKWebView)
    })
}

- (void)openOfflinePackageAction
{
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithNebulaApp:@{@"appId":@"12345678"}];
}

-(void)openOfflineIfamePackageAction{
//    [[MPNebulaAdapterInterface shareInstance] requestNebulaAppsWithParams:@{@"15010000":@"*"} finish:^(NSDictionary *data, NSError *error) {
//        NSLog(@"%@",data);
//    }];
//    
//    NSLog(@"%@",[[MPNebulaAdapterInterface shareInstance] allAppsForAppId:@[@"0000000000000002"]]);

    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithNebulaApp:@{@"appId":@"00000089"}];
}

-(void)openOnlineAction{
//    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://help.aliyun.com/document_detail/55577.html?spm=a2c4g.107255.0.0.36407594Bgbk18#topic-2125657"}];
    
    //渝快办
    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"http://221.178.28.177:81/kuaiban/lost-register/lost-register-create"}];

}

//- (void)customNavigatorBar
//{
//    MPNavigatorDemoVC *vc = [MPNavigatorDemoVC new];
//    [self.navigationController pushViewController:vc animated:YES];
//}
//
//- (void)openPDFAction {
//    MP_PDFViewController *vc = [MP_PDFViewController new];
//    [self.navigationController pushViewController:vc animated:YES];
//}
//
//- (void)openOnlineAction
//{
////    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://ykbapp.cqdcg.com/intelligentService"}];
//    
////    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": @"https://cq12349.cn/yyyl-h5/#/pages/common/avoidLogin01"}];
//    
//    [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url":@"https://help.aliyun.com/document_detail/106682.html?spm=a2c4g.51734.0.0.5830324dXuRYxI"}];
//}
//
- (void)openLocalFileAction
{
    NSString *path = [[NSBundle mainBundle].bundlePath stringByAppendingFormat:@"/%@", @"index.html"];
    path = [NSString stringWithFormat:@"file://%@", path];
    if ([path length] > 0) {
        [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": path}];
    }
}
//
//- (void)customJsApiAction
//{
//    NSString *path = [[NSBundle mainBundle].bundlePath stringByAppendingFormat:@"/%@", @"H52Native.html"];
//    path = [NSString stringWithFormat:@"file://%@", path];
//    if ([path length] > 0) {
//        [[MPNebulaAdapterInterface shareInstance] startH5ViewControllerWithParams:@{@"url": path,@"showRightBarItem":@"1"}];
//    }
//}
//
-(void)uploadOnlineAction{
    
    //强制更新所有离线包
    [[MPNebulaAdapterInterface shareInstance]requestAllNebulaApps:^(NSDictionary *data, NSError *error) {
    }];
}
//
//-(void)delOnlineAction{
////    [[MPNebulaAdapterInterface shareInstance] clearAllAppInfo:@"66668888"];
//}
//
-(void)openWKWebView{
    MPWKWebViewViewController *wkVC = [[MPWKWebViewViewController alloc] init];
    [self.navigationController pushViewController:wkVC animated:YES];
}

@end
