//
//  IOpenNoCaptchaComponent.h
//  SecurityGuardSDK
//
//  Created by chenkong on 15/4/29.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

@protocol IOpenNoCaptchaComponent <NSObject>


/**
 *  初始化无痕验证模块
 *
 *  @param appKey 接入应用使用的appkey
 *  @param pageName 页面名称
 *  @param screenWidth 表示屏幕的宽度像素值
 *  @param screenHeight 表示屏幕的高度像素值
 *  @param retryTimes 校验重试次数
 *  @param statusCB 回调函数
 *  @param authCode 二方用户请传nil，三方用户请传AuthCode
 */
-(void) initNoCaptcha: (NSString*) appKey
             pageName: (NSString*) pageName
                width: (int) screenWidth
               height: (int) screenHeight
                retry: (int) retryTimes
               status: (void(^)(NSInteger status, CGPoint pt1, CGPoint pt2, NSString* token, NSString* sig, NSString* sessionID))statusCb
             authCode: (NSString*) authCode;

/**
 *  写入用户触屏打点数据
 *
 *  @param touchEvent touch的类型
 *  @param pt 打点的坐标
 */
-(BOOL) putNoCaptchaTraceRecord: (NSInteger) touchEvent
                          point: (CGPoint) pt;

/**
 *  请求进行无线验证
 *
 *  @param appKey 接入应用使用的appkey
 *  @param statusCB 回调函数
 */
-(void) noCaptchaVerification: (NSString*)appKey
                       status: (void(^)(NSInteger status, CGPoint pt1, CGPoint pt2, NSString* token, NSString* sig, NSString* sessionID))statusCb;

/**
 *  前向化请求，验证接口
 *
 *  @param methodName     需要调用的Top API名；
 *
 *  @param authInfo       其他需要的信息，以key-v形式存于authInfo中；
 *
 *  @param timeout        接口调用超时时间，单位秒，最大不超过22，最小不小于1。
 *
 *  @param authCode 二方用户请传nil，三方用户请传AuthCode
 */
- (NSString*) noCaptchaForwardAuth: (NSString *) methodName
                          authInfo: (NSDictionary*) authInfo
                          authCode: (NSString *) authCode
                           timeout: (NSInteger) timeout;


@end
