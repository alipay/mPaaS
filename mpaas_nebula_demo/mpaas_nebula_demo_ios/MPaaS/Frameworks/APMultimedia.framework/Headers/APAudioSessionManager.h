//
//  APAudioSessionManager.h
//  APMultimedia
//
//  Created by Cloud on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <APMUtils/APMAudioSessionManager.h>

typedef NS_OPTIONS (NSUInteger, APAudioSessionMode) {
    APAudioSessionModeAudioRecorder,            ///< 音频录制模式
    APAudioSessionModeAudioPlayerWithReceiver,  ///< 音频播放模式，听筒播放
    APAudioSessionModeAudioPlayerWithSpeaker,   ///< 音频播放模式，扬声器播放
    APAudioSessionModeVideoRecorder,            ///< 视频录制模式
    APAudioSessionModeVideoPlayerMuted,         ///< 视频播放模式，静音
    APAudioSessionModeVideoPlayer,              ///< 视频播放模式，有声
    APAudioSessionModeTone,                     ///< 提示音等，不独占session,系统静音模式下不播放声音
    APAudioSessionModeBackgroundAudioRecorder,  ///< 后台音频录制模式
    APAudioSessionModeMixWithOthers,            ///< 当前session中 混合播放
    APAudioSessionModeSoloTone,                 ///< 提示音等，独占session,系统静音模式下不播放声音
    APAudioSessionModePlayAndRecord,            ///< 边播放边录制
    APAudioSessionModeMixWithOthersAndAndObeyMuteSwitch,            ///< 如果当前session已经有音频播放，则混合，否则直接播放,系统静音模式下不播放声音
};

@protocol APAudioSessionManagerDelegate <APMAudioSessionManagerDelegate>
@end

@interface APAudioSessionManager : NSObject

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
- (BOOL)requestBecomeActive:(id<APAudioSessionManagerDelegate>)object mode:(APAudioSessionMode)mode;

/**
 *  请求注销音频模式
 *
 *  @param  object    请求的对象
 */
- (void)requestResignActive:(id<APAudioSessionManagerDelegate>)object;

/**
 *  当前是否有第三方音乐在播放
 *
 *  @return YES : NO
 */
- (BOOL)isOtherAudioPlaying;

/**
   系统控件UIImagePickerControoler在录制视频的时候，如果预览或者重拍会导致系统中断通知，会打乱sessionManager的pause／resume流程，需要特使处理。
 */
@property (nonatomic, assign, getter = isShowImagePickerController) BOOL showImagePickerController;

@end
