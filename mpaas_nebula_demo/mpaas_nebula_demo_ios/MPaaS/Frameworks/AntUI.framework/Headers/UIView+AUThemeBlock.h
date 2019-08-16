//
//  UIView+AUThemeBlock.h
//  AntUI
//
//  Created by 莜阳 on 2017/12/4.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>



#define themeBlocks     @"themeBlocks"  //
typedef void (^AUBindThemeBlock)();

//
@interface UIView (AUThemeBlock)

/*  自动刷新肤色 —— 多参数主题
 *  不支持在block内包含业务逻辑，因此暂不对外开放
 */
- (void)au_bindThemeBlock:(AUBindThemeBlock)block;


//#define     AU_ARG_COLOR(key,bundle,defaultC)   (__bridge void *))((UIColor *)^{ return  __THEME_COLOR(bundle,key, defaultC);})
//#define     AU_ARG_FONT(key,bundle,defaultF)   ((UIFont *)^{ return __THEME_FONT(bundle,key, defaultF);})
//#define     AU_ARG_FLOAT(key,bundle,defaultFL)  (__bridge void *))((CGFloat)^{ return __THEME_FLOAT(bundle,key, defaultFL);})
//#define     AU_ARG_SIZE(key,bundle,defaultS)    (__bridge void *))((CGSize)^{ return __THEME_SIZE(bundle,key, defaultS)})
//#define     AU_ARG_IMAGE(key,bundle,defaultI)   (__bridge void *))((UIImage *)^{ return __THEME_IMAGE(bundle,key, defaultI);})

#define     AU_ARG_KEY_NAME     @"AU_ARG_KEY_NAME"
#define     AU_ARG_VALUE        @"AU_ARG_VALUE"
#define     AU_ARG_TYPE         @"AU_ARG_TYPE"
#define     AU_COMMON_VALUE     @"AU_COMMON_VALUE"

// 判断数据类型
#define     AU_ARG_TYPE_STR(dataValue)     [[NSString alloc] initWithCString:@encode(typeof (dataValue)) encoding:NSUTF8StringEncoding]
//#define     AU_ARG_OBJ_BOOL(dataValue)     [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"@"]
//#define     AU_ARG_CGSIZE_BOOL(dataValue)  [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"{CGSize=dd}"]
//#define     AU_ARG_BASIC_BOOL(dataValue)   ([AU_ARG_TYPE_STR(dataValue) isEqualToString:@"i"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"c"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"s"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"l"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"q"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"C"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"I"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"S"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"L"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"Q"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"f"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"d"] || [AU_ARG_TYPE_STR(dataValue) isEqualToString:@"B"])

// 基础数据类型转换
#define     AU_NSVALUE_SIZE(size)       [NSValue valueWithCGSize:size]
#define     AU_NSNUMBER_VALUE(argV)      ([AU_ARG_TYPE_STR(argV) isEqualToString:@"i"] ? [NSNumber numberWithInt:argV] : ([AU_ARG_TYPE_STR(argV) isEqualToString:@"f"] ? [NSNumber numberWithFloat:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"d"] ? [NSNumber numberWithDouble:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"B"] ? [NSNumber numberWithBool:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"s"] ? [NSNumber numberWithShort:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"q"] ? [NSNumber numberWithLongLong:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"I"] ? [NSNumber numberWithUnsignedInteger:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"S"] ? [NSNumber numberWithUnsignedShort:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"Q"] ? [NSNumber numberWithUnsignedLongLong:argV] : \
    ([AU_ARG_TYPE_STR(argV) isEqualToString:@"C"] ? [NSNumber numberWithUnsignedChar:argV] : \
    [NSNumber numberWithChar:argV]) ) ) ) ) ) ) ) ) )

//



#define     AU_ARG_COLOR(key,defaultC)      (__bridge void *)@{AU_ARG_KEY_NAME : key?:AU_COMMON_VALUE, AU_ARG_VALUE : defaultC ? : @"NULL", AU_ARG_TYPE : @"UIColor"}
#define     AU_ARG_FONT(key,defaultF)       (__bridge void *)@{AU_ARG_KEY_NAME : key?:AU_COMMON_VALUE, AU_ARG_VALUE : defaultC ? : @"NULL", AU_ARG_TYPE : @"UIFont"}
#define     AU_ARG_FLOAT(key,defaultFL)     (__bridge void *)@{AU_ARG_KEY_NAME : key?:AU_COMMON_VALUE, AU_ARG_VALUE : @(defaultFL), AU_ARG_TYPE : @"CGFloat"}
#define     AU_ARG_SIZE(key,defaultS)       (__bridge void *)@{AU_ARG_KEY_NAME :key?:AU_COMMON_VALUE, AU_ARG_VALUE : [NSValue valueWithCGSize:defaultS], AU_ARG_TYPE : @"CGSize"}
#define     AU_ARG_IMAGE(key,defaultI)     (__bridge void *)@{AU_ARG_KEY_NAME : key?:AU_COMMON_VALUE, AU_ARG_VALUE : defaultI ? : @"NULL"}


// 常规size
#define     AU_SIZE(width, height)   AU_ARG_SIZE(nil, CGSizeMake(width, height))
// 基础数据类型
#define     AU_VALUE(value)          (__bridge void *)@{AU_ARG_KEY_NAME : AU_COMMON_VALUE, AU_ARG_VALUE : AU_NSNUMBER_VALUE(value), AU_ARG_TYPE : AU_ARG_TYPE_STR(value)}
// 对象类型
#define     AU_OBJ(objValue)        (__bridge void *)@{AU_ARG_KEY_NAME : AU_COMMON_VALUE, AU_ARG_VALUE : objValue ? : @"NULL", AU_ARG_TYPE : AU_ARG_TYPE_STR(objValue)}


- (void)au_bindTheme:(NSString *)selectorStr
            inBundle:(NSString *)bundle
            argsList:(void *)args1, ...;

// 内部方法，不建议外部直接调用
- (void)setupThemes:(NSDictionary *)kvs
         invocation:(NSInvocation *)invocation
              index:(NSInteger)i
             bunlde:(NSString *)bundle;

@end
