//
//  APMPictureResponse.h
//  APMPicture
//
//  Created by JAY on 16/8/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface APMImageProcessResponse : NSObject

@property (nonatomic, strong) UIImage* image;
@property (nonatomic, strong) NSData* data;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, strong) NSError *error;

/**
 *  根据错误生成response对象
 *
 *  @param error NSError实例
 *
 *  @return APMImageProcessResponse实例
 */
+ (instancetype)responseWithError:(NSError *)error;

/**
 *  根据image生成response对象
 *
 *  @param image UIImage实例
 *
 *  @return APMImageProcessResponse实例
 */
+ (instancetype)responseWithImage:(UIImage *)image;

@end
