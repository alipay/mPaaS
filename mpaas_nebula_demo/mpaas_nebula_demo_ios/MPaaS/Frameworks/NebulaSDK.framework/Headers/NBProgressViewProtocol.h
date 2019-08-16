//
//  NBProgressViewProtocol.h
//  Nebula
//
//  Created by chenwenhong on 15/10/13.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NBProgressViewProtocol <NSObject>

@required
- (void)setProgress:(float)progress animated:(BOOL)animated;

- (void)startProgress;

- (void)completeProgress;

- (void)reset;

- (void)cancel;

@optional
- (void)setProgressTintColor:(nullable UIColor *)tintColor;

- (void)setTrackTintColor:(nullable UIColor *)trackTintColor;

@end
