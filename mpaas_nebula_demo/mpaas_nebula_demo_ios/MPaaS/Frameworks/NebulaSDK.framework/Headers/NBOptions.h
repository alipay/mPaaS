//
//  NBOptions.h
//  NBService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 如果需要添加新的属性，请指定NBServiceConfiguration的OptionsClass

@protocol NBOptionsProtocol <NSObject>

@property(nonatomic, copy) NSString *nbl_id;
@property(nonatomic, copy) NSString *url;
@property(nonatomic, copy) NSString *defaultTitle;
@property(nonatomic) BOOL showTitleBar; // default is YES
@property(nonatomic) BOOL showToolBar; // default is YES
@property(nonatomic) BOOL showLoading; // default is NO
@property(nonatomic, copy) NSString *closeButtonText; // default is "关闭"
@property(nonatomic) BOOL readTitle; // default is YES
@property(nonatomic, copy) NSString *bizScenario;
@property(nonatomic, copy) NSString *backBehavior; // default is kNBBackBehaviorBack, kNBBackBehaviorBack or kNBBackBehaviorPop
@property(nonatomic) BOOL pullRefresh; // default is NO
@property(nonatomic, copy) NSString *toolbarMenu;
@property(nonatomic) BOOL showProgress; // default is YES
@property(nonatomic, copy) NSString *defaultSubtitle;
@property(nonatomic) long long backgroundColor; // default is 0xFFFFFFFF (10.0.20 extend from int to longlong)
@property(nonatomic) BOOL gestureBack; // default is YES
@property(nonatomic) BOOL canPullDown; // default is YES
@property(nonatomic) BOOL showOptionMenu; // default is YES
@property(nonatomic) BOOL showTitleLoading; // default is NO
@property(nonatomic, assign) BOOL showDomain; // default is YES
@property(nonatomic, assign) BOOL showStatusBar; // default is YES
@property(nonatomic, copy) NSString *titleImage; //not implementation
@property(nonatomic, copy) NSString *landscape; //not implementation
@property(nonatomic) BOOL fullscreen; //not implementation
@property(nonatomic) BOOL enableJSC; //not implementation
@property(nonatomic, strong) NSObject *customParams;
@property(nonatomic, copy) NSString *pushingURLString;
@property(nonatomic, weak) NBViewControllerProxy *viewControllerProxy;



/**
 *  @brief 实例化options，并从dict上解析对应的字段到属性中。创建session的第一个viewController时调用
 *
 *  @date 2015-12-31
 *
 *  @param dict 字段的字典
 *
 *  @return 返回options
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

/**
 *  @brief 实例化options，将other上的字段同步到options，并将dict上的字段覆盖对应的属性，其中bizScenario和nbl_id不能覆盖。session的非第一个viewController创建时调用
 *
 *  @date 2015-12-31
 *
 *  @param other 上一个viewController的options，以便继承
 *  @param dict  字段的字典
 *
 *  @return 返回options
 */
- (id)initWithOptions:(id<NBOptionsProtocol>)other overrides:(NSDictionary *)dict;

@end


@interface NBOptions : NSObject <NBOptionsProtocol>


@end
