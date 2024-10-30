//
//  MPMDSViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/4/18.
//

#import "MPMDSViewController.h"

@interface MPMDSViewController ()

@end

@implementation MPMDSViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"检测升级：默认弹框提示 ", nil), checkUpgradeDefault)
        BUTTON_WITH_ACTION(NSLocalizedString(@"检测升级：自定义弹框图像和loading", nil), checkUpgradeWithHeaderImage)
        BUTTON_WITH_ACTION(NSLocalizedString(@"检测升级：自定义弹框UI", nil), checkUpgradeWIthCustomUI)
        BUTTON_WITH_ACTION(NSLocalizedString(@"模拟崩溃", nil), createCrash)
        BUTTON_WITH_ACTION(NSLocalizedString(@"Configuration", nil), configuration)
    })

}

#pragma mark - checkUpgrade
- (void)checkUpgradeDefault {
    [MPCheckUpgradeInterface sharedService].defaultUpdateInterval = 7;
    [[MPCheckUpgradeInterface sharedService] checkNewVersion];
}

- (void)checkUpgradeWithHeaderImage {
    MPCheckUpgradeInterface *upgradeInterface = [MPCheckUpgradeInterface sharedService];
    upgradeInterface.viewDelegate = self;
    [upgradeInterface checkNewVersion];
}

- (UIImage *)upgradeImageViewHeader{
    return APCommonUILoadImage(@"ilustration_ap_expection_alert");
}

- (void)showToastViewWith:(NSString *)message duration:(NSTimeInterval)timeInterval {
    [self showAlert:message];
}

- (void)showAlert:(NSString*)message {
    AUNoticeDialog* alertView = [[AUNoticeDialog alloc] initWithTitle:@"Information" message:message delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alertView show];
}

- (void)checkUpgradeWIthCustomUI {
    [[MPCheckUpgradeInterface sharedService] checkUpgradeWith:^(NSDictionary *upgradeInfos) {
        
        NSString *msg = upgradeInfos[@"message"];
        msg = [msg stringByReplacingOccurrencesOfString:@"\n" withString:@"\\n"];
        NSDictionary *dic = [self dictionaryWithJsonString:msg];
        NSLog(@"%@",dic);
        [self showAlert:[upgradeInfos JSONString_mp]];
        
    } failure:^(NSException *exception) {
        
    }];
}

- (NSString*)dictionaryToJson:(NSDictionary*)dic
{
    NSError *parseError =nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:&parseError];
    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}

- (NSDictionary*)dictionaryWithJsonString:(NSString*)jsonString {
    
    if(jsonString ==nil) {
         return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError*err;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                        options:NSJSONReadingMutableContainers
                        error:&err];
    
    if(err) {
            NSLog(@"json解析失败：%@",err);
            return nil;
    }
    return dic;
}

#pragma mark - Hotpatch
-(void)createCrash{
    NSArray *array = @[NSLocalizedString(@"crash被Hotpacth热修复啦", nil), @"hello world"];
    NSString *message = array[1];
    
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:NSLocalizedString(@"提示", nil) message:message];
    [alert addButton:NSLocalizedString(@"知道了", nil) actionBlock:^{}];
    [alert show];

}

#pragma mark - configuration
-(void)configuration{
    [[MPConfigInterface sharedService] forceLoadConfig];

    NSString *value = [[MPConfigInterface sharedService] stringValueForKey:@"configPush"];
    NSLog(@"value====>>>>%@",value);
    
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:NSLocalizedString(@"配置信息", nil) message:value delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    [alert addButton:NSLocalizedString(@"确定", nil) actionBlock:^{
        
        if ([value integerValue] == 1) {
            
//            MP_AViewController *vc =  MP_AViewController.new;
//            [self.navigationController pushViewController:vc animated:YES];
        }else{
            
//            MP_BViewController *vc =  MP_BViewController.new;
//            [self.navigationController pushViewController:vc animated:YES];
        }
        
    }];
    [alert show];

}

@end
