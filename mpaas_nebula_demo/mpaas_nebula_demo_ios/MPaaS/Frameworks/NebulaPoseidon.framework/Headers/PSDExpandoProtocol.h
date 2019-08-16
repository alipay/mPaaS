//
//  PSDExpandoProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//扩展协议
@protocol PSDExpandoProtocol <NSObject>

/**
 *  根据属性名添加扩展属性
 *
 *  @param expandProperty 属性名
 *  @param value          扩展属性对象
 */
- (void)setExpando:(NSString *)expandProperty withValue:(id)value;

/**
 *  根据属性名获取扩展属性对象
 *
 *  @param expandProperty 扩展属性名
 *
 *  @return 扩展属性对象
 */
- (id)getExpando:(NSString *)expandProperty;

/**
 *  根据属性名删除扩展属性
 *
 *  @param expandProperty 扩展属性名
 */
- (void)deleteExpando:(NSString *)expandProperty;

@end
