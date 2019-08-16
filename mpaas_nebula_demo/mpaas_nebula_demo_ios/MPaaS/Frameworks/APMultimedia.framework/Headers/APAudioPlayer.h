//
//  APAudioPlayer.h
//  APMultimedia
//
//  Created by Monster on 16/7/6.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APAudioSessionManager.h"

extern NSString* const kAPExtraParamsResourceUrlKey;
extern NSString* const kAPExtraParamsAudioExtraRemoteLogKey;

typedef void (^APAudioPlayerPlayCompletionBlock)(BOOL isFinished, NSError* error);

typedef enum : NSUInteger {
    APAudioPlayerStateStopped,                       // 停止
    APAudioPlayerStatePlaying,                       // 播放中
    APAudioPlayerStatePaused,                        // 暂停
    APAudioPlayerStateLoading,                            //数据加载中
} APAudioPlayerState;

@class  APAudioPlayer;
@protocol APAudioPlayerDelegate <NSObject>
@optional
/**
 *  播放器加载出错
 *
 *  @param player APAudioPlayer
 *  @param error  错误信息
 */
- (void)audioPlayer:(APAudioPlayer *)audioPlayer failedWithError:(NSError *)error;

/**
 *  播放器状态切换
 *
 *  @param state APAudioPlayerState
 */
- (void)audioPlayer:(APAudioPlayer *)audioPlayer stateChangedTo:(APAudioPlayerState)state oldStatus:(APAudioPlayerState)oldStatus;

/**
 缓冲进度

 @param audioPlayer APAudioPlayer
 @param loadedTime 缓冲时间 单位为秒
 */
- (void)audioPlayer:(APAudioPlayer *)audioPlayer loadedTime:(NSTimeInterval)loadedTime;

/**
 当前播放时间

 @param player APAudioPlayer
 @param time 当前播放时间 单位为秒
 */
- (void)audioPlayer:(APAudioPlayer *)player playedCurrentTime:(NSTimeInterval)time;

/**
 当前资源已经播放完毕

 @param player APAudioPlayer
 */
- (void)audioPlayerDidFinishToEnd:(APAudioPlayer *)player;


/**
 音频资源已经准备好播放

 @param player APAudioPlayer
 */
- (void)audioPlayerDidReadyToPlay:(APAudioPlayer *)player;

//开始播放
- (void)audioPlayerDidStartToPlay:(APAudioPlayer *)player;

//开始Seek
- (void)audioPlayerDidStartToSeek:(APAudioPlayer *)player;

//seek结束,finished代表整个seek过程是否完成，seek可能被后面的一次seek打断，而导致无法完成。
- (void)audioPlayer:(APAudioPlayer *)player didEndSeek:(BOOL)finished;

@end

@interface APAudioPlayer : NSObject

/**
 当前播放歌曲的identifier
 */
@property (nonatomic, readonly) NSString *identifier;

/**
 *  delegate
 */
@property (nonatomic, weak) id<APAudioPlayerDelegate> delegate;

/**
 下载完后是否存到缓存中 默认为YES；
 */
@property (nonatomic, assign) BOOL shouldCacheAfterDownload;


/**
 *  音频播放是否与其它的播放器混合，如果为YES时，则允许其它播放器存在，声音同时播放
 *  如果为NO，则会暂停其它播放器
 */
@property (nonatomic, assign) BOOL mixAudioWithOthers;


@property (nonatomic, assign) BOOL replayAfterPlayedToEnd;


/**
 额外的参数 只识别已经定义APRequestExtraParamKey.h中的kExtraParams* key，需要在设置[setIdentifier: business:]前设置
 */
@property (nonatomic,copy) NSDictionary *extraParams;

/**
 *  总可播时间，单位为秒
 */
@property (nonatomic, readonly,getter = getTotalDuration) NSTimeInterval totalDuration;

/**
 *  已播放时间，单位为秒
 */
@property (nonatomic, readonly,getter = getDurationWatched) NSTimeInterval durationWatch;

/**
 *  已缓冲时间，单位为秒
 */
@property (nonatomic, readonly,getter = getDurationLoaded) NSTimeInterval durationLoaded;


/* Indicates the current audio volume of the player; 0.0 means "silence all audio", 1.0 means "play at the full volume of the current item".
 
 iOS note: Do not use this property to implement a volume slider for media playback. For that purpose, use MPVolumeView, which is customizable in appearance and provides standard media playback behaviors that users expect.
 This property is most useful on iOS to control the volume of the AVPlayer relative to other audio output, not for volume control by end users. */
@property (nonatomic, assign) float volume NS_AVAILABLE(10_7, 7_0);


/**
 开始播放的时间
 */
@property (nonatomic, assign) float startTime;


@property (nonatomic, assign) BOOL autoplay;


@property (nonatomic, assign, readonly) APAudioPlayerState currentState;

/**
 是否遵循静音开关。默认值为false，打开了静音开关，也会播放
 */
@property (nonatomic,assign) BOOL obeyMuteSwitch;

/**
 播放资源是否是hls协议。默认根据url资源中是否包含m3u8字符串来判断，也可以强制设置是否是hls资源
 */
@property (nonatomic, assign, getter=isHls) BOOL hls;



/**
 *  准备播放的歌曲，只有调用play方法后才真正开始播放
 *
 *  @param songId songId  url或者djangoID
 *  @param business  业务标示
 */
- (void)setIdentifier:(NSString *)identifier business:(NSString *)business;


/**
 *  播放
 */
- (void)play;

/**
 *  暂停
 */
- (void)pause;


/**
 停止播放
 */
- (void)stop;
/**
 *  因为seek是一个过程，在seekToTime后 需要调用seekEnd 结束seek。
 *
 *  @param time CMTime
 */
- (void)seekToTime:(NSTimeInterval)time;

/**
 *  seek结束
 *
 *  @param time CMTime
 */
- (void)seekEnd;

/**
 *  用于特殊场景 如：用户退出登录
 *  时，需要退出音乐播放器并清空状态和信息
 */
- (void)clear;

@end


#pragma mark - 下面接口专门用来播放data 和上面的属性方法无关， 播放data数据 调用上面接口， 可能导致无法播放声音

@interface APAudioPlayer (NSData)

//播放相关AudioSession模式 默认：APAudioSessionModeTone(提示音等，不独占session,系统静音模式下不播放声音)
@property (nonatomic, assign) APAudioSessionMode sessionMode;

/**
 *  播放音频
 *
 *  @param data     wav数据
 *  @param complete 播放完成/错误回调
 */
- (void)playAudioData:(NSData*)data completionBlock:(APAudioPlayerPlayCompletionBlock)complete;

/**
 *  停止播放
 */
- (void)stopPlay;

@end
