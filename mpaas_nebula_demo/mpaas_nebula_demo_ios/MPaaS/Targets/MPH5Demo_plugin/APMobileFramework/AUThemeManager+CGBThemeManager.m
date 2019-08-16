//
//  AUThemeManager+CGBThemeManager.m
//  CGBCredit
//
//  Created by george on 2018/3/30.
//  Copyright © 2018年 ynet. All rights reserved.
//

#import "AUThemeManager+CGBThemeManager.h"

@implementation AUThemeManager (CGBThemeManager)


+ (NSDictionary *)au_defaultTheme_extraInfo
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    dict[TITLEBAR_BACKGROUND_COLOR] = @"COLOR(#108EE9)";             // 导航栏背景色
    dict[TITLEBAR_LINE_COLOR] = @"COLOR(#108EE9)";                            // 导航栏底部分割线或边线的颜色
    dict[TITLEBAR_TITLE_TEXTCOLOR] = @"COLOR(#ffffff)";          // 导航栏标题色
    dict[TITLEBAR_TITLE_TEXTSIZE_BOLD] = @"FONT(18)";              // 导航栏标题大小
    dict[TITLEBAR_TEXTCOLOR] = @"COLOR(#ffffff)";                  // 导航栏返回按钮颜色
    
    return dict;
}


@end
