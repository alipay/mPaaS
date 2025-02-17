//
//  MPSecurityViewController.m
//  mPaaSSecurity_Poc_Demo
//
//  Created by 浩鲸UED on 2023/2/15.
//  Copyright © 2023 Alibaba. All rights reserved.
//



#import "MPSecurityViewController.h"
#import <MPSecurityAdapter/MPEnvironmentInterface.h>
#import <MPSecurityAdapter/MPEnvironmentUtil.h>
#import <MPSecurityAdapter/NSObject+MPMPAASEnvironment.h>
#import <CoreLocation/CoreLocation.h>

@interface MPSecurityViewController ()<CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;

@end

@implementation MPSecurityViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"移动安全";

    self.view.backgroundColor = [UIColor whiteColor];
    [MPEnvironmentInterface initMPAASEnvironment];
    
    CREATE_UI({
        // 移动安全环境检测
        BUTTON_WITH_ACTION(@"调用环境检测 Call environment check", getEnvironmentCheck);
        BUTTON_WITH_ACTION(@"调用wifi检测 Call wifi check", getWifiCheck);
        BUTTON_WITH_ACTION(@"调用截屏、录屏监听 Call screen capture and record observer", screenCaptureAndRecordObserver);
        BUTTON_WITH_ACTION(@"检测类方法Hook Detect class method hook", checkClsMethodHook);
        BUTTON_WITH_ACTION(@"检测实例方法Hook Detect instance method hook", checkInsMethodHook);
    })
}

#pragma mark - 环境检测

- (void)getEnvironmentCheck
{
    NSDictionary *dic = [MPEnvironmentInterface getAllMPAASStatus];
    UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"环境检测 environment check" message:dic.description preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定 Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
    }];
    [alertVc addAction:action];
    [self presentViewController:alertVc animated:YES completion:nil];
}

- (void)getWifiCheck
{
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    self.locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    self.locationManager.distanceFilter = 1000.0;
    [self.locationManager requestWhenInUseAuthorization];
    [self.locationManager startUpdatingLocation];
    dispatch_after(3, dispatch_get_main_queue(), ^{
        NSDictionary *dic = [MPEnvironmentInterface getMPAASWifiInfo];
        UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"wifi检测 WifiCheck" message:dic.description preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定 Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        }];
        [alertVc addAction:action];
        [self presentViewController:alertVc animated:YES completion:nil];
    });
}

-(void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    NSLog(@"");
}


- (void)screenCaptureAndRecordObserver
{
    [self addScreenCaptureObserver:self selector:@selector(screenCaptureChange)];
    [self addScreenRecordObserver:self selector:@selector(screenRecordChange)];
}

#pragma mark - 录屏 截屏 回调
- (void)screenCaptureChange {
    UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"检测结果 Detection result" message:@"检测到截屏，请确认是否本人操作 Detected screenshot, please confirm whether it is your operation" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定 Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
    }];
    [alertVc addAction:action];
    [self presentViewController:alertVc animated:YES completion:nil];
}

- (void)screenRecordChange {
    UIScreen * sc = [UIScreen mainScreen];
    if (@available(iOS 11.0,*)) {
        if (sc.isCaptured) {
            UIAlertController *alertVc = [UIAlertController alertControllerWithTitle:@"检测结果 Detection result" message:@"检测到您的设备正在进行视频录制，存在安全风险，请关闭视频录制再继续交易 We detected that your device is currently recording a video, which poses a security risk. Please stop recording the video before continuing the transaction " preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定 Confirm" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            }];
            [alertVc addAction:action];
            [self presentViewController:alertVc animated:YES completion:nil];
        } else {
           
        }
    }
}

+ (void)checkClsMethodHookTemp
{
    NSLog(@"checkClsMethodHookTemp get");
}

- (void)checkInsMethodHookTemp
{
    NSLog(@"checkInsMethodHookTemp get");
}

- (void)checkClsMethodHook
{
    if (MPEnvironmentUtilImpl != nil) {
        BOOL isHooked = MPAASCheckClsSelSwizzling(@"ViewController", @selector(checkClsMethodHookTemp));
        AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"检测类方法Hook Detect class method hook" message:[NSString stringWithFormat:@"is Hooked：%@", @(isHooked)] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
}

- (void)checkInsMethodHook
{
    if (MPEnvironmentUtilImpl != nil) {
        BOOL isHooked = MPAASCheckInsSelSwizzling(@"ViewController", @selector(checkInsMethodHookTemp));
        AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"检测实例方法Hook Detect instance method hook" message:[NSString stringWithFormat:@"is Hooked：%@", @(isHooked)] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
}

- (void)dealloc
{
    [self removeScreenRecordObserver:self];
    [self removeScreenCaptureObserver:self];
}

@end
