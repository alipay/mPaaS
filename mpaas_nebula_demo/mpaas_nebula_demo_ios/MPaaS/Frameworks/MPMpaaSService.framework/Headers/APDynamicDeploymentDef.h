//
//  APDynamicDeploymentDef.h
//  DynamicDeployment
//
//  Created by majie on 16/6/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef APDynamicDeploymentDef_h
#define APDynamicDeploymentDef_h

@class APDynamicDeploymentTaskModel;

typedef enum
{
    RegisterClassNameError = 1,
    RegisterClassFromStringError = 2,
    RegisterClassNoInteraction = 3,
    RegisterSuccess = 4
    
} APDynamicDeploymentRegisterBusinessStatus;


typedef enum
{
    PolicyTypeStart = 1,
    PolicyTypeLogin = 2,
    PolicyTypeForeground = 3,
    PolicyTypeBackground = 4,
    PolicyTypeNone = 5
    
} APDynamicDeploymentPolicyType;


typedef enum
{
    NetTypeNotReachable,
    NetType2G,
    NetType3G,
    NetType4G,
    NetTypeWifi,
    NetTypeUnknown,
    NetTypeAll,

} APDynamicDeploymentNetType;


typedef enum
{
    Unknown      = -1,
    Http         = 0,
    MultiMedia

} APDynamicDeploymentDownloadType;


typedef enum
{
    Image      = -1,
    Video      = 0,
    Audio,
    Zip,
    Txt

} APDynamicDeploymentResourceType;


static NSString * const APDynamicDeploymentCommandPolicyStart = @"start";
static NSString * const APDynamicDeploymentCommandPolicyLogin = @"login";
static NSString * const APDynamicDeploymentCommandPolicyForeground = @"foreground";
static NSString * const APDynamicDeploymentCommandPolicyBackground = @"background";

static NSString * const APDynamicDeploymentCommandBusinessName = @"cmd";

static NSString * const kDynamicDeploymentErrorCode0  =  @"APDynamicDeployment add an request model in running enginer";
static NSString * const kDynamicDeploymentErrorCode1  =  @"APDynamicDeployment download channel error";
static NSString * const kDynamicDeploymentErrorCode2  =  @"APDynamicDeployment download url error";


typedef void (^APDynamicDeploymentDownloadCompletionBlock)(APDynamicDeploymentTaskModel *model, NSData *data, NSError *error);
typedef void (^APDynamicDeploymentEnginerCompletionBlock)(NSString *name, NSData *data, NSError *error);

#define kAPDynamicDeploymentLongLinkTypeBandage  @"MPAAS-MDS-HOTPATCH-GLOBAL"  //hotptch sync biztype
#define kAPDynamicDeploymentLongLinkTypeNebula  @"MPAAS-MDS-NEBULA-GLOBAL"    //Nebula sync biztype

#endif /* APDynamicDeploymentDef_h */
