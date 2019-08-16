//
//  UIImageView+AUTheme.h
//  AntUI
//
//  Created by 莜阳 on 2018/1/8.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

//typedef void (^AUImageProgress)(double percentage,long long partialBytes,long long totalBytes);
//typedef void (^AUImageCompletion)(UIImage *image, NSError *error);
//
//@interface AUImageRequest : NSObject
//
//@property (nonatomic, strong) NSString *cloudId;
//@property (nonatomic, strong) NSString *business;
//@property (nonatomic, assign) CGSize zoomSize;
//@property (nonatomic, assign) CGSize originalSize;
//@property (nonatomic, weak)   AUImageProgress progress;
//
//@end


@interface UIImageView  (AUTheme)

@property (nonatomic, strong) NSString *curIdentify;

@property (nonatomic, assign) BOOL curIdentifyComplete; // 标记当前正在下载的URL是否成功完成下载

@property (nonatomic, assign) BOOL curIdentifySuccess; // 下载成功

/* 换肤支持图片URL
 * @param request 对应多媒体的 APImageRequest 对象
 * @param 根据key在主题资源中查找对应值，如果找不到则使用defaultURL对应的image
 */
- (UIImage *)au_bindImageWithKey:(NSString *)key
                        inBundle:(NSString *)bundle
               defaultIdentifier:(NSString *)defaultIdentifier
                         request:(id)request; // 默认的URL

// 内部方法
+ (NSDictionary *)defaultDicByKey:(NSString *)key viewInstant:(UIImageView *)viewInstant;
// 内部方法下载结束更新内存数据
+ (void)updateViewThemeResult:(NSString *)key
                  viewInstant:(UIImageView *)viewInstant
                    externDic:(NSDictionary *)externDic;

@end
