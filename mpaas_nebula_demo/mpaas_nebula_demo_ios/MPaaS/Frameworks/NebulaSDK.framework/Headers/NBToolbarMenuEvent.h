//
//  NBToolbarMenuEvent.h
//  Nebula
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import "NBToolbarMenuProtocol.h"

@interface NBToolbarMenuEvent : PSDEvent

@property(nonatomic, strong) id<NBToolbarMenuProtocol> toolbarMenu;
@property(nonatomic, readonly, copy) NSString *selectedRowTag;
@property(nonatomic, readonly, copy) NSString *selectedTag;

+ (instancetype)allEvent:(id<NBToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)createBeforeEvent:(id<NBToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)createAfterEvent:(id<NBToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)selectEvent:(id<NBToolbarMenuProtocol>)toolbarMenu selectedTag:(NSString *)selectedTag selectedRowTag:(NSString *)selectedRowTag;

+ (instancetype)selectCancelEvent:(id<NBToolbarMenuProtocol>)toolbarMenu selectedTag:(NSString *)selectedTag selectedRowTag:(NSString *)selectedRowTag;

@end
