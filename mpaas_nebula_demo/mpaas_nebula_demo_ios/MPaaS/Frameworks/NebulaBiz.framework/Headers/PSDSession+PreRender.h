//
//  PSDSession+PreRender.h
//  H5Service
//
//  Created by chenwenhong on 15-5-11.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@class WKWebView;
@interface PSDSession (PreRender)

@property (nonatomic, strong) WKWebView *daemonView;

- (PSDScene *)createScene:(PSDSceneParam *)sceneParam preRenderParams:(NSDictionary *)preRenderParams kickOut:(NSString *)kickOut isHit:(BOOL*)isHit;

- (BOOL)preRenderScene:(PSDSceneParam *)sceneParam preRenderParams:(NSDictionary *)preRenderParams kickOut:(NSString *)kickOut;

- (NSArray *)preRenderScenes; // PSDScene

- (void)clearPreRender;

- (void)removePreRenderInRange:(NSRange)range;

- (PSDScene *)createScene:(PSDSceneParam *)sceneParam
          preRenderParams:(NSDictionary *)preRenderParams;
@end
