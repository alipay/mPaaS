//
//  APDPBGeneratedMessage.h
//  DynamicPB
//
//  Created by cuinacai on 15/12/19.
//  Copyright © 2015年 cuinacai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APPBGeneratedMessage.h"

typedef enum {
    PBFieldOptional = 0,
    PBFieldRequired = 1 ,
    PBFieldRepeated = 2
} PBFieldLabel;

typedef enum {
    //Type=2
    PBFieldTypeString = 0,
    PBFieldTypeBytes,
    PBFieldTypeMessage,
    //Type=0
    PBFieldTypeBOOL,
    PBFieldTypeEnum,
    PBFieldTypeInt32,
    PBFieldTypeInt64,
    PBFieldTypeUInt32,
    PBFieldTypeUInt64,
    //Type=5
    PBFieldTypeFloat32,
    PBFieldTypeFixed32,
    PBFieldTypeSFixed32,
    //Type=1
    PBFieldTypeFloat64,
    PBFieldTypeFixed64,
    PBFieldTypeSFixed64,
} PBFieldType;

typedef struct {
    Byte fieldNumber;
    Byte fieldLabel;//PBFieldLabel
    Byte fieldType;//PBFieldType
    BOOL packed;//
    __unsafe_unretained NSString *fieldName;
    __unsafe_unretained NSString *fieldClassName;
    union {
        SInt32 _enump;
        SInt32 _int32p;
        SInt64 _int64p;
        UInt32 _uint32p;
        UInt64 _uint64p;
        BOOL _boolp;
        Float32 _float32p;
        Float64 _float64p;
    }baseTypeInitValue;
    __unsafe_unretained NSString *stringInitValue;
} PBMsgFieldInfo;

typedef struct {
    PBMsgFieldInfo *fieldInfo;
    int count;
} PBMsgFieldInfos;

@interface APDPBGeneratedMessage : APPBGeneratedMessage<GeneratedMessageProtocol>

/**
 业务切不可调用修改

 @return pb描述文件
 */
+(PBMsgFieldInfos*)_fieldInfos;
@end


