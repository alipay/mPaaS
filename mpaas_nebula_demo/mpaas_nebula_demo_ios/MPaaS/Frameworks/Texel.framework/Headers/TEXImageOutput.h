//
//  TEXImageOutput.h
//  Texel
//
//  Created by feihu on 2018/3/1.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
#import <UIKit/UIKit.h>

@class TEXImageOutput;
@protocol TEXImageOutputDelegate <NSObject>
// 有数据更新，可以在这个回调中调用getCurrentFrame的方法来获取当前帧
- (void)imageOutputDidReceiveNewFrame:(TEXImageOutput *)imageOutput;
@end

@interface TEXImageOutput : NSObject <TEXInput>
@property (nonatomic, weak) id<TEXImageOutputDelegate> delegate;
@property (nonatomic, assign) CGSize inputSize;
@property (nonatomic, assign) AVCaptureVideoOrientation orientation;
// 当手机方向与UI方向一致时的输出视频尺寸，以像素为单位
// 当视频录制考虑手机的姿态时，真实的视频大小为该大小+手机方向共同决定，
// 手机方向相对于UI方向不一致时，真实输出大小会做出调整
@property (nonatomic, assign) CGSize outputSizeInPixels;

- (UIImage *)getCurrentFrame;

@end
