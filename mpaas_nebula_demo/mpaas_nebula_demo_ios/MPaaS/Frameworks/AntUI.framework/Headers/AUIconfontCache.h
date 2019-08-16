#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_IconFont_AUIconView//程序自动生成
//
//  AUIconfontCache.h
//  AntUI
//
//  Created by 沫竹 on 2017/11/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUIconfontCache : NSObject

+ (instancetype)sharedCache;

- (void)addIcon:(UIImage *)icon
           name:(NSString *)name
       fontName:(NSString *)fontName
          width:(CGFloat)width
          color:(UIColor *)color;

- (void)addIcon:(UIImage *)icon
           name:(NSString *)name
       fontName:(NSString *)fontName
          width:(CGFloat)width
          color:(UIColor *)color
          alpha:(CGFloat)alpha;

- (UIImage *)cachedIcon:(NSString *)name
               fontName:(NSString *)fontName
                  width:(CGFloat)width
                  color:(UIColor *)color;

- (UIImage *)cachedIcon:(NSString *)name
               fontName:(NSString *)fontName
                  width:(CGFloat)width
                  color:(UIColor *)color
                  alpha:(CGFloat)alpha;

@end


#endif//程序自动生成
