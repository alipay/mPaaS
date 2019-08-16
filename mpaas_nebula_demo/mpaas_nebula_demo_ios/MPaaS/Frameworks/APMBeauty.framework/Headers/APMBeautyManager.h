//
//  APMBeautyManager.h
//  APMultimedia
//
//  Created by Cloud on 16/3/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

@class APMBeautyManager;

@protocol APMBeautyManagerDelegate <NSObject>

- (void)beautyManager:(APMBeautyManager *)beautyManager texture:(GLuint)texture renderinfo:(NSDictionary*)renderinfo time:(CMTime)time;

@optional
/**
 * 美颜耗时，可用于埋点监控
 */
- (void)beautyManager:(APMBeautyManager *)beautyManager performance:(NSTimeInterval)time;

@end


@interface APMBeautyManager : NSObject

#pragma mark - 用于处理从摄像头中读出的sampleBuffer数据
/**
 *  预加载初始化BeautyManager需要的一些耗时资源，调用的话会节省BeautyManager初始化的时间。不调用也不影响BeautyManager初始化。
 */
+ (void)initBeautyManagerContext;

/**
 *  delegate，可以接收APMBeautyManagerDelegate通知
 */
@property (nonatomic, weak) id<APMBeautyManagerDelegate> delegate;

/**
 *  美颜模式开关，默认为关，如果为关时，调用captureOutput接口时只会裁减
 */
@property (nonatomic, assign) BOOL enableBeautyMode;

/**
 *  美颜程度，范围为[0, 1]，如果超过这个范围时，向边界靠拢
 */
@property (nonatomic, assign) CGFloat beautyLevel;

/**
 *  贴素材接口，nil为不贴
 */
@property (nonatomic, strong) NSString* materialpath;

/**
 *  滤镜类型，<=0不进行滤镜
 */
@property (nonatomic, assign) NSInteger filtertype;

/**
 *  是否有做镜像翻转
 */
@property (nonatomic,assign) BOOL isMirror;

/**
 *  方向信息变换时需要设置此方向
 */
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;

/**
 *  是否正在拍摄，用于拍摄有水印的照片，防止因为处理时间过长而导致水印没对准的情况
 */
@property (nonatomic, assign) BOOL isCapturingStillImage;

/**
 *  美颜算法信息
 */
@property (nonatomic, assign, readonly) NSUInteger beautyDescription;

/**
 *  美颜模式信息
 */
@property (nonatomic, assign, readonly) NSUInteger beautyMode;

/**
 *  初始化
 *  会将原始尺寸的sampleBuffer转成目标尺寸的纹理，并在delegate中给出裁减之后的纹理回调
 *
 *  @param  size        输入的图像尺寸
 *  @param  toSize      裁减之后的纹理尺寸
 */
- (instancetype)initWithSize:(CGSize)fromSize toSize:(CGSize)toSize;

/**
 *  释放对象资源
 *  由于可能会出现系统无法即时释放旧的对象的现象，会导致crash，所以这里提供一个接口用于释放
 */
- (void)uninit;

/**
 *  可以用于渲染美颜后纹理的OpenGL上下文
 */
- (EAGLContext *)context;

/**
 *  获取从摄像头中拿到的sampleBuffer数据
 *
 *  @param captureOutput    获取数据的AVCaptureVideoDataOutput
 *  @param sampleBuffer     视频帧
 *  @param connection       获取数据的AVCaptureConnection
 */
- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;

/**
 *  对纹理进行美颜处理
 *
 *  @param texture    需要处理的纹理
 *  @param toSize     需要裁减的尺寸
 *  @param time       对应纹理的时间戳
 */
- (void)proceedTexture:(GLuint)texture toSize:(CGSize)toSize time:(CMTime)time;

/**
 *  截取当前处理纹理并转化成图像
 */
- (UIImage *)captureImage;

/**
 *  美颜耗时回调
 *
 *  @param performance 耗时
 */
- (void)performance:(NSTimeInterval)performance;

#pragma mark - 用于处理单张图像

/**
 *  异步对图像进行美颜处理
 *
 *  @param  image       要处理的图像
 *  @param  complete    处理完成后的回调，线程未知
 */
- (void)proceedImage:(UIImage *)image complete:(void (^)(UIImage *image))complete;

/**
 *  同步对图像进行美颜处理
 *
 *  @param  image       要处理的图像
 *  @return complete    返回美颜之后的图像
 */
- (UIImage *)proceedImage:(UIImage *)image;

@end


