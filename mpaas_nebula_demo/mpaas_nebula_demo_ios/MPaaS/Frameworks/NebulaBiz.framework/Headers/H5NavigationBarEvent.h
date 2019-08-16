//
//  H5NavigationBarEvent.h
//  NebulaBiz
//
//  Created by theone on 16/5/23.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface H5NavigationBarEvent : PSDEvent
@property(nonatomic, assign) BOOL shouldSetDefaultColor;
+ (instancetype)changeNavigationBarColorEvent:(BOOL)setDefaultColor;

@property(nonatomic, assign) BOOL isLightTheme;
+ (instancetype)navigationBarItemThemeEvent:(BOOL)isLightTheme;
@end
