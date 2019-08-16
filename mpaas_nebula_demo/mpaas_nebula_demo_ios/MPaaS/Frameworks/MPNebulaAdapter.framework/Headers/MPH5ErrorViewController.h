//
//  H5ErrorViewController.h
//  NebulaBiz
//
//  Created by Denis Swain on 16/5/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MPH5ErrorViewController : UIViewController

/**
 *  传入的URL实例
 */
@property (strong, nonatomic) NSURL *url;

/**
 *  传入的错误码
 */
@property (strong, nonatomic) NSString *errorCode;

/**
 *  传入SPDY状态  "Y" 启用 "N" 未启用 nil 未知
 */
@property (strong, nonatomic) NSString *spdyStatus;

/**
 *  传入的错误原因
 */
@property (strong, nonatomic) NSString *reason;

@end
