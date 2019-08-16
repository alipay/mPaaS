//
//  APVideoPlayer.h
//  APMultimedia
//
//  Created by Cloud on 15/5/11.
//  Copyright (c) 2015年 alipay. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

#import "APVideoManager.h"

#pragma mark - 视频类型

typedef enum : NSUInteger {
    APVideoPlayerVideoTypeSmall,                //小视频
    APVideoPlayerVideoTypePhotoAlbum,           //相册视频
} APVideoPlayerVideoType;

#pragma mark - 状态定义

// 小视频播放器状态
typedef enum : NSUInteger {
    APVideoPlayerIDNotSet,                      // 视频id未设置
    APVideoPlayerThumbnailLoadFailed,           // 缩略图加载失败
    APVideoPlayerVideoNotExist,                 // 视频缓存不存在
    APVideoPlayerUndefinedError,                // 未知错误
} APVideoPlayerStatus;

// 小视频播放状态
typedef enum : NSUInteger {
    APVideoPlayerStopped,                       // 停止
    APVideoPlayerPlaying,                       // 播放中
    APVideoPlayerPaused,                         // 暂停
    APVideoPlayerLoading,                        //视频加载中，只有APVideoPlayerModeLoadVideoLocalAndNetwork mode下作用
} APVideoPlayerState;

// 视频画面填充模式
typedef enum : NSUInteger {
    APVideoPlayerFillingModeAuto,               // 自动模式，对于小视频：视频方向与view长宽一致时为fill模式；不一致时为fit模式
                                                // 对于大视频：始终采用fit的方式
    APVideoPlayerFillingModeFill,               // fill，会填满画面，可能会撑出
    APVideoPlayerFillingModeFit                 // fit
} APVideoPlayerFillingMode;

typedef NS_ENUM(NSInteger, APVideoPlayerLoadMode) {
    APVideoPlayerLoadModeLocal, //只从本地缓存加载资源
    APVideoPlayerLoadModeLocalAndNetwork //如果缓存有则直接读取缓存，如果没有则从网络加载资源，边下边播。
};

// 视频渲染特效
typedef NS_OPTIONS(NSUInteger, APVideoPlayerRenderEffect) {
    APVideoPlayerRenderEffectNone        = 0,       // 原始
    APVideoPlayerRenderEffectTransparent = 1 << 0,  // 透明视频效果，需要播放透明视频的id
};

#pragma mark - 视频播放器事件代理

@class APVideoPlayer;

/**
 *   视频播放器事件代理
 */
@protocol APVideoPlayerDelegate <NSObject>
@optional

- (void)videoPlayer:(APVideoPlayer *)player failedWithError:(NSError *)error;

//开始播放
- (void)videoPlayerDidStartToPlay:(APVideoPlayer *)player;

//当前播放时长，单位为秒，回调间隔默认为0.5s，可通过durationWatchedInterval设置
- (void)videoPlayer:(APVideoPlayer *)player playedCurrentTime:(NSTimeInterval)time;

//整个视频播放完成
- (void)videoPlayerDidFinishToEnd:(APVideoPlayer *)player;

// 视频状态变化
- (void)videoPlayerStateChangedTo:(APVideoPlayerState)newState oldStatus:(APVideoPlayerState)oldState;

/**
 视频播放器已经准备好 可以立即播放画面
 @param player 当前的APVideoPlayer对象
 */
- (void)videoPlayerDidReadyToPlay:(APVideoPlayer *)player;

// 缓冲进度
- (void)videoPlayer:(APVideoPlayer *)player loadedTime:(NSTimeInterval)time;


//开始Seek
- (void)videoPlayerDidStartToSeek:(APVideoPlayer *)player;

//seek结束,finished代表整个seek过程是否完成，seek可能被后面的一次seek打断，而导致无法完成。
- (void)videoPlayer:(APVideoPlayer *)player didEndSeek:(BOOL)finished;

@end

#pragma mark - 小视频播放器控件/相册视频播放器控件

/**
 *   小视频播放器控件
 */
@interface APVideoPlayer : UIView

#pragma mark - 属性
//默认只加载本地缓存中的资源，如果要下载网络资源，使用initWithFrame:loadMode:方法，并设置loadMode为APVideoPlayerModeLoadVideoLocalAndNetwork
- (instancetype)initWithFrame:(CGRect)frame;

- (instancetype)initWithFrame:(CGRect)frame loadMode:(APVideoPlayerLoadMode)loadMode;
/**
 *  播放器播放视频的类型，(小视频/相册视频)，默认是小视频
 */
@property (nonatomic, assign) APVideoPlayerVideoType videoType;

/**
 *  静音属性，为YES时，表示静音，否则未静音。默认是静音
 */
@property (nonatomic, assign, getter = isMuted) BOOL muted;

/**
 *  播放完成后是否重播放，默认为NO
 */
@property (nonatomic, assign) BOOL replayAfterPlayedToEnd;

/**
 *  在缩略图下载下来之前的占位图像
 */
@property (nonatomic, strong) UIImage *placeHolderImage;

/**
 *  播放器当前的缩略图view
 */
@property (nonatomic, strong, readonly) UIImageView *thumbnailView;

/**
 *  delegate
 */
@property (nonatomic, weak) id<APVideoPlayerDelegate> delegate;


/**
 *  当前UI的方向，小视频的填充方式会根据这个方向来决定
 */
@property (nonatomic, assign) UIInterfaceOrientation currentInterfaceOrientation;

/**
 *  视频的填充模式，默认是自动APVideoPlayerFillingModeAuto
 */
@property (nonatomic, assign) APVideoPlayerFillingMode fillingMode;

/**
 *  音频播放是否与其它的播放器混合，如果为YES时，则允许其它播放器存在，声音同时播放
 *  如果为NO，则会暂停其它播放器
 */
@property (nonatomic, assign) BOOL mixAudioWithOthers;

/* Indicates whether the player allows switching to "external playback" mode. The default value is YES. */
@property (nonatomic, assign) BOOL allowsExternalPlayback;

/**
 *  视频播放的特效，传入的identifier必须是符合透明视频制作要求的视频。默认为APVideoPlayerRenderEffectNone
 */
@property (nonatomic, assign) APVideoPlayerRenderEffect renderEffect;

/* indicates the natural dimensions of the media data referenced by the video track as a CGSize, the value is the natural dimensions if the play item is ready to play, otherwise the value is CGSizeZero */
@property (nonatomic, readonly) CGSize naturalSize;
/**
 *  当前已播放时间，单位为秒
 */
@property (nonatomic, readonly,getter = getDurationWatched) NSTimeInterval durationWatched;

/**
 *  通过进度回调播放当前播放时长的间隔，单位为秒，默认为0.5s
 *  注意：必须在播放前设置才有用
 */
@property (nonatomic, assign, getter = getDurationWatchedInterval) NSTimeInterval durationWatchedInterval;

/**
 *  总可播时间，单位为秒
 */
@property (nonatomic, readonly,getter = getTotalDuration) NSTimeInterval totalDuration;

/**
 *  已缓冲时间，单位为秒
 */
@property (nonatomic, readonly,getter = getDurationLoaded) NSTimeInterval durationLoaded;


/* Indicates the current audio volume of the player; 0.0 means "silence all audio", 1.0 means "play at the full volume of the current item".
 
 iOS note: Do not use this property to implement a volume slider for media playback. For that purpose, use MPVolumeView, which is customizable in appearance and provides standard media playback behaviors that users expect.
 This property is most useful on iOS to control the volume of the AVPlayer relative to other audio output, not for volume control by end users. */
@property (nonatomic) float volume NS_AVAILABLE(10_7, 7_0);


/*!
 @property        rate
 @abstract        Indicates the desired rate of playback; 0.0 means "paused", 1.0 indicates a desire to play at the natural rate of the current item.
 @discussion
 Setting the value of rate to 0.0 pauses playback, causing the value of timeControlStatus to change to AVPlayerTimeControlStatusPaused.
 Setting the rate to a non-zero value causes the value of timeControlStatus to become either AVPlayerTimeControlStatusWaitingToPlayAtSpecifiedRate or AVPlayerTimeControlStatusPlaying, depending on whether sufficient media data has been buffered for playback to occur and whether the player's default behavior of waiting in order to minimize stalling is permitted. See discussion of AVPlayerTimeControlStatus for more details.
 
 AVPlayer can reset the desired rate to 0.0 when a change in overall state requires playback to be halted, such as when an interruption occurs on iOS, as announced by AVAudioSession, or when the playback buffer becomes empty and playback stalls while automaticallyWaitsToMinimizeStalling is NO.
 
 The effective rate of playback may differ from the desired rate even while timeControlStatus is AVPlayerTimeControlStatusPlaying, if the processing algorithm in use for managing audio pitch requires quantization of playback rate. For information about quantization of rates for audio processing, see AVAudioProcessingSettings.h. You can always obtain the effective rate of playback from the currentItem's timebase; see the timebase property of AVPlayerItem.
 */
@property (nonatomic, assign) float rate;

/**
 开始播放的时间
 */
@property (nonatomic, assign) float startTime;

@property (nonatomic, assign, getter=isHls) BOOL hls;

@property (nonatomic, assign, readonly) APVideoPlayerState currentState;



#pragma mark - 网络资源

/**
 *  从网络下载资源后 是否缓存在本地 默认为YES
 */
@property (nonatomic, assign) BOOL shouldCacheAfterDownload;

/**
 对于identifier为cloud ID的情况，默认使用cloudID去组装成url去获取网络资源。
 但有些场景，业务同一cloudID对应的不同资源访问url，此时url设置该字段，即如果指定了resourceUrl，则使用resourceUrl取获取资源，使用cloudid取存/取缓存。
 */
@property (nonatomic,copy) NSString *resourceUrl;


/**
 需要设置identifier之后设置
 */
@property (nonatomic, copy) NSString *customRemoteLogInfo;

#pragma mark - 方法

/**
 *  设置video id，可以为localId或cloudId 或者url
 *
 *  @param identifier   video的id
 *  @param business     业务存储标识
 */
- (void)setIdentifier:(NSString *)identifier business:(NSString *)business;

/**
 *  重新尝试加载缩略图
 *  在加载缩略图失败时调用
 */
- (void)retryLoadingThumbnail;

/**
 *  取消加载视频
 */
- (void)cancelLoading;

/**
 *  开始播放
 */
- (void)play;

/**
 *  停止播放
 */
- (void)stop;

/**
 *  暂停
 */
- (void)pause;

/**
 *  清理播放器，一旦调用，后面便无法使用
 */
- (void)clean;

/**
 *  是否正在播放
 *
 *  @return BOOL
 */
- (BOOL)isPlaying;

/**
 *  seek到某一时间
 *
 *  @param  time        NSTimeInterval，单位为秒
 *
 *  @return seek的时间点字串 例如：02:32
 */
- (NSString*)seekToTime:(NSTimeInterval)time;

/**
 *  seek结束 (用于后开始播放)
 */
- (void)seekEnd;

/**
 *  获取当前帧
 *
 *  @return 当前帧数据，调用方自行释放。如果为空表示可能没有更新
 */
- (CVPixelBufferRef)pixelBufferForCurrentFrame;
@end
