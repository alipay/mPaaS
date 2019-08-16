//
//  APExistenceTable.h
//  MobileFoundation
//
//  Created by shenmo on 3/1/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APExistenceTable : NSObject

/**
 *  添加对象
 */
- (void)addObject:(id)object;

/**
 *  是否含有对象
 */
- (BOOL)containsObject:(id)object;

/**
 *  删除对象
 */
- (void)removeObject:(id)object;

@end
