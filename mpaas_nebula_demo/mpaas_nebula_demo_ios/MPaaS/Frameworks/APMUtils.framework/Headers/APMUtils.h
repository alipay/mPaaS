//
//  Utils.h
//  APMultimedia
//
//  Created by Cloud on 16/3/18.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMVideoUtils.h"
#import "APMVideoWriter.h"
#import "APMPing.h"
#import "APMSimplePing.h"
#import "APMRecorderFocusLayer.h"
#import "APMRecorderFocusView.h"
#import "APMVideoPreviewViewContainer.h"
#import "APMLoadingView.h"
#import "APMTextureView.h"
#import "APMCameraView.h"
#import "APMOpenGLShaderCompiler.h"
#import "UIView+APMGaussianBlur.h"
#import "APMLog.h"
#import "APMAudioSessionManager.h"
#import "NSString+APMContainString.h"
#import "NSString+APMMD5.h"
#import "NSString+APMDeviceVersion.h"
#import "APMMainCall.h"
#import "APMOpenGLESManager.h"
#import "APMHttpResponse.h"
#import "APMConfig.h"
#import "APMVertexArrayCalculator.h"
#import "UIImage+APMFixOrientation.h"
#import "APMDylibLoader.h"
#import "APMRemoteLog.h"
#import "UIView+APMImagePosition.h"
#import "APMLock.h"
#import "APMDeviceInfo.h"
#import "APMDeviceOrientationMonitor.h"

#define WEAKSELF() __weak __typeof(self) weakSelf = self;
#define STRONGSELF() if (!weakSelf) return; __strong __typeof(weakSelf) self = weakSelf;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// 安全的主线程同步调用
void safetyMainThreadSyncCall(dispatch_block_t block);

#ifdef __cplusplus
}
#endif // __cplusplus
