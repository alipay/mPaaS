//
//  UIImage+HEVC.h
//  APMultimedia
//
//  Created by 慎一 on 2017/5/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (HEVC)

+ (UIImage *)apm_imageWithHevcData:(NSData *)data;

+ (unsigned long)apm_currentAHPVersion;

@end
