//
//  SecurityStorage.h
//  SecurityGuardSDK
//
//  Created by lifengzhong on 15/1/19.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SecurityStorage : NSObject

+ (NSInteger) putString: (NSString*) value key: (NSString*) key;

+ (NSString*) getString: (NSString*) key;

+ (void) removeString: (NSString*) key;

@end
