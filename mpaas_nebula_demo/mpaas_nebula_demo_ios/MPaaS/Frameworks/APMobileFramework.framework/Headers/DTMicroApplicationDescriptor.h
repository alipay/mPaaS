//
//  DTMicroApplicationDescriptor.h
//  Alipay Mobile Runtime Framework
//
//  Created by WenBi on 13-3-30.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTMicroApplicationDescriptor : NSObject

/**
 * 应用Id。
 */
@property(nonatomic, copy) NSString *name;

/**
 * 应用的版本号。
 */
@property(nonatomic, copy) NSString *version;


@end
