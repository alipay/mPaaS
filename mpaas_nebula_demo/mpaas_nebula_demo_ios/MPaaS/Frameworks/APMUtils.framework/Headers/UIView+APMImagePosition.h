//
//  UIView+APMImagePosition.h
//  APMUtils
//
//  Created by Cloud on 2017/11/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface UIView (APMImagePosition)

- (CGPoint)apm_imagePositionForPoint:(CGPoint)pointInView imageOrientation:(AVCaptureVideoOrientation)imageOrientation imageDimension:(CGSize)imageDimension mirror:(BOOL)mirror;
- (CGPoint)apm_pointForImagePosition:(CGPoint)positionInImage imageOrientation:(AVCaptureVideoOrientation)imageOrientation imageDimension:(CGSize)imageDimension mirror:(BOOL)mirror;

- (CGRect)apm_imageFrameForFrame:(CGRect)frameInView imageOrientation:(AVCaptureVideoOrientation)imageOrientation imageDimension:(CGSize)imageDimension mirror:(BOOL)mirror;
- (CGRect)apm_frameForImageFrame:(CGRect)frameInImage imageOrientation:(AVCaptureVideoOrientation)imageOrientation imageDimension:(CGSize)imageDimension mirror:(BOOL)mirror;

@end
