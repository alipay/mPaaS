#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUImageDialog//程序自动生成
//
//  AUImageDialog+largeImageStyle.h
//  AntUI
//
//  Created by 莜阳 on 2017/11/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUImageDialog.h"

/**
 图片 Dialog ， 支持 UED 需求的一种特殊样式 Dialog
 *  样式：图片属于大图样式，图片高度固定为312px，关闭按钮在图片右上角
 *  关闭按钮是iconfont，在大图样式下默认白色
 */

@interface AUImageDialog (largeImageStyle)

/**
 不带按钮标题的初始化方法。
 
 @param image 图片
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithLargeImage:(UIImage *)image
                             title:(NSString *)title
                           message:(NSString *)message
                          delegate:(id<AUDialogDelegate>)delegate;

/**
 带下载链接的
 
 @param imageUrl 图片链接
 @param placeholder 占位图片
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @return AUImageDialog 实例
 */
- (instancetype)initWithLargeImageUrl:(NSString *)imageUrl
                          placeholder:(UIImage *)placeholder
                                title:(NSString *)title
                              message:(NSString *)message
                             delegate:(id<AUDialogDelegate>)delegate;

/**
 不带按钮标题的初始化方法。
 
 @param image 图片
 @param customView 自定义内容区域视图
 @return AUImageDialog 实例
 */
- (instancetype)initWithLargeImage:(UIImage *)image customView:(UIView *)customView;

/**
 * 设置右上角关闭按钮的色值，默认白色
 */
- (void)resetCloseIconColor:(UIColor *)color;


@end

#endif//程序自动生成
