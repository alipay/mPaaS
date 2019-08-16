//
//  NBFileManager.h
//  Nebula
//
//  Created by chenwenhong on 15/9/21.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBFileManager : NSObject

+ (NSString *)jsPerformanceFileContentString;

+ (NSString *)jsGeoFileContentString;

+ (NSString *)jsBridgeFileContentString;

+ (NSString *)jsShareFileContentString;

+ (NSString *)errorHtmlFileContentString;

+ (void)registerImage:(UIImage *)image forName:(NSString *)name;

+ (UIImage *)cachedImageNamed:(NSString *)named;

@end
