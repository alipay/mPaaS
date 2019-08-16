//
//  UIImage+Base64.h
//  APMultimedia
//
//  Created by 慎一 on 16/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (APMBase64)


+ (UIImage *)apm_imageWithBase64String:(NSString *)string;

@end
