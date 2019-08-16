//
//  MASSChannelInstance.h
//  MASSChannel
//
//  Created by yangxiao on 15/11/24.
//  Copyright © 2015年 ppp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@interface MASSChannelInstance : NSObject

@property (atomic,strong) NSThread* mainThread;

@property (atomic) NSRunLoop*   mainRunloop;



@end
