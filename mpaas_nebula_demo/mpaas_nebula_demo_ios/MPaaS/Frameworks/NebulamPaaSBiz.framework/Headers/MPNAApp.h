//
//  NAApp.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/3/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <MPMpaaSService/UnionResourceItem.pb.h>
@interface MPNAApp : NAMApp

- (instancetype)initWithAppInfo:(UnionResourceItem *)info;

@end
