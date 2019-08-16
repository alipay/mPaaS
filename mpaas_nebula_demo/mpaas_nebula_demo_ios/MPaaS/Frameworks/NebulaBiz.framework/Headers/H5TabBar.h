//
//  H5TabBar.h
//  NebulaBiz
//
//  Created by lyusheng on 2018/11/26.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface H5TabBar : UITabBar
@property (nonatomic,copy) void(^tabbarShouldSelectItem)(H5TabBar *tabBar,NSInteger idx, UITabBarItem *item);
@end

NS_ASSUME_NONNULL_END
