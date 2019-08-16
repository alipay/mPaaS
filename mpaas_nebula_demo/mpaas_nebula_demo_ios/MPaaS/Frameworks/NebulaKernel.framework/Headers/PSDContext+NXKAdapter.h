//
//  PSDContext+NXKAdapter.h
//  NebulaKernel
//
//  Created by theone on 2018/9/9.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>
@class NBViewControllerProxy;

@interface PSDContext (NXKAdapter)
- (UIViewController *)currentViewController;

- (NBViewControllerProxy *)currentViewControllerProxy;

- (PSDSession *)currentSession;

- (PSDScene *)currentScene;

@end
