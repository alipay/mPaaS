//
//  APThemeManager.h
//  APCommonUI
//
//  Created by shenmo on 10/8/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APTheme.h"

#define APDefaultTheme [APThemeManager sharedInstance].defaultTheme
#define APCurrentTheme [APThemeManager sharedInstance].currentTheme

@protocol UnableUseLoggerProtocol <NSObject>

+ (void)logger_unableUse:(NSString*)bizName subName:(NSString*)subName failCode:(NSInteger)failCode params:(NSDictionary*) params;

@end

@interface APThemeManager : NSObject <UnableUseLoggerProtocol>

@property (nonatomic, strong, readonly) APTheme* defaultTheme;
@property (nonatomic, strong, readonly) APTheme* currentTheme;

+ (instancetype)sharedInstance;

/**
 *  加载主题，并作为Current Theme
 *
 *  @param path 主题.bundle的资源路径
 */
- (void)loadThemeWithPath:(NSString*)path;


@end
