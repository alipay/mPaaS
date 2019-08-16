//
//  APAudioRecordSetting.h
//  APMultimedia
//
//  Created by Kris Tian on 2018/8/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreAudio/CoreAudioTypes.h>

typedef NS_ENUM(NSUInteger, APAudioFormat) {
    APAudioFormatSilk, //Silk编码
    APAudioFormatAAC, // AAC编码
    APAudioFormatMP3, //MP3编码，暂时不支持
};

typedef NS_ENUM(NSUInteger, APAudioChannelLayout) {
    APAudioChannelLayoutMono,  //单声道
    APAudioChannelLayoutStereo, // 双声道
};


extern NSString * const APAudioSourceAuto;
extern NSString * const APAudioSourceBuildInMic;
extern NSString * const APAudioSourceHeadsetMic;





@interface APAudioRecordSetting : NSObject

/**
 录音最大时长，单位秒，默认60s，大于这个值会自动结束录音. 最大3分钟
 */
@property (nonatomic, assign) NSUInteger maxDuration;

/**
 录音最小时长，单位秒，默认1s，小于这个值会录音失败
 */
@property (nonatomic, assign) float minDuration;

/**
 录音采样率16000
 */
@property (nonatomic, assign) NSUInteger sampleRate;

/**
 编码码率32000
 */
@property (nonatomic, assign) NSUInteger encodeBitRate;

/**
 录音声道，单声道或者双声道，默认是APAudioChannelLayoutMono 单声道
 */
@property (nonatomic, assign) APAudioChannelLayout audioChannelLayout;

/**
 录音格式，当前支持AAC和Silk, AAC专门为小程序准备的，非小程序请用Silk编码，默认是APAudioFormatSilk
 */
@property (nonatomic, assign) APAudioFormat audioFormat;


/**
 录音来源，来源mic还是headSet，默认是APAudioSourceAuto,必须为APAudioSourceAuto，APAudioSourceBuildInMic，APAudioSourceHeadsetMic其中的一个
 */
@property (nonatomic, copy) NSString *audioSource;

/**
 指定帧大小，单位 KB，默认值0, 范围在0-2048之间。传入frameSize后，每录制指定帧大小的内容后，会回调录制的文件内容,不指定则按照默认值回调,仅对mp3有效。当值为0的时候 每0.2s数据当作一个frame
 */
@property (nonatomic, assign) NSUInteger frameSize;

/**
 是否支持边录边传，只对Silk编码生效。
 */
@property (nonatomic, assign) BOOL enableUploadWhileRecording;

- (instancetype)init;


/**
 AAC默认采样设置。采样率44100 码率192000，单声道
 @return
 */
+ (instancetype)defaultAACAudioRecordSetting;


/**
 当前有效的音频输入源

 @return 当前有效的音频输入源
 */
+ (NSArray <NSString *> *)availableAudioSources;

/**
 检查audioRecordSetting是否有效，无效的话返回错误信息

 @param error 错误信息
 @return 是否有效
 */
- (BOOL)isValidWithError:(NSError **)error;

/**
 返回声道的数量

 @return 返回声道的数量，1或者2，单声道为1，双声道为2
 */
- (int)numberOfChannels;

/**
 根据当前的setting，返回pcm格式描述

 @return pcm格式描述，AudioStreamBasicDescription对象
 */
- (AudioStreamBasicDescription)pcmFormatDescriptionWithCurrentSetting;


#pragma mark - 码率和采样率匹配

/**
 内部做适当的调整。
 */
- (void)adjustRecordSetting;

/**
 有效的采样率数组,根据录音格式，获取有效的采样率数组，录音组件支持固定几种采样率。
 @return 有效的采样率数组
 */
+ (NSArray *)availableSampleRatesWithAudioFormat:(APAudioFormat)audioFormat;

/**
 特定格式和采样率情况下，最大的码率

 @param sampleRate 采样率
 @return 最大的码率
 */
+ (NSUInteger)maxEncodeBitRateWithSampleRate:(NSUInteger)sampleRate audioFormat:(APAudioFormat)audioFormat;

/**
 特定格式和采样率情况下，最小的码率

 @param sampleRate 采样率
 @return 最小的码率
 */
+ (NSUInteger)minEncodeBitRateWithSampleRate:(NSUInteger)sampleRate audioFormat:(APAudioFormat)audioFormat;

@end
