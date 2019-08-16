//
//  NXKExtensionDataStorage.h
//  NebulaKernel
//
//  Created by theone on 2018/8/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NXKNode;

@protocol NXKExtensionDataStorageProtocol <NSObject>
@property(nonatomic, weak) NXKNode      *node;
@property(nonatomic) Class    dataTypeClass;
- (id)getData;
@end

@interface NXKExtensionDataStorage : NSObject <NXKExtensionDataStorageProtocol>
@property(nonatomic, weak) NXKNode  *node;
@property(nonatomic)       Class    dataTypeClass;
- (id)getData;
- (instancetype)initWithNode:(NXKNode *)node dataTypeClass:(Class)dataTypeClass;
@end
