//
//  UIImage+AntImageRemote.h
//  AntUI
//
//  Created by 莜阳 on 2018/5/16.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

/*
 * 支持在线配置图片资源，防止本地误删操作
 * 远端图片通过configService配置，配置格式如下：以本地name为key，value为在线URL地址
 * { "APCommonUI.bundle/AP_Search" : "https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png" }
 */

@interface UIImage (AntImageRemote)

+ (NSString *)aui_getRemoteURLByName:(NSString *)name;
+ (UIImage *)aui_getDownloadRemoteImage:(NSString *)imageUrl;

@end
