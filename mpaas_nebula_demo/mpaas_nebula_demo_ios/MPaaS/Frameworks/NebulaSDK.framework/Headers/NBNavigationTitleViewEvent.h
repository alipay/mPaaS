//
//  NBTitleViewEvent.h
//  Nebula
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import "NBNavigationTitleViewProtocol.h"

@interface NBNavigationTitleViewEvent : PSDEvent

@property(nonatomic, strong) id<NBNavigationTitleViewProtocol>  titleView;
@property(nonatomic, copy) NSString                             *mainTitle;
@property(nonatomic, copy) NSString                             *subtitle;

+ (instancetype)allEvent:(id<NBNavigationTitleViewProtocol>)titleView;

+ (instancetype)createBeforeEvent;

+ (instancetype)createAfterEvent:(id<NBNavigationTitleViewProtocol>)titleView;

+ (instancetype)setTitleEvent:(NSString *)mainTitle subtitle:(NSString *)subtitle;

+ (instancetype)titleClickEvent:(id<NBNavigationTitleViewProtocol>)titleView;

+ (instancetype)subtitleClickEvent:(id<NBNavigationTitleViewProtocol>)titleView;

+ (instancetype)rightIconClickEvent:(id<NBNavigationTitleViewProtocol>)titleView;


@end
