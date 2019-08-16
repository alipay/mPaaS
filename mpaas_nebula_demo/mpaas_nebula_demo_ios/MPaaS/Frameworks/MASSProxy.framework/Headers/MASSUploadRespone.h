//
//  MASSUploadRespone.h
//  MASSProxy
//
//  Created by cuinacai on 16/2/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MASSUploadRespone : NSObject
@property(nonatomic,strong)NSString *fileid;
@property(nonatomic,strong)NSString *zooms;
@property(nonatomic,strong)NSDictionary *desc;
@property(nonatomic,strong)NSString *taskId;
@property(nonatomic,strong)NSDictionary* responseHeaders;
@end
