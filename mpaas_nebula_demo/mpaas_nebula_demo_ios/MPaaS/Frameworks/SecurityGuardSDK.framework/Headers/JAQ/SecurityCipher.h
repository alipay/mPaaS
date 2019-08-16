//
//  SecurityCipher.h
//  SecurityGuardSDK
//
//  Created by lifengzhong on 15/1/19.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SecurityCipher : NSObject

+ (NSString*) encryptString: (NSString*) input key: (NSString*) key;

+ (NSString*) decryptString: (NSString*) input key: (NSString*) key;

+ (NSData*) encryptBinary: (NSData*) input key: (NSString*) key;

+ (NSData*) decryptBinary: (NSData*) input key: (NSString*) key;

+ (NSString*) atlasEncryptString: (NSString*) input ;

@end
