//
//  ExternKVParam.h
//  APProtocolBuffers
//
//  Created by cuinacai on 15/11/27.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import "APPBGeneratedMessage.h"

@interface ExternKVParam : APPBGeneratedMessage<GeneratedMessageProtocol>
@property (readonly) BOOL hasKey;
@property (readonly) BOOL hasValue;
@property (nonatomic,strong) NSString* key;
@property (nonatomic,strong) NSString* value;
@end
