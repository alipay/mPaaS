//
//  MASSUpMethod.h
//  MASSProxy
//
//  Created by cuinacai on 16/2/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MASSMethod.h"

@interface MASSUpMethod : MASSMethod
@property(nonatomic, strong) NSData *content;
@property(nonatomic)BOOL needJudgeQuick;
@property(nonatomic,strong)NSString *fileName;
@property(nonatomic,strong) NSDictionary<NSString*,NSString*>* externParams;    //额外的上传上传参数
//下面的属性都是外部域名上传时候要用的，其他不用
@property(nonatomic,strong)NSString* url;           //上传到外部域名的时候，需要填上服务端地址
@property(nonatomic,strong) NSDictionary* externHeaders;    //需要添加的额外http头
@end
