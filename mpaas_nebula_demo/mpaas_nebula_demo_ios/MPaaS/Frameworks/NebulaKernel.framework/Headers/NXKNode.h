//
//  NXKNode.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NXKNodeProtocol <NSObject>
@property(nonatomic, assign)  BOOL isNXKNode;
@end


@interface NXKNode : PSDKernel <PSDExpandoProtocol,NXKNodeProtocol>
@property(nonatomic, assign)  BOOL isNXKNode;
@end
