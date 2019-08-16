//
//  APVideoMaterialPktModel.h
//  APMultimedia
//
//  Created by Monster on 16/5/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
//素材小包信息
@interface APVideoMaterial : NSObject
@property (nonatomic, strong) NSString* seq;            //序列号，用于排序
@property (nonatomic, strong) NSString* materialId;     //素材id
@property (nonatomic, strong) NSString* iconId;         //素材iconId
@property (nonatomic, strong) NSString* shortCut;       //素材名
@property (nonatomic, strong) NSString* md5;            //md5校验
@end

//素材大包信息
@interface APVideoMaterialPktModel : NSObject
@property (nonatomic, strong) UIImage* thumbnailImage;      //缩略图
@property (nonatomic, strong) UIImage* thumbnailHLImage;    //缩略图选中高亮
@property (nonatomic, strong) NSString* shortCut;           //包名
@property (nonatomic, strong) NSArray* materials;           //素材小包数组
@end

//业务包信息
@interface APVideoMaterialBusinessModel : NSObject
@property (nonatomic, strong) NSString* businessId;
@property (nonatomic, strong) NSString* shortCut;       //包名
@property (nonatomic, strong) NSString* version;        //版本
@property (nonatomic, strong) NSArray* packages;        //APVideoMaterialPktModel数组
@end

