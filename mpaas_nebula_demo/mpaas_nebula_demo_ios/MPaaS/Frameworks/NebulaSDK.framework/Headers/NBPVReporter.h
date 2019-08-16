//
//  NBPVReporter.h
//  Nebula
//
//  Created by chenwenhong on 15/10/8.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBContentViewPageProfile.h"
#import "NBNebulaViewProtocol.h"

@interface NBPVReporter : NSObject <NBContentViewPageDelegate>

@property(nonatomic, copy) NSString *nbl_id;
@property(nonatomic, copy) NSString *entranceUrl;

- (void)viewWillAppear;

- (void)viewWillDisappear;

- (void)viewWillDestroy;

@end
