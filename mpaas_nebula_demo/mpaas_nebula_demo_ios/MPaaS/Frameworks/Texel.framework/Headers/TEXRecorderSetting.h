//
//  TEXRecorderSetting.h
//  Texel
//
//  Created by Cloud on 2017/3/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    TEXRecorderPresetSize360P, // 手机能够支持的最接近360 x 640的尺寸
    TEXRecorderPresetSize540P, // 手机能够支持的最接近540 x 960的尺寸
    TEXRecorderPresetSize720P  // 手机能够支持的最接近720 x 1280的尺寸
} TEXRecorderPresetSize;

typedef enum : NSUInteger {
    TEXRecorderPresetAudioSampleRateDefault,  // 默认与当前AVAudioSession的采样率一致
    TEXRecorderPresetAudioSampleRate16000,    // 16KHz
    TEXRecorderPresetAudioSampleRate44100,    // 44.1KHz
} TEXRecorderPresetAudioSampleRate;

@interface TEXRecorderSetting : NSObject

@property (nonatomic, assign, readonly) CGSize size; /// 默认为720x1280，宽度保证为16的倍数
@property (nonatomic, assign, readonly) int bitrate; /// 默认为2.5 * 1000 * 1000bps
@property (nonatomic, assign, readonly) int fps;     /// 默认为30fps
@property (nonatomic, assign, readonly) int audioSampleRate; /// 默认为[[AVAudioSession sharedInstance] sampleRate]

/**
 *  默认的设置
 *
 *  @return 默认的设置
 */
+ (instancetype)defaultSetting;

/**
 *  自定义的录制配置
 *
 *  @param  size    输出的视频预置大小
 *  @param  bitrate 比特率
 *  @param  fps     帧率
 *
 *  @return 配置对象
 */
- (instancetype)initWithSize:(TEXRecorderPresetSize)size
                     bitrate:(int)bitrate
                         fps:(int)fps;

/**
 *  自定义的录制配置
 *
 *  @param  size            输出的视频预置大小
 *  @param  bitrate         比特率
 *  @param  fps             帧率
 *  @param  audioSampleRate 采样率
 *
 *  @return 配置对象
 */
- (instancetype)initWithSize:(TEXRecorderPresetSize)size
                     bitrate:(int)bitrate
                         fps:(int)fps
             audioSampleRate:(TEXRecorderPresetAudioSampleRate)audioSampleRate;

/**
 *  自定义的录制配置
 *
 *  @param  size            输出的视频预置大小
 *  @param  aspectRatio     宽高比，会影响上面的size，宽度按照上面的参数，高度根据该参数计算
 *  @param  bitrate         比特率
 *  @param  fps             帧率
 *  @param  audioSampleRate 采样率
 *
 *  @return 配置对象
 */
- (instancetype)initWithSize:(TEXRecorderPresetSize)size
                 aspectRatio:(float)aspectRatio
                     bitrate:(int)bitrate
                         fps:(int)fps
             audioSampleRate:(TEXRecorderPresetAudioSampleRate)audioSampleRate;

/**
 *  使用sharedInstance，别用init
 *
 *  @return 对象
 */
- (instancetype)init __attribute__((unavailable("init not available")));

@end
