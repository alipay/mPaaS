//
//  MP_CustomEventController.m
//  mPaas_Poc_Demo
//
//  Created by wyy on 2021/7/17.
//

#import "MP_CustomEventController.h"

@interface MP_CustomEventController ()

@end

@implementation MP_CustomEventController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = NSLocalizedString(@"自定义分析", nil);
    
    CREATE_UI({
        BUTTON_WITH_ACTION(@"openApp", openAppEvent)
        BUTTON_WITH_ACTION(@"rpc", rpcEvent)
        BUTTON_WITH_ACTION(@"safekeyboard", safekeyboardEvent)
        BUTTON_WITH_ACTION(@"gdmap", gdmapEvent)
        BUTTON_WITH_ACTION(@"startTinyApp", startTinyAppEvent)
        BUTTON_WITH_ACTION(@"PayResults", payResultsEvent)
    })
}

- (void)openAppEvent
{
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz"
                                          eventId:@"openAppNum"
                                         extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟打开app自定义事件" duration:2.0 logTag:@"myBiz"];

}

- (void)rpcEvent
{
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"rpc" extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟打开移动网关自定义事件" duration:2.0 logTag:@"myBiz"];

}

- (void)safekeyboardEvent
{
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"safekeyboard" extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟打开安全键盘自定义事件" duration:2.0 logTag:@"myBiz"];
    [self uploadEvent];

}

- (void)gdmapEvent
{
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"gdmap" extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟打开高德地图自定义事件" duration:2.0 logTag:@"myBiz"];

}

- (void)payResultsEvent{
    
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"PayResults" extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟支付自定义事件" duration:2.0 logTag:@"myBiz"];

}

- (void)startTinyAppEvent
{
    [MPRemoteLoggingInterface writeLogWithBizType:@"myBiz" eventId:@"startTinyApp" extParam:@{@"logkey":@"logValue"}];
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"模拟打开小程序自定义事件" duration:2.0 logTag:@"myBiz"];
    
    [self uploadEvent];
}


-(void)uploadEvent{
    [MPRemoteLoggingInterface upload];
}
@end
