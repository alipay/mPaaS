//
//  TEXCameraView.h
//  Texel
//
//  Created by feihu on 2018/3/12.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <APMUtils/APMCameraView.h>
#import "TEXFunctor.h"
#import "TEXSource.h"

@interface TEXCameraView : APMCameraView
@property (nonatomic, strong) TEXFunctor *filter;
@property (nonatomic, strong, readonly) TEXSource *source; // 可用于录制的源，添加给TEXRecorder，包含了filter的处理
@property (nonatomic, assign) BOOL silence; // 拍照时是否静音，默认为NO
@end
