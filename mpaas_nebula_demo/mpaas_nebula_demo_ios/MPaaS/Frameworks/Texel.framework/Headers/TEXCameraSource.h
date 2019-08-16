//
//  TEXCameraSource.h
//  Texel
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"
#import <AVFoundation/AVFoundation.h>

@interface TEXCameraSource : TEXSource

@property (nonatomic, assign) AVCaptureDevicePosition capturePosition;

- (instancetype)initWithOrientation:(AVCaptureVideoOrientation)orientation; // orientation表示输入视频帧的方向
- (void)feedVideoFrame:(CVPixelBufferRef)frame;

@end
