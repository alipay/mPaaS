//
//  PBMapStringString.h
//  APProtocolBuffers
//
//  Created by cuinacai on 16/6/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APDPBGeneratedMessage.h"



@class PBEntryStringString;
@class PBMapStringString;

@interface PBMapStringString : APDPBGeneratedMessage
//hasEntries
@property (readonly) BOOL hasEntries;
//PBEntryStringString
@property (nonatomic,strong) NSArray<PBEntryStringString*>* entries ;
//用dic构建PBMapStringString
+(PBMapStringString*)mapWithDictionary:(NSDictionary<NSString*,NSString*>*)dic;
//PBMapStringString转为Dictionary
-(NSDictionary<NSString*,NSString*>*)toDictionary;
@end


