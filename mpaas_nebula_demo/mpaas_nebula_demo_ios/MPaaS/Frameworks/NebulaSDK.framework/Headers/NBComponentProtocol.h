//
//  NBComponentProtocol.h
//  NebulaPlugins
//
//  Created by theone on 17/3/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^NBComponentCallback)(NSDictionary *data);

typedef enum
{
    NBComponentVisibilityVisibility,
    NBComponentVisibilityHidden,
} NBComponentVisibilityState;

@class NBComponentContext;
@protocol NBComponentProtocol;


@protocol NBComponentMessageDelegate <NSObject>

@required
/**
 * 组件主动发送消息给页面(Native->Page)
 *
 * @param message 消息名称
 * @param component 要发送消息的组件
 * @param data 消息内容
 * @param callback 页面处理完消息后的回调
 *
 * @return void
 */
- (void)sendMessage:(NSString *)message
          component:(id<NBComponentProtocol>)component
               data:(NSDictionary *)data
           callback:(NBComponentCallback)callback;
@optional

/**
 * 组件可以在执行环境中直接执行JS
 *
 * @param javaScriptString 需要执行的JS
 * @param completionHandler 执行回调函数
 *
 * @return void
 */
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

@end

@protocol NBComponentLifeCycleProtocol <NSObject>

- (void)componentWillAppear;
- (void)componentDidAppear;
/**
 * 组件将要销毁
 *
 * @return void
 */
- (void)componentWillDestory;
/**
 * 组件销毁之后
 *
 * @return void
 */
- (void)componentDidDestory;
- (void)componentWillResume;
- (void)componentDidResume;
- (void)componentWillPause;
- (void)componentDidPause;

//fullscreen
/**
 component即将进入全屏的回调
 */
- (void)componentWillEnterFullScreen;
/**
 component进入全屏的回调
 */
- (void)componentWillExitFullScreen;
/**
 component即将退出全屏的回调
 */
- (void)componentDidEnterFullScreen;
/**
 component退出全屏的回调
 */
- (void)componentDidExitFullScreen;

//visiblity
/**
 component即将退出全屏的回调
 */
- (void)componentDidHidden;
/**
 component退出全屏的回调
 */
- (void)componentDidVisiblity;
@end


@protocol NBComponentDataProtocol <NSObject>
/**
 * 组件数据将要更新
 *
 * @param data 数据内容
 *
 * @return void
 */
- (void)componentDataWillChangeWithData:(NSDictionary *)data;
/**
 * 组件数据已经更新，这时候一般是要作界面更新，或者组件的其他操作
 *
 * @param data 数据内容
 *
 * @return void
 */
- (void)componentDataDidChangeWithData:(NSDictionary *)data;
@end

@protocol NBComponentFullScreenProtocol <NSObject>
/**
 是否处于全屏模式
 
 @return 是否处于全屏模式
 */
- (BOOL)isFullScreen;

/**
 @return 是否需要进入全屏模
 */
- (BOOL)shouldEnterFullScreen;

/**
 设置ContentView是否需要全屏幕，业务通过换个来切换全屏模式

 @param fullScreen 是否需要全屏幕
 @param shouldRotate 是否需要旋转屏幕

 */
- (void)setContentViewFullScreen:(BOOL)fullScreen shouldRotate:(BOOL)shouldRotate;
@end

@protocol NBComponentVisibilityProtocol <NSObject>

/**
 visibilityState状态
 @return VisibilityState状态
 */
- (NBComponentVisibilityState)visibilityState;

/**
 设置VisibilityState状态

 @param state VisibilityState
 @return 是否设置成功
 */
- (BOOL)setVisibilityState:(NBComponentVisibilityState)state;

/**
 业务重写此方法给出是否需要监听visibility变化，默认是NO

 @return 是否需要监听visibility变化
 */
- (BOOL)shouldObServerVisibilityStateChange;
@end


@protocol NBComponentViewControllerProtocol <NSObject>
@property(nonatomic, assign)   BOOL  contentViewFullScreen;
@end

@protocol NBComponentProtocol <NSObject, NBComponentLifeCycleProtocol, NBComponentDataProtocol, NBComponentFullScreenProtocol,NBComponentVisibilityProtocol>
@required
@property(nonatomic, weak) id<NBComponentMessageDelegate>  nbComponentMessageDelegate;
@property(nonatomic, strong)          NBComponentContext  *context;
@property(nonatomic, copy)            NSString *type;
@property(nonatomic, strong)          NSDictionary *data;
@property(nonatomic, copy)            NSString *componentId;

/**
 * NBComponent需要返回一个UIView对象
 * @return void
 */
- (UIView *)contentView;

/**
 * 组件收到页面发送过来的消息(Page->Native)
 *
 * @param message 消息名称
 * @param data 消息内容
 * @param callback 将Native处理后的结果返回给页面的回调函数
 *
 * @return void
 */
- (void)componentReceiveMessage:(NSString *)message
                          data:(NSDictionary *)data
                      callback:(NBComponentCallback)callback;
@end

NS_ASSUME_NONNULL_END
