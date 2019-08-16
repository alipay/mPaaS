//
//  APSecurityUtility.h
//  APSecurityUtility
//
//  Created by NianXi on 14-9-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#ifndef APSecurityUtility_APSecurityUtility_h
#define APSecurityUtility_APSecurityUtility_h
#import "APSecurityUtilImpl.h"
#import "APGuardSwizzle.h"

/**
 *  在调用一个(+)selector前，检查该selector是否被外部注入的库hook
 *  仅适用于本应用程序内(包含静态库)实现的selector，不能使用此方法检测iOS系统Framework API及其他dylib中定义的API
 * 
 *  (BOOL)APDetectClassSelectorSwizzling(NSString *className, SEL sel)
 *
 *  ------------------------------------------------------
 *  @param className selector所属类名
 *  @param sel       selector
 *
 *  @return 返回值类型BOOL，返回YES时表示该selector已被hook
 *  ------------------------------------------------------
 *
 *  示例如下:
 *  BOOL isHooked = APDetectClassSelectorSwizzling(@"SomeClass", @selector(test));
 *
 */
#define APDetectClassSelectorSwizzling(className, sel) (APSecurityUtilImpl->isSwizzlingClassMethod(className, sel))

/**
 *  在调用一个(-)selector前，检查该selector是否被外部注入的库hook
 *  仅适用于本应用程序内(包含静态库)实现的selector，不能使用此方法检测iOS系统Framework API其他dylib中定义的API
 *
 *  (BOOL)APDetectInstanceSelectorSwizzling(NSString *className, SEL sel)
 *
 *  ------------------------------------------------------
 *  @param className selector所属类名
 *  @param sel       selector
 *
 *  @return 返回值类型BOOL，返回YES时表示该selector已被hook
 *  ------------------------------------------------------
 *
 *  示例如下:
 *  BOOL isHooked = APDetectInstanceSelectorSwizzling(@"SomeClass", @selector(test));
 *
 */
#define APDetectInstanceSelectorSwizzling(className, sel) (APSecurityUtilImpl->isSwizzlingInstanceMethod(className, sel))

/**
 *  在C函数内部实现中加入此检测方法，检查该函数是否被外部注入的程序调用，如gdb、外部注入的dylib等
 *
 *  示例如下：
 *  bool isRisky = APDetectCFuncCalledByOthers;
 *
 */
#define APDetectCFuncCalledByOthers (APSecurityUtilImpl->isExternalCall(__builtin_return_address(0)))
#define APDetectNonFrameworkSelectorCalledByOthers (APSecurityUtilImpl->isExternalCall(__builtin_return_address(0)))

/**
 *  在调用一个UIKit里(-)selector前，检查该selector是否被外部注入的库hook，即系统API是否被非己hook
 *  仅适用于iOS系统UIKit Framework中定义的API
 *
 *  (BOOL)APDetectUIKitInstanceSelectorSwizzling(NSString *className, SEL sel)
 *
 *  ------------------------------------------------------
 *  @param className selector所属类名
 *  @param sel       selector
 *
 *  @return 返回值类型BOOL，返回YES时表示该selector已被hook
 *  ------------------------------------------------------
 *
 *  示例如下:
 *  BOOL isHooked = APDetectUIKitInstanceSelectorSwizzling(@"UITextfield", @selector(text));
 *
 */
#define APDetectUIKitInstanceSelectorSwizzling(className, sel) (APSecurityUtilImpl->isSwizzlingUIKitInstanceMethod(className, sel))

/**
 *  在调用一个LocalAuthentication.framework里(-)selector前，检查该selector是否被外部注入的库hook，即系统API是否被非己hook
 *  仅适用于iOS系统LocalAuthentication.framework中定义的API
 *  不适用于模拟器
 *
 *  注意：调用方需自行保证link LocalAuthentication.framework (可设置optional)
 *       当运行在iOS8以下的系统link不到LocalAuthentication.framework时，默认返回 NO
 *
 *  (BOOL)APDetectLocalAuthInstanceSelectorSwizzling(NSString *className, SEL sel)
 *
 *  ------------------------------------------------------
 *  @param className selector所属类名
 *  @param sel       selector
 *
 *  @return 返回值类型BOOL，返回YES时表示该selector已被hook
 *  ------------------------------------------------------
 *
 *  示例如下:
 *  BOOL isHooked = APDetectLocalAuthInstanceSelectorSwizzling(@"LAContext", @selector(canEvaluatePolicy:error:));
 *
 */
#define APDetectLocalAuthInstanceSelectorSwizzling(className, sel) (APSecurityUtilImpl->isSwizzlingLocalAuthInstanceMethod(className, sel))

/**
 *  越狱检测
 *  
 *  (BOOL)APDetectJailbroken;
 */
#define APDetectJailbroken (APSecurityUtilImpl->isJailbroken(NULL))

/**
 *  检查当前是否处于调试状态
 *  (BOOL)APDetectDebugger;
 *
 *  @return 返回值类型BOOL，返回YES时表示当前为调试状态
 */
#define APDetectDebugger (APSecurityUtilImpl->isDebugging(NULL))

/**
 *  获取可执行程序二进制的代码段摘要
 *
 *  (NSString *)APGetTextSectionDigest;
 */
#define APGetTextSectionDigest (APSecurityUtilImpl->getTextSectionDigest())


/**
 *  检查二进制可执行程序的linker flag的restrict标志
 *
 *  (BOOL)APDetectLinkerFlag;
 *  @return 返回值类型BOOL，返回YES时表示当前为存在
 */
#define APDetectLinkerFlag (APSecurityUtilImpl->isLinkerFlagExisted(NULL))

/**
 *  接收到通知后，检查通知发送者是否出自应用内部。当第三方插件发送通知名为 name 的通知时，返回NO，表示存在风险.
 *  特别注意：需保证通知名字符串为静态字符串，若通知发送者以format拼接通知名，此方法返回NO，不符合预期。
 *
 *  Sample:
 *
 *  NSString *name = [notification name];
 *  if (!APCheckNotificationSecurity(name)) {
 *      //不响应钱包外部发送的通知
 *      return;
 *  }
 *
 *  @return 返回值类型BOOL，返回YES时表示安全
 */
#define APCheckNotificationSecurity(name) (APSecurityUtilImpl->isInternalNotification(name))

/**
 *  获取注入进程空间内注入的动态库信息
 *
 *  (NSDictionary *)APGetInjectInfo
 *  @return 返回值类型NSDictionary，以库名为key，filter为value的字典
 */
#define APGetInjectInfo (APSecurityUtilImpl->getInjectInfo())

#define APGetBaseInfo (APSecurityUtilImpl->baseInfo())
#endif
