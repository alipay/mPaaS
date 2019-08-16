//
//  DTNumber.h
//  MobileFoundation
//
//  Created by WenBi on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTNumber : NSObject <NSCoding>

- (char)charValue;
- (unsigned char)unsignedCharValue;
- (short)shortValue;
- (unsigned short)unsignedShortValue;
- (int)intValue;
- (unsigned int)unsignedIntValue;
- (long)longValue;
- (unsigned long)unsignedLongValue;
- (long long)longLongValue;
- (unsigned long long)unsignedLongLongValue;
- (float)floatValue;
- (double)doubleValue;
- (BOOL)boolValue;

- (NSString *)stringValue;

- (NSComparisonResult)compare:(DTNumber *)otherNumber;

- (BOOL)isEqualToNumber:(DTNumber *)number;

@end

@interface DTBoolean : DTNumber

+ (DTBoolean *)booleanWithObject:(id)object;

@end

@interface DTByte : DTNumber

+ (DTByte *)byteWithObject:(id)object;

@end

@interface DTCharacter : DTNumber

+ (DTCharacter *)characterWithObject:(id)object;

@end

@interface DTDouble : DTNumber

+ (DTDouble *)doubleWithObject:(id)object;

@end

@interface DTFloat : DTNumber

+ (DTFloat *)floatWithObject:(id)object;

@end

@interface DTInteger : DTNumber

+ (DTInteger *)integerWithObject:(id)object;

@end

@interface DTLong : DTNumber

+ (DTLong *)longWithObject:(id)object;

@end

@interface DTShort : DTNumber

+ (DTShort *)shortWithObject:(id)object;

@end