//
//  DTNavigationController.h
//  APMobileFramework
//
//  Created by Wanlei on 14-4-16.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "APBaseNavigationController.h"

// 注意：不要直接使用这个类作为NavigationController，使用它在页面消失的时候对应的App不会自动退出问题。
// 如果有App维度，直接使用startApp launchMode选择present方式，否则可以使用DFNavigationController。
@interface DTNavigationController : APBaseNavigationController

@end
