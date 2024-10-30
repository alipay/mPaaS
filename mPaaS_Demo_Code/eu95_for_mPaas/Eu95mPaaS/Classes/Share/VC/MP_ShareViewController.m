//
//  MP_ShareViewController.m
//  mPaas_Poc_Demo
//
//  Created by wyy on 2021/7/5.
//

#import "MP_ShareViewController.h"
//#import <MPShareKit/WXApi.h>

typedef NS_ENUM(NSUInteger, MPShareType) {
    MPShareTypeText = 1,
    MPShareTypeImage,
    MPShareTypeURL,
};
@interface MP_ShareViewController ()<APSKLaunchpadDelegate>

@end

@implementation MP_ShareViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = NSLocalizedString(@"分享", nil);
    self.view.backgroundColor = AU_COLOR_CLIENT_BG1;
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"分享文本", nil), shareText)
        BUTTON_WITH_ACTION(NSLocalizedString(@"分享图片", nil), shareImage)
        BUTTON_WITH_ACTION(NSLocalizedString(@"分享链接", nil), shareUrl)
    })
}

- (void)shareText {
    [self openPannel:MPShareTypeText];
}

- (void)shareImage {
    [self openPannel:MPShareTypeImage];
}

- (void)shareUrl {
    [self openPannel:MPShareTypeURL];
}

- (void)openPannel:(MPShareType)type {
    NSArray *channelArr = @[kAPSKChannelWeibo, kAPSKChannelWeixin, kAPSKChannelWeixinTimeLine, kAPSKChannelSMS, kAPSKChannelQQ, kAPSKChannelQQZone, kAPSKChannelDingTalkSession, kAPSKChannelALPContact, kAPSKChannelALPTimeLine];
    
    APSKLaunchpad *launchPad = [[APSKLaunchpad alloc] initWithChannels:channelArr sort:NO];
    launchPad.tag = type;
    launchPad.delegate = self;
    
    [launchPad showForView:[[UIApplication sharedApplication] keyWindow] animated:YES];
}

- (void)shareWithChannel:(NSString *)channelName tag:(NSInteger)tag {
    APSKMessage *message = [self messageOfType:tag];
    APSKClient *client = [[APSKClient alloc] init];
    client.disableToastDisplay = YES;
    
    [APSKClient isAppInstalledForChannel:@"kAPSKChannelWeibo"];
    
    [client shareMessage:message toChannel:channelName completionBlock:^(NSError *error, NSDictionary *userInfo) {
        if(!error) {// 成功
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconSuccess
                                   text:@"分享成功"
                               duration:2
                                 logTag:@"demo"];
        } else {// 失败
            NSString *desc = error.localizedFailureReason.length > 0 ? error.localizedFailureReason : @"分享失败";
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconNone
                                   text:desc
                               duration:2
                                 logTag:@"demo"];
            NSLog(@"error = %@", error);
        }
    }];
}

- (APSKMessage *)messageOfType:(MPShareType)type {
    APSKMessage *message = [[APSKMessage alloc] init];
    switch (type) {
        case MPShareTypeText:
            message.contentType = @"text";//类型分"text","image", "url"三种
            message.desc = @"分享文本在这里";
            break;
        case MPShareTypeImage:
            message.contentType = @"image";//类型分"text","image", "url"三种
            message.content = [UIImage imageNamed:@"APCommonUI.bundle/ilustration_ap_expection_empty.png"];//大图
            message.icon = [UIImage imageNamed:@"APCommonUI.bundle/ilustration_ap_expection_empty.png"];//缩略图
            message.desc = @"描述";
            break;
        case MPShareTypeURL:
            message.contentType = @"url";//类型分"text","image", "url"三种
            message.content = [NSURL URLWithString:@"http://www.sina.com.cn"];
            message.icon = [UIImage imageNamed:@"MPShareKit.bundle/Icon_Laiwang@2x.png"];
            message.title = @"这里是网页标题";
            message.desc = @"这里是描述啦啦啦～";
            break;
            
        default:
            break;
    }
    
    return message;
}


#pragma mark - APSKLaunchpadDelegate
- (void)sharingLaunchpad:(APSKLaunchpad *)launchpad didSelectChannel:(NSString *)channelName {
    [self shareWithChannel:channelName tag:launchpad.tag];
    [launchpad dismissAnimated:YES];
}




@end
