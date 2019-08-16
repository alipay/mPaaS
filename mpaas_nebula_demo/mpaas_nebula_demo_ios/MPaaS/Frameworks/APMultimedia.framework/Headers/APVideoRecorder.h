//
//  APVideoRecorder.h
//  APMultimedia
//
//  Created by Cloud on 15/5/12.
//  Copyright (c) 2015年 alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APVideoManager.h"

#pragma mark - 状态定义

// 拍摄模式
typedef enum : NSUInteger {
    APVideoCapturingModeVideo,                // 视频模式
    APVideoCapturingModePicture               // 拍照模式
} APVideoCapturingMode;

// 闪光灯以及手电筒模式
typedef enum : NSUInteger {
    APVideoFlashModeOff,                      // 关闭
    APVideoFlashModeOn,                       // 打开
    APVideoFlashModeAuto,                     // 自动
    APVideoFlashModeNotSupported,             // 不支持
} APVideoFlashMode;

// 加亮模式
typedef enum : NSUInteger {
    APVideoLowLightModeOff,                   // 关闭
    APVideoLowLightModeOn,                    // 打开
} APVideoLowLightMode;

// 录制视频和拍照时的方向检测模式
typedef enum : NSUInteger {
    APVideoRecordingOrientationDetectModeManual = 0,                      // 手动设置方向，在开始录制及拍照之前设置recordingOrientation属性，默认是Portrait方向
    APVideoRecordingOrientationDetectModeAuto = 1,                        // 自动模式，录制及拍照时自动检测当前设备方向，锁定设备旋转时无效
    APVideoRecordingOrientationDetectModeAutoEvenWhenRotateLocked = 2     // 自动模式，录制及拍照时自动检测当前设备方向，锁定设备旋转依然有效，与系统相机保持一致
} APVideoRecordingOrientationDetectMode;

// 摄像头数据采集相关状态
typedef enum : NSUInteger {
    APVideoRunningStarting,                   // 采集准备启动
    APVideoRunningStarted,                    // 采集完成启动
    APVideoRunning,                           // 正在采集
    APVideoNoCameraPermission,                // 无摄像头权限
    APVideoRunningStopped,                    // 采集结束
    APVideoRunningError,                      // 采集错误
    APVideoAmbientLightDrak,                  // 周围环境光线过暗
} APVideoRunningStatus;

// 视频录制相关状态
typedef enum : NSUInteger {
    APVideoRecordCameraNotStarted,            // 摄像头未启动
    APVideoRecordInvalidCapturingMode,        // 错误的模式
    APVideoRecordStarted,                     // 录制开始
    APVideoRecording,                         // 正在录制
    APVideoRecordCanceled,                    // 录制取消
    APVideoRecordFinished,                    // 录制完成
    APVideoRecordEncoded,                     // 转码完成
    APVideoRecordEncodeFailed,                // 转码错误
    APVideoRecordCompressed,                  // 压缩完成，此时可以去取历史小视频了
    APVideoRecordInterupted,                  // 录制被中断
    APVideoRecordUndefine                     // 未知错误
} APVideoRecordStatus;

// 视频滤镜类型
typedef enum : NSUInteger {
    APVideoFilterTypeOrigin,
    APVideoFilterTypeCharm,
    APVideoFilterTypeOrange,
    APVideoFilterTypeSunshine,
    APVideoFilterTypeLomo,
    APVideoFilterTypeWalden,
    APVideoFilterTypeCool,
    APVideoFilterTypeIce,
    APVideoFilterTypeGray,
    APVideoFilterTypeMax
} APVideoFilterType;

typedef enum : NSUInteger {
    APVideoRecorderMaterialMiss = 5001,     //素材缺失
    APVideoRecorderMaterialLoadFail,        //人脸模型加载异常
    APVideoRecorderMaterialUndetectFace,    //未检测到人脸
    APVideoRecorderMaterialUnknow,          //未知错误
} APVideoRecorderMaterialErrorEnum;

@protocol APVideoRecorderDelegate <NSObject>
@optional
//当所选素材需要检测人脸时，且人脸检测结果有变化时回调
- (void)videoRecorderDetectUserFace:(BOOL)detected error:(NSError*)error;
//当录制时环境昏暗与否有变化时回调
- (void)videoRecorderDetectEnvirnomentDark:(BOOL)dark;
@end

#pragma mark - handler定义

/**
 *  开始采集Block
 *
 *  @param status  开始采集状态
 *  @param error   异常信息
 */
typedef void (^APVideoRunningHandler)(APVideoRunningStatus status, NSError* error);

/**
 *  开始录制Block
 *
 *  @param status  开始录制状态
 *  @param info    压缩后的视频信息
 *  @param error   异常信息
 */
typedef void (^APVideoRecordHandler)(APVideoRecordStatus status, APVideoInfo *info, NSError* error);

/**
 *  拍摄照片Block
 *
 *  @param image   拍得的照片
 *  @param error   异常信息
 */
typedef void (^APVideoPictureHandler)(UIImage *image, NSError* error);

/**
 *  摄像头操作Block
 *
 *  @param result  成功与否
 */
typedef void (^APVideoCameraOperationHandler)(BOOL result);

#pragma mark - APVideoExportSetting

@interface APVideoExportSetting : NSObject

@property (nonatomic, assign) CGSize size; /// 默认为368x640
@property (nonatomic, assign) int bitrate; /// 默认为800 * 1000bps
@property (nonatomic, assign) int fps;     /// 默认为30fps

@end

#pragma mark - APVideoRecorder

@interface APVideoRecorder : UIView

/**
 *  最大录制时长，以秒为单位，默认为8s
 *  录制过程中设置无效
 */
@property (nonatomic, assign) NSUInteger maxRecordedSeconds;

/**
 *  拍摄模式属性，默认为拍照
 */
@property (nonatomic, assign, readonly) APVideoCapturingMode capturingMode;

/**
 *  当前摄像头前置、后置
 */
@property (nonatomic, assign) AVCaptureDevicePosition currentPosition;

/**
 *  手电和闪光灯模式属性
 */
@property (nonatomic, assign, readonly) APVideoFlashMode flashMode;

/**
 *  加亮模式
 */
@property (nonatomic, assign) APVideoLowLightMode lowLightMode;

/**
 *  美颜模式开关，默认为关
 */
@property (nonatomic, assign) BOOL enableBeautyMode;

/**
 *  美颜程度，范围为[0, 1]，如果超过这个范围时，向边界靠拢，enableBeautyMode打开时，该值默认为0.5
 */
@property (nonatomic, assign) CGFloat beautyLevel;

/**
 *  被打断后是否压缩录制完的视频，默认为NO
 */
@property (nonatomic, assign) BOOL willCompressWhenInterrupted;

/**
 *  录制APVideoRunning前加载图片
 */
@property (nonatomic, strong) UIImage* loadingImage;

/**
 *  是否支持zoom(双击放大)，默认为YES
 */
@property (nonatomic, assign) BOOL enableZoom;

/**
 *  方向检测模式，这将决定最终视频保存的方向
 */
@property (nonatomic, assign) APVideoRecordingOrientationDetectMode recordingOrientationDetectMode;

/**
 *  录制视频或者拍照时保存视频和图片的方向，只有在设置检测模式为APVideoRecordingOrientationDetectModeManual时有效
 */
@property (nonatomic, assign) AVCaptureVideoOrientation recordingOrientation;

/**
 *  状态变化通知的delegate
 */
@property (nonatomic, weak) id<APVideoRecorderDelegate> delegate;

/**
 *  视频导出的参数设置，默认参数见APVideoExportSetting描述
 */
@property (nonatomic, strong) APVideoExportSetting *exportSetting;

#pragma mark - 摄像头属性设置

/**
 *  设置拍摄模式
 *  录制过程中设置无效
 *
 *  @param  mode        拍摄模式，可以为录像和拍照
 *  @param  handler     拍摄模式设置完成回调
 */
- (void)setCapturingMode:(APVideoCapturingMode)mode handler:(APVideoCameraOperationHandler)handler;

/**
 *  设置手电和闪光灯模式
 *  录制过程中设置无效
 *
 *  @param  mode        闪光灯模式
 *  @param  handler     设置完成回调
 */
- (void)setFlashMode:(APVideoFlashMode)flashMode handler:(APVideoCameraOperationHandler)handler;

/**
 *  切换摄像头
 *
 *  @param  handler     切换完成回调
 */
- (void)switchCamera:(APVideoCameraOperationHandler)handler;

#pragma mark - 采集与拍摄

/**
 *  开始采集摄像头的数据
 *
 *  @param  handler     异步开始采集回调，回调位于主线程
 */
- (void)startRunning:(APVideoRunningHandler)handler;

/**
 *  结束采集
 *  会在startRunning的回调中返回相应的事件，一定要在对象销毁前调用此方法
 *
 */
- (void)stopRunning;

/**
 *  开始录制
 *  在视频模式下调用
 *
 *  @param  handler     异步开始录制回调，回调位于主线程
 */
- (void)startRecording:(APVideoRecordHandler)handler;

/**
 *  取消录制
 *  在视频模式下调用
 *  会在startRecording的回调中返回相应的事件
 */
- (void)cancelRecording;

/**
 *  结束录制
 *  在视频模式下调用
 *  会在startRecording的回调中返回相应的事件
 */
- (void)stopRecording;

/**
 *  拍摄照片
 *  在拍照模式下调用
 *
 *  @param  handler     拍摄照片完成回调，回调位于主线程
 */
- (void)takePicture:(APVideoPictureHandler)handler;

/**
 *  设置水印贴图
 *
 *  @param MaterialId 素材包id
 */
- (void)setSeletedMaterialId:(NSString*)materialId;

/**
 *  设置滤镜类型
 *
 *  @param identifier 滤镜id
 */
- (void)setVideoFilterId:(NSString*)identifier;

/**
 *  将view中的某个点(点为单位)转换成获取的图像中对应的位置(像素为单位)
 *
 *  @param pointInView view中的点
 *
 *  @return 对应图像中的位置(像素为单位)
 */
- (CGPoint)imagePositionForPoint:(CGPoint)pointInView;

@end
