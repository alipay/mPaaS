
#import "AUTheme.h"
#import "UIView+AUThemeBlock.h"

//
@interface UIView (AUTheme)

#define AU_COLOR(key)           [self au_colorForKey:key]
#define AU_FONT(key)            [self au_fontForKey:key]
#define AU_ICONSIZE(key)        [self au_iconSizeForKey:key]
#define AU_SPACE(key)           [self au_spaceForKey:key]
#define AU_CORNERRADIUS(key)    [self au_cornerRadiusForKey:key]
#define AU_IAMGE_NAME(key)      [self au_imageNameForKey:key]

@property (nonatomic, strong) AUTheme *auTheme;

/**AUTheme
 获取Theme中key对应的颜色值

 @param key theme中的key
 @return 颜色值
 */
- (UIColor *)au_colorForKey:(NSString *)key;

/**
 获取Theme中key对应的字体

 @param key them e中的key
 @return 字体
 */
- (UIFont *)au_fontForKey:(NSString *)key;

/**
 获取Theme中key对应的图标的大小

 @param key theme中的key
 @return icon的size
 */
- (CGSize)au_iconSizeForKey:(NSString *)key;

/**
 获取Theme中key对应的间距

 @param key theme中的key
 @return 间距
 */
- (CGFloat)au_spaceForKey:(NSString *)key;


/**
 获取Theme中key对应的圆角大小

 @param key theme中的key
 @return 圆角大小
 */
- (CGFloat)au_cornerRadiusForKey:(NSString *)key;

/**
 获取Theme中key对应的图标名字
 
 @param key theme中的key
 @return 圆角大小
 */
- (NSString *)au_imageNameForKey:(NSString *)key;

@end


/**
 子类继承这里，以支持外部在非初始化的时候改变theme
 */
#define __bindTheme(selector, key, defaultValue) \
[self au_bindTheme:(selector) key:(key) inBundle:@"AntUI" defaultValue:(defaultValue)];



@interface UIView (AUThemeInherit)

@property (nonatomic, strong) NSMutableArray *auViewThemes;

/** 手动刷新肤色
 setTheme会自动调用updateThemeIfNeeded
 外部，请勿直接调用
 */
- (void)au_updateThemeIfNeeded;


/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 的主题，包括背景色，字体颜色，字体大小，图片等等
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 当前view设置肤色默认值，如 [UIColor blueColor]
 */
- (void)au_bindTheme:(NSString *)selectorStr
                 key:(NSString *)key
            inBundle:(NSString *)bundle
        defaultValue:(id)defaultValue;

/*  自动刷新肤色 —— 主题肤色在AntUI内部
 *  需要自动刷新的业务必须使用该方法设置 view 的主题，包括背景色，字体颜色，字体大小，图片等等
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 */
- (void)au_bindTheme:(NSString *)selectorStr
                 key:(NSString *)key;


//
/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 的色值
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 当前view设置肤色默认值，如 [UIColor blueColor]
 */
- (void)au_bindThemeForColor:(NSString *)selectorStr
                         key:(NSString *)key
                    inBundle:(NSString *)bundle
                defaultValue:(UIColor *)defaultValue;

//
/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 的字体
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 当前默认值
 */
- (void)au_bindThemeForFont:(NSString *)selectorStr
                        key:(NSString *)key
                   inBundle:(NSString *)bundle
               defaultValue:(UIFont *)defaultValue;

/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 常量数值
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 默认值
 */
- (void)au_bindThemeForFloat:(NSString *)selectorStr
                        key:(NSString *)key
                   inBundle:(NSString *)bundle
               defaultValue:(CGFloat)defaultValue;

/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 的尺寸
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 默认值
 */
- (void)au_bindThemeForSize:(NSString *)selectorStr
                        key:(NSString *)key
                   inBundle:(NSString *)bundle
               defaultValue:(CGSize)defaultValue;


/*  自动刷新肤色
 *  需要自动刷新的业务必须使用该方法设置 view 图像image
 *  @param selectorStr 当前view设置肤色所需调用的方法，如setBackgroundColor
 *  @param key 当前view设置肤色在主题库中的key
 *  @param inBundle 所在bundle
 *  @param defaultValue 默认值
 */
- (void)au_bindThemeForImage:(NSString *)selectorStr
                        key:(NSString *)key
                   inBundle:(NSString *)bundle
               defaultValue:(UIImage *)defaultValue;


/**
 当前控件支持的所有thme中key

 @return 当前控件支持的所有thme中key
 */
- (NSArray *)au_allThemeKeys;


@end

@interface UIView (AUViewUtils)

/*
 * 内部方法，不建议外部直接调用
 */
- (BOOL)checkNeedUpdateCacheList:(NSArray *)backupArray
                             key:(NSString *)key
                    defaultValue:(id)defaultValue;

@end

