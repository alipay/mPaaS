#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUImageView//程序自动生成
//
//  AUImageView.h
//  AntUI
//
//  Created by maizhelun on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


AntUI_BaseComponent
//AUIImageView 是系统类，避免审核冲突问题
@interface AUIImageView : UIImageView

@end



@interface AUIImageView (AULottie)

// 返回image的大小（如果是lottie，返回的是lottie的view的大小）
@property (nonatomic, readonly) CGSize imageSize;


/**
 用lottie初始化imageview（异步加载lottie）
 
 @param lottiePath lottie的文件路径
 @param placeholder lottie初始化失败时的占位图（极低概率）
 @return AUImageView实例
 */
- (instancetype)initWithLottiePath:(NSString *)lottiePath
                       placeholder:(UIImage *)placeholder
              lottieLoadcompletion:(void(^)(AUIImageView *imageView, NSError *error))completion;

/**
 用lottie初始化imageview（同步加载lottie）

 @param lottiePath lottie的文件路径
 @return AUImageView实例
 */
- (instancetype)initWithLottiePath:(NSString *)lottiePath;


/**
 播放lottie动画
 */
- (void)startAnimating;


/**
 停止lottie动画
 */
- (void)stopAnimating;

@end



#endif//程序自动生成
