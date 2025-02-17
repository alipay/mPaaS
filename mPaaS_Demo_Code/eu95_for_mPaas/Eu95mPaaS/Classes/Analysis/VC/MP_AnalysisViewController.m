//
//  MP_AnalysisViewController.m
//  mPaas_Poc_Demo
//
//  Created by wyy on 2021/7/9.
//

#import "MP_AnalysisViewController.h"
#import "MP_CustomEventController.h"
@interface MP_AnalysisViewController ()

@end

@implementation MP_AnalysisViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = NSLocalizedString(@"移动分析", nil);
    
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"行为日志", nil), sendBehaviorLog)
        BUTTON_WITH_ACTION(NSLocalizedString(@"报活日志", nil), sendReportActive)
        BUTTON_WITH_ACTION(NSLocalizedString(@"性能日志", nil), sendPerformanceLog)
        BUTTON_WITH_ACTION(NSLocalizedString(@"卡顿报告（需在真机且非xcode调试）", nil), sendPerformanceLog1)
        BUTTON_WITH_ACTION(NSLocalizedString(@"卡死报告", nil), sendPerformanceLog2)
        BUTTON_WITH_ACTION(NSLocalizedString(@"闪退报告", nil), sendCrashLog)
        BUTTON_WITH_ACTION(NSLocalizedString(@"自定义分析", nil), customEvent)
        BUTTON_WITH_ACTION(NSLocalizedString(@"诊断日志", nil), diagnosticLog)
    })
}

- (void)customEvent
{
    MP_CustomEventController *vc = MP_CustomEventController.new;
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)sendBehaviorLog
{
    [APToastView presentToastWithin:self.view withIcon:nil text:NSLocalizedString(@"添加行为日志", nil) duration:2.0];

    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"log_test_case" extParam:@{@"logkey":@"logValue"}];

}

- (void)sendReportActive
{
    [APToastView presentToastWithin:self.view withIcon:nil text:NSLocalizedString(@"添加报活日志", nil) duration:2.0];
    [[MPAnalysisHelper sharedInstance] writeLogForReportActive];
}

- (void)sendPerformanceLog
{
    NSArray *params = @[@"param1", @"param2", @"param3", @{@"key1":@"value1", @"key2":@"value2"}];
    [APRemoteLogger writePerformanceLogWithType:APLogTypeMemory subType:@"demo" extraParams:params];
    [APToastView presentToastWithin:self.view withIcon:nil text:NSLocalizedString(@"添加性能日志", nil) duration:2.0];

}

- (void)sendPerformanceLog1
{
    // 模拟卡顿
    [APToastView presentToastWithin:self.view withIcon:nil text:NSLocalizedString(@"模拟卡顿，休眠10秒", nil) duration:2.0];
    sleep(10);
}

- (void)sendPerformanceLog2
{
    // 模拟程序卡死
    [APToastView presentToastWithin:self.view withIcon:nil text:NSLocalizedString(@"模拟卡死，休眠30秒", nil) duration:2.0];
    sleep(30);
}

- (void)sendCrashLog
{
    NSArray *arr = @[@"1", @"2"];
    [arr objectAtIndex:3];
}

-(void)diagnosticLog{
    APLogToFile(@"mPaaS", kAPLogLevelInfo, @"%@",@"诊断日志");
}

@end
