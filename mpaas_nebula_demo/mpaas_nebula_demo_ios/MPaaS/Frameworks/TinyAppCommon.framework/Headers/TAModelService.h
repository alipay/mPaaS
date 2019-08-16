//
//  TAModelService.h
//  TinyAppCommon
//
//  Created by 百喻 on 2018/9/29.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TAApp : NSObject <NSCopying>
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *iconUrl;
@property (nonatomic, copy) NSString *scene;
@end

@interface TAModelService : NSObject
+ (TAModelService *)shared;
- (TAApp *)findApp:(NSString *)appId version:(NSString *)version;
@end


    
TAModelService * TAModelServiceGet();


