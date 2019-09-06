//
//  MPJsApiHandler4TitleView.m
//  MyH5Application
//
//  Created by evan.lxl on 2019/8/23.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import "MPJsApiHandler4TitleView.h"

@implementation MPJsApiHandler4TitleView

- (void)pluginDidLoad
{
    self.scope = kPSDScope_Scene;
    
    // -- 返回区域
    [self.target addEventListener:kNBEvent_Scene_NavigationItem_Left_Back_Create_Before withListener:self useCapture:NO];
    
    [super pluginDidLoad];
}

- (void)handleEvent:(PSDEvent *)event
{
    [super handleEvent:event];
    
    if ([kNBEvent_Scene_NavigationItem_Left_Back_Create_Before isEqualToString:event.eventType]) {
        // 在默认返回按钮基础上，修改样式
        NSArray *leftBarButtonItems = event.context.currentViewController.navigationItem.leftBarButtonItems;
        if ([leftBarButtonItems count] == 1) {
            if (leftBarButtonItems[0] && [leftBarButtonItems[0] isKindOfClass:[AUBarButtonItem class]]) {
                // 在默认返回按钮基础上，修改返回箭头和文案颜色
                AUBarButtonItem *backItem = leftBarButtonItems[0];
                backItem.backButtonColor = [UIColor redColor];
                backItem.titleColor = [UIColor redColor];
            }
        }
        [event preventDefault];
        [event stopPropagation];
    }
}

- (int)priority
{
    return PSDPluginPriority_High;
}

@end
