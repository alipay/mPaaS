//
//  AUDefine.h
//  AntUI
//
//  Created by 祝威 on 16/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef AUDefine_h
#define AUDefine_h

#define kAUAdjustHeight(height) height
#define kButtonPanel           (30300010)

// 定义不要子类化
#define ANTUI_DONOT_SUBCLASS(clazz) NSCAssert([self isMemberOfClass:[clazz class]], @"当前类不支持子类化");
#define final_implementation(clazz)  \
implementation clazz \
- (instancetype)initWithFrame:(CGRect)frame \
{\
    self = [super initWithFrame:frame];\
    if (self) {\
        ANTUI_DONOT_SUBCLASS(clazz)\
        [self au_setup_ui];\
    }\
    return self;\
}\
- (void)au_setup_ui


#define Inherit class NSObject;

#define AU_UNAVAILABLE_INIT \
- (instancetype)init NS_UNAVAILABLE; \
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;




#ifdef DEBUG

// 如下宏只做声明用
// 声明UI组件的依赖其他的UI组件列表
#define AntUI_dependency(...)
// 声明UI组件的模块名称，如果不定义，则使用当前文件所在的文件夹名称
#define AntUI_module(moduleName)
// 声明是基本的UI组件，不支持组件定制化
#define AntUI_BaseComponent
// 声明是基本的UI组件，不支持组件定制化
#define AntUI_BaseComponent

#define AntUI_DEMO(demoClassName)


#else

// 如下宏只做声明用
// 声明UI组件的依赖其他的UI组件列表
#define AntUI_dependency(...)
// 声明UI组件的模块名称，如果不定义，则使用当前文件所在的文件夹名称
#define AntUI_module(moduleName)
// 声明是基本的UI组件，不支持组件定制化
#define AntUI_BaseComponent
// 声明是基本的UI组件，不支持组件定制化
#define AntUI_DEMO(demoClassName)

#endif



// 换肤宏定义
#define __ENABLE_AUTHEME__ 1
#if __ENABLE_AUTHEME__

#undef __theme
#define __theme(bundle,keyStr,defaultValue) \
[AUThemeService themeRealValueForKey:keyStr inBundle:bundle] ? : (defaultValue)

#undef __SEL
#define __SEL(selector) NSStringFromSelector((selector))

#else

#undef __theme
#define __theme(key,bundle,defaultValue) \
(defaultValue)

#endif

// 通用
//#define __THEME(bundle,key,defaultValue)         __theme((bundle),(key),(defaultValue))
//#define __THEME_COLOR(bundle,key,defaultValue)   ((UIColor *)__theme((bundle),(key),(defaultValue)))
//#define __THEME_FONT(bundle,key,defaultValue)    ((UIFont *)([AUThemeService themeForFontKey:key inBundle:bundle] ?: (defaultValue)))
//#define __THEME_FLOAT(bundle,key,defaultValue)   ((CGFloat)[[AUThemeService themeForKey:key inBundle:bundle] floatValue] ?: (defaultValue))
//#define __THEME_SIZE(bundle,key,defaultValue)    (CGSizeFromNSValue([AUThemeService themeForKey:key inBundle:bundle],(defaultValue)))

// 通用新格式

#define __THEME_STR(bundle,key,defaultValue)    [AUThemeService themeForKey:key inBundle:bundle] ? : (defaultValue) // 没有定义格式，则直接返回主题文件中的原始格式
#define __THEME_COLOR(bundle,key,defaultV)  ([AUThemeService AUColorForKey:(key) inBundle:(bundle) defaultValue:(defaultV)])
#define __THEME_FONT(bundle,key,defaultV)    ([AUThemeService AUFontForKey:key inBundle:bundle defaultValue:defaultV])
#define __THEME_FLOAT(bundle,key,defaultV)   ([AUThemeService AUFloatForKey:key inBundle:bundle defaultValue:defaultV])
#define __THEME_SIZE(bundle,key,defaultV)    ([AUThemeService AUSizeForKey:key inBundle:bundle defaultValue:defaultV])
#define __THEME_IMAGE_URL(bundle,key,defaultV)   ([AUThemeService AUImagePathForKey:key inBundle:bundle defaultValue:defaultV])

// AntUI
#define AUI_THEME(key)         __THEME_STR((@"AntUI"),(key),(nil))
#define AUI_THEME_COLOR(key)   __THEME_COLOR((@"AntUI"),(key),(nil))
#define AUI_THEME_FONT(key)    __THEME_FONT((@"AntUI"),(key),(nil))
#define AUI_THEME_FLOAT(key)   __THEME_FLOAT((@"AntUI"),(key),(0.f))
#define AUI_THEME_SIZE(key)    __THEME_SIZE((@"AntUI"),(key),(CGSizeZero))
#define AUI_THEME_URL(key)     __THEME_IMAGE_URL((@"AntUI"),(key),(nil))

// AntUI支持换肤的宏定义
#define AUI_THEMES(key, value)         __THEME_STR((@"AntUI"),(key),(value))
#define AUI_THEMES_COLOR(key, value)   __THEME_COLOR((@"AntUI"),(key),[AUThemeService AUColorWithStringValue:(value)])
#define AUI_THEMES_FONT(key, value)    __THEME_FONT((@"AntUI"),(key),[AUThemeService AUFontWithStringValue:(value)])
#define AUI_THEMES_FLOAT(key, value)   __THEME_FLOAT((@"AntUI"),(key),[AUThemeService AUFloatWithStringValue:(value)])
#define AUI_THEMES_SIZE(key, value)    __THEME_SIZE((@"AntUI"),(key),[AUThemeService AUSizeWithStringValue:(value)])
#define AUI_THEMES_URL(key, value)     __THEME_IMAGE_URL((@"AntUI"),(key),[AUThemeService AUImagePathWithStringValue:(value)])


// 定义从Sel 到 string 的宏
#define AU_SEL(sel)  NSStringFromSelector(@selector(sel))

// 默认configKey是公共前缀AUTheme_拼上bundleName
#define AUThemePreffix   @"AUTheme_"
#define AUConfigKey(bundle)    [NSString stringWithFormat:@"%@%@", AUThemePreffix, (bundle)]

//
#define     AU_SELECTOR_STR     @"AU_SELECTOR_STR"
#define     AU_CURRENT_KEY      @"AU_CURRENT_KEY"
#define     AU_CURRENT_TYPE     @"AU_CURRENT_TYPE"
#define     AU_CURRENT_VALUE    @"AU_CURRENT_VALUE"
#define     AU_CURRENT_BUNDLE   @"AU_CURRENT_BUNDLE"
#define     AU_DEFAULT_URL      @"AU_DEFAULT_URL"
#define     AU_DEFAULT_URL_IMG  @"AU_DEFAULT_URL_IMG" // 用于记录默认URL对应的IMG
#define     AU_DEFAULT_URL_DOWNLOAD_COMPLETE      @"AU_DEFAULT_URL_DOWNLOAD_COMPLETE" // 默认URL下载结果

#define     AU_TYPE_IMAGE       @"UIImage"
#define     AU_TYPE_FONT        @"UIFont"
#define     AU_TYPE_FLOAT       @"CGFloat"
#define     AU_TYPE_SIZE        @"CGSize"
#define     AU_TYPE_COLOR       @"UIColor"
#define     AU_TYPE_DICTIONARY          @"NSDictionary"
#define     AU_TYPE_MEDIA_REQUEST       @"APImageRequest"


// 换肤相关的key
#define AU_THEME_1              @"themes/theme1.strings"
#define AU_THEME_2              @"themes/theme2.strings"
#define AU_THEME_CUSTOM         @"themes/theme1_custom.strings"
#define AntUIBundleName   @"AntUI"

#endif /* AUDefine_h */


