//
//  PSDArgumentsChecker.h
//  NebulaPoseidon
//
//  Created by theone on 2017/8/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define PSD_TYPE_OF_NUMBER              @"NSNumber"
#define PSD_TYPE_OF_STRING              @"NSString"
#define PSD_TYPE_OF_OBJECT              @"NSDictionary"
#define PSD_TYPE_OF_BOOL                @"NSNumber"
#define PSD_TYPE_OF_ARRAY               @"NSArray"
#define PSD_TYPE_OF_ARRAYBUFFER         @"NSString"


#define PSD_CHECKER_NAME                @"name"
#define PSD_CHECKER_TYPE                @"type"
#define PSD_CHECKER_REQUIRE             @"require"
#define PSD_CHECKER_SUPPORTVERSION      @"supportVersion"
#define PSD_CHECKER_RULE                @"rule"

#define PSD_CHECKER_REQUIRE_YES         @YES
#define PSD_CHECKER_REQUIRE_NO          @NO


/**
 定义JSAPI入参规则
 
 DECLAREARGUMENTRULE(url,@"url", PSD_TYPE_OF_String,@"请求的url字段", PSD_CHECKER_REQUIRE_YES, @"10.0.0", @".*")
 
 @param constVar plain 索引键
 @param argumentName  string  参数名称
 @param type string 参数类型
 @param desc string 参数代表的业务含义
 @param require BOOL  是否必填
 @param supportVersion string 参数开始支持的版本
 @param rule string  参数值范围的正则规则
 @return void
 */
#define DECLAREARGUMENTRULE(constVar,argumentName, type, desc, require, supportVersion, rule) \
NSMutableDictionary *constVar##dic = [NSMutableDictionary dictionary];\
if([argumentName isKindOfClass:[NSString class]]){[constVar##dic setValue:argumentName forKey:PSD_CHECKER_NAME];}\
if([type isKindOfClass:[NSString class]]){[constVar##dic setValue:type forKey:PSD_CHECKER_TYPE];}\
if([require isKindOfClass:[NSNumber class]]){[constVar##dic setValue:require forKey:PSD_CHECKER_REQUIRE];}\
if([supportVersion isKindOfClass:[NSString class]]){[constVar##dic setValue:supportVersion forKey:PSD_CHECKER_SUPPORTVERSION];}\
if([rule isKindOfClass:[NSString class]]){[constVar##dic setValue:rule forKey:PSD_CHECKER_RULE];}\
[self.checker declareJsApiArgumentsRule:constVar##dic];\


/**
 定义JSAPI调用结果规则规则
 
 DECLAREARGUMENTRULE(data,@"data", PSD_TYPE_OF_String,@"请求返回的结果", PSD_CHECKER_REQUIRE_YES, @"10.0.0", @".*")
 
 @param constVar plain 索引键
 @param resultName string  参数名称
 @param type string 参数类型
 @param desc 参数代表的业务含义
 @param require 是否必填
 @param supportVersion 参数开始支持的版本
 @param rule 参数值范围的正则规则
 @return void
 */
#define DECLARERESULTRULE(constVar,resultName,type, desc, require, supportVersion, rule) \
NSMutableDictionary *constVar##dic = [NSMutableDictionary dictionary];\
if([resultName isKindOfClass:[NSString class]]){[constVar##dic setValue:resultName forKey:PSD_CHECKER_NAME];}\
if([type isKindOfClass:[NSString class]]){[constVar##dic setValue:type forKey:PSD_CHECKER_TYPE];}\
if([require isKindOfClass:[NSNumber class]]){[constVar##dic setValue:require forKey:PSD_CHECKER_REQUIRE];}\
if([supportVersion isKindOfClass:[NSString class]]){[constVar##dic setValue:supportVersion forKey:PSD_CHECKER_SUPPORTVERSION];}\
if([rule isKindOfClass:[NSString class]]){[constVar##dic setValue:rule forKey:PSD_CHECKER_RULE];}\
[self.checker declareJsApiResultRule:constVar##dic];\

#define DECLAREERROR(errorCode,errorDesc)

@protocol PSDArgumentsCheckerProtocal;

@interface PSDArgumentsChecker : NSObject
@property(nonatomic, readonly, strong) NSMutableArray *argumentsRules;
@property(nonatomic, readonly, strong) NSMutableArray *callbackResultRules;

- (instancetype)initWithParent:(id<PSDArgumentsCheckerProtocal>)parent;

/**
 给jsApi入参校验器加一条验证规则
 
 规则格式如下:
 @{@"type":PSD_TYPE_OF_Number,@"name":@"xxx",@"require":@YES/@NO,@"supportVersion":@"10.0"}
 
 @param rule 校验规则
 */
- (void)declareJsApiArgumentsRule:(NSDictionary *)rule;

/**
 给jsApi调用结果加一条验证规则
 
 规则格式如下:
 @{@"type":PSD_TYPE_OF_Number,@"name":@"xxx",@"require":@YES/@NO,@"supportVersion":@"10.0"}
 
 @param rule 校验规则
 */
- (void)declareJsApiResultRule:(NSDictionary *)rule;

/**
 执行jsApi入参校验，返回校验失败的项
 */
- (NSArray *)checkArguments:(NSDictionary *)arguments;

/**
 执行jsApi结果校验，返回校验失败的项
 */
- (NSArray *)checkResult:(NSDictionary *)result;
@end


@protocol PSDArgumentsCheckerProtocal <NSObject>
@property(nonatomic, strong) PSDArgumentsChecker *checker;
@optional

/**
 实现类实现该方法，在方法中使用DECLARERULE这个宏来指定参数规则
 */
- (void)declareJsApiArgumentsRules;


/**
 实现类实现该方法，在方法中使用DECLARERULE这个宏来指定参数规则
 */
- (void)declareJsApiResultRules;
@end
