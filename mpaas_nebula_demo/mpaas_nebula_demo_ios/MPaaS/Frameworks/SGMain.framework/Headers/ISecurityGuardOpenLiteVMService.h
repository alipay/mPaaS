//
//  ISecurityGuardOpenLiteVMService.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/12/17.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenLiteVMService_h
#define ISecurityGuardOpenLiteVMService_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@class LiteVMInstance;



/**
 LVM参数封装类，目前支持 char、unsigned char、int、unsigned int、long、
 unsigned long、long long、unsigned long long、NSString、NSData类型的入参
 */
@interface LiteVMParameterWrapper : NSObject

+ (LiteVMParameterWrapper*) createCharParameter: (char) value;
+ (LiteVMParameterWrapper*) createUnsignedCharParameter: (unsigned char) value;

+ (LiteVMParameterWrapper*) createIntParameter: (int) value;
+ (LiteVMParameterWrapper*) createUnsignedIntParameter: (unsigned int) value;

+ (LiteVMParameterWrapper*) createLongParameter: (long) value;
+ (LiteVMParameterWrapper*) createUnsignedLongParameter: (unsigned long) value;

+ (LiteVMParameterWrapper*) createLongLongParameter: (long long) value;
+ (LiteVMParameterWrapper*) createUnsignedLongLongParameter: (unsigned long long) value;

+ (LiteVMParameterWrapper*) createStringParameter: (NSString*) value;
+ (LiteVMParameterWrapper*) createDataParameter: (NSData*) value;

@end



/**
 LVM接口封装类
 */
@protocol ISecurityGuardOpenLiteVMService <NSObject, IOpenSecurityGuardPluginInterface>


/**
 创建LVM实例

 @param authCode 保镖为业务方分配的标识id，与bianry一一对应
 @param bizId 为binary code分配的name （一个binary中可以有多个binarycode，通过biz id来索引）
 @param binary 存储待执行的bianry code的二进制
 @param symbolArray binary code依赖符号的数组，可为空
 @param error 错误
 @return 根据bizId和binaryCode生成的vm实例
 */
- (LiteVMInstance*) createLiteVMInstanceWithAuthCode: (NSString*) authCode
                                               bizId: (NSString*) bizId
                                              binary: (NSData*) binary
                                      requiredSymbol: (NSArray*) symbolArray
                                               error: (NSError**) error;


/**
 让LVM实例重新加载binary code

 @param instance LVM实例
 @param binaryCode 需要重新加载的binary code
 @param error 错误
 */
- (void) reloadLiteVMInstance: (LiteVMInstance*) instance
                       binary: (NSData*) binaryCode
                        error: (NSError**) error;


/**
 销毁LVM实例

 @param instance LVM实例
 @param error 错误
 */
- (void) destroyLiteVMInstance: (LiteVMInstance*) instance
                         error: (NSError**) error;



/**
 调用无返回值的LVM函数

 @param instance LVM实例
 @param index 要调用的函数在binary code中的index （一个binary code中可以有多个函数，以0为开始的下标来标识）
 @param param 参数数组
 @param error 错误
 */
- (void) callLiteVMVoidMethod: (LiteVMInstance*) instance
                 funtionIndex: (int) index
                   paramArray: (NSArray<LiteVMParameterWrapper*>*) param
                        error: (NSError**) error;


/**
 调用返回值为long（整型）的LVM函数

 @param instance LVM实例
 @param index 要调用的函数在binary code中的index （一个binary code中可以有多个函数，以0为开始的下标来标识）
 @param param 参数数组
 @param error 错误
 @return long型结果
 */
- (long) callLiteVMLongMethod: (LiteVMInstance*) instance
                 funtionIndex: (int) index
                   paramArray: (NSArray<LiteVMParameterWrapper*>*) param
                        error: (NSError**) error;
/**
 调用返回值为NSString类型的LVM函数
 
 @param instance LVM实例
 @param index 要调用的函数在binary code中的index （一个binary code中可以有多个函数，以0为开始的下标来标识）
 @param param 参数数组
 @param error 错误
 @return NSString返回值
 */
- (NSString*) callLiteVMStringMethod: (LiteVMInstance*) instance
                        funtionIndex: (int) index
                          paramArray: (NSArray<LiteVMParameterWrapper*>*) param
                               error: (NSError**) error;

/**
 调用返回值为NSData类型的LVM函数
 
 @param instance LVM实例
 @param index 要调用的函数在binary code中的index （一个binary code中可以有多个函数，以0为开始的下标来标识）
 @param param 参数数组
 @param error 错误
 @return NSData返回值
 */
- (NSData*) callLiteVMByteMethod: (LiteVMInstance*) instance
                    funtionIndex: (int) index
                      paramArray: (NSArray<LiteVMParameterWrapper*>*) param
                           error: (NSError**) error;

@end

#endif /* ISecurityGuardOpenLiteVMService_h */
