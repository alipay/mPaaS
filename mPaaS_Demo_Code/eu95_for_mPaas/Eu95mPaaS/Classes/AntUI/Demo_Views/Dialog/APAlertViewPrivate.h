//
//  APAlertViewPrivate.h
//  APCommonUI
//
//  Created by 逆仞 on 14-4-22.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


#import "APAlertViewBase.h"
#import "APAlertViewManager.h"

@interface APAlertViewBase()
@property(nonatomic, weak)APAlertViewManager *dtAlertManager;
@property(nonatomic, readwrite, strong) NSMutableArray *callbacks;
@end
