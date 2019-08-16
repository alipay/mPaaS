//
//  NXKExtensionPoint.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NXKExtension;

typedef void(^nxkStopPropagationCallback)(NXKExtension *extension);
typedef void(^nxkPreventDefaultCallback)(NXKExtension *extension);
typedef void(^nxkProgressCallback)(NXKExtension *extension, id result);
typedef void(^nxkCompleteCallback)(id result);


@protocol NXKExtensionPointLifeCycleProtocol <NSObject>

@required
@property(nonatomic) BOOL isPreventDefault;                       // 扩展点是否阻止默认行为
@property(nonatomic) BOOL isStopPropagation;                      // 扩展点是否停止传播
@property(nonatomic) nxkStopPropagationCallback  stopPropagationCallback;    // 阻止传播回调
@property(nonatomic) nxkPreventDefaultCallback  preventDefaultCallback;     // 阻止默认处理回调
@property(nonatomic) nxkProgressCallback  processCallback;              // 处理过程中回调
@property(nonatomic) nxkCompleteCallback  completeCallback;             // 完成调用回调
@end


@interface NXKExtensionPointLifeCycle : NSObject <NXKExtensionPointLifeCycleProtocol>
@property(nonatomic) BOOL isPreventDefault;                       // 扩展点是否阻止默认行为
@property(nonatomic) BOOL isStopPropagation;                      // 扩展点是否停止传播
@property(nonatomic) nxkStopPropagationCallback  stopPropagationCallback;    // 阻止传播回调
@property(nonatomic) nxkPreventDefaultCallback  preventDefaultCallback;     // 阻止默认处理回调
@property(nonatomic) nxkProgressCallback        processCallback;              // 处理过程中回调
@property(nonatomic) nxkCompleteCallback  completeCallback;             // 完成调用回调

- (instancetype)initWithStopPropagationCallback:(nxkStopPropagationCallback)stopPropagationCallback
                         preventDefaultCallback:(nxkPreventDefaultCallback)preventDefaultCallback
                                processCallback:(nxkProgressCallback)processCallback
                               completeCallback:(nxkCompleteCallback)completeCallback;
@property(nonatomic) Protocol *ponit;

// convenient for setting by chain
- (instancetype)onStopPropagation:(nxkStopPropagationCallback)callback;
- (instancetype)onPreventDefault:(nxkPreventDefaultCallback)callback;
- (instancetype)onProcess:(nxkProgressCallback)callback;
- (instancetype)onComplete:(nxkCompleteCallback)callback;

@end
