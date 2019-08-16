//
//  NXKExtension.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaPoseidon/PSDEvent.h>
#import "NXKExtensionDataAwareProtocol.h"

#import "NXKNode.h"

@protocol NXKSchedulableProtocol;
@protocol NXKExtensionDataAwareProtocol;
@protocol NXKExtensionDataStorageProtocol;

@protocol NXKResultDeliverableProtocol <NSObject>
@property(nonatomic) id previousExtensionResult;
@end

@protocol NXKInterruptableProtocol <NSObject>
@property(nonatomic, assign)  BOOL shouldStopPropagation;
@property(nonatomic, assign)  BOOL shouldPreventDefault;
@end

@protocol NXKExtensionProtocol <NSObject>
@property(nonatomic, assign)  BOOL  didInited;
@property(nonatomic, strong)  id<NXKExtensionDataStorageProtocol>  dataStorage;
@property(nonatomic, weak)    NXKNode  *currentTargetNode;
@property(nonatomic, weak)    PSDEvent *currentEvent;
- (void)onInit;
@end

@interface NXKExtension : NSObject <NXKExtensionProtocol, NXKInterruptableProtocol, NXKResultDeliverableProtocol,NXKExtensionDataAwareProtocol>
@property(nonatomic, assign)  BOOL didInited;
@property(nonatomic, strong)  id<NXKExtensionDataStorageProtocol>  dataStorage;
@property(nonatomic)          id previousExtensionResult;
@property(nonatomic, assign)  BOOL shouldStopPropagation;
@property(nonatomic, assign)  BOOL shouldPreventDefault;
@property(nonatomic, weak)    NXKNode  *currentTargetNode;
@property(nonatomic, weak)    PSDEvent *currentEvent;
@end
