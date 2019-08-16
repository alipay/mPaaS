//
//  NXKBridgeMethod.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, NXKNullability) {
    NXKNullabilityUnspecified,
    NXKNullable,
    NXKNonnullable,
};


@interface NXKMethodArgument : NSObject

@property (nonatomic, copy, readonly) NSString *type;
@property (nonatomic, readonly) NXKNullability nullability;
@property (nonatomic, readonly) BOOL unused;
@property (nonatomic, copy, readonly) NSString *name;

@end

NSString *NXKParseMethodSignature(const char *input, NSArray<NXKMethodArgument *> **arguments);
SEL selectorForType(NSString *type);


