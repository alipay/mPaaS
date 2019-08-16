//
//  TEXSourceContainer.h
//  Texel
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"
#import "TEXFunctor.h"

@interface TEXSourceContainer : TEXSource

@property(nonatomic, strong)TEXSource* source;
@property(nonatomic, strong)TEXFunctor* destFunctor;
/**
 以chain的某一段整体作为source,指定这段整体某一个节点functor作为输出节点

 @param source  chain的source
 @param functor functor的输出
 @return TEXSourceContainer
 */
- (instancetype)initWithSource:(TEXSource*)source functor:(TEXFunctor*)functor;

- (void)start;
- (void)stop;
@end
