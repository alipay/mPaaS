//
//  TAImageUtils.h
//  TinyAppCommon
//
//  Created by 应俊康 on 2018/1/10.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface TAImageModel:NSObject
@property (nonatomic,strong) NSData * imageData;
@property (nonatomic,strong) NSString * errorCode;
@property (nonatomic,strong) NSString * errorMessage;
@property (nonatomic,strong) NSString * path;
@end

typedef void(^TAImageCallback)(TAImageModel * model);

@interface TAImageUtils : PSDJsApiHandler
+(void)imageModelWith:(NSString*)path context:(PSDContext*)context callback:(TAImageCallback)callback;
+(TAImageModel*)imageModelWithApFilePath:(NSString*)path context:(PSDContext*)context;
+(void)imageModelFromNetwork:(NSString*)path context:(PSDContext*)context callback:(TAImageCallback)callback;
+(TAImageModel*)imageModelFromRelation:(NSString*)originalImageUrl context:(PSDContext*)context;
@end
