//
//  VideoMaterialModelInternal.h
//  APMultimedia
//
//  Created by Monster on 16/5/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APVideoMaterialPktModel.h"

@interface VideoMaterialModelInternal : NSObject
@property (nonatomic, strong) NSString* packageId;
@property (nonatomic, strong) NSString* cloudId;
@property (nonatomic, strong) NSString* shortCut;
@property (nonatomic, strong) NSString* iconId;
@property (nonatomic, strong) NSString* selectedIconId;
@property (nonatomic, strong) NSArray* materials;
+ (APVideoMaterial*)materialsElementClass;
@end

@interface VideoMaterialBusinessModelInternal : NSObject
@property (nonatomic, strong) NSString* businessId;
@property (nonatomic, strong) NSString* shortCut;       //包名
@property (nonatomic, strong) NSString* version;        //版本
@end
//业务包信息
@interface VideoMaterialBusinessModel : NSObject
@property (nonatomic, strong) VideoMaterialBusinessModelInternal* business;
@property (nonatomic, strong) NSArray* packages;
+ (VideoMaterialModelInternal*)packagesElementClass;
@end