//
//  APMVoiceRecordCallback.h
//  APMultimedia
//
//  Created by Kris Tian on 2018/10/11.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 开始录音状态
 */
typedef enum : NSUInteger {
    APMMAudioStartRecord,                       //准备录音
    APMMAudioRecording,                         //录音开始
    APMMAudioStartRecordFail,                   //录音发生错误
    APMMAudioStartInvalidFilePath,              //无效路径
    APMMAudioRecordUndefine
} APMMAudioStartRecordStatus;

/**
 结束录音状态
 */
typedef enum : NSUInteger {
    APMMAudioStopRecordError,                       //录音错误
    APMMAudioStopRecordFinish,                      //录音完成(默认自动上传)
    APMMAudioStopRecordCancel,                      //录音取消
    APMMAudioStopRecordTimerOut,                    //录制时间超过设定的最大时间而异常结束
    APMMAudioStopRecordTimeNotEnough,               //录音时间不足
    APMMAudioStopRecordUploadFail,                  //上传录音失败
    APMMAudioStopRecordUploadSuccuss,               //上传录音成功
    APMMAudioStopRecordUndefined                    //
} APMMAudioStopRecordStatus;


/**
 *  开始录音Block
 *
 *  @param status  开始录音状态
 *  @param message 音频对象(包含wav路径、时长、音频数据)
 *  @param cloudId 云ID，上传成功后会获取到该ID
 *  @param error   异常信息
 */
typedef void (^APMultiMediaAudioStartRecordHandler)(APMMAudioStartRecordStatus status, NSError* error);


/**
 *  录音计时
 *
 *  @param time
 */
typedef void (^APMultiMediaAudioRecordTime)(NSTimeInterval time);

/**
 *  结束录音Block
 *
 *  @param status  结束录音状态
 *  @param localId LocalId, 录音结束后会获取到该ID
 *  @param cloudId CloudID，上传成功后会获取到该ID
 *  @param error   异常信息
 */
typedef void (^APMultiMediaAudioStopRecordHandler)(APMMAudioStopRecordStatus status,NSString* localId,NSString* cloudId,NSError* error);

/**
 获取到frame数据的时候回调

 @param encodeData 编码后的帧数据
 @param lastFrame 是否是最后的帧
 @param error 编码失败的错误信息
 */
typedef void (^APMultiMediaAudioFrameRecordedHandler)(NSData *encodeData,BOOL lastFrame ,NSError* error);

/**
 暂停录音回调

 @param success 是否暂停成功
 */
typedef void (^APMultiMediaAudioPauseRecordHandler)(BOOL success);

/**
 恢复录音回调
 
 @param success 是否恢复录音成功
 */
typedef void (^APMultiMediaAudioResumeRecordHandler)(BOOL success);

/**
 *  Mic输入音量分贝值
 *
 *  @param power (-120 ~ -1)
 */
typedef void (^APMultiMediaAudioMicPower)(CGFloat power);

@interface APMAudioRecordCallback : NSObject

@property (nonatomic, copy) APMultiMediaAudioStartRecordHandler startRecordHandler;
@property (nonatomic, copy) APMultiMediaAudioStopRecordHandler stopRecordHandler;
@property (nonatomic, copy) APMultiMediaAudioMicPower powerHandler;
@property (nonatomic, copy) APMultiMediaAudioRecordTime recordTimeHandler;
@property (nonatomic, copy) APMultiMediaAudioFrameRecordedHandler frameRecordedHandler;
@property (nonatomic, copy) APMultiMediaAudioPauseRecordHandler pauseRecordHandler;
@property (nonatomic, copy) APMultiMediaAudioResumeRecordHandler resumeRecordHandler;

@end
