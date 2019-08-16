//
//  APLanguageBundleLoader.h
//  APLanguage
//
//  Created by Jason Kaer on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APLanguageBundleLoader : NSObject

+ (APLanguageBundleLoader *)sharedLoader;

+ (NSBundle *)mainLanguageBundle;

+ (NSBundle *)languageBundleForName:(NSString *)bundleName;

- (NSBundle *)languageBundleForName:(NSString *)bundleName;

@end

