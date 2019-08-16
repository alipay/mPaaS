//
//  AudioSessionConfiguration.h
//  APMultimedia
//
//  Created by Cloud on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface APMAudioSessionConfiguration : NSObject

@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *mode;
@property (nonatomic, assign) AVAudioSessionCategoryOptions options;
@property (nonatomic, assign) BOOL needStopOtherApp;
@property (nonatomic, assign) BOOL needStopOtherSession;
@property (nonatomic, strong) NSArray *coexistModes; // 这里面的模式会和当前模式共存，不会被打断
@property (nonatomic, strong) NSArray *higherPriorityModes; // 这里面的模式优化级较高，有他们存在时，不能够请求active

@end
