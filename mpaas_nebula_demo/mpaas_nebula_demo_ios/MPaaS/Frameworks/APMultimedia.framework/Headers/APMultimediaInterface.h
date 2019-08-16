//
//  APMultimediaInterface.h
//  APMultimedia
//
//  Created by shenmo on 8/31/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMultimediaInterface : NSObject

/**
 *  单例对象
 */
+ (instancetype)sharedInstance;

/**
 *  手动清理时，不清理的业务biz代码
 *  默认返回空数组
 */
- (NSArray<NSString*>*)manualCacheCleanExemptBusinessIds;

@end
