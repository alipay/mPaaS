//
//  PSDContext+NBService.h
//  NBService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@class NBViewControllerProxy;

@interface PSDContext (NB)

- (UIViewController *)currentViewController;

- (NBViewControllerProxy *)currentViewControllerProxy;

- (PSDSession *)currentSession;

- (PSDScene *)currentScene;

@end
