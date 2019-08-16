//
//  NXKDefines.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef NXKDefines_h
#define NXKDefines_h


#define NKXBridgeExtensionSubFixSel  @" originParam:(NSDictionary *)originParam page:(NXKPage *)page callback:(PSDJsApiResponseCallbackBlock)callback"



//********************** NKXRegisterMod ***********************//
#define kNXKConfigKey_PluginRuntime             @"PluginRuntime"
#define kNXKConfigKey_Plugins                   @"Plugins"
#define kNXKConfigKey_PluginName                @"name"
#define kNXKConfigKey_PluginEvents              @"events"
#define kNXKConfigKey_PluginEvent               @"name"
#define kNXKConfigKey_PluginUseCapture          @"useCapture"

#define kNXKConfigKey_JsApiRuntime              @"JsApiRuntime"
#define kNXKConfigKey_JsApis                    @"JsApis"
#define kNXKConfigKey_JsApiName                 @"name"
#define kNXKConfigKey_JsApi                     @"jsApi"
#define kNXKConfigKey_JsApiAlias                @"alias"
#define kNXKConfigKey_CheckParams               @"checkParams"
#define kNXKConfigKey_IsPrivate                 @"isPrivate"
#define kNXKConfigKey_Scope                     @"scope"
#define kNXKConfigKey_Level                     @"level"

#define kNXKConfigKey_ComponentRuntime          @"ComponentRuntime"
#define kNXKConfigKey_Components                @"Components"
#define kNXKConfigKey_ComponentName             @"component"

#define kNXKConfigKey_ExtensionRuntimeKey       @"ExtensionRuntime"
#define kNXKConfigKey_Extensions                @"Extensions"


#define NKXConfigurationMod()\
+ (void)load{\
[[NXKConfigManager defaultConfigManager]  registerConfigurationMod:NSStringFromClass(self)];\
}\


/**
 注册一个JSAPI,可配置如：
 
 NXK_Register_JSAPI(toast, JSApi4Toast, mytoast, Y, scene, high)
 
 @param name plain jsapi名称
 @param cls  plain  jsapi对应的实现类
 @param alias plain jsapi别名(可选，不需要就写-)
 @param isPrivate plain 这个jsapi是否支持重写(可选(Y/N)，不需要就写-)
 @param scope plain jsapi作用域(可选(service,session,scene,page)，不需要就写-)
 @param level plain jsapi权限等级(可选(high,abovemedium,medium,low,none)，不需要就写-，默认权限放开)
 @return void
 */
#define NXK_Register_JSAPI(name, cls , alias , isPrivate, scope, level)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kNXKConfigKey_JsApi];\
[name##dic setValue:@#cls forKey:kNXKConfigKey_JsApiName];\
if(![@#alias isEqualToString:@"-"]){\
[name##dic setValue:@#alias forKey:kNXKConfigKey_JsApiAlias];\
}\
if([@#isPrivate isEqualToString:@"Y"]||[@#isPrivate isEqualToString:@"N"]){\
[name##dic setValue:@#isPrivate forKey:kNXKConfigKey_IsPrivate];\
}else{\
[name##dic setValue:@"Y" forKey:kNXKConfigKey_IsPrivate];\
}\
if([@#scope isEqualToString:@"service"]||[@#scope isEqualToString:@"session"] || [@#scope isEqualToString:@"scene"] || [@#scope isEqualToString:@"page"]){\
[name##dic setValue:@#scope forKey:kNXKConfigKey_Scope];\
}\
if(![@#level isEqualToString:@"-"]){\
[name##dic setValue:@#level forKey:kNXKConfigKey_Level];\
}\
[self registerJsapiWithConfig:name##dic];\


/**
 注册一个插件,可配置如：
 
 NXK_Register_Plugin(Plugin4TabBar,scene)
 
 @param name plain 插件的实现类名称
 @param scope plain 插件的作用域(可选(service,session,scene,page)，不需要就写-)
 */
#define NXK_Register_Plugin(name, scope)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kNXKConfigKey_PluginName];\
if([@#scope isEqualToString:@"service"]||[@#scope isEqualToString:@"session"] || [@#scope isEqualToString:@"scene"] || [@#scope isEqualToString:@"page"] || [@#scope isEqualToString:@"proxy"]){\
[name##dic setValue:@#scope forKey:kNXKConfigKey_Scope];\
}\
[self registerPluginWithConfig:name##dic];\


/**
 注册一个Component,可配置如：
 
 NXK_Register_Component(NBComponent4Canvas,canvas)
 
 @param name plain Component的实现类名称
 @param component plain 前端使用的组件名称
 */
#define NXK_Register_Component(name, component)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kNXKConfigKey_PluginName];\
[name##dic setValue:@#component forKey:kNXKConfigKey_ComponentName];\
[self registerComponentWithConfig:name##dic];\

/**
 注册一个扩展,可配置如：
 
 NXK_Register_Extension(NXExtension4Tab)
 
 @param name plain Extension的实现类名称
 */
#define NXK_Register_Extension(name)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kNXKConfigKey_PluginName];\
[self registerExtensionWithConfig:name##dic];\

#endif /* NXKDefines_h */
