//
//  APMCameraView.h
//  APMultimedia
//
//  Created by Cloud on 15/5/12.
//  Copyright (c) 2015年 alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "APMTextureView.h"

#pragma mark - 状态定义

// 摄像头数据采集相关状态
typedef enum : NSUInteger {
    APMCameraRunningStarting,                   // 采集准备启动
    APMCameraRunningStarted,                    // 采集完成启动
    APMCameraRunning,                           // 正在采集
    APMCameraNoCameraPermission,                // 无摄像头权限
    APMCameraRunningStopped,                    // 采集结束
    APMCameraRunningError,                      // 采集错误
} APMCameraRunningStatus;


@class APMCameraView;
@protocol APMCameraViewDelegate <NSObject>
@optional
- (void)cameraView:(APMCameraView *)cameraView didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end

#pragma mark - handler定义

/**
 *  开始采集Block
 *
 *  @param status  开始采集状态
 *  @param error   异常信息
 */
typedef void (^APMCameraRunningHandler)(APMCameraRunningStatus status, NSError* error);

/**
 *  拍摄照片Block
 *
 *  @param imageData   拍得的照片，包含exif和方向信息。
 *  @param error   异常信息
 */
typedef void (^APMCameraPictureHandler)(NSData *imageData, NSError* error);

/**
 *  摄像头操作Block
 *
 *  @param result  成功与否
 */
typedef void (^APMCameraOperationHandler)(BOOL result);

#pragma mark - APMCameraView

@interface APMCameraView : UIView
/**
 *  扩展初始化函数
 *
 *  @param frame 预览view的frame
 *  @param options 属性设置字典，目前支持的key:frameFormat:视频帧输出格式
 */
- (instancetype)initWithFrame:(CGRect)frame options:(NSDictionary *)options;

/**
 *  当前摄像头前置、后置
 */
@property (nonatomic, assign) AVCaptureDevicePosition currentPosition;

/**
 *  手电和闪光灯模式属性
 */
@property (nonatomic, assign, readonly) AVCaptureFlashMode flashMode;
@property (nonatomic, assign, readonly) AVCaptureTorchMode torchMode;

/**
 *  对焦模式，默认为AVCaptureFocusModeContinuousAutoFocus
 */
@property (nonatomic, assign) AVCaptureFocusMode focusMode;

/**
 *  曝光模式，默认为AVCaptureExposureModeContinuousAutoExposure
 */
@property (nonatomic, assign) AVCaptureExposureMode exposureMode;

/**
 *  录制APMCameraRunning前加载图片
 */
@property (nonatomic, strong) UIImage* loadingImage;

/**
 *  状态变化通知的delegate
 */
@property (nonatomic, weak) id<APMCameraViewDelegate> delegate;

/**
 *  输出视频帧的格式，默认是'420f'，目前只支持kCVPixelFormatType_420YpCbCr8PlanarFullRange与kCVPixelFormatType_32BGRA
 *  视频帧会通过kAPMCameraFrameSampleBufferKey发出通知，其中包含的对象是NSValue，内部为CMSampleBufferRef
 */
@property (nonatomic, assign) OSType frameFormat;

/**
 *  是否需要对焦和放大，默认YES
 */
@property (nonatomic, assign) BOOL needFocusAndZoom;

/**
 *  是否需要启动摄像头的loading缩放效果,默认YES
 */
@property (nonatomic, assign) BOOL needRunningAnimation;

/**
 *  是否开启视频画面稳定开关，开启之后采集到的画面会被裁减一部分。默认为NO
 */
@property (nonatomic, assign) BOOL enableVideoStabilization;

/**
 *  是否需要在开启和关闭时隐藏预览,默认YES，隐藏
 */
@property (nonatomic, assign) BOOL hiddenPreviewWhenStop;

/**
 *  默认为AVCaptureSessionPreset1280x720(IPHONE4前置为AVCaptureSessionPreset640x480)
 */
@property (nonatomic, strong) NSString *preset;

/**
 *  视频帧的输出方向，影响监听到的视频帧方向，与预览无关。默认为AVCaptureVideoOrientationPortrait
 */
@property (nonatomic, assign) AVCaptureVideoOrientation cameraOrientation;

/**
 *  自动根据当前的手机方向调整拍摄的照片方向，默认为NO
 */
@property (nonatomic, assign) BOOL useDeviceOrientation;

/**
 *  是否使用系统AVCaptureVideoPreviewLayer渲染
 */
@property (nonatomic, assign) BOOL usePreviewLayer;

/**
 * usePreviewLayer若设置为NO，则containerPreview可传入自渲染的View
 */
@property (nonatomic, weak) UIView* containerPreview;

#pragma mark - 摄像头属性设置

+ (BOOL)isFlashSupport:(AVCaptureDevicePosition)position;

+ (BOOL)isTorchSupport:(AVCaptureDevicePosition)position;
/**
 *  切换摄像头
 *
 *  @param  handler     切换完成回调
 */
- (void)switchCamera:(APMCameraOperationHandler)handler;

/**
 *  设置手电和闪光灯模式
 *  录制过程中设置无效
 *
 *  @param  flashMode   闪光灯模式
 *  @param  handler     设置完成回调
 */
- (void)setFlashMode:(AVCaptureFlashMode)flashMode handler:(APMCameraOperationHandler)handler;

/**
 *  设置手电和闪光灯模式
 *  录制过程中设置无效
 *
 *  @param  torchMode   手电筒灯模式
 *  @param  handler     设置完成回调
 */
- (void)setTorchMode:(AVCaptureTorchMode)torchMode handler:(APMCameraOperationHandler)handler;

#pragma mark - 采集与拍摄

/**
 *  开始采集摄像头的数据
 *
 *  @param  handler     异步开始采集回调，回调位于主线程
 */
- (void)startRunning:(APMCameraRunningHandler)handler;

/**
 *  结束采集
 *  会在startRunning的回调中返回相应的事件，一定要在对象销毁前调用此方法
 *
 */
- (void)stopRunning;

/**
 *  拍摄照片
 *  在拍照模式下调用
 *
 *  @param  handler     拍摄照片完成回调，回调位于主线程
 */
- (void)takePicture:(APMCameraPictureHandler)handler;

/**
 *  将view中的某个点(点为单位)转换成获取的图像中对应的位置(像素为单位)
 *
 *  @param pointInView view中的点
 *
 *  @return 对应图像中的位置(像素为单位)
 */
- (CGPoint)imagePositionForPoint:(CGPoint)pointInView;

@end
