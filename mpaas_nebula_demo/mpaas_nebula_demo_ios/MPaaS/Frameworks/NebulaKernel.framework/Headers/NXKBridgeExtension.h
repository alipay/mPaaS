//
//  NXKBridgeExtension.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaKernel/NebulaKernel.h>
#import "NXKBridgeMethodInfo.h"
#import "NXKDefines.h"
#import "NXKBridgeMethodInfoManager.h"

/*!
 使用NXKBridgeExtension来注册Jsapi，新增Extension继承自NXKBridgeExtension，一个Extension可以实现多个jsapi
 * jsapi实现方法：
    * 通过NXK_DEFINE_JSAPI宏在Extension中定义jsapi
 * 参数说明
   * 第一个参数是jsapi的名称
   * 第二个jsapi实现对应的方法，需要指定每一个需要的参数名称以及类型，会按照参数名称和类型
      从前端传入的字典中自动映射到对应的参数中，映射规则是按照参数名称从字典中取到对应的值
      并且会做参数类型判断，如果类型不符合预期会直接回调前端参数错误
      对于必填参数可以通过方法参数中指定nonnull nullable等来表示
      该参数是否必填，如果必填项前端没有传入会直接提示入参错误
      目前参数可以指定以下类型:@[@"NSString",@"NSNumber",@"NSDictionary",@"NSArray",@"NSDate",@"BOOL"]
   *  第三个参数是是否支持重写，支持就是Y,不支持就是N
 * 其他
   * 实现方可以直接拿到当前的Page对象和callback函数，无需自己在方法中添加
 * 示范
 ```
 //注册setTitle这个jsapi，不可复写，没有别名
 NXK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc)
 {
 NXKPage *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 
 //注册setTitle这个jsapi，可复写，没有别名
 NXK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc,Y)
 {
 NXKPage *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 
 //注册setTitle这个jsapi，可复写，别名setBizTitle
 NXK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc,Y,setBizTitle)
 {
 NXKPage *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 ```
 */

@class NXKBridgeMethodInfo;

NS_ASSUME_NONNULL_BEGIN

/************************************** bridge **************************************/
#define NXK_CONCAT2(A, B) A ## B
#define NXK_CONCAT(A, B) NXK_CONCAT2(A, B)

#if !defined NXK_DYNAMIC
#if __has_attribute(objc_dynamic)
#define NXK_DYNAMIC __attribute__((objc_dynamic))
#else
#define NXK_DYNAMIC
#endif
#endif

#define _NXK_MAP_JSAPI(js_name, method,...) \
+ (void)NXK_CONCAT(__NXK_export__, NXK_CONCAT(js_name, NXK_CONCAT(__LINE__, __COUNTER__))){ \
NXKBridgeMethodInfoManager *manager =  [NXKBridgeMethodInfoManager defaultMethodInfoManager];\
NXKBridgeMethodInfo *info = [[NXKBridgeMethodInfo alloc] init];\
info.jsName = @#js_name;\
info.objectMethodName = @#method;\
info.objectClsName = NSStringFromClass([self class]);\
info.originOverrideAndAlias =@#__VA_ARGS__;\
[manager addMethodInfo:info];\
}

#define NXK_MAP_JSAPI_INFO(js_name, method, args...) \
_NXK_MAP_JSAPI(js_name,method,args) \
- (void)method originParam:(NSDictionary *)originParam page:(NXKPage *)page callback:(PSDJsApiResponseCallbackBlock)callback NXK_DYNAMIC

#define NXK_DEFINE_JSAPI(js_name, method, args...) \
NXK_MAP_JSAPI_INFO(js_name, method,args)

#define NXK_DEFINE_NXKBRIDGEEXTENSION(name) \
@protocol NXEvent4##name <NSObject>\
@end\
@interface name : NXKExtension <NXKBridgeExtensionProtocol,NXEvent4##name>\
@end\


#define NXK_DEFINE_BRIDGEEXTENSION(name) \
@protocol NXEvent4##name <NSObject>\
@end\
@interface name : NXKBridgeExtension <NXEvent4##name>\
@end\

@protocol NXKBridgeExtensionProtocol <NSObject>
@end

NXK_DEFINE_NXKBRIDGEEXTENSION(NXKBridgeExtension)

NS_ASSUME_NONNULL_END
