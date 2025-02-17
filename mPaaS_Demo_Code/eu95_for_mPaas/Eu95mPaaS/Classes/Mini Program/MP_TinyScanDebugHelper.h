//
//  MPDemoTinyScanHelper.h
//  MPTinyAppDemo
//
//  Created by yemingyu on 2019/6/19.
//  Copyright © 2019 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MP_TinyScanDebugHelper : NSObject

+ (instancetype)sharedInstance;

- (void)startScanWithNavVc:(UINavigationController *)navVC;

@property (nonatomic, strong) NSString* code;

@end

NS_ASSUME_NONNULL_END
