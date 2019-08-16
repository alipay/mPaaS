//
//  NBViewControllerStatus.h
//  NebulaSDK
//
//  Created by theone on 16/2/22.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBViewControllerStatus : NSObject
@property(nonatomic, assign) int isInited;
@property(nonatomic, assign) int didShowCloseBtn;
@property(nonatomic, assign) int isViewReady;
@property(nonatomic, assign) BOOL isViewWillDisappear;
@property(nonatomic, assign) BOOL didDidEnterBackground;
@end
