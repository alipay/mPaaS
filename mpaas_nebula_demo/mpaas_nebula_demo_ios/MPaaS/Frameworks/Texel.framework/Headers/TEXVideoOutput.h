//
//  TEXVideoOutput.h
//  Texel
//
//  Created by Cloud on 2017/4/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
#import <AVFoundation/AVFoundation.h>

// 录制音频的模式
typedef enum : NSUInteger {
    TEXRecorderAudioSourceNone = 0,       // 不录制任何声音
    TEXRecorderAudioSourceMic = 1,        // 录制麦克风的声音
} TEXRecorderAudioSource;

@class TEXVideoOutput;
@protocol TEXVideoOutputDelegate <NSObject>

- (void)videoOutputStarted:(TEXVideoOutput *)videoOutput;
- (void)videoOutput:(TEXVideoOutput *)videoOutput didFailWithError:(NSError *)error;
- (void)videoOutputComplete:(TEXVideoOutput *)videoOutput;
- (void)videoOutput:(TEXVideoOutput *)videoOutput snapshot:(UIImage *)image;

@end

@interface TEXVideoOutput : NSObject <TEXInput>

@property (nonatomic, assign) BOOL useDeviceOrientation; // 根据手机的方向来处理调整输出的方向
@property (nonatomic, assign) AVCaptureVideoOrientation orientation; 
@property (nonatomic, copy)   NSString *outputPath; // 视频生成路径
@property (nonatomic, strong) UIImage *thumbnail; // 视频首帧图
@property (nonatomic, weak)   id<TEXVideoOutputDelegate> delegate;
// 当手机方向与UI方向一致时的输出视频尺寸，以像素为单位
// 当视频录制考虑手机的姿态时，真实的视频大小为该大小+手机方向共同决定，
// 手机方向相对于UI方向不一致时，真实输出大小会做出调整
@property (nonatomic, assign) CGSize outputSizeInPixels;
@property (nonatomic, assign) int bitrate;
@property (nonatomic, assign) int fps;
@property (nonatomic, assign) int audioSampleRate; // 仅仅针对吐出来的buffer数据有效，对录制结果无效
@property (nonatomic, assign) TEXRecorderAudioSource audioSource; // 声音源

- (void)startRecording;
- (void)cancelRecording;
- (void)stopRecording;
- (void)snapshot;

@end
