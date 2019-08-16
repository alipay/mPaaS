//
//  UIImage+AntUIPatch.h
//  AntUI
//
//  Created by 沫竹 on 2017/12/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

void imageToIconfont(NSString *imageName, NSString *iconName, CGFloat width, int rgb);


@interface UIImage (AntUIPatch)

+(UIImage *)au_defaultAPCommonUIIcon:(NSString *)imageName;

+(UIImage *)au_getAPCommonUIResource:(NSString *)imageName;

@end

#define image2Iconfont(imageName, iconName, width, rgb) imageToIconfont(imageName,iconName,width,rgb)
