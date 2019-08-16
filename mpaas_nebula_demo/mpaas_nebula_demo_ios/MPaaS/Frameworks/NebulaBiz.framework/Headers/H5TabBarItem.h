//
//  H5TabBarItem.h
//  NebulaBiz
//
//  Created by Glance on 17/2/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface H5TabBarItem : UITabBarItem

@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, assign) BOOL selectedFromApi;
@property(nonatomic, assign) BOOL cancelOrigIcon;

- (instancetype)initWithTitle:(NSString *)title
                   identifier:(NSString *)identifier
                        color:(NSNumber *)color
                selectedColor:(NSNumber *)selectedColor;

@end


@interface UITabBar(smallRedDot)

@property(nonatomic, assign) CGFloat nbZeroBadgeSize;
@property(nonatomic, strong) UIColor *nbBadgeColor;

- (void)setBadgeValue:(NSString *)badgeValue atTabBarItem:(H5TabBarItem *)item;

@end
