//
//  APPreferencesAccessor.h
//  MobileFoundation
//
//  Created by shenmo on 14-9-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APBusinessPreferences.h"

@interface APPreferencesAccessor : NSObject

/**
 *  根据业务名创建key-value存取对象，使用这个对象里的commonPreferences和userPreferences不需要再传business了。
 */
- (id)initWithBusiness:(NSString*)business;

/**
 *  返回与用户无关的全局存储对象的操作器
 */
- (APBusinessPreferences*)commonPreferences;

/**
 *  返回操作当前登录态用户的操作器，业务层持有的APPreferencesAccessor，在切换用户后不需要重新创建。
 */
- (APBusinessPreferences*)userPreferences;

@end
