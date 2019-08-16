//
//  AUShellDependencyProtocol.h
//  AntUIShellForMpass
//
//  Created by maizhelun on 2017/7/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AUCLASS(clazz) NSClassFromString(clazz)

typedef void (^LOTAnimationCompletionBlock)(BOOL animationFinished);
typedef void (^LOTAnimationBlock)(NSError *error, UIView *lotView);

@protocol AUShellDependencyProtocol <NSObject>

+ (instancetype)sharedInstance;

+ (instancetype)manager;
/**
 * 支持DJANGO图片下载，以及外部url图片下载
 * 指定缩略图大小，取回云端图片
 * django图片下载
 * 1 originalSize 为0时，将原图下载
 * 2 zoom 为0时，将大图下载
 * 3 originalSize和zoom的宽高比不是一样的（两者的差的绝对值小于0.001）话将缩放下载
 * 4 否则将等比按照zoom的宽高下载
 */
- (NSString *)getImage:(NSString *)identifier
              business:(NSString *)business
                  zoom:(CGSize)size
          originalSize:(CGSize)size
              progress:(void (^)(double percentage,
                                 long long partialBytes,
                                 long long totalBytes))progress
            completion:(void(^)(UIImage *image, NSError *error))compelete;


- (void)setImageWithKey:(NSString *)key
               business:(NSString *)business
       placeholderImage:(UIImage *)placeholder
                   zoom:(CGSize)zoom
           originalSize:(CGSize)originalSize
               progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
             completion:(void (^)(UIImage *image, NSError *error))complete;

- (id)syncGetImageCacheForIdentifier:(NSString*)identifier request:(id)request;

@property (nonatomic, strong) NSString *actionName;

/**
 *  在名称为 \c bundleName 的bundle中取当前语言状态下\c key 对应的字符串值.
 *
 *  @param key        字符串表中\c key
 *  @param value      默认值, 当找不到该 \c key 对应的 \c value 时返回该默认值.
 *  @param bundleName bundle名称字符串
 *
 *  @return 当前语言状态下\c key 对应的字符串值
 */
+ (NSString *)localizedStringForKey:(NSString *)key
                       defaultValue:(NSString *)value
                           inBundle:(NSString *)bundleName;


/**
 *  获取框架接口对象。
 *
 *  @return 返回当前框架接口对象。
 */
//id DTContextGet();

/**
 * 根据指定的名称查到一个服务。
 *
 * @param name 服务名
 *
 * @return 如果找到指定名称的服务，则返回一个服务对象，否则返回空。
 */
- (id)findServiceByName:(NSString *)name;

- (NSString *)MD5String;


/// Flag is YES when the animation is playing
@property (nonatomic, readonly) BOOL isAnimationPlaying;
/// Tells the animation to loop indefinitely.
@property (nonatomic, assign) BOOL loopAnimation;
@property (nonatomic, assign) CGFloat animationProgress;
@property (nonatomic, readonly) NSNumber* animationCurrentFrame;
- (void)playFromProgress:(CGFloat)fromStartProgress
              toProgress:(CGFloat)toEndProgress
          withCompletion:(nullable LOTAnimationCompletionBlock)completion;
- (void)setProgressWithFrame:(nonnull NSNumber *)currentFrame;
- (void)playFromFrame:(nonnull NSNumber *)fromStartFrame
              toFrame:(nonnull NSNumber *)toEndFrame
       withCompletion:(nullable LOTAnimationCompletionBlock)completion;
- (void)playToFrame:(nonnull NSNumber *)toFrame
     withCompletion:(nullable LOTAnimationCompletionBlock)completion;
+ (nonnull instancetype)animationWithFilePath:(nonnull NSString *)filePath error:(NSError *_Nullable*_Nullable)error;

+ (void)animationAsyncWithFilePath:(NSString *_Nullable)filePath
                        completion:(LOTAnimationBlock _Nonnull )completion;

@end
