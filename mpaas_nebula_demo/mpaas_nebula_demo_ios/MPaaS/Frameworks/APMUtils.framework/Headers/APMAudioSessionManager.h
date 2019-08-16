//
//  APAudioSessionManager.h
//  APMultimedia
//
//  Created by Cloud on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  静音开关改变回调
 *
 *  @param  mute 是否静音
 */
typedef void(^APMAudioSessionMuteSwitchBlock)(BOOL mute);

typedef NS_OPTIONS (NSUInteger, APMAudioSessionMode) {
    APMAudioSessionModeAudioRecorder,            ///< 音频录制模式
    APMAudioSessionModeAudioPlayerWithReceiver,  ///< 音频播放模式，听筒播放
    APMAudioSessionModeAudioPlayerWithSpeaker,   ///< 音频播放模式，扬声器播放
    APMAudioSessionModeVideoRecorder,            ///< 视频录制模式
    APMAudioSessionModeVideoPlayerMuted,         ///< 视频播放模式，静音
    APMAudioSessionModeVideoPlayer,              ///< 视频播放模式，有声
    APMAudioSessionModeTone,                     ///< 提示音等，不独占session,系统静音模式下不播放声音
    APMAudioSessionModeBackgroundAudioRecorder,  ///< 后台音频录制模式
    APMAudioSessionModeMixWithOthers,            ///< 如果当前session已经有音频播放，则混合，否则直接播放
    APMAudioSessionModeSoloTone,                 ///< 到账提示音等，独占session,系统静音模式下不播放声音
    APMAudioSessionModePlayAndRecord,            ///< 边播放边录制
    APMAudioSessionModeMixWithOthersAndAndObeyMuteSwitch,            ///< 如果当前session已经有音频播放，则混合，否则直接播放,系统静音模式下不播放声音
};

@class APMAudioSessionManager;
@protocol APMAudioSessionManagerDelegate
@optional
/**
 *  收到其他音频抢占的通知，在通知前需要暂停你目前的音频服务，比如：
 *  如果收到其他player抢占的通知，需要先停止你目前音频的播放
 *
 *  @param  manager   注册时的audiosession对象
 */
- (void)audioSessionManagerReceivePauseCommand:(APMAudioSessionManager *)manager;

/**
 *  已经通知完毕，直接恢复你之前的状态即可
 *
 *  @param  manager   注册时的audiosession对象
 */
- (void)audioSessionManagerReceiveResumeCommand:(APMAudioSessionManager *)manager;

@end

@interface APMAudioSessionManager : NSObject

/**
 *  共享实例
 */
+ (instancetype)sharedManager;

/**
 *  请求激活音频模式
 *
 *  @param  object    请求的对象
 *  @param  mode      音频服务模式
 *
 *  @return 是否成功，如果不成功，不可执行后续操作
 */
- (BOOL)requestBecomeActive:(id<APMAudioSessionManagerDelegate>)object mode:(APMAudioSessionMode)mode;

/**
 *  请求注销音频模式
 *
 *  @param  object    请求的对象
 */
- (void)requestResignActive:(id<APMAudioSessionManagerDelegate>)object;

/**
 *  当前是否有第三方音乐在播放
 *
 *  @return YES : NO
 */
- (BOOL)isOtherAudioPlaying;

/**
 *  开始检测静音开关
 *
 *  @param  block    静音开关变换时的回调
 */
- (void)startDetectingMuteSwitch:(APMAudioSessionMuteSwitchBlock)block;

/**
 *  结束检测静音开关
 */
- (void)stopDetectingMuteSwitch;

/**
 *  当前是否静音，只有调用了startDetectingMuteSwith并得到回调之后，才能得到正确的值
 *
 *  @return 是否静音 静音是YES, 非静音是NO
 */
- (BOOL)isMute;

@end
