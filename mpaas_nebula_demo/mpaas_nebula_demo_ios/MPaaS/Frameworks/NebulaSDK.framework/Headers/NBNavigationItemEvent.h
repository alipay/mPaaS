//
//  NBNavigationItemEvent.h
//  Nebula
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

@interface NBNavigationItemEvent : PSDEvent

@property(nonatomic, strong) UIButton   *customView;

+ (instancetype)allEvent:(UIButton *)customView;

+ (instancetype)createBeforeEvent:(UIButton *)customView;

+ (instancetype)createAfterEvent:(UIButton *)customView;

+ (instancetype)clickEvent:(UIButton *)customView;

@end


@interface NBNavigationItemLeftBackEvent : NBNavigationItemEvent

@end

@interface NBNavigationItemLeftCloseEvent : NBNavigationItemEvent

@end

@interface NBNavigationItemRightSettingEvent : NBNavigationItemEvent

@property(nonatomic, assign) BOOL    adjustsWidthToFitText; // default is NO
@property(nonatomic, assign) CGFloat maxWidth; // default is
@property(nonatomic, strong) NSString *defaultImageName;
@property(nonatomic, strong) UIColor  *defaultColor;
@property(nonatomic, strong) NSDictionary *data;
@property(nonatomic, strong) UIImage *iconTypeImage;
+ (instancetype)changeRightSettingEvent:(NSDictionary *)data;
@end

@interface NBNavigationItemRightSubSettingEvent : NBNavigationItemEvent
@property(nonatomic, assign) BOOL    adjustsWidthToFitText; // default is NO
@property(nonatomic, assign) CGFloat maxWidth; // default is
@end

