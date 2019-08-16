//
//  PBEntryStringString.h
//  APProtocolBuffers
//
//  Created by cuinacai on 16/6/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APDPBGeneratedMessage.h"



@class PBEntryStringString;

@interface PBEntryStringString : APDPBGeneratedMessage
//hasKey
@property (readonly) BOOL hasKey;
//hasValue
@property (readonly) BOOL hasValue;
//key
@property (nonatomic,strong) NSString* key ;
//value
@property (nonatomic,strong) NSString* value ;
@end