//
//  H5Plugin4TitleView.m
//  GFPOC
//
//  Created by 刘军军 on 2018/2/26.
//  Copyright © 2018年 ynet. All rights reserved.
//

#import "MPPlugin4TitleView.h"
#import <NebulaBiz/H5Defines.h>

@implementation MPPlugin4TitleView

- (void)pluginDidLoad
{
    self.scope = kPSDScope_Scene;
    
    // -- 返回区域
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Left_Back_Create_Before withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Left_Back_Create_After withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Left_Close_Create_Before withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Left_Close_Create_After withListener:self useCapture:NO];
    
    // -- 标题区域
    [self.target addEventListener:kNBEvent_Scene_TitleView_Create_Before withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_TitleView_Create_After withListener:self useCapture:NO];
    
    // -- 控制按钮区域
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Right_Setting_Create_Before withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Right_Setting_Create_After withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Right_SubSetting_Create_After withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Right_Setting_Change withListener:self useCapture:NO];
    
    // -- 进度条
    [self.target addEventListener:kNBEvent_Scene_ProgressView_Create_Before withListener:self useCapture:NO];
    [self.target addEventListener:kNBEvent_Scene_ProgressView_Create_After withListener:self useCapture:NO];
    
    // -- 修改导航栏风格
    [self.target addEventListener:kH5Event_Scene_NavigationBar_ChangeColor withListener:self useCapture:NO];
    
    [super pluginDidLoad];
}

- (void)handleEvent:(PSDEvent *)event
{
    [super handleEvent:event];
    
    if ([kNBEvent_Scene_NavigationItem_Left_Back_Create_Before isEqualToString:event.eventType]) {
        // 重写返回按钮样式
//        event.context.currentViewController.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"取消" style:UIBarButtonItemStylePlain target:self action:@selector(onClickBack)];
//        [event preventDefault];
    }else if ([kNBEvent_Scene_NavigationItem_Left_Back_Create_After isEqualToString:event.eventType]){
        // 在默认返回按钮基础上，修改样式
        NSArray *leftBarButtonItems = event.context.currentViewController.navigationItem.leftBarButtonItems;
        if ([leftBarButtonItems count] == 1) {
            if (leftBarButtonItems[0] && [leftBarButtonItems[0] isKindOfClass:[AUBarButtonItem class]]) {
                // 在默认返回按钮基础上，修改返回箭头和文案颜色
                AUBarButtonItem *backItem = leftBarButtonItems[0];
                backItem.backButtonColor = [UIColor greenColor];
                backItem.titleColor = [UIColor colorFromHexString:@"#00ff00"];
                
                // 隐藏返回箭头
//                backItem.hideBackButtonImage = YES;

                // 隐藏返回文案：文案设置为透明，保留返回按钮s点击区域
//                backItem.titleColor = [UIColor clearColor];
            }
        }
        [event preventDefault];
        [event stopPropagation];
    }else if([kNBEvent_Scene_NavigationItem_Left_Back_Click isEqualToString:event.eventType]){
        
    }else if ([kNBEvent_Scene_NavigationItem_Left_Close_Create_Before isEqualToString:event.eventType]){
        // 隐藏关闭按钮
//        NBNavigationItemLeftCloseEvent *itemEvent = (NBNavigationItemLeftCloseEvent *)event;
//        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
//        button.frame = CGRectMake(0, 0, 44, 44);
//        button.backgroundColor = [UIColor greenColor];
//        [button setTitle:@"Close" forState:UIControlStateNormal];
//        itemEvent.customView = button;
//        [event preventDefault];
//        [event stopPropagation];
    }else if ([kNBEvent_Scene_NavigationItem_Left_Close_Create_After isEqualToString:event.eventType]){
        // 修改关闭按钮样式
        NBNavigationItemLeftCloseEvent *itemEvent = (NBNavigationItemLeftCloseEvent *)event;
        UIButton *closeButton = (UIButton *)itemEvent.customView;
        [closeButton setTitle:@"Close" forState:UIControlStateNormal];
        [closeButton setTitleColor:[UIColor greenColor] forState:UIControlStateNormal];
        [event preventDefault];
        [event stopPropagation];
    }else if ([kNBEvent_Scene_TitleView_Create_Before isEqualToString:event.eventType]) {
        // 重写TitleView的样式
//        NBNavigationTitleViewEvent *e = (id)event;
//        [e preventDefault];
//        [e stopPropagation];
    }else if ([kNBEvent_Scene_TitleView_Create_After isEqualToString:event.eventType]) {
        // 更改已创建TitleView的样式
        NBNavigationTitleViewEvent *e = (id)event;
        [[e.titleView mainTitleLabel] setFont:[UIFont systemFontOfSize:16]];
        [[e.titleView mainTitleLabel] setTextColor:[UIColor greenColor]];
        [e.titleView mainTitleLabel].lineBreakMode = NSLineBreakByTruncatingMiddle;
        [e preventDefault];
        [e stopPropagation];
    }else if ([kNBEvent_Scene_NavigationItem_Right_Setting_Create_After isEqualToString:event.eventType] || [kNBEvent_Scene_NavigationItem_Right_SubSetting_Create_After isEqualToString:event.eventType]) {
        // 更改已创建RightBarItem的样式
        NBNavigationItemRightSettingEvent *settingEvent = (id)event;
        settingEvent.adjustsWidthToFitText = YES;
        settingEvent.maxWidth = [UIScreen mainScreen].bounds.size.width / 3.0f;
        UIButton *button = settingEvent.customView;
        button.titleLabel.font = [UIFont systemFontOfSize:14.0f];
        CGRect frame = CGRectMake(0, 0, 22, 22);
        button.frame = frame;
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        if (!CGSizeEqualToSize(button.bounds.size, frame.size)) {
            button.frame = frame;
        }
        [button setTitleColor:[UIColor greenColor] forState:UIControlStateNormal];
        [event preventDefault];
    }else if ([kNBEvent_Scene_NavigationItem_Right_Setting_Change isEqualToString:event.eventType]){
 
    }else if ([kNBEvent_Scene_NavigationItem_Right_Setting_Click isEqualToString:event.eventType]){
        NSLog(@"-----kNBEvent_Scene_NavigationItem_Right_Setting_Click----");
        
    }else if([kNBEvent_Scene_ProgressView_Create_After isEqualToString:event.eventType]){
        // 更改进度条样式
        NBProgressViewEvent *progressEvent = (NBProgressViewEvent *)event;
        id<NBProgressViewProtocol> progressView = progressEvent.progressView;
        [progressView setProgressTintColor:[UIColor greenColor]];
        [event preventDefault];
        [event stopPropagation];
    }else if([kH5Event_Scene_NavigationBar_ChangeColor isEqualToString:event.eventType]) {
        
        // 禁止容器默认导航栏样式
        [event preventDefault];
        [event stopPropagation];
    }
}

- (int)priority
{
    return PSDPluginPriority_High +1;
}

- (void)onClickBack
{
    [DTContextGet().navigationController popViewControllerAnimated:YES];
}
@end


