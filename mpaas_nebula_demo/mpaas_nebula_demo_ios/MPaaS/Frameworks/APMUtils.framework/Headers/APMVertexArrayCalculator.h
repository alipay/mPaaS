//
//  APMTextureCoordinatesGenerator.h
//  APMUtils
//
//  Created by Cloud on 2017/3/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <AVFoundation/AVFoundation.h>

typedef enum : NSUInteger {
    APMTextureRotate0,
    APMTextureRotate90,
    APMTextureRotate180,
    APMTextureRotate270,
} APMTextureRotate;

@interface APMVertexArrayCalculator : NSObject

+ (void)defaultImageVertexArray:(GLfloat *)v;
+ (void)defaultTextureCoordinateArray:(GLfloat *)v;

/**
 *  保持长宽比，类似于view的UIViewContentModeScaleAspectFill填充模式
 *
 *  @param v          输入的texture coordinates，计算之后会写入此数组中
 *  @param inputSize  texture的输入尺寸
 *  @param outputSize texture的输出尺寸
 */
+ (void)calcTextureCoordinateArray:(GLfloat *)v inputSize:(CGSize)inputSize outputSize:(CGSize)outputSize;

+ (void)flipVertexArray:(GLfloat *)v;
+ (void)mirrorVertexArray:(GLfloat *)v;
+ (void)rotateVertexArray:(GLfloat *)v rotation:(APMTextureRotate)rotation;

/**
 裁剪区域的顶点坐标获取,默认两个rect是相交或包含的

 @param v 输入的texture coordinates，计算之后会写入此数组中
 @param source texture的输入尺寸
 @param dest texture的目标尺寸
 */
+ (void)cutVertexArray:(GLfloat *)v sourceRect:(CGRect)source destRect:(CGRect)dest;

+ (APMTextureRotate)rotationFromOrientation:(AVCaptureVideoOrientation)fromOrientation toOrientation:(AVCaptureVideoOrientation)toOrientation;
+ (AVCaptureVideoOrientation)relativeOrientationFromOrientation:(AVCaptureVideoOrientation)fromOrientation toOrientation:(AVCaptureVideoOrientation)toOrientation;

@end
