//
//  UIView+SnapShot.h
//  MobileFoundation
//
//  Created by 孟嵩 on 15/11/2.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (SnapShot)

- (UIImage *)snapShot __attribute__((unavailable("使用snapShot_au")));
- (UIImage *)snapShot_au;

- (UIImage *)snapShotWithSize:(CGSize)size __attribute__((unavailable("使用snapShotWithSize_au")));
- (UIImage *)snapShotWithSize_au:(CGSize)size;

- (UIImage *)snapShotOnIOS8WithSize:(CGSize)size
                     scaleInContext:(CGFloat)scaleInContext
                      scaleForImage:(CGFloat)scaleForImage __attribute__((unavailable("不再支持iOS 8")));

- (UIImage *)snapShotWithSize_au:(CGSize)size
               scaleInContext:(CGFloat)scaleInContext
                scaleForImage:(CGFloat)scaleForImage;

- (UIImage *)snapShotWithSize:(CGSize)size
               scaleInContext:(CGFloat)scaleInContext
                scaleForImage:(CGFloat)scaleForImage __attribute__((unavailable("使用snapShotWithSize_au:scaleInContext:scaleForImage:")));
@end
