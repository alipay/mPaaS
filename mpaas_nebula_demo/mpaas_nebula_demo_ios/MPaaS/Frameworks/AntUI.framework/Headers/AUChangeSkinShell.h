//
//  AUChangeSkinShell.h
//  AntUIShell
//
//  Created by niki on 2019/4/2.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUChangeSkinShell : NSObject

/*
 适用于换肤的下载图片接口
 */
+ (void)getImageByIdentifier:(NSString *)identifier
                       request:(id)request
                   viewInstant:(UIImageView *)viewInstants
                           key:(NSString *)key;

@end


NS_ASSUME_NONNULL_END
