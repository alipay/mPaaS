//
//  H5PreRenderEvent.h
//  NebulaBiz
//
//  Created by theone on 17/5/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface H5PreRenderEvent : PSDEvent
@property(nonatomic, strong) PSDScene *preRenderScene;
@property(nonatomic, weak) PSDSceneParam *sceneParam;
@property(nonatomic, weak) NSDictionary *data;
+ (instancetype)preRenderEventWithSceneParam:(PSDSceneParam *)sceneParam data:(NSDictionary *)data;
@end
