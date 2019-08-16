//
//  SecuritySignature.h
//  SecurityGuardSDK
//
//  Created by lifengzhong on 15/1/19.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SecuritySignature : NSObject

+ (NSString*) sign: (NSString*) input key: (NSString*) key;

+ (NSString*) signWithSimulator: (NSString*) input key: (NSString*) key;

+ (NSString*) atlasSign: (NSString*) input key: (NSString*) key;

@end
